#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const string FILE_NAME = "Clients.txt";
const string CLIENT_RECORD_SEPARATOR = "#//#";

enum enMinMenueChoice
{
    cleintList = 1,
    AddClient = 2,
    DeleteClient = 3,
    UpdateClient = 4,
    FindClient = 5,
    transaction = 6,
    Exist = 7
};

enum enTransctionsOperations
{
    deposit = 1,
    withdraw = 2,
    TotalBalance = 3,
    BackMenue = 4
};

struct sclient
{
    string AccountNumber;
    string PinCode;
    string ClientName;
    string phoneNumber;
    double AccountBalance;
    bool MarkForDelete = false;
};

// --- Helper Functions ---
void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
}

vector<string> split(const string &s1, const string &delim)
{
    vector<string> vclient;
    size_t pos = 0;
    string current_string = s1;
    while ((pos = current_string.find(delim)) != string::npos)
    {
        string word = current_string.substr(0, pos);
        if (word != "")
            vclient.push_back(word);
        current_string.erase(0, pos + delim.length());
    }
    if (current_string != "")
        vclient.push_back(current_string);
    return vclient;
}

string ConvertRecordToLine(const sclient &client, string Separator = CLIENT_RECORD_SEPARATOR)
{
    return client.AccountNumber + Separator + client.PinCode + Separator +
           client.ClientName + Separator + client.phoneNumber + Separator +
           to_string(client.AccountBalance);
}

sclient ConvertLineTORecord(string line, string Separator = CLIENT_RECORD_SEPARATOR)
{
    sclient client;
    vector<string> vclient = split(line, Separator);
    if (vclient.size() == 5)
    {
        client.AccountNumber = vclient[0];
        client.PinCode = vclient[1];
        client.ClientName = vclient[2];
        client.phoneNumber = vclient[3];
        client.AccountBalance = stod(vclient[4]);
    }
    return client;
}

vector<sclient> LoadCleintsDataFromFile(string FileName)
{
    vector<sclient> vclient;
    fstream Myfile;
    Myfile.open(FileName, ios::in);
    if (Myfile.is_open())
    {
        string line;
        while (getline(Myfile, line))
        {
            if (line != "")
                vclient.push_back(ConvertLineTORecord(line));
        }
        Myfile.close();
    }
    return vclient;
}

void SaveClientsDataToFile(string FileName, vector<sclient> &vclient)
{
    fstream Myfile;
    Myfile.open(FileName, ios::out);
    if (Myfile.is_open())
    {
        for (const sclient &c : vclient)
        {
            if (!c.MarkForDelete)
                Myfile << ConvertRecordToLine(c) << endl;
        }
        Myfile.close();
    }
}

// --- CRUD Functions ---
bool FindClientByAccountNumber(string AccountNumber, const vector<sclient> &vclient, sclient &client)
{
    for (const sclient &c : vclient)
    {
        if (c.AccountNumber == AccountNumber)
        {
            client = c;
            return true;
        }
    }
    return false;
}

void printClientCard(const sclient &client)
{
    cout << "\nThe Following are client details:\n";
    cout << "-----------------------------------\n";
    cout << "Acc Number : " << client.AccountNumber << endl;
    cout << "PinCode    : " << client.PinCode << endl;
    cout << "Name       : " << client.ClientName << endl;
    cout << "Phone      : " << client.phoneNumber << endl;
    cout << "Balance    : " << fixed << setprecision(2) << client.AccountBalance << endl;
    cout << "-----------------------------------\n";
}

void PrintRecordData(const sclient &Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(30) << left << Client.ClientName;
    cout << "| " << setw(12) << left << Client.phoneNumber;
    cout << "| " << setw(12) << left << fixed << setprecision(2) << Client.AccountBalance;
}

void PrintAllClinetData(const vector<sclient> &vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
    cout << "____________________________________________________________________________________________________\n";
    cout << "| " << left << setw(15) << "Acc Number" << "| " << setw(10) << "Pin Code" << "| " << setw(30) << "Client Name" << "| " << setw(12) << "Phone" << "| " << setw(12) << "Balance" << endl;
    cout << "____________________________________________________________________________________________________\n";
    for (const sclient &client : vClients)
    {
        PrintRecordData(client);
        cout << endl;
    }
}

void AddNewClient()
{
    sclient client;
    cout << "Enter Account Number? ";
    getline(cin >> ws, client.AccountNumber);
    cout << "Enter PinCode? ";
    getline(cin, client.PinCode);
    cout << "Enter Name? ";
    getline(cin, client.ClientName);
    cout << "Enter Phone? ";
    getline(cin, client.phoneNumber);
    cout << "Enter Balance? ";
    cin >> client.AccountBalance;

    fstream MyFile;
    MyFile.open(FILE_NAME, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << ConvertRecordToLine(client) << endl;
        MyFile.close();
    }
}

void DeleteClientByAccountNumber(string AccountNumber, vector<sclient> &vClients)
{
    sclient Client;
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        printClientCard(Client);
        char Answer;
        cout << "\nAre you sure you want delete this client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            for (sclient &c : vClients)
            {
                if (c.AccountNumber == AccountNumber)
                {
                    c.MarkForDelete = true;
                    break;
                }
            }
            SaveClientsDataToFile(FILE_NAME, vClients);
            cout << "\nClient Deleted Successfully.";
        }
    }
    else
        cout << "\nClient not found!";
}

void UpdateClientByAccountNumber(string AccountNumber, vector<sclient> &vClients)
{
    sclient Client;
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        printClientCard(Client);
        char Answer;
        cout << "\nAre you sure you want update this client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            for (sclient &c : vClients)
            {
                if (c.AccountNumber == AccountNumber)
                {
                    cout << "Enter PinCode? ";
                    getline(cin >> ws, c.PinCode);
                    cout << "Enter Name? ";
                    getline(cin, c.ClientName);
                    cout << "Enter Phone? ";
                    getline(cin, c.phoneNumber);
                    cout << "Enter Balance? ";
                    cin >> c.AccountBalance;
                    break;
                }
            }
            SaveClientsDataToFile(FILE_NAME, vClients);
            cout << "\nClient Updated Successfully.";
        }
    }
    else
        cout << "\nClient not found!";
}

// --- Transaction Functions ---
void deposit_function(vector<sclient> &vclient)
{
    string AccNum;
    cout << "Enter Account Number? ";
    cin >> AccNum;
    sclient client;
    if (FindClientByAccountNumber(AccNum, vclient, client))
    {
        printClientCard(client);
        double amount;
        cout << "Please Enter Deposit Amount: ";
        cin >> amount;
        char answer;
        cout << "Confirm Transaction? y/n: ";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            for (sclient &c : vclient)
            {
                if (c.AccountNumber == AccNum)
                {
                    c.AccountBalance += amount;
                    break;
                }
            }
            SaveClientsDataToFile(FILE_NAME, vclient);
            cout << "\nDone!";
        }
    }
}

void withdraw_function(vector<sclient> &vclient)
{
    string AccNum;
    cout << "Enter Account Number? ";
    cin >> AccNum;
    sclient client;
    if (FindClientByAccountNumber(AccNum, vclient, client))
    {
        printClientCard(client);
        double amount;
        cout << "Please Enter Withdraw Amount: ";
        cin >> amount;
        while (amount > client.AccountBalance)
        {
            cout << "Insufficient Balance! Max: " << client.AccountBalance << "\nEnter again: ";
            cin >> amount;
        }
        char answer;
        cout << "Confirm Transaction? y/n: ";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            for (sclient &c : vclient)
            {
                if (c.AccountNumber == AccNum)
                {
                    c.AccountBalance -= amount;
                    break;
                }
            }
            SaveClientsDataToFile(FILE_NAME, vclient);
            cout << "\nDone!";
        }
    }
}

void Transctions_program()
{
    short choice = 0;
    while (choice != enTransctionsOperations::BackMenue)
    {
        system("cls");
        cout << "=================================================\n\t\tTransactions Menu\n=================================================\n";
        cout << "\t1) Deposit\n\t2) Withdraw\n\t3) Total Balances\n\t4) Main Menu\nChoice: ";
        cin >> choice;
        vector<sclient> vclient = LoadCleintsDataFromFile(FILE_NAME);

        switch (choice)
        {
        case enTransctionsOperations::deposit:
            system("cls");
            deposit_function(vclient);
            GoBackToMainMenue();
            break;
        case enTransctionsOperations::withdraw:
            system("cls");
            withdraw_function(vclient);
            GoBackToMainMenue();
            break;
        case enTransctionsOperations::TotalBalance:
            system("cls");
            double Total = 0;
            PrintAllClinetData(vclient);
            for (auto &c : vclient)
                Total += c.AccountBalance;
            cout << "\n\t\t\t\t Total Balances = " << Total;
            GoBackToMainMenue();
            break;
        }
    }
}

void start_program()
{
    while (true)
    {
        system("cls");
        cout << "=================================================\n\t\tMain Menu Screen\n=================================================\n";
        cout << "\t1) Show Clients List\n\t2) Add New Client\n\t3) Delete Client\n\t4) Update Client\n\t5) Find Client\n\t6) Transactions\n\t7) Exit\nChoice: ";
        short choice;
        cin >> choice;
        vector<sclient> vclient = LoadCleintsDataFromFile(FILE_NAME);

        switch ((enMinMenueChoice)choice)
        {
        case cleintList:
            system("cls");
            PrintAllClinetData(vclient);
            GoBackToMainMenue();
            break;
        case AddClient:
            system("cls");
            AddNewClient();
            GoBackToMainMenue();
            break;
        case DeleteClient:
            system("cls");
            cout << "Enter Acc Number: ";
            {
                string acc;
                cin >> acc;
                DeleteClientByAccountNumber(acc, vclient);
            }
            GoBackToMainMenue();
            break;
        case UpdateClient:
            system("cls");
            cout << "Enter Acc Number: ";
            {
                string acc;
                cin >> acc;
                UpdateClientByAccountNumber(acc, vclient);
            }
            GoBackToMainMenue();
            break;
        case FindClient:
            system("cls");
            cout << "Enter Acc Number: ";
            {
                string acc;
                cin >> acc;
                sclient c;
                if (FindClientByAccountNumber(acc, vclient, c))
                    printClientCard(c);
                else
                    cout << "Not Found.";
            }
            GoBackToMainMenue();
            break;
        case transaction:
            Transctions_program();
            break;
        case Exist:
            return;
        }
    }
}

int main()
{
    start_program();
    return 0;
}