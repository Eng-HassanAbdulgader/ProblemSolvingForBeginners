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

    int arr[3][3];

    Fill_Matrix_With_RandomNumbers(arr , 3,3);
    Print_Matrix(arr,3,3);

    cout << "Sum Of Matrix 1 : "<<sum_of_matrix(arr , 3,3)<<endl;

    cout <<"Press Enter To Contine...";
    cin.ignore();
    cin.get();

}