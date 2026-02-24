#include <iostream>
using namespace std;

int ReadPostiveNumber(string M)
{
    int LetterNumber = 0;
    do
    {
        cout << M;
        cin >> LetterNumber;
    } while (LetterNumber > 26 || LetterNumber < 0);
    return LetterNumber;
}

void PrintLetterPattern(int num)
{
    for (int i = 65; i <= 65 + num - 1; i++) // to to make sure it's loops till the number
    {
        for (int j = 0; j < i - 64; j++)
        {
            cout << char(i); // we can puts char(64+i) well work too with some changes in loops
        }
        cout << endl;
    }
}

int main()
{
    PrintLetterPattern(ReadPostiveNumber("Please Enter number ? "));
    return 0;
}