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

char invertLetterCase(char chr)
{
    return isupper(chr) ? tolower(chr) : toupper(chr);
}

short CountLetter(string s, char letter, bool MatchCase = true)
{
    short count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (MatchCase)
        {
            if (s[i] == letter)
            {
                count++;
            }
        }
        else if (tolower(s[i]) == tolower(letter))
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

    cout << "Letter '" << chr << "'" << "count = " << CountLetter(s, chr) << endl;
    cout << "Letter '" << chr << "' Or " << invertLetterCase(chr) << " count = " << CountLetter(s, chr, false);

    system("pause>0");
}