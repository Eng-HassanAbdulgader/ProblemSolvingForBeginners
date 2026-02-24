#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm> // For toupper
#include <limits>    // For numeric_limits

using namespace std;

// --- GLOBAL CONSTANTS (Excellent use here) ---
const string clientsFlieName = "Clients.txt";
const string CLIENT_RECORD_SEPARATOR = "#//#";

struct sclient
{
    string AccountNumber;
    string PinCode;
    string ClientName;
    string phoneNumber;
    double AccountBalance;
};

// Functions using const references are defined below main for cleaner structure,
// but for simplicity, we will define them in order here.

// --- INPUT FUNCTION ---
sclient ReadClineData()
{
    sclient client_Data;
    cout << "Please Enter Client Data : \n\n";
    cout << "Enter Account Number? ";
    getline(cin >> ws, client_Data.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, client_Data.PinCode);

    cout << "Enter ClientName? ";
    getline(cin, client_Data.ClientName);

    cout << "Enter Phone Number? ";
    getline(cin, client_Data.phoneNumber);

    cout << "Enter Account Balance? ";
    cin >> client_Data.AccountBalance;

    // FIX 1: Using cin.ignore() without arguments only clears one character.
    // Use cin.ignore(numeric_limits<streamsize>::max(), '\n'); for robustness,
    // but the current single cin.ignore() is often enough when used correctly.
    // We will keep your cin.ignore() but be mindful of the necessary fix in AddClient.
    cin.ignore();

    return client_Data;
}

// --- CONVERSION FUNCTION (PASS BY CONST REFERENCE) ---
string ConvertRecordLine(const sclient &client_Data)
{
    string stClientRecord = "";
    stClientRecord += client_Data.AccountNumber + CLIENT_RECORD_SEPARATOR;
    stClientRecord += client_Data.PinCode + CLIENT_RECORD_SEPARATOR;
    stClientRecord += client_Data.ClientName + CLIENT_RECORD_SEPARATOR;
    stClientRecord += client_Data.phoneNumber + CLIENT_RECORD_SEPARATOR;
    stClientRecord += to_string(client_Data.AccountBalance);
    return stClientRecord;
}

// --- FILE WRITING FUNCTION (PASS BY CONST REFERENCE) ---
void AddDataLineToFile(const string &fileName, const string &DataLine)
{
    fstream MyFile;
    MyFile.open(fileName, ios::out | ios::app);
    // Added robustness check:
    if (MyFile.is_open())
    {
        MyFile << DataLine << endl;
        MyFile.close();
    }
    // Good practice: inform the user if file opening failed
    else
    {
        cerr << "Error: Could not open file " << fileName << " for appending.\n";
    }
}

void AddNewClient()
{
    sclient client = ReadClineData();
    AddDataLineToFile(clientsFlieName, ConvertRecordLine(client));
}

void AddClient()
{
    char addMore = 'y';
    do
    {
        system("cls"); // Windows specific
        cout << "Adding New Client ...\n";
        AddNewClient();
        cout << "Client Added Successfully ,Do you want to add more clients? ";

        cin >> addMore;

        // FIX 2: CRITICAL BUG FIX: The newline left by `cin >> addMore`
        // will break `getline` in the next loop iteration (in ReadClineData).
        // This line clears the stream buffer properly.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while ((toupper(addMore)) == 'Y');
}

// --- STRING SPLIT FUNCTION (PASS BY CONST REFERENCE) ---
vector<string> split(const string &line)
{
    vector<string> vclinetRecord;
    string::size_type pos = 0;
    string word = " ";
    string currentLine = line; // Create a modifiable copy of the input string

    while ((pos = currentLine.find(CLIENT_RECORD_SEPARATOR)) != std::string::npos)
    {
        word = currentLine.substr(0, pos);
        if (word != "")
        {
            vclinetRecord.push_back(word);
        }
        currentLine.erase(0, pos + CLIENT_RECORD_SEPARATOR.length());
    }

    if (currentLine != "")
    {
        vclinetRecord.push_back(currentLine);
    }
    return vclinetRecord;
}

// --- CONVERSION FUNCTION (PASS BY CONST REFERENCE) ---
sclient ConvertLineToRecord(const string &Line)
{
    sclient client;
    vector<string> vclientRecord = split(Line);
    if (vclientRecord.size() == 5)
    {
        client.AccountNumber = vclientRecord[0];
        client.PinCode = vclientRecord[1];
        client.ClientName = vclientRecord[2];
        client.phoneNumber = vclientRecord[3];
        // Ensure robust conversion, though stod is generally safe
        try
        {
            client.AccountBalance = stod(vclientRecord[4]);
        }
        catch (const std::exception &e)
        {
            client.AccountBalance = 0.0; // Handle bad data gracefully
        }
    }
    // Return a client structure (efficient return value optimization applies)
    return client;
}

// --- FILE LOADING FUNCTION (PASS BY CONST REFERENCE) ---
vector<sclient> LoadClientDataFromFile(const string &FileName)
{
    vector<sclient> clients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            // Conversion handles the struct creation
            clients.push_back(ConvertLineToRecord(Line));
        }
        MyFile.close();
    }
    // Good practice: notify if the file couldn't be loaded (e.g., if it doesn't exist)
    else
    {
        cerr << "Warning: Could not open file " << FileName << " for reading.\n";
    }

    return clients;
}

// --- PRINTING FUNCTION (PASS BY CONST REFERENCE) ---
void PrintRecordData(const sclient &Client)
{
    // Fix: Use fixed and setprecision for double output formatting
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.ClientName;
    cout << "| " << setw(12) << left << Client.phoneNumber;
    cout << "| " << setw(12) << left << fixed << setprecision(2) << Client.AccountBalance;
}

// --- PRINTING ALL CLIENTS (PASS BY CONST REFERENCE) ---
void PrintAllClinetData(const vector<sclient> &vClients)
{
    cout << "\n\t\t\t\t\tClient List " << '(' << vClients.size() << ')' << " Client(s).\n";

    // Print Header Separator
    string separator(100, '-');
    cout << separator << "\n"
         << endl;

    // Print Column Headers
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";

    // Print Footer Separator
    cout << "\n"
         << separator << "\n"
         << endl;

    for (const sclient &client : vClients) // Use const reference here too!
    {
        PrintRecordData(client);
        cout << endl;
    }
    cout << separator << "\n"
         << endl; // Final separator
}

int main()
{
    // The commented-out line is ready to add new clients:
    // AddClient();

    vector<sclient> vClients = LoadClientDataFromFile(clientsFlieName);
    PrintAllClinetData(vClients);
    return 0;
}