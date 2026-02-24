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

char ReadCharacter()
{
    char chr = ' ';
    cout << "please Enter character You Want to Count : ";
    cin >> chr;
    return chr;
}

short CountLetter(string s, char letter)
{
    short count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == letter)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string s = Read_string();
    char chr = ReadCharacter();
    cout << CountLetter(s, chr);
    system("pause>0");
}