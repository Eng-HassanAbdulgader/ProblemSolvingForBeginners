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


int sum_of_matrix(int arr[3][3], short rows, short cols)
{
    int sum =0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
           sum+= arr[i][j];
        }
    }return sum;
}

bool AreEqualMatrix(int arr1[3][3], int arr2[3][3] ,short rows ,short cols)
{
    return (sum_of_matrix(arr1 , rows , cols) ==  sum_of_matrix(arr2 , rows , cols));
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
 
    if( AreEqualMatrix(arr1,arr2,3,3))
    {
        cout <<"Yes/Both Matrix Are Equal ";
    }else
    {
         cout <<"No/Both Matrix Are NOT Equal \n";
    }
    

    cout <<"Press Enter To Contine...";
    cin.ignore();
    cin.get();

}