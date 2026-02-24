// Problem: Check if array is typical

#include <iostream>
using namespace std;

int ReadNumber()
{
    int num = 0;
    cout << "Enter the number to count in matrix? ";
    cin >> num;
    return num;
}

void Fill_Matrix_With_Numbers(int arr[3][3], short rows, short cols)
{
    cout << "Please Enter Matrix Elements : " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter Element at [" << i << "]" << "[" << j << "]" << ": "; // User_Friendly Prompt
            cin >> arr[i][j];
        }
    }
}

int count_repeated_element(int matrix[3][3], int row, int col, int target)
{
    int cn = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == target)
            {
                cn++;
            }
        }
    }
    return cn;
}

void Print_Matrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{

    int arr1[3][3];

    Fill_Matrix_With_Numbers(arr1, 3, 3);
    cout << "Matrix 1 Elements : \n";
    Print_Matrix(arr1, 3, 3);

    int target = ReadNumber();
    cout << "Number " << target << " count in matrix " << count_repeated_element(arr1, 3, 3, target) << endl;

    cout << "Press Enter To Contine...";
    cin.ignore();
    cin.get();
}