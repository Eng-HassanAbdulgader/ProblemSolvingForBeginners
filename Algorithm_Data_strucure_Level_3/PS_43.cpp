#include <iostream>
#include <vector>
#include <string>
#include <cctype>    // Required for tolower

using namespace std;

string Read_string()
{
    string s = "";
    cout << "Please Enter your string : \n";
    // Use std::ws to discard any leading whitespace/newline from the buffer
    getline(cin >> ws, s);
    return s;
}

vector<string> split_string(string S1)
{
    vector<string> myvector;
    int pos = 0;
    // CORRECTED: Delimiter MUST be a space (" ") to split words.
    string word = "", delim = " ";

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        word = S1.substr(0, pos);
        if (!word.empty()) // Check for empty string (handles multiple spaces)
        {
            myvector.push_back(word);
        }
        S1.erase(0, pos + delim.length());
    }

    // Add the remaining part (the last word)
    if (!S1.empty())
    {
        myvector.push_back(S1);
    }
    return myvector;
}

string lowerAllString(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}
string JoinString(vector<string> vString, string Delim)
{
    string S1;
    for (string &s : vString)
    {
        S1 = S1 + s + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());
}

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string ReplaceTo, bool match)
{
    vector<string> stringVector = split_string(S1);

    // Pre-calculate the lowercased search word for efficiency
    string lowerSearchWord = lowerAllString(StringToReplace);

    for (string &s : stringVector)
    {
        if (match) // Case-Sensitive Match
        {
            if (s == StringToReplace)
            {
                s = ReplaceTo;
            }
        }
        else // Case-Insensitive Match
        {
            // CORRECTED: Compare the current word (s) against the word to SEARCH FOR (StringToReplace).
            if (lowerAllString(s) == lowerSearchWord)
            {
                s = ReplaceTo;
            }
        }
    }

    return JoinString(stringVector, " ");
}

int main()
{
    string s1 = Read_string();

    string stringToReplace = "";
    cout << "\nEnter string To Replace : " << endl;
    // CORRECTED: Use getline with ws to safely read the word to replace
    getline(cin >> ws, stringToReplace);

    string ReplaceTo = "";
    cout << "Enter string Replace  To: " << endl;
    // CORRECTED: Use getline with ws to safely read the replacement word
    getline(cin >> ws, ReplaceTo);

    cout << "\n\nOrginal string: " << s1;

    cout << "\n\nRepalce With Match case (Case-Sensitive): \n"
         << ReplaceWordInStringUsingSplit(s1, stringToReplace, ReplaceTo, true);

    cout << "\n\nRepalce With Not Match case (Case-Insensitive): \n"
         << ReplaceWordInStringUsingSplit(s1, stringToReplace, ReplaceTo, false);

    // More portable way to pause the console than system("pause>0")
    cout << "\n\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}