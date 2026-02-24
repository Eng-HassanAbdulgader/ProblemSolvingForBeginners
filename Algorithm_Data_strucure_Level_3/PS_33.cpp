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

short count_vowel_in_string(string s)
{
    short cn = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isVowel(s[i]))
            cn++;
    }
    return cn;
}

int main()
{

    string s = Read_string();
    cout << "Number of vowel letter in the string is : " << count_vowel_in_string(s);

    system("pause>0");
}