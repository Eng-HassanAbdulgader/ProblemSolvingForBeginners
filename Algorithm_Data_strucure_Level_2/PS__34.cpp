#include <iostream>
using namespace std;

int ReadPostiveNumber(string M)
{
    int number;
    do
    {
        cout << M;
        cin >> number;
    } while (number < 0);
    return number;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[], int arrLength)
{

    for (int k = 0; k < arrLength; k++)
    {
        arr[k] = RandomNumber(1, 100);
    }
}

void PrintArray(const int arr[], int arrLength)
{
    for (int m = 0; m < arrLength; m++)
    {
        cout << arr[m] << " ";
    }
    cout << endl;
}

int FindPostionInArray(int arr[], int arrLength, int Target)
{

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Target)
            return i;
    }
    return -1;
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arrLength = 0, Target = 0, Position = 0;
    arrLength = ReadPostiveNumber("Please Enter size of the array ? ");

    FillArrayWithRandomNumbers(arr, arrLength);
    PrintArray(arr, arrLength);

    Target = ReadPostiveNumber("Please Enter number to search ? ");
    cout << "Number You are looking for is : " << Target;
    Position = FindPostionInArray(arr, arrLength, Target);

    if (Position == -1)
    {
        cout << "\nThe number is not found :-)";
    }
    else
    {
        cout << "\nThe number found at position : " << Position << endl;
        cout << "The number found it's order  : " << Position + 1 << endl;
    }

    return 0;
}