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

float MyAbs(float number)
{
    if (number < 0)
    {
        return -1 * number;
    }
    else
    {
        return number;
    }
}

int main()
{
    float number = ReadNumber();

    cout << "My abs result : " << MyAbs(number) << '\n';
    cout << "C++ abs result : " << abs(number);
}