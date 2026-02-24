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

int CountDigitFrequency(int number, int target)
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

int main()
{
    int number = ReadPostiveNumber("Please Enter postive number ? ");
    int target = ReadPostiveNumber("Please Enter target number ? ");
    cout << "Digit " << target << " Frequency is " << CountDigitFrequency(number, target) << " time(s)";
    return 0;
}