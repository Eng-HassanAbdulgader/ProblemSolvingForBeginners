#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct sclient
{
    string AccountNumber;
    string PinCode;
    string ClientName;
    string phoneNumber;
    double AccountBalance;
};

void ReadClineData(sclient &client_Data)
{
    cout << "Please Enter Client Data : \n\n";
    cout << "Enter Account Number? ";
    cin >> client_Data.AccountNumber;
    cout << "Enter PinCode? ";
    cin >> client_Data.PinCode;

    cin.ignore(); // ✅ clear leftover newline before getline

    cout << "Enter ClientName? ";
    getline(cin, client_Data.ClientName);

    cout << "Enter Phone Number? ";
    cin >> client_Data.phoneNumber;

    cout << "Enter Account Balance? ";
    cin >> client_Data.AccountBalance;
}

string ConvertRecordLine(sclient client_Data, string seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += client_Data.AccountNumber + seperator;
    stClientRecord += client_Data.PinCode + seperator;
    stClientRecord += client_Data.ClientName + seperator;
    stClientRecord += client_Data.phoneNumber + seperator;
    stClientRecord += to_string(client_Data.AccountBalance);
    return stClientRecord;
}

vector<string> split(string line, string seperator = "#//#")
{
    vector<string> vclinetRecord;
    int pos = 0;
    string word = " ";
    while ((pos = line.find(seperator)) != std::string::npos)
    {
        word = line.substr(0, pos);
        if (word != "")
        {
            vclinetRecord.push_back(word);
        }
        line.erase(0, pos + seperator.length());
    }
    if (line != "")
    {
        vclinetRecord.push_back(line);
    }
    return vclinetRecord;
}

sclient ConvertLineToRecord(string Line, string seperator = "#//#")
{
    sclient client;
    vector<string> vclientRecord = split(Line, seperator);
    client.AccountNumber = vclientRecord[0];
    client.PinCode = vclientRecord[1];
    client.ClientName = vclientRecord[2];
    client.phoneNumber = vclientRecord[3];
    client.AccountBalance = stod(vclientRecord[4]);
    return client;
}

void PrintClient(sclient client)
{
    cout << "Account Number : " << client.AccountNumber;
    cout << "\nPinCode : " << client.PinCode;
    cout << "\nClient Name : " << client.ClientName;
    cout << "\nClinet Phone Number : " << client.phoneNumber;
    cout << "\nAccount Balance : " << client.AccountBalance;
}

int main()
{
    sclient client;
    ReadClineData(client);
    string Line = ConvertRecordLine(client);
    cout << "\n\n Client Record For Saving is: \n";
    cout << Line;

    client = ConvertLineToRecord(Line);
    cout << "\n Line To Record : \n";
    PrintClient(client);
}
