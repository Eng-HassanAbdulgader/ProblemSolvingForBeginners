#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

int RandomNumber(int From ,int To)
{
    return (rand()%(To - From + 1)+From);
}
 int sum(int a  , int b){return a+b;}
 int multiply(int a  , int b){return a*b;}


void Fill_Matrix_With_RandomNumbers(int arr[2][2], short rows, short cols)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = RandomNumber(1,100);
        }
    }
}

void Multiplicate2_Matrices(int arr1[2][2],int arr2[2][2],int arr3[2][2] ,short rows , short cols)
{
    for(int i = 0; i<rows ; i++){
        for(int j = 0;j<cols ;j++){
            arr3[i][j] = sum(multiply(arr1[i][j] , arr2[i][j]),multiply(arr1[i][j+1] , arr2[i+1][j]));
        }
    }
}

void Print_Matrix(int arr[2][2], short rows, short cols)
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
    srand(unsigned(time(NULL)));
    int arr1[2][2], arr2[2][2] ,arr3[2][2];

    Fill_Matrix_With_RandomNumbers(arr1, 2, 2);
    cout << "Matrix 1 Elements are :- \n";
    Print_Matrix(arr1, 2, 2);
    
    Fill_Matrix_With_RandomNumbers(arr2, 2, 2);
    cout << "Matrix 2 Elements are :- \n";
    Print_Matrix(arr2, 2, 2);

    Multiplicate2_Matrices(arr1,arr2,arr3 ,2,2);
    cout << "Result Of Multiply 2 matrix  :- \n";
    Print_Matrix(arr3, 2, 2);

    // Better alternative to system("pause")
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    return 0;
}