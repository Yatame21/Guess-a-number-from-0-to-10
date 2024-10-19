#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Rand(int x, int y)
{
    return rand() % (y - x + 1) + x;
}

void GameOver(int secretNumber, bool isWin)
{
    cout << (isWin ? "Victory!" : "Defeat!") << endl;
    cout << "The hidden number was: " << secretNumber << endl;
}

void FailedTry(bool isHigher, int& tries)
{
    cout << (isHigher ? "The hidden number is greater" : "The hidden number is smaller.") << endl;
    tries--;
    if (tries > 0)
        cout << "Attempts left:" << tries << endl;
    else
        cout << "The attempts are over!" << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");
    srand(static_cast<unsigned int>(time(0)));

    char playAgain;
    do
    {
        int tries = 3;
        int currentNumber, secretNumber;
        bool isWin = false;

        secretNumber = Rand(0, 10);

        while (tries > 0)
        {
            cout << "Guess a number from 0 to 10:" << endl;
            cin >> currentNumber;

            if (cin.fail()) {
                cout << "Please enter a valid number" << endl;
                cin.clear(); // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore incorrect input
                continue;
            }

            if (currentNumber == secretNumber)
            {
                isWin = true;
                break;
            }
            else if (currentNumber < secretNumber)
            {
                FailedTry(true, tries);
            }
            else
            {
                FailedTry(false, tries);
            }
        }

        GameOver(secretNumber, isWin);

        cout << "Want to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}