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

bool IsPalindromeNumber(int Number)
{
    return Number == ReversNumber(Number);
}

void PrintResult(int Number)
{
    if (IsPalindromeNumber(Number))
    {
        cout << "Yes , It's a Palindrome Number\n";
    }
    else
    {
        cout << "No , It's Not a Palindrome Number\n";
    }
}

int main()
{
    PrintResult(ReadPostiveNumber("Please Enter your Number ? "));
    return 0;
}