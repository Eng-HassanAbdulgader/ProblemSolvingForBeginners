#include <iostream>
#include <iomanip> // For setw
using namespace std;

int min_in_matrix(int matrix[3][3], int row, int col)
{
    int min = matrix[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

int max_in_matrix(int matrix[3][3], int row, int col)
{
    int max = matrix[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

// Prints the elements of a 3x3 matrix.
void Print_Matrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << "\t"; // Use setw for consistent formatting
        }
        cout << endl;
    }
}

int main()
{
    int matrix[3][3] = {{1, 4, 5}, {6, 7, 8}, {10, 12, 9}};

    cout << "\nMatrix elements:" << endl;
    Print_Matrix(matrix, 3, 3);

    cout << "\n\nMinmum Number in matrix : ";
    cout << min_in_matrix(matrix, 3, 3);

    cout << "\n\nMaxmum Number in matrix : ";
    cout << max_in_matrix(matrix, 3, 3);

    cout << "\nPress Enter to continue...";
    cin.ignore(); // Consume any leftover newline character
    cin.get();    // Wait for user to press Enter

    return 0; // Indicate successful execution
}