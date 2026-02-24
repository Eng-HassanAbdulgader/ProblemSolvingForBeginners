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

int col_sum(int arr[3][3], int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum += arr[i][cols];
    }
    return sum;
}
void  Sum_Of_colsIN_Array(int arr[3][3],int arr2[3] ,short rows, short cols)
{
    for (int i = 0; i < cols; i++)
    {

       arr2[i] = col_sum(arr, rows, i) ;
    }
}

void print_ColsSumArray(int arr[3] ,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"col "<<i+1<< " sum = " <<arr[i]<<'\n';
    }
}

int main()

{

    srand((unsigned)time(NULL));
    int arr[3][3],arr2[3];
    

    Fill_Matrix_With_RandomNumbers(arr, 3, 3);

    cout << "\nThe Following Are 3*3 Random Matrix's Elements : \n";
    Print_Matrix(arr, 3, 3);
    cout << "\nThe Following are The Sum Of each colmun of the matrix: \n";
    Sum_Of_colsIN_Array(arr, arr2,3, 3);
    print_ColsSumArray(arr2 ,3);
    system("pause>0");
}