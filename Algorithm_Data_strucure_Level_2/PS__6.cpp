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

int SumOfDigit(int number)
{
    int sum = 0;
    do
    {
        int remainder = number % 10;
        sum += remainder;
        number /= 10;
    } while (number > 0);
    return sum;
}

void PrintSumOfDigit(int number)
{
    cout << "Sum Of  Digits of " << number << " is : " << SumOfDigit(number) << '\n';
}

int main()
{
    PrintSumOfDigit(ReadPostiveNumber("Please Enter postive number ? "));
    return 0;
}