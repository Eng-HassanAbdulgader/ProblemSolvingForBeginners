#include <iostream>
using namespace std;

int ReadPostiveNumber(string M)
{
    int num = 0;
    do
    {
        cout << M;
        cin >> num;
    } while (num <= 0);
    return num;
}

int ReadArray(int Arr[], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        cout << "Element[" << i + 1 << "] : ";
        cin >> Arr[i];
    }
    return Arr[Length - 1];
}

int TimesRepeatedElement(int arr[], int Length, int El)
{
    int cn = 0;
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] == El)
            cn++;
    }
    return cn;
}

void PrintArray(int Arr[], int Length)
{
    cout << "Orginal Array is : ";

    for (int i = 0; i < Length; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size = ReadPostiveNumber("Please Enter Array Size : ");
    int Arr[size];
    ReadArray(Arr, size);
    int Element = ReadPostiveNumber("\nPlease Enter the number you want to check : ");
    PrintArray(Arr, size);
    cout << Element << " Is Repeated " << TimesRepeatedElement(Arr, size, Element) << " time (s)";
    return 0;
}