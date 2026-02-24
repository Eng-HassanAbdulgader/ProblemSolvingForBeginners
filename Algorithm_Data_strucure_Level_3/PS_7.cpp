#include<iostream>
using namespace std;

void Fill_Matrix_With_OrderedNumbers(int arr[3][3], short rows, short cols)
{
    int num = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = num++;
        }
    }
}

void Transpose_Matrix(int arr[3][3], int TransposedArr[3][3], short rows, short cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            TransposedArr[j][i] = arr[i][j];  // Corrected the order of indices
        }
    }
}

void Print_Matrix(int arr[3][3], short rows, short cols)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3], arrTransposed[3][3];

    Fill_Matrix_With_OrderedNumbers(arr, 3, 3);
    cout << "Matrix Elements are :- \n";
    Print_Matrix(arr, 3, 3);
    
    Transpose_Matrix(arr, arrTransposed, 3, 3);
    cout << "Matrix Elements After Transpose :- \n";
    Print_Matrix(arrTransposed, 3, 3);

    // Better alternative to system("pause")
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    return 0;
}