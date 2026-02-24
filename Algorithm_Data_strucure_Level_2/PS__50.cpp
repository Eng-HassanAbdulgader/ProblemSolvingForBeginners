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

int MySqrt(float number)
{
    return pow(number, 0.5);
}

int main()
{
    float number = ReadNumber();

    cout << "My Sqrt result : " << MySqrt(number) << '\n';
    cout << "C++ sqrt result : " << sqrt(number);
}