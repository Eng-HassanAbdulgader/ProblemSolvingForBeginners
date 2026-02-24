#include <iostream>
#include <iomanip> // For setw
using namespace std;

// Fills a 3x3 matrix with numbers from user input.
void Fill_Matrix_With_Numbers(int arr[3][3], short rows, short cols)
{
    cout << "Please Enter Matrix Elements:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter Element at [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

// Checks if a 'target' number exists anywhere within a given 3x3 matrix.
bool Is_NumberIn_Matrix(int matrix[3][3], int row, int col, int target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == target)
            {
                return true; // Found the number
            }
        }
    }
    return false; // Number not found
}

// Prints numbers from matrix_1 that exist anywhere in matrix_2.
void Print_Intersected_NumberIn_Matrix(int matrix_1[3][3], int matrix_2[3][3], int row, int col)
{
    bool found_any_intersection = false;
    cout << "\nNumbers from Matrix 1 that are present anywhere in Matrix 2: ";

    // Iterate through each element of matrix_1
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int current_number_from_matrix1 = matrix_1[i][j];

            // Check if this number exists anywhere in matrix_2
            if (Is_NumberIn_Matrix(matrix_2, row, col, current_number_from_matrix1))
            {
                cout << setw(3) << current_number_from_matrix1 << " ";
                found_any_intersection = true;
            }
        }
    }

    if (!found_any_intersection)
    {
        cout << "None";
    }
    cout << endl;
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
    int matrix_1[3][3], matrix_2[3][3];

    Fill_Matrix_With_Numbers(matrix_1, 3, 3);
    cout << "\nMatrix 1 elements:" << endl;
    Print_Matrix(matrix_1, 3, 3);

    Fill_Matrix_With_Numbers(matrix_2, 3, 3);
    cout << "\nMatrix 2 elements:" << endl;
    Print_Matrix(matrix_2, 3, 3);

    // Call the modified function to print numbers from matrix_1 that exist anywhere in matrix_2.
    Print_Intersected_NumberIn_Matrix(matrix_1, matrix_2, 3, 3);

    cout << "\nPress Enter to continue...";
    cin.ignore(); // Consume any leftover newline character
    cin.get();    // Wait for user to press Enter

    return 0; // Indicate successful execution
}