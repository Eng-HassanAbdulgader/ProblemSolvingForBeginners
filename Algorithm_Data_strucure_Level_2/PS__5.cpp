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

void ReversNumber(int num)
{
    int remainder = 0;
    do
    {
        remainder = num % 10;
        cout << remainder << '\n';
        num /= 10;
    } while (num > 0);
}

int main()
{
    ReversNumber(ReadPostiveNumber("Please Enter Postive Number ? "));
    return 0;
}