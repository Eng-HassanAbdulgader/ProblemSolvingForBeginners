#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[], int &arrLength)
{
    cout << "Please Enter Number of elements ? \n";
    cin >> arrLength;

    for (int k = 0; k < arrLength; k++)
    {
        arr[k] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[], int arrLength)
{
    for (int m = 0; m < arrLength; m++)
    {
        cout << arr[m] << " ";
    }
}

int SumArray(int arr[], int arrLength)
{
    int sum = 0;
    for (int i = 0; i < arrLength; i++)
    {
        sum += arr[i];
    }
    return sum;
}

float ArrayAverage(int arr[], int arrLength)
{
    return (float)SumArray(arr, arrLength) / arrLength;
}

int CopyArray(int OrginalArray[], int CopyArray[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        CopyArray[i] = OrginalArray[i];
    }
    return CopyArray[arrLength - 1];
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr1[100], arr2[100], arrLength;

    FillArrayWithRandomNumbers(arr1, arrLength);
    CopyArray(arr1, arr2, arrLength);

    cout << "Array 1 Elements : ";
    PrintArray(arr1, arrLength);

    cout << "\nArray 2 Elements After copy: ";
    PrintArray(arr2, arrLength);
    return 0;
}