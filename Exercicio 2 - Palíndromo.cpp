#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;

int main(int argc, char **argv)
{
    string msg = "";
    string msg2 = "";

    cout << "Digite alguma frase: ";

    cin >> msg;

    for (string::iterator it = msg.end() - 1; it >= msg.begin(); --it)
    {
        msg2 += *it;
    }

    if (msg.compare(msg2) == 0)
    {
        cout << "Palindromo";
    }
    else
    {
        cout << "Nao E palindromo";
    }

    cout << endl;
}