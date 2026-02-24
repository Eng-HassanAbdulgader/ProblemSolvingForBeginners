#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string Read_string()
{
    string s = "";
    cout << "Please Enter your string : \n";
    // Use std::ws to discard any leading whitespace/newline from the buffer
    getline(cin >> ws, s);
    return s;
}

string Remove_Punctuation(string s1)
{
    string s2 = " ";
    for (int i = 0; i < s1.length(); i++)
    {
        if (!ispunct(s1[i]))
        {
            s2 += s1[i];
        }
    }
    return s2;
}

int main()
{
    string s1 = Read_string();
    cout << "Orginal string : " << s1 << endl;
    cout << "String After remove punctuation : " << Remove_Punctuation(s1);
    cout << "\npress Enter...";
    cin.ignore();
    cin.get();
}