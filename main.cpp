#include <iostream>
#include <random>
#include <ctime>
using namespace std;
class Game
{
private:
    string player1;
    static int player1Score, player2Score;

public:
    Game() {}
    Game(string player1);
    void startPlaying();
    void roundResult(int choice1, int choice2);
    void gameResult(int rounds, int player1Score, int player2Score);
};
int Game::player1Score = 0;
int Game::player2Score = 0;
int main()
{
    string player1;
    cout << " - ROCK PAPER SCISSORS - " << endl;
    cout << " ----------------------- " << endl;
    cout << " Enter your name : " << endl;
    getline(cin, player1);
    cout << " ----------------------- " << endl;
    cout << " " << player1 << " vs Bot " << endl;
    cout << " ----------------------- " << endl;
    Game game(player1);
    game.startPlaying();
    return 0;
}
Game::Game(string player1)
{
    this->player1 = player1;
}
void Game::startPlaying()
{
    cout << " ----------------------- " << endl;
    int choice, botChoice, rounds = 0;
    mt19937 rng(static_cast<unsigned int>(std::time(0)));
    uniform_int_distribution<int> dist(1, 3);
    while (true)
    {
        cout << " " << this->player1 << " turn : " << endl;
        cout << " 1. Rock\n 2. Paper\n 3. Scissors\n 4. Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << " You choose Rock" << endl;
        }
        else if (choice == 2)
        {
            cout << " You choose Paper" << endl;
        }
        else
        {
            cout << " You choose Scissors" << endl;
        }
        if (choice == 4)
        {
            gameResult(rounds, player1Score, player2Score);
            exit(0);
            break;
        }
        else
        {
            cout << " Bot turn : " << endl;
            botChoice = dist(rng);
            if (botChoice == 1)
            {
                cout << " Bot choose Rock" << endl;
            }
            else if (botChoice == 2)
            {
                cout << " Bot choose Paper" << endl;
            }
            else
            {
                cout << " Bot choose Scissors" << endl;
            }
        }
        roundResult(choice, botChoice);
        rounds++;
    }
    cout << " ----------------------- " << endl;
}
void Game::roundResult(int choice1, int choice2)
{
    cout << " ----------------------- " << endl;
    if ((choice1 == 1 && choice2 == 3) || (choice1 == 2 && choice2 == 1) || (choice1 == 3 && choice2 == 2))
    {
        player1Score++;
        cout << " " << this->player1 << " wins " << endl;
    }
    else if ((choice1 == 1 && choice2 == 2) || (choice1 == 2 && choice2 == 3) || (choice1 == 3 && choice2 == 1))
    {
        player2Score++;
        cout << " Bot wins " << endl;
    }
    else
    {
        cout << " It's a tie " << endl;
    }
    cout << " ----------------------- " << endl;
}
void Game::gameResult(int rounds, int player1Score, int player2Score)
{
    cout << " ----------------------- " << endl;
    cout << " Game Over " << endl;
    cout << " ----------------------- " << endl;
    cout << " Number of rounds played : " << rounds << endl;
    cout << " " << this->player1 << " score : " << player1Score << endl;
    cout << " Bot score : " << player2Score << endl;
    if (player1Score != 0 && player2Score != 0)
    {
        if (player1Score > player2Score)
        {
            cout << " " << this->player1 << " wins " << endl;
        }
        else if (player1Score < player2Score)
        {
            cout << " Bot wins " << endl;
        }
        else
        {
            cout << " It's a tie " << endl;
        }
    }
    else
    {
    }
    cout << " ----------------------- " << endl;
}
