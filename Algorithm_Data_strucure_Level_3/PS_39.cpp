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
string Join_String(vector<string> vstring, string Delim)
{
    string joinstr = " ";
    for (string sword : vstring)
    {
        joinstr = joinstr + sword + Delim;
    }
    return joinstr.substr(0, joinstr.length() - Delim.length());
}
int main()
{

    vector<string> vstring;
    vstring = split_words_in_string(Read_string());
    cout << "Tokens " << vstring.size() << endl;
    for (string sword : vstring)
    {
        cout << sword << endl;
    }

    cout << "joined String : " << Join_String(vstring, "###");
    system("pause>0");
}