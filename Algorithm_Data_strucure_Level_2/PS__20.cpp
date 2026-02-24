
#include <iostream>
#include <string>
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

void ShowMinu()
{
    cout << "------------------------------------------\n";
    cout << "\t\tWelcom to the program\n";
    cout << "------------------------------------------\n";
    cout << "Please Select from the minue ? \n";
    cout << "1)Print Random Small Letter \n";
    cout << "2)Print Random Capitail Letter \n";
    cout << "3)Print Random Special Charcter \n";
    cout << "4)Print Random Digit  \n";
}

int main()
{
    srand((unsigned)time(NULL));

    ShowMinu();
    cout << GetRandomCharcter(InputCharType()) << endl;
}
