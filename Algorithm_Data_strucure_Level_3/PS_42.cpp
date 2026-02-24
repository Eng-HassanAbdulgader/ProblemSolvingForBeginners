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

void replace_word_in_string(string &S1, string reword, string word)
{
    /*vector<string>::iterator iter = v.end();
     while (iter != v.begin())
     {
         --iter;
         if (*iter == erword)
             *iter = reword;
     }*/
    short pos = S1.find(reword);
    while (pos != std::string::npos)
    {
        S1.replace(pos, reword.length(), word);
        pos = S1.find(reword);
    }
}

int main()
{
    string S1 = Read_string();
    //  vector<string> vstring = split_words_in_string(S1);
    cout << " orginal string is : " << S1 << endl;
    replace_word_in_string(S1, "USA", "kassala");
    cout << " string after replace  : " << S1;
    /*for (string word : vstring)
    {
        cout << word << " ";
    }*/

    system("pause>0");
}