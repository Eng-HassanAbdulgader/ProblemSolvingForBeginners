#include <iostream>
#include <vector>
#include <string>
using namespace std;

string Read_string()
{
    string s = "";
    cout << "Please Enter your string : \n";
    getline(cin, s);
    return s;
}

vector<string> split_words_in_string(string s)
{

    vector<string> svector;
    string delim = " ";
    short pos = 0;
    string word = " ";

    while ((pos = s.find(delim)) != std::string::npos)
    {
        word = s.substr(0, pos);
        if (word != " ")
        {
            svector.push_back(word);
        }
        s.erase(0, pos + delim.length());
    }
    if (s != " ")
    {
        svector.push_back(s);
    }
    return svector;
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
string reverse_string(vector<string> v)
{
    string reversed_string = "";
    vector<string>::iterator iter = v.end();
    while (iter != v.begin())
    {
        --iter;
        reversed_string += *iter + " ";
    }
    return Trime_right(reversed_string);
}

int main()
{
    string S1 = Read_string();
    vector<string> vstring = split_words_in_string(S1);
    cout << " orginal string is : " << S1 << endl;
    cout << " reversed string is : " << reverse_string(vstring) << endl;

    system("pause>0");
}