#include <iostream>
#include <cmath>
using namespace std;

enum enPrimeOrNotPrime
{
    Prime = 1,
    NotPrime = 2
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

enPrimeOrNotPrime CheckPrime(int Number)
{

    int M = round(Number / 2);
    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
        {
            return enPrimeOrNotPrime::NotPrime;
        }
    }
    return enPrimeOrNotPrime::Prime;
}

void PrintPrimeNumber(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        if (CheckPrime(i) == enPrimeOrNotPrime::Prime)
        {
            cout << i << " is Prime Number " << endl;
        }
    }
}

int main()
{
    PrintPrimeNumber(ReadPostiveNumber("Please Enter Postive Number ? "));
    return 0;
}