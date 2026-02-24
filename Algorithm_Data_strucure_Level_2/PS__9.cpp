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

int CountDigitFrequency(int target, int number)
{
    int FreqCount = 0, remainder = 0;
    do
    {
        remainder = number % 10;
        number /= 10;
        if (remainder == target)
            FreqCount++;
    } while (number > 0);
    return FreqCount;
}

void PrintAllDigitsFreq(int number)
{

    for (int i = 0; i < 10; i++)
    {
        int FreqCount = CountDigitFrequency(i, number);
        if (FreqCount > 0)
        {
            cout << "Digit " << i << " Frequency is " << FreqCount << " Time(s)" << '\n';
        }
    }
}

int main()
{
    PrintAllDigitsFreq(ReadPostiveNumber("Please Enter Number ? "));
    return 0;
}