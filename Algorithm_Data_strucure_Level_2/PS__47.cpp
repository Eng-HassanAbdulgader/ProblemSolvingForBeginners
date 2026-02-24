#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
    cout << "Please Enter Number ? ";
    float number;
    cin >> number;
    return number;
}

float GetFractionPart(double number)
{
    return number - (int)number;
}

int MyRound(float number)
{
    int IntPart = (int)number;
    if (abs(GetFractionPart(number)) >= 0.5)
    {
        if (number > 0)
            return ++IntPart;
        else
            return --IntPart;
    }
    else
    {
        return IntPart;
    }
}

int main()
{
    float number = ReadNumber();

    cout << "My Round result : " << MyRound(number) << '\n';
    cout << "C++ Round result : " << round(number);
}