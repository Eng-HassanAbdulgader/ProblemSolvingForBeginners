#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string s = "";
    cout << "Please Enter string ? \n";
    getline(cin, s);
    return s;
}

void print_first_letters_in_string(string s)
{
    bool is_first_letter = true;
    cout << "First Letters of this string : ";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ' && is_first_letter)
        {
            cout << s[i] << " ";
        }

        is_first_letter = (s[i] == ' ' ? true : false);
    }cout<<endl;
}

int main()
{
    print_first_letters_in_string(ReadString());

    cout << "Press Enter to continu...\n";
    cin.ignore();
    cin.get();
}