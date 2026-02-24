// Problem: Check if array is typical

#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    return (rand() % (To - From + 1) + From);
}

void Fill_Matrix_With_RandomNumbers(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

bool Is_identity(int matrix[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j && matrix[i][j] != 1)
            {
                return false;
            }
            else if (i != j && matrix[i][j] != 0)
            {
                return false;
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
    srand((unsigned)time(NULL));

    int arr1[3][3];

    Fill_Matrix_With_RandomNumbers(arr1, 3, 3);
    cout << "Matrix 1 Elements : \n";
    Print_Matrix(arr1, 3, 3);

    if (Is_identity(arr1, arr2, 3,3))
    {
        cout << "Yes: it Is identity";
    }
    else
    {
        cout << "No: it is Not identity\n";
    }

    cout << "Press Enter To Contine...";
    cin.ignore();
    cin.get();
}