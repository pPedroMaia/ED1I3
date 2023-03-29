#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;

void gotoxy(short x, short y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(int argc, char **argv)
{
    string frase = "";
    int aux = 10;
    cout << "Digite alguma frase: ";
    cin >> frase;

    gotoxy(10, 10);
    cout << frase << endl;

    for (string::iterator it = frase.begin(); it < frase.end(); ++it)
    {
        ++aux;
        gotoxy(11, aux);
        cout << *it << " ";
    }

    cout << endl;
}