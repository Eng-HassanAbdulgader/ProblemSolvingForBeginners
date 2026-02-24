#include <iostream>
#include <iomanip> // For setw
using namespace std;

int Is_palindrome_matrix(int matrix[3][3], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col / 2; j++)
        {
            if (matrix[i][j] != matrix[i][col - 1 - j])
            {
                return false;
            }
        }
    }
    return true;
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
    int matrix[3][3] = {{1, 4, 1}, {6, 7, 6}, {10, 12, 10}};

    cout << "\nMatrix elements:" << endl;
    Print_Matrix(matrix, 3, 3);

    if (Is_palindrome_matrix(matrix, 3, 3))
    {
        cout << "yes , it's palindrome matrix";
    }
    else
    {
        cout << "No, it's Not a palindrome matrix";
    }

    cout << "\nPress Enter to continue...";
    cin.ignore(); // Consume any leftover newline character
    cin.get();    // Wait for user to press Enter

    return 0; // Indicate successful execution
}