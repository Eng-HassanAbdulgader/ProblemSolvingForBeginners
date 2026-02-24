#include<iostream>
using namespace std;

int ReadNumber()
{
    cout << "Please Enter Number ? ";
    int num ; cin >> num ; return num ;
}

void AddArrayElement(int number , int arr[100] , int &arrLength)
{
    arr[arrLength] = number ;
    arrLength++;
}

void InputUserNumbersInArray(int arr[], int& arrLength) {
    bool AddMore  = true;

    do {
       
       AddArrayElement(ReadNumber(),arr , arrLength);
        cout << "\nDo you want to add more numbers? [0]: No, [1]: Yes ";
        cin >> AddMore;
    } while (AddMore);

   
}

void PrintArray(const int arr[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100];
    int arrLength = 0;
    InputUserNumbersInArray(arr, arrLength);

    cout << "Array Length: " << arrLength << endl;
    cout << "Array Elements: ";
    PrintArray(arr , arrLength);

    return 0;
}
