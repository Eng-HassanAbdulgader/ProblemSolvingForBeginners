#include <iostream>
#include <iomanip>
using namespace std;

short RandomNumber(short From, short To)
{
    return rand() % (To - From + 1) + From;
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

void Print_Matrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()

{

    srand((unsigned)time(NULL));
    int arr[3][3];

    Fill_Matrix_With_RandomNumbers(arr, 3, 3);

    cout << "\nThe Following Are 3*3 Random Matrix Elements : \n";
    Print_Matrix(arr, 3, 3);
    system("pause>0");
}