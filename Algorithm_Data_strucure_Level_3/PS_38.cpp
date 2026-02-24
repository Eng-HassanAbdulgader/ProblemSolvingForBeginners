#include <iostream>
using namespace std;

string Trime_left(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            return s.substr(i, s.length() - 1);
        }
    }
    return "";
}

string Trime_right(string s)
{
    for (int i = s.length(); i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            return s.substr(0, i + 1);
        }
    }
    return "";
}

string Trime(string s)
{
    return (Trime_left(Trime_right(s)));
}

int main()
{
    string S = "    Hassan Wad Kokal";
    cout << "string  is : " << S << endl;
    cout << "string Trimed left : " << Trime_left(S) << endl;
    cout << "string Trimed right : " << Trime_right(S) << endl;
    cout << "string Trimed : " << Trime(S);
}