#include <iostream>
#include <cmath>
using namespace std;

int getPostiveNumber(const string &M)
{
    int number;
    do
    {
        cout << M;
        cin >> number;
    } while (number <= 0);
    return number;
}

int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void FillArrayWithRandomNumbers(int arr[], int arrLength, int min = 1, int max = 100)
{

    for (int k = 0; k < arrLength; k++)
    {
        arr[k] = generateRandomNumber(min, max);
    }
}

void ReveseArray(const int src[], int dest[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        dest[i] = src[arrLength - i - 1];
    }
}

void PrintArray(const int arr[], int arrLength)
{
    for (int m = 0; m < arrLength; m++)
    {
        cout << arr[m] << " ";
    }
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[100], reverseArr[100];
    int arrLength = getPostiveNumber("Enter How Many Elements ? ");

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "Array 1 Elements : ";
    PrintArray(arr, arrLength);

    ReveseArray(arr, reverseArr, arrLength);
    cout << "\nCopyed Array Elements In Revese Order : ";
    PrintArray(reverseArr, arrLength);

    return 0;
}