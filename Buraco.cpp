#include <iostream>
using namespace std;

string naipe[4] = {"1", "2", "3", "4"};
string numero[13] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13"};
string playersCards[4][11];
string deck[2][4][13];

void setDeck()
{
    int count = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 13; k++)
            {
                deck[i][j][k] = naipe[j] + "-" + numero[k] + "-" + to_string(i + 1);
            }
        }
    }
}

void shuflleDeckToPlayers()
{
    srand(time(NULL));

    string shouldIgnoreSequence[44];

    int count = 0;
    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k < 11; k++)
        {
            int num1 = rand() % 2;  
            int num2 = rand() % 4;  
            int num3 = rand() % 13; 

            bool found = false;
            string currentData = to_string(num1) + "-" + to_string(num2) + "-" + to_string(num3);

            for (int i = 0; i < 44; i++)
            {
                if (currentData == shouldIgnoreSequence[i])
                {
                    found = true;
                    break;
                }
            }

            while (found)
            {
                num1 = rand() % 2;
                num2 = rand() % 4;
                num3 = rand() % 13;

                currentData = to_string(num1) + "-" + to_string(num2) + "-" + to_string(num3);

                for (int i = 0; i < 44; i++)
                {
                    if (currentData == shouldIgnoreSequence[i])
                    {
                        found = true;
                        break;
                    }
                    else
                    {
                        found = false;
                    }
                }
            }

            if (!found)
            {
                shouldIgnoreSequence[count] = currentData;
            }

            count++;
            playersCards[j][k] = deck[num1][num2][num3];
        }
    }
}

void showPlayersCards()
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Player " << i + 1 << endl;
        for (int j = 0; j < 11; j++)
        {
            cout << playersCards[i][j] << endl;
        }
        cout << endl;
    }
}

int main()
{
    setDeck();
    shuflleDeckToPlayers();
    showPlayersCards();
    return 0;
}