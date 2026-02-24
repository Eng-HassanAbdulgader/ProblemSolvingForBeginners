#include <iostream>
using namespace std;

int ReadPostiveNumber(string M)
{
    int Number = 0;
    do
    {
        cout << M;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

void PrintInvertedLetter(int num)
{
    for (int i = num; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << char(64 + i);
        }
        cout << endl;
    }
}

int main()
{
    PrintInvertedLetter(ReadPostiveNumber("Please Enter number ? "));
    return 0;
}