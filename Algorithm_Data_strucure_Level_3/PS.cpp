#include <iostream>
using namespace std;

string Read_string()
{
    string s = "";
    cout << "Please Enter your string : \n";
    getline(cin, s);
    return s;
}

string trim_left(string S)
{
    short n = S.length();
    for (int i = 0; i < n; i++)
    {
        if (S[i] != ' ')
        {
            return S.substr(i, n - i);
        }
    }
}