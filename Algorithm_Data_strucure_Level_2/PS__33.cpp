#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{

    return rand() % (To - From + 1) + From;
}

enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
};

int ReadPostiveNumber(string M)
{
    int Number = 0;
    do
    {
        cout << M;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

string GenerateWord(enCharType CharType, short Length)
{
    string Key = "";
    for (int i = 0; i < Length; i++)
    {
        Key += RandomNumber(65, 90);
    }
    return Key;
}

string GenerateKey()
{
    string Key = "";

    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + '-';
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + '-';
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + '-';
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

    return Key;
}

void FillArrayWithKeys(string arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateKey();
}

void PrintStringArray(const string arr[], int NumberOfKeys)
{
    cout << "\nArray Elements : \n";
    for (int i = 0; i < NumberOfKeys; i++)
    {
        cout << "Key[" << i << "] : ";
        cout << arr[i] << "\n";
    }
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arrLength = ReadPostiveNumber("\nPlease Enter number of keys You want to Generate ? \n");
    string arr[arrLength];

    FillArrayWithKeys(arr, arrLength);
    PrintStringArray(arr, arrLength);

    return 0;
}