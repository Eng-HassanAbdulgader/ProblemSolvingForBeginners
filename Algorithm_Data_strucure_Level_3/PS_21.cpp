#include <iostream>
using namespace std;
int ReadNumber()
{
    int num = 0;
    cout << "Please Enter Number ? ";
    cin >> num;
    return num;
}
void Fiboncci_Fun(int number)
{
    int startNum = 0, secondNum = 1;
    if (number == 1)
    {
        cout << startNum;
    }
    else if (number == 2)
    {
        cout << startNum << " " << secondNum;
    }
    else
    {
        cout << secondNum << " ";
        for (int i = 2; i <= number; i++)
        {
            long long result = startNum + secondNum;
            cout << result << " ";
            startNum = secondNum;
            secondNum = result;
        }
    }
}

int main()
{
    Fiboncci_Fun(ReadNumber());

    cout << "\nPress Enter to continu ...";
    cin.ignore();
    cin.get();
    return 0;
}