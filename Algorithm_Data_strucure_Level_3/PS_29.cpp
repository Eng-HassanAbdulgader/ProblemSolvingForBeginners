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

enum enWhatToCount
{
    SmallLetters = 0,
    CapitalLettere = 1,
    All = 3

};

short Count_letters(string &s, enWhatToCount WhatToCount = enWhatToCount::All)
{
    if (WhatToCount == enWhatToCount::A#include <iostream>
#include <string>
using namespace std;

string Read_string()
{
    string s = "";
    cout << "Please Enter your string : \n";
    getline(cin, s);
    return s;
}

enum enWhatToCount
{
    SmallLetters = 0,
    CapitalLettere = 1,
    All = 3

};

short Count_letters(string &s, enWhatToCount WhatToCount = enWhatToCount::All)
{
    if (WhatToCount == enWhatToCount::All)
    {
        return s.length();
    }
    short count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLettere && isupper(s[i]))
        {
            count++;
        }
        else if (WhatToCount == enWhatToCount::SmallLetters && islower(s[i]))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string s = Read_string();
    cout << "Count Length : " << Count_letters(s) << '\n';
    cout << "Count Capital letters : " << Count_letters(s, enWhatToCount::CapitalLettere) << '\n';
    cout << "Count Small letters : " << Count_letters(s, enWhatToCount::SmallLetters) << endl;
    system("pause>0");
}ll)
    {
        return s.length();
    }
    short count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLettere && isupper(s[i]))
        {
            count++;
        }
        else if (WhatToCount == enWhatToCount::SmallLetters && islower(s[i]))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string s = Read_string();
    cout << "Count Length : " << Count_letters(s) << '\n';
    cout << "Count Capital letters : " << Count_letters(s, enWhatToCount::CapitalLettere) << '\n';
    cout << "Count Small letters : " << Count_letters(s, enWhatToCount::SmallLetters) << endl;
    system("pause>0");
}