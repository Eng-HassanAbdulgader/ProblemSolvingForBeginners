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

bool isVowel(char letter)
{
    letter = tolower(letter);
    return (letter == 'a') || (letter == 'o') || (letter == 'u') || (letter == 'e') || (letter == 'i');
}

void print_vowels_in_string(string s)
{
    cout << "vowels in string are  : ";
    for (int i = 0; i < s.length(); i++)
    {
        if (isVowel(s[i]))
        {
            cout << s[i] << " ";
        }
    }
}

int main()
{

    string s = Read_string();
    print_vowels_in_string(s);

    system("pause>0");
}