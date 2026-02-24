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

short count_number_of_words_in_string(string s)
{

    string delim = " ";
    short pos = 0, cn = 0;
    string word = " ";

    while ((pos = s.find(delim)) != std::string::npos)
    {
        word = s.substr(0, pos);
        if (word != " ")
        {
            cn++;
        }
        s.erase(0, pos + delim.length());
    }
    if (s != " ")
    {
        cn++;
    }
    return cn;
}

int main()
{

    string s = Read_string();
    cout << "Number Of Words In The String is : " << count_number_of_words_in_string(s);

    system("pause>0");
}