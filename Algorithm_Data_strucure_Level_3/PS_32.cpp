#include <iostream>
#include <string>
using namespace std;

char ReadCharacter()
{
    char chr = ' ';
    cout << "please Enter charecter ";
    cin >> chr;
    return chr;
}

bool isVowel(char letter)
{
    letter = tolower(letter);
    return (letter == 'a') || (letter == 'o') || (letter == 'u') || (letter == 'e') || (letter == 'i');
}

int main()
{
    char s[5] = {'a', 'e', 'u', 'o', 'i'};
    char chr = ReadCharacter();

    if (isVowel(chr))
    {
        cout << "Yes , " << chr << " Is Vowel Letter";
    }
    else
    {
        cout << "No , " << chr << " Is Not Vowel Letter";
    }

    system("pause>0");
}