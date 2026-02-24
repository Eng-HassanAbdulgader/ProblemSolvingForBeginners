#include <iostream>
using namespace std;
int ReadNumber()
{
    int num = 0;
    cout << "Please Enter Number ? ";
    cin >> num;
    return num;
}
void Fiboncci_Fun(int number, int prev1, int prev2)
{
    int FibNumber = 0;
    if (number > 0)
    {

        FibNumber = prev1 + prev2;
        prev2 = prev1;
        prev1 = FibNumber;
        cout << FibNumber << " ";
        Fiboncci_Fun(number - 1, prev1, prev2);
    }
}

int main()
{
    Fiboncci_Fun(ReadNumber(), 0, 1);

    cout << "\nPress Enter to continu ...";
    cin.ignore();
    cin.get();
    return 0;
}