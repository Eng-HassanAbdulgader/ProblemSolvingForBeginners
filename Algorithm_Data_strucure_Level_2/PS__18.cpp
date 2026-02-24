#include <string>
#include <iostream>
using namespace std;

string ReadText(string M)
{
    cout << M;
    string Text;
    getline(cin, Text);
    return Text;
}

string EncryptText(string Text, short EncryptionKey)
{

    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text;
}

string DecryptText(string Text, short EncryptionKey)
{

    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}

int main()
{
    const short EncryptionKey = 2;
    string Text = ReadText("Please Enter Text ? ");
    cout << "Text Before Encrption : " << Text << '\n';
    cout << "Text After Encrption : " << EncryptText(Text, EncryptionKey) << '\n';
    cout << "Text After Decrption : " << DecryptText(EncryptText(Text, EncryptionKey), EncryptionKey);

    return 0;
}