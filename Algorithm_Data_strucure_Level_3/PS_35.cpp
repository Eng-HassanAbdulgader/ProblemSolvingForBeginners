#include <iostream>
#include <string>
using namespace std;

string Read_string()
{
    string s = "";
    cout << "Please Enter your string : \n";
    getline(cin, s);
    return s;
}

void print_words_from_string(string s)
{
    string delim = " ";
    short pos = 0;
    string word = " ";
    cout << "words in string are  : ";

    while ((pos = s.find(delim)) != std::string::npos)
    {
        word = s.substr(0, pos);
        if (word != " ")
        {
            cout << word << endl;
        }
        s.erase(0, pos + delim.length());
    }
    if (s != " ")
    {
        cout << s;
    }
}

int main()
{

    string s = Read_string();
    print_words_from_string(s);

    system("pause>0");
}