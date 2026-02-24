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

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr1[100], arr2[100], arrLength, arr2Length = 0;

    FillArrayWithRandomNumbers(arr1, arrLength);
    CopyOnlyPrimeNumbers(arr1, arr2, arrLength, arr2Length);

    cout << "Array  Elements : ";
    PrintArray(arr1, arrLength);

    cout << "\nPrime Numbers in Array 2: ";
    PrintArray(arr2, arr2Length);
    return 0;
}