/**
 * @file templates.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template <class T>
class Player
{
public:
    Player();
    Player(T guess);
    T getGuess() const;
    void setGuess(T guess);
    ~Player();
    virtual T reviseGuess(T guess, bool isTooHigh, T TooLow) = 0;
private:
    T guess;
};

template <class T>
Player<T>::Player() : guess(0)
{
    cout << "Player constructor called" << endl;
}

template <class T>
Player<T>::Player(T guess) : guess(guess)
{
    cout << "Player constructor called" << endl;
}

template <class T>
T Player<T>::getGuess() const
{
    return guess;
}

template <class T>
void Player<T>::setGuess(T guess)
{
    this->guess = guess;
}

template <class T>
Player<T>::~Player()
{
    cout << "Player destructor called" << endl;
}

template <class T>
class HumanPlayer : public Player<T>
{
public:
    HumanPlayer();
    HumanPlayer(T guess);
    T getGuess() const;
    void setGuess(T guess);
    T reviseGuess(T guess, bool isTooHigh, T TooLow);
};

template <class T>
HumanPlayer<T>::HumanPlayer() : Player<T>()
{
    cout << "HumanPlayer constructor called" << endl;
}

template <class T>
HumanPlayer<T>::HumanPlayer(T guess) : Player<T>(guess)
{
    cout << "HumanPlayer constructor called" << endl;
}

template <class T>
T HumanPlayer<T>::getGuess() const
{
    return Player<T>::getGuess();
}

template <class T>
void HumanPlayer<T>::setGuess(T guess)
{
    Player<T>::setGuess(guess);
}

template <class T>
T HumanPlayer<T>::reviseGuess(T guess, bool isTooHigh, T TooLow)
{
    if (isTooHigh)
    {
        cout << "Too high, try again: ";
        cin >> guess;
    }
    else
    {
        cout << "Too low, try again: ";
        cin >> guess;
    }
    return guess;
}

template <class T>
class ComputerPlayer : public Player<T>
{
public:
    ComputerPlayer();
    ComputerPlayer(T guess);
    T getGuess() const;
    void setGuess(T guess);
    T reviseGuess(T guess, bool isTooHigh, T TooLow);
};

template <class T>
ComputerPlayer<T>::ComputerPlayer() : Player<T>()
{
    cout << "ComputerPlayer constructor called" << endl;
}

template <class T>
ComputerPlayer<T>::ComputerPlayer(T guess) : Player<T>(guess)
{
    cout << "ComputerPlayer constructor called" << endl;
}

template <class T>
T ComputerPlayer<T>::getGuess() const
{
    return Player<T>::getGuess();
}

template <class T>
void ComputerPlayer<T>::setGuess(T guess)
{
    Player<T>::setGuess(guess);
}

template <class T>
T ComputerPlayer<T>::reviseGuess(T guess, bool isTooHigh, T TooLow)
{
    if (isTooHigh)
    {
        guess = rand() % TooLow;
    }
    else
    {
        guess = rand() % TooLow + TooLow;
    }
    return guess;
}

template <class T>
class Game
{
public:
    Game();
    Game(T secretNumber, T maxGuesses);
    void play();
    ~Game();
private:
    T secretNumber;
    T maxGuesses;
};

template <class T>
Game<T>::Game() : secretNumber(0), maxGuesses(0)
{
    cout << "Game constructor called" << endl;
}

template <class T>
Game<T>::Game(T secretNumber, T maxGuesses) : secretNumber(secretNumber), maxGuesses(maxGuesses)
{
    cout << "Game constructor called" << endl;
}

template <class T>
void Game<T>::play()
{
    T guess;
    bool isWon = false;
    bool isTooHigh = false;
    T TooLow = 0;
    T TooHigh = 0;
    T guesses = 0;
    HumanPlayer<T> humanPlayer;
    ComputerPlayer<T> computerPlayer;
    cout << "Enter your secret number: ";
    cin >> secretNumber;
    cout << "Enter the maximum number of guesses allowed: ";
    cin >> maxGuesses;
    while (!isWon && guesses < maxGuesses)
    {
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess == secretNumber)
        {
            isWon = true;
            cout << "You won!" << endl;
        }
        else if (guess > secretNumber)
        {
            isTooHigh = true;
            TooHigh = guess;
            guess = humanPlayer.reviseGuess(guess, isTooHigh, TooLow);
            guesses++;
        }
        else
        {
            isTooHigh = false;
            TooLow = guess;
            guess = humanPlayer.reviseGuess(guess, isTooHigh, TooLow);
            guesses++;
        }
        if (guess == secretNumber)
        {
            isWon = true;
            cout << "You won!" << endl;
        }
        else if (guess > secretNumber)
        {
            isTooHigh = true;
            TooHigh = guess;
            guess = computerPlayer.reviseGuess(guess, isTooHigh, TooLow);
            guesses++;
        }
        else
        {
            isTooHigh = false;
            TooLow = guess;
            guess = computerPlayer.reviseGuess(guess, isTooHigh, TooLow);
            guesses++;
        }
    }
    if (!isWon)
    {
        cout << "You lost!" << endl;
    }
}

template <class T>
Game<T>::~Game()
{
    cout << "Game destructor called" << endl;
}

template <class T>
void swapValues(T& variable1, T& variable2)
{
    T temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

template <class T>
void sort(T array[], int size)
{
    int minIndex;
    int minIndex2;
    for (minIndex = 0; minIndex < size - 1; minIndex++)
    {
        for (minIndex2 = minIndex + 1; minIndex2 < size; minIndex2++)
        {
            if (array[minIndex2] < array[minIndex])
            {
                swapValues(array[minIndex2], array[minIndex]);
            }
        }
    }
}

template <class T>
void printArray(T array[], int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << array[index] << " ";
    }
    cout << endl;
}

template <class T>
T* returnMaximum(T array[], int size)
{
    T maximum = array[0];
    for (int index = 1; index < size; index++)
    {
        if (array[index] > maximum)
        {
            maximum = array[index];
        }
    }
    return maximum;
}

template <class T>
T* returnMinimum(T array[], int size)
{
    T minimum = array[0];
    for (int index = 1; index < size; index++)
    {
        if (array[index] < minimum)
        {
            minimum = array[index];
        }
    }
    return minimum;
}

template <class T>
T* returnAbsoluteValue(T num)
{
    if (num < 0)
    {
        num = num * -1;
    }
    return num;
}
/**
 * @brief
 *
 * @return
 */

int main()
{
    Game<int> game;
    game.play();
    return 0;
}

/**
 * @brief The Template <T> class is characterized by
 * the ability to use the same code for multiple data types.
 */
