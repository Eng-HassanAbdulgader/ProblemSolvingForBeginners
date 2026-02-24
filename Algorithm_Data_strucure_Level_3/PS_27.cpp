#include <iostream>
using namespace std;

char Read_character()
{
    char chr = ' ';
    cout << "Please Enter a Character : ";
    cin >> chr;
    return chr;
}

char invert_character(char chr)
{
    return isupper(chr) ? tolower(chr) : toupper(chr);
}

int main()
{
    char chr = Read_character();
    cout << invert_character(chr);
}