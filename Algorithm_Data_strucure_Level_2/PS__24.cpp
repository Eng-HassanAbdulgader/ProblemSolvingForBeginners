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

int FindMaxElement(int arr[], int arrLength)
{
    int maxElement = arr[0];
    for (int i = 1; i < arrLength; i++)
    {
        if (arr[i] > maxElement)
            maxElement = arr[i];
    }
    return maxElement;
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "Array Elements : ";
    PrintArray(arr, arrLength);

    int maxElement = FindMaxElement(arr, arrLength);
    cout << "\nThe maximum element is: " << maxElement << endl;
    return 0;
}