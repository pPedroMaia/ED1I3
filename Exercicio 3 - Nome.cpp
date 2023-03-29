#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");

    string linha;
    string nome;
    string primeiroNome;
    string segundoNome;
    int totalNome = 0;
    ifstream arq("lista.txt");

    if (arq.is_open())
    {
        while (!arq.eof())
        {
            getline(arq, linha);
            totalNome = linha.size();
            primeiroNome = linha;
            segundoNome = linha;

            nome = segundoNome.erase(0, totalNome - 4);

            cout << nome << ", " << primeiroNome.erase(5, totalNome) << endl;
        }
        arq.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }

    return 0;
}