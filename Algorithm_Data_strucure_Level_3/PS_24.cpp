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

void Toupper_first_letters_in_string(string &s)
{
    bool is_first_letter = true;
    cout << "change the first  Letters of this string  into Upper letter : ";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ' && is_first_letter)
        {
            s[i] = toupper(s[i]);
        }

        is_first_letter = (s[i] == ' ' ? true : false);
    }
    cout << endl;
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
    Toupper_first_letters_in_string(s1);
    print_string(s1);

    cout << "Press Enter to continu...\n";
    cin.ignore();
    cin.get();
}