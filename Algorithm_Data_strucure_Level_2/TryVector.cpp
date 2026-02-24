#include <iostream>
#include <vector>
using namespace std;

int FindLargestElemntInArray(vector<int> &arr, int n)
{
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = arr[i];
        for (int j = 1; j < n; j++)
        {
            if (arr[j] > arr[i])
                maxi = arr[j];
        }
    }
    return maxi;
}

int main()
{
    // int n = 4;
    vector<int> arr[]={1, 4, 7, 10};
    cout << "Largest element in the array is : " << FindLargestElemntInArray(arr, 4);
}