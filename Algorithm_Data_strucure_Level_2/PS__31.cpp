#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void Swap(int &A, int &B)
{
    int Tmp = A;
    A = B;
    B = Tmp;
}

void FillArrayWith1toN(int arr[], int &arrLength)
{
    cout << "Enter Number Of Element : ";
    cin >> arrLength;

    for (int m = 0; m < arrLength; m++)
    {
        arr[m] = m + 1;
    }
}

void PrintArray(int arr[], int arrLength)
{
    for (int m = 0; m < arrLength; m++)
    {
        cout << arr[m] << " ";
    }
}

void ShuffleArray(int arr[100], int arrLength)
{
    for (int k = 0; k < arrLength; k++)
    {
        Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arrLength = 0;

    FillArrayWith1toN(arr, arrLength);
    cout << "Array Element Before Shuffing : ";
    PrintArray(arr, arrLength);

    ShuffleArray(arr, arrLength);
    cout << "\nArray Element After Shuffing : ";
    PrintArray(arr, arrLength);

    return 0;
}