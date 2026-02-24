#include<iostream>
#include<string>
#include<ctime>
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



void Print_Matrix(int arr[3][3], short rows, short cols)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j]<<" ";
           
        }
        cout << endl;
    }
}

void Print_Middle_Row_Of_Matrix(int arr[3][3], short rows, short cols)
{
    short middleRow = rows/2;

    for(int i = 0; i < rows; i++) 
        
            {cout << arr[middleRow ][i] << " ";}
            
}

void Print_Middle_Col_Of_Matrix(int arr[3][3], short rows, short cols)
{
    short middleCol = cols/2;
        for(int j= 0; j < cols; j++) 
            {cout << arr[j][middleCol] << " ";}
}

int main()
{
    srand(unsigned(time(NULL)));
    int arr[3][3];

    Fill_Matrix_With_RandomNumbers(arr, 3, 3);
    cout << "Matrix 1 Elements are :- \n";
    Print_Matrix(arr, 3, 3);
    
    cout << "Middle Row Of Matrix1 :- \n";
     Print_Middle_Row_Of_Matrix(arr,3,3);

    cout << "\nMiddle col Of Matrix1 :- \n";
    Print_Middle_Col_Of_Matrix(arr,3,3);

    // Better alternative to system("pause")
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    return 0;
}