/**
 * @file guessGame.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

class Player
{
public:
    Player();
    Player(int guess);
    int getGuess() const;
    void setGuess(int guess);
    ~Player();
    virtual int reviseGuess(int guess, bool isTooHigh, int TooLow) = 0;
private:
    int guess;
};

Player::Player() : guess(0)
{
    cout << "Player constructor called" << endl;
}

Player::Player(int guess) : guess(guess)
{
    cout << "Player constructor called" << endl;
}

int Player::getGuess() const
{
    return guess;
}

void Player::setGuess(int guess)
{
    this->guess = guess;
}

Player::~Player()
{
    cout << "Player destructor called" << endl;
}

class HumanPlayer : public Player
{
public:
    HumanPlayer();
    HumanPlayer(int guess);
    int getGuess() const;
    void setGuess(int guess);
    ~HumanPlayer();
    int reviseGuess(int guess, bool isTooHigh, int TooLow);
};

HumanPlayer::HumanPlayer() : Player()
{
    cout << "HumanPlayer constructor called" << endl;
}

HumanPlayer::HumanPlayer(int guess) : Player(guess)
{
    cout << "HumanPlayer constructor called" << endl;
}

int HumanPlayer::getGuess() const
{
    return Player::getGuess();
}

void HumanPlayer::setGuess(int guess)
{
    Player::setGuess(guess);
}

HumanPlayer::~HumanPlayer()
{
    cout << "HumanPlayer destructor called" << endl;
}

int HumanPlayer::reviseGuess(int guess, bool isTooHigh, int TooLow)
{
    int newGuess;
    cout << "Your guess is too " << (isTooHigh ? "high" : "low") << endl;
    cout << "Enter a new guess between " << TooLow << " and " << guess << ": ";
    cin >> newGuess;
    return newGuess;
}

class ComputerPlayer : public Player
{
public:
    ComputerPlayer();
    ComputerPlayer(int guess);
    int getGuess() const;
    void setGuess(int guess);
    ~ComputerPlayer();
    int reviseGuess(int guess, bool isTooHigh, int TooLow);
};

ComputerPlayer::ComputerPlayer() : Player()
{
    cout << "ComputerPlayer constructor called" << endl;
}

ComputerPlayer::ComputerPlayer(int guess) : Player(guess)
{
    cout << "ComputerPlayer constructor called" << endl;
}

int ComputerPlayer::getGuess() const
{
    return Player::getGuess();
}

void ComputerPlayer::setGuess(int guess)
{
    Player::setGuess(guess);
}

ComputerPlayer::~ComputerPlayer()
{
    cout << "ComputerPlayer destructor called" << endl;
}

int ComputerPlayer::reviseGuess(int guess, bool isTooHigh, int TooLow)
{
    if (isTooHigh)
    {
        return rand() % guess + 1;
    }
    else
    {
        return rand() % (100 - guess) + guess + 1;
    }
}

class Game
{
public:
    Game();
    void play();
    ~Game();
private:
    int secretNumber;
    Player* players[2];
};

Game::Game() : secretNumber(0)
{
    cout << "Game constructor called" << endl;
    srand(time(NULL));
    secretNumber = rand() % 100 + 1;
    players[0] = new HumanPlayer;
    players[1] = new ComputerPlayer;
}

bool checkForWin(int guess,int  number)
{
    if (guess == number)
    {
        cout << "You win!" << endl;
        return true;
    }
    else if (guess < number)
    {
        cout << "Your guess is too low" << endl;
        return false;
    }
    else
    {
        cout << "Your guess is too high" << endl;
        return false;
    }
}

void play(Player &player1, Player &player2)
{
    int guess;
    int currentPlayer = 0;
    do
    {
        cout << "Player " << currentPlayer + 1 << " turn" << endl;
        cout << "Enter a guess between 1 and 100: ";
        cin >> guess;
        if (currentPlayer == 0)
        {
            player1.setGuess(guess);
            checkForWin(player1.getGuess(), player2.getGuess());
        }
        else
        {
            player2.setGuess(guess);
            checkForWin(player2.getGuess(), player1.getGuess());
        }
        currentPlayer = (currentPlayer + 1) % 2;
    } while (true);
}

void Game::play()
{
    int guess;
    int currentPlayer = 0;
    do
    {
        cout << "Player " << currentPlayer + 1 << " turn" << endl;
        cout << "Enter a guess between 1 and 100: ";
        cin >> guess;
        if (currentPlayer == 0)
        {
            players[0]->setGuess(guess);
            checkForWin(players[0]->getGuess(), players[1]->getGuess());
            //revise guess
            players[1]->setGuess(players[1]->reviseGuess(players[1]->getGuess(), players[1]->getGuess() > secretNumber, players[1]->getGuess() < secretNumber));
        }
        else
        {
            players[1]->setGuess(guess);
            checkForWin(players[1]->getGuess(), players[0]->getGuess());
        }
        currentPlayer = (currentPlayer + 1) % 2;
    } while (players[currentPlayer]->getGuess() != secretNumber);
}

Game::~Game()
{
    cout << "Game destructor called" << endl;
    delete players[0];
    delete players[1];
}

int main()
{
    Game game;
    game.play();
    return 0;
}
