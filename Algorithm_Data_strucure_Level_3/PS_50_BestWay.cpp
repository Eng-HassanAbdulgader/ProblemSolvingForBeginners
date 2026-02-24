#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const string FILE_NAME = "Clients.txt";
const string CLIENT_RECORD_SEPARATOR = "#//#";

struct sclient
{
    string AccountNumber;
    string PinCode;
    string ClientName;
    string phoneNumber;
    double AccountBalance;
    bool MarkForDelet = false;
};

vector<string> split(const string &s1, const string &delim)
{
    vector<string> vclient;
    size_t pos = 0;
    string word;
    string current_string = s1;
    while ((pos = current_string.find(delim)) != std::string::npos)
    {
        word = current_string.substr(0, pos);
        if (word != " ")
        {
            vclient.push_back(word);
        }
        current_string.erase(0, pos + delim.length());
    }
    if (current_string != " ")
    {
        vclient.push_back(current_string);
    }
    return vclient;
}

string ConvertRecordToLine(const sclient &client, const string &CLIENT_RECORD_SEPARATOR)
{
    string line;
    line += client.AccountNumber + CLIENT_RECORD_SEPARATOR;
    line += client.PinCode + CLIENT_RECORD_SEPARATOR;
    line += client.ClientName + CLIENT_RECORD_SEPARATOR;
    line += client.phoneNumber + CLIENT_RECORD_SEPARATOR;
    line += to_string(client.AccountBalance);
    return line;
}

sclient ConvertLineTORecord(const string &s1, const string &CLIENT_RECORD_SEPARATOR)
{
    sclient client;
    vector<string> vclient = split(s1, CLIENT_RECORD_SEPARATOR);
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

vector<sclient> LoadCleintsDataFromFile(const string &FILE_NAME)
{
    vector<sclient> vclient;
    fstream Myfile;
    Myfile.open(FILE_NAME, ios::in);
    if (Myfile.is_open())
    {
        string line;
        sclient client;
        while (getline(Myfile, line))
        {
            client = ConvertLineTORecord(line, CLIENT_RECORD_SEPARATOR);
            vclient.push_back(client);
        }
        Myfile.close();
    }
    return vclient;
}

void printClientCard(const sclient &client)
{
    cout << "The Following are client details \n\n";
    cout << "Account Number : " << client.AccountNumber << '\n';
    cout << "PinCode : " << client.PinCode << '\n';
    cout << " Client Name: " << client.ClientName << '\n';
    cout << "Client Phone Number : " << client.phoneNumber << '\n';
    cout << "Account Balance : " << fixed << setprecision(2) << client.AccountBalance << endl;
}

bool FindClientByAccountNumber(const string &AccountNumber, const vector<sclient> &vclient, sclient &client)
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

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sclient> &vclient)
{
    for (sclient &c : vclient)
    {
        if (c.AccountNumber == AccountNumber)
        {
            c.MarkForDelet = true;
            return true;
        }
    }
    return false;
}

vector<sclient> SaveClientsDataToFile(string FILE_NAME, vector<sclient> &vclient)
{
    fstream Myfile;
    Myfile.open(FILE_NAME, ios::out);
    string DataLine;
    if (Myfile.is_open())
    {
        for (sclient c : vclient)
        {
            if (c.MarkForDelet == false)
            {
                DataLine = ConvertRecordToLine(c, CLIENT_RECORD_SEPARATOR);
                Myfile << DataLine << endl;
            }
        }
        Myfile.close();
    }
    return vclient;
}

void DeleteClientByAccountNumber(string AccountNumber, vector<sclient> &vClients)
{
    sclient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        printClientCard(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientsDataToFile(FILE_NAME, vClients);
            // Refresh Clients
            vClients = LoadCleintsDataFromFile(FILE_NAME);
            cout << "\n\nClient Deleted Successfully.";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
}

string ReadClientAccountNumber()
{
    string AccountNamber = " ";
    cout << "\nPlease Enter Account Number ? ";
    cin >> AccountNamber;
    return AccountNamber;
}

int main()
{
    vector<sclient> vclient;
    vclient = LoadCleintsDataFromFile(FILE_NAME);
    string AccountNamber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNamber, vclient);
    system("pause>0");
}
