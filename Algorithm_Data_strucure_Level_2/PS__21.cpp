#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharcter = 3,
    Digit = 4
};

enCharType InputCharType()
{
    int num;
    cin >> num;
    return (enCharType)num;
}

char GetRandomCharcter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
    {
        return char(RandomNumber(97, 122));
        break;
    }

    case enCharType::CapitalLetter:
    {
        return char(RandomNumber(65, 90));
        break;
    }

    case enCharType::SpecialCharcter:
    {
        return char(RandomNumber(33, 47));
        break;
    }

    case enCharType::Digit:
    {
        return char(RandomNumber(48, 57));
        break;
    }
    }
    return '\0';
}

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
        Key += GetRandomCharcter(CharType);
    }
    return Key;
}

string GenerateKey(enCharType CharType)
{
    string Key = "";

    Key = Key + GenerateWord(CharType, 4) + '-';
    Key = Key + GenerateWord(CharType, 4) + '-';
    Key = Key + GenerateWord(CharType, 4) + '-';
    Key = Key + GenerateWord(CharType, 4);

    return Key;
}

void GenerateKeys(enCharType CharType, short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key[" << i << "] : ";
        cout << GenerateKey(CharType) << "\n";
    }
}

void ShowMinu()
{
    cout << "------------------------------------------\n";
    cout << "\t\tWelcom to the program\n";
    cout << "------------------------------------------\n";
    cout << "Please Select Which Type of Charcter You Want to Generate? \n";
    cout << "1) Small Letter \n";
    cout << "2) Capitail Letter \n";
    cout << "Enter Your Choose : ";
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    ShowMinu();
    enCharType CharType = InputCharType();
    GenerateKeys(CharType, ReadPostiveNumber("\nPlease Enter number of keys You want to Generate ? \n"));

    return 0;
}