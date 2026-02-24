#include <iostream>
using namespace std;

string ReadWord(string M)
{
    cout << M;
    string word;
    cin >> word;
    return word;
}

bool GuessPassword(string Password)
{
    string word = "";
    int count = 1;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
                cout << "Trail[" << count << "] : " << word << endl;
                if (word == Password)
                {
                    cout << "Password " << Password << '\n';
                    cout << "Found After " << count << " Trial(s)";
                    return true;
                }
                word = "";
                count++;
            }
        }
    }
    return false;
}

int main()
{
    GuessPassword(ReadWord("Please Enter Password ? \n"));
    return 0;
}