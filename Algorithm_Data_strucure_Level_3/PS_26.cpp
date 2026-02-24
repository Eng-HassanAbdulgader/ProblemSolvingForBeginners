#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
    string s = "";
    cout << "Please Enter string ? \n";
    getline(cin, s);
    return s;
}

void Tolower_first_letters_in_string(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }
}

void Toupper_first_letters_in_string(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);
    }
}

void print_string(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i];
    }
    cout << endl;
}

int main()
{
    string s1 = ReadString();

    cout << "\nString After Upper :\n";
    Toupper_first_letters_in_string(s1);
    print_string(s1);

    cout << "\nString After Lower :\n";
    Tolower_first_letters_in_string(s1);
    print_string(s1);

    cout << "\nPress Enter to continu...\n";
    cin.ignore();
    cin.get();
}