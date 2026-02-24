//Problem: Check if array is typical

#include<iostream>
using namespace std;


int RandomNumber(int From ,int To)
{
    return (rand()%(To - From + 1)+From);
}

void Fill_Matrix_With_RandomNumbers(int arr[3][3], short rows, short cols)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = RandomNumber(1,100);
        }
    }
}

bool Is_typical(int arr1[3][3],int arr2[3][3],int row ,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr1[i][j]!=arr2[i][j]){
                return false;
            }
        }
    }
    return true;
}

void Print_Matrix(int arr[3][3], short rows, short cols)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j]<<" ";
           
        }
        cout << endl;
    }
}



int main()
{
    srand((unsigned)time(NULL));

    int arr1[3][3] , arr2[3][3];

    Fill_Matrix_With_RandomNumbers(arr1 , 3,3);
    cout << "Matrix 1 Elements : \n";
    Print_Matrix(arr1,3,3);


    Fill_Matrix_With_RandomNumbers(arr2 , 3,3);
    cout << "Matrix 2 Elements : \n";
    Print_Matrix(arr2,3,3);
 
    if( Is_typical(arr1,arr2,3,3))
    {
        cout <<"Yes: it is typical ";
    }else
    {
         cout <<"No: it is Not typical \n";
    }
    

    cout <<"Press Enter To Contine...";
    cin.ignore();
    cin.get();

}