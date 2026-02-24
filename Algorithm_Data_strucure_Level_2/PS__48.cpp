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

int Myfloor(float number)
{
    int IntPart = (int)number;
    if (number > 0)
        return IntPart;
    else
        return --IntPart;
}

int main()
{
    float number = ReadNumber();

    cout << "My floor result : " << Myfloor(number) << '\n';
    cout << "C++ floor result : " << floor(number);
}