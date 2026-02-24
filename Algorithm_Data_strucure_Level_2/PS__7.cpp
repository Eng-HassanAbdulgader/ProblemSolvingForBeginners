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

int ReversNumber(int num)
{
    int remainder = 0, ReversedNum = 0;
    do
    {
        remainder = num % 10;
        ReversedNum = ReversedNum * 10 + remainder;
        num /= 10;
    } while (num > 0);
    return ReversedNum;
}

int main()
{
    int Number = ReadPostiveNumber("Please Enter Postive Number ? ");
    cout << "The Reverse Number for : " << Number << " is : " << ReversNumber(Number);
    return 0;
}