#include <iostream>
using namespace std;

void Print_Design()
{
    cout << "\t";
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n--------------------------------------------------------------------------------\n";
}

string ColomunSpartor(int i)
{
    if (i < 10)
    {
        return "   |";
    }
    else
    {
        return "  |";
    }
}

void Print_MultiplicationTable()
{

    for (int i = 1; i <= 10; i++)
    {
        cout << "" << i << ColomunSpartor(i) << "\t";
        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

void ExplainPairs()
{
    pair<int, int> P{10, 15};
    cout << "Example of using Pairs\n";
    cout << P.first << "," << P.second;
}

int main()
{
    Print_Design();
    Print_MultiplicationTable();
    ExplainPairs();
    return 0;
}