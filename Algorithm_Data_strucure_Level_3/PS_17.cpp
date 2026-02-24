#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber()
{
    int num = 0;
    cout << "Please Enter number u want to check\n";
    cin >> num;
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

bool Is_NumberIn_Matrix(arr[3][3], int row, int col, int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
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
    int matrix[3][3];
    Fill_Matrix_With_Numbers(matrix, 3, 3);
    cout << "Matrix elements : " << endl;
    Print_Matrix(matrix, 3, 3);
    int target = ReadNumber();
    if (Is_NumberIn_Matrix(matrix, 3, 3, target))
    {
        cout << "Yes: the number in the  matrix\n";
    }
    else
    {
        cout << "No: it is Not in the matrix\n";
    }
    cout << "Press Enter toi contine...";
    cin.ignore();
    cin.get();
}