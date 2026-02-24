// Problem: Check if array is typical

#include <iostream>
using namespace std;

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

bool Is_scaler_matrix(int matrix[3][3], int row, int col)
{
    if (row != col)
    {
        return false; // For Not Squar matrix No Scaler matrix
    }
    int diagonalValue = matrix[0][0];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                if (matrix[i][j] != diagonalValue)
                {
                    return false;
                }
            }
            else
            {
                if (matrix[i][j] != 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
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
    cout << "Matrix Elements : \n";
    Print_Matrix(arr1, 3, 3);

    if (Is_scaler_matrix(arr1, 3, 3))
    {
        cout << "Yes: it Is scaler matrix\n";
    }
    else
    {
        cout << "No: it is Not Is scaler matrix\n";
    }

    cout << "Press Enter To Contine...";
    cin.ignore();
    cin.get();
}