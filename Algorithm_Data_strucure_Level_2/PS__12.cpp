#include <iostream>
#include"MyLib.h";
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

void PrintInvertedNumber(int num)
{
    for (int i = num; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

int main()
{
 //   PrintInvertedNumberPattern(ReadPostiveNumber("Please Enter Your Number ? "));
    MyLib::TestLib();
    return 0;
}