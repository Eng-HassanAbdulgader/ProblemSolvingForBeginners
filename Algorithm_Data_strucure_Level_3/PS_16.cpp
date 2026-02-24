#include <iostream>
#include <cmath>
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

/*bool Is_sparse_matrix(int matrix[3][3], int row, int col)
{
    int zero_cnt = 0;
    int non_zero_cnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                non_zero_cnt++;
            }
            else
            {
                zero_cnt++;
            }
        }
    }
    return (zero_cnt > non_zero_cnt);
}*/

bool Is_sparse_matrix(int matrix[3][3], int row, int col)
{
    int matrix_size = row * col;
    return (count_repeated_element(matrix, 3, 3, 0) > (ceil(matrix_size / 2)));
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
    if (Is_sparse_matrix(matrix, 3, 3))
    {
        cout << "Yes: it sparse matrix\n";
    }
    else
    {
        cout << "No: it is Not sparse matrix\n";
    }
    cout << "Press Enter toi contine...";
    cin.ignore();
    cin.get();
}