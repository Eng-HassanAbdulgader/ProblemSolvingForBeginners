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

float GetFractionPart(float number)
{
    return number - (int)number;
}

int MyCeil(float number)
{
    int IntPart = (int)number;

    if (abs(GetFractionPart(number)) > 0)
    {
        if (number > 0)
            return ++IntPart;
        else
            return IntPart;
    }
    else
        return number;
}

int main()
{
    float number = ReadNumber();

    cout << "My Ceil result : " << MyCeil(number) << '\n';
    cout << "C++ ceil result : " << ceil(number);
}