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

bool isPerfectNumber(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
            sum += i;
    }
    return number == sum;
}

void PrintResults(int Number)
{
    if (isPerfectNumber(Number))
    {
        cout << Number << " Is Perfect Number";
    }
    else
    {
        cout << Number << " Is Not Perfect Number";
    }
}

int main()
{
    PrintResults(ReadPostiveNumber("Please Enter postive number ? "));
    return 0;
}