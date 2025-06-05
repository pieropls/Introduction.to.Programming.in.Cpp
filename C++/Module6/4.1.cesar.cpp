#include <iostream>
#include <string>
using namespace std;

char decale(char c, char debut, int decalage);
char code(char c, int d);
string code(string chaine, int d);
string decode(string message_to_decode, int d);

int main()
{
    string message_to_decode("Ezid-zsyw zy qiw 3 glexw ix qiw 2 glmirw ?");
    cout << decode(message_to_decode, 4);

    return 0;
}

char decale(char c, char debut, int decalage)
{
    while(decalage < 0){
        decalage += 26;
    }
    return debut + (((c - debut) + decalage) % 26);
}

char code(char c, int d)
{
    if(c >= 'a' and c <= 'z'){
        return decale(c,'a',d);
    }
    else if(c >= 'A' and c <= 'Z'){
        return decale(c,'A',d);
    }
    return c;
}

string code(string message_to_code, int d)
{
    string message_coded;
    for (auto c : message_to_code){
        message_coded += code(c,d);
    }
    return message_coded;
}

string decode(string message_to_decode, int d)
{
    return code(message_to_decode, -d);
}