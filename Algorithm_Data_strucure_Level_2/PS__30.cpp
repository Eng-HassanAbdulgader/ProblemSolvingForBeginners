#include <iostream>
#include <cmath>
using namespace std;

enum enPrimeOrNotPrime
{
    Prime = 1,
    NotPrime = 2
};

enPrimeOrNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
        {
            return enPrimeOrNotPrime::NotPrime;
        }
    }
    return enPrimeOrNotPrime::Prime;
}

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
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillArrayWithRandomNumbers(int arr[], int arrLength)
{

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

void CopyOnlyPrimeNumbers(int arrSource[], int arrDestination[], int arrLength, int &arr2Length)
{
    int counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimeOrNotPrime::Prime)
        {
            arrDestination[counter] = arrSource[i];
            counter++;
        }
    }
    arr2Length = counter;
}

void SumOf2Array(int arr1[100], int arr2[100], int arr3[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr1[100], arr2[100], arr3[100];
    int arrLength = ReadPostiveNumber("Enter How Many Elements ? ");

    FillArrayWithRandomNumbers(arr1, arrLength);
    FillArrayWithRandomNumbers(arr2, arrLength);

    cout << "Array 1 Elements : ";
    PrintArray(arr1, arrLength);

    cout << "\n Array 2 Element : ";
    PrintArray(arr2, arrLength);

    SumOf2Array(arr1, arr2, arr3, arrLength);
    cout << "\n Sum Of Array 1 and Array 2 Elements: ";
    PrintArray(arr3, arrLength);

    return 0;
}