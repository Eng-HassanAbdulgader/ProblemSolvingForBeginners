#include <iostream>
using namespace std;

void FillArrayWithNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        cin >> arr[i];
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
for (int i = 0; i < arrLength; i++)
{
if (arr[i] == Number)
return i;
}
return -1;
}

bool IsNumberInArray(int Number , int Arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number , Arr , arrLength)!=-1;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    arr[arrLength++] = Number;
}

void CopyDistnictNumberInArray(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
        if (!IsNumberInArray(arrSource[i] , arrDestination, arrLength))
        {
            AddArrayElement(arrSource[i], arrDestination,
                            arrDestinationLength);
        }
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arrLength = 0, arr2Length = 0;

    FillArrayWithNumbers(arr, arrLength);

    int arr2[100];

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    CopyDistnictNumberInArray(arr, arr2, arrLength, arr2Length);
    cout << "\nArray 2 elements after copy:\n";
    PrintArray(arr2, arr2Length);

    return 0;
}
