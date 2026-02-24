#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm> // For toupper
#include <limits>    // For numeric_limits

using namespace std;

// --- GLOBAL CONSTANTS ---
const string clientsFlieName = "Clients.txt";
const string CLIENT_RECORD_SEPARATOR = "#//#";
// تعريف ثابت لعدم العثور على العنصر
const int NOT_FOUND = -1;

struct sclient
{
    string AccountNumber;
    string PinCode;
    string ClientName;
    string phoneNumber;
    double AccountBalance;
};

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

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تم توحيد الـ cin.ignore لضمان الأمان

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
    if (MyFile.is_open())
    {
        MyFile << DataLine << endl;
        MyFile.close();
    }
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

        // تم تثبيت مشكلة الـ Buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while ((toupper(addMore)) == 'Y');
}

// --- STRING SPLIT FUNCTION (PASS BY CONST REFERENCE) ---
vector<string> split(const string &line)
{
    vector<string> vclinetRecord;
    string::size_type pos = 0;
    string word = " ";
    string currentLine = line;

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
        try
        {
            client.AccountBalance = stod(vclientRecord[4]);
        }
        catch (const std::exception &e)
        {
            client.AccountBalance = 0.0;
        }
    }
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
            clients.push_back(ConvertLineToRecord(Line));
        }
        MyFile.close();
    }
    else
    {
        cerr << "Warning: Could not open file " << FileName << " for reading.\n";
    }

    return clients;
}

// --- PRINTING FUNCTION (PASS BY CONST REFERENCE) ---
void PrintRecordData(const sclient &Client)
{
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

    string separator(100, '-');
    cout << separator << "\n"
         << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n"
         << separator << "\n"
         << endl;

    for (const sclient &client : vClients)
    {
        PrintRecordData(client);
        cout << endl;
    }
    cout << separator << "\n"
         << endl;
}

// --- دالة البحث المعدلة: تعيد الفهرس أو NOT_FOUND (-1) ---
int FindClientIndexByAccountNumber(const string &AccountNumber, const vector<sclient> &vclients)
{
    // تم حذف متغير flag واستبدال نمط البحث بإرجاع الفهرس
    for (int i = 0; i < vclients.size(); ++i)
    {
        if (vclients[i].AccountNumber == AccountNumber)
        {
            return i; // إرجاع الفهرس
        }
    }
    return NOT_FOUND; // إرجاع قيمة NOT_FOUND
}

void printClientInfo(const sclient &client)
{
    cout << "The Flowing are the client details : \n";
    cout << endl;
    cout << "Account Number : " << client.AccountNumber << '\n';
    cout << "PinCode : " << client.PinCode << '\n';
    cout << "Cient's Name : " << client.ClientName << '\n';
    cout << "client's phone Number : " << client.phoneNumber << '\n';
    cout << "Account Balance : " << client.AccountBalance << endl;
}

// --- دالة جديدة لتنفيذ عملية البحث بالكامل ---
void PerformClientSearch(const vector<sclient> &vClients)
{
    string AccountNumber;
    cout << "Enter Account Number ? ";
    cin >> AccountNumber;
    // مسح الـ buffer بعد قراءة الـ AccountNumber
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // استخدام دالة البحث الجديدة التي تعيد الفهرس
    int clientIndex = FindClientIndexByAccountNumber(AccountNumber, vClients);

    if (clientIndex != NOT_FOUND)
    {
        // استخدام الفهرس للوصول إلى بيانات العميل وطباعتها

        printClientInfo(vClients[clientIndex]);
        
    }
    else
    {
        cout << "Account Number " << AccountNumber << " Not Founded\n";
    }
}

int main()
{
    // 1. تحميل كل البيانات مرة واحدة عند بدء التشغيل
    vector<sclient> vClients = LoadClientDataFromFile(clientsFlieName);

    // 2. استدعاء دالة البحث المجمعة لتقوم بالعملية
  //  PerformClientSearch(vClients);

    // طبع جدول بكل العملاء
    PrintAllClinetData(vClients);

    return 0;
}