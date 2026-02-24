#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>    // Needed for numeric_limits
#include <algorithm> // Needed for std::toupper

using namespace std;

// --- 1. Use constants for fixed values ---
const string CLIENTS_FILE_NAME = "Clients.txt";
const string CLIENT_RECORD_SEPARATOR = "#//#";

struct sclient
{
    string AccountNumber;
    string PinCode;
    string ClientName;
    string phoneNumber;
    double AccountBalance;
};

sclient ReadClineData()
{
    sclient client_Data;
    cout << "Please Enter Client Data : \n\n";

    // Use cin >> ws to discard leading whitespace, which is fine here
    cout << "Enter Account Number? ";
    getline(cin >> ws, client_Data.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, client_Data.PinCode);

    cout << "Enter ClientName? ";
    getline(cin, client_Data.ClientName);

    cout << "Enter Phone Number? ";
    getline(cin, client_Data.phoneNumber);

    cout << "Enter Account Balance? ";
    // Read the number
    cin >> client_Data.AccountBalance;

    // FIX: Clear the leftover newline character in the stream buffer
    // This is crucial before the next getline() or the next iteration of the loop
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return client_Data;
}

// --- 2. Pass by const reference for efficiency ---
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

// --- 3. Use CLIENTS_FILE_NAME constant and better error handling ---
void AddDataLineToFile(const string &fileName, const string &DataLine)
{
    fstream MyFile;
    // Note: The second argument is redundant in the old version if you use the constant
    MyFile.open(fileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << DataLine << endl;
        MyFile.close();
    }
    else
    {
        cerr << "Error: Unable to open file " << fileName << "\n";
    }
}

void AddNewClient()
{
    sclient client = ReadClineData();
    AddDataLineToFile(CLIENTS_FILE_NAME, ConvertRecordLine(client));
}

void AddClient()
{
    char addMore = 'y';
    do
    {
        // system("cls"); // Windows specific - use with caution
        cout << "Adding New Client ...\n";
        AddNewClient();
        cout << "Client Added Successfully, Do you want to add more clients? (Y/N): ";

        cin >> addMore;
        // FIX: Clear the leftover newline character after reading the char 'addMore'
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while ((toupper(addMore)) == 'Y');
}

int main()
{
    AddClient();
    return 0;
}