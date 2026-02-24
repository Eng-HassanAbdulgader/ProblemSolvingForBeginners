#include <iostream>
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

int main()
{
    sclient client_Data;
    ReadClineData(client_Data);

    cout << "\n\n Client Record For Saving is: \n";
    cout << ConvertRecordLine(client_Data);
    return 0;
}
