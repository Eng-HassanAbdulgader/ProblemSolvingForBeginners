#include <iostream>
using namespace std;

void ReadArray(int arr[], short &arrLength)
{
    cout << "\nPlease Enter size of the Array ? ";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
    {
        cin >> arr[i];
    }
}

bool IsPalindromeArray(int arr[], short arrLength)
{
    for (int i = 0; i < arrLength / 2; i++)
    {
        if (arr[i] != arr[arrLength - i - 1])
            return false;
    }
    return true;
}

int main()
{
    int arr[100];
    short arrLength = 0;
    ReadArray(arr, arrLength);

    if (IsPalindromeArray(arr, arrLength))
    {
        cout << "Yes ,Array is a Palindrome";
    }
    else
    {
        cout << "No,Array is Not palindrome";
    }
    return 0;
}