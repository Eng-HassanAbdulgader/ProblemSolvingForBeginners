#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
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

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "Array Elements : ";
    PrintArray(arr, arrLength);
    cout << "\nThe Average Of Numbers In The Array: " << ArrayAverage(arr, arrLength) << endl;
    return 0;
}