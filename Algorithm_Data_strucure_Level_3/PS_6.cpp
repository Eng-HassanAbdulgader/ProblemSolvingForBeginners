#include<iostream>
using namespace std;

void Fill_Matrix_With_OrderedNumbers(int arr[3][3],short rows , short cols)
{
    int num = 1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            arr[i][j] = num++;
        }
    }

}

void Print_Matrix(int arr[3][3] ,short rows , short cols)
{
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << arr[i][j]<<" ";
        }cout<<endl;
    }
}

int main()
{
    int arr[3][3];
    Fill_Matrix_With_OrderedNumbers(arr ,3,3);
    cout << "Matrix Elements are :- \n";
    Print_Matrix(arr ,3,3);
    system("pause>0");
}