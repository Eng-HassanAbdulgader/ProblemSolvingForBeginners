#include <iostream>
#include <string>
using namespace std;

string Read_string()
{
    string s = "";
    cout << "Please Enter your string : \n";
    getline(cin, s);
    return s;
}

char invert_character(char chr)
{
    return isupper(chr) ? tolower(chr) : toupper(chr);
}

string invert_all_string_letters_case(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = invert_character(s[i]);
    }
    return s;
}

int main()
{
    string s = Read_string();
    cout << invert_all_string_letters_case(s);
}