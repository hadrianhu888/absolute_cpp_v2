/**
 * @file p8.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cmath>
#include <string> 
#include <cstring>
#include <cctype> 
#include <string> 
#include <ctime> 
#include <time.h> 

using namespace std; 

const int totalGames = 10e3; 
int totalWins = 0; 
int totalLosses = 0; 
int DiceOne = 0; 
int DiceTwo = 0;
int DiceSum = 0;
int diceRolls = 0; 
int firstRollTotal = 0;
bool win = true; 
float winPercentage = 0.0; 
float lossPercentage = 0.0;

int main(int argc, char ** argv); 
int rollDice(void); 
int returnSum(int x, int y); 
int countWins(bool wins); 
int countLosses(int wins); 
int returnDiceRollCount(int i); 
bool checkWinOrLose(int x); 
int resetDiceRolls(int x);
int countDiceRolls(int x);
int resetDiceRolls(void);
void game(int i); 
bool checkComeOutRollValue(int sum);
int setComeOutRoll(int sum);
int comeOutRoll(void);
int getThePoint(int x);

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char ** argv)
{
    int i = 0;
    for (i = 0; i <= totalGames; i = i + 1)
    {
        cout << "Game " << i; 
        cout <<  " " << ", Win or Loss: " << endl; 
    }
    return 0;
}
/**
 * @brief 
 * 
 * @return int 
 */
int rollDice(void)
{
    srand(time(NULL));
    int roll_dice = 0; 
    roll_dice = rand() % 6 + 1; 
    return roll_dice; 
}
/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int returnSum(int x, int y)
{
    int sum = 0; 
    sum = x + y; 
    return sum; 
}
/**
 * @brief 
 * 
 * @param x 
 * @return true 
 * @return false 
 */
bool checkWinOrLose(int x)
{
    if ((x == 7) || (x == 11))
    {
        win = true; 
    } 
    else if ((x == 4) || (x == 5) || (x == 6) || (x == 8) || (x == 9) || (x == 10))
    {
        win = true;
    }
    else if ((x == 2) || (x == 3) || (x == 12))
    {
        win = false; 
    }
    return win; 
}
/**
 * @brief 
 * 
 * @param wins 
 * @return int 
 */
int countWins(bool wins)
{
    int winnings = 0; 
    if (wins == true) 
    {
        winnings = winnings + 1;
    }
    return winnings; 
}
/**
 * @brief 
 * 
 * @param wins 
 * @return int 
 */
int countLoses (bool wins) 
{
    int losses = 0; 
    if (wins == false) 
    {
        losses = losses + 1;
    }
    return losses; 
}
/**
 * @brief 
 * 
 * @param i 
 * @return int 
 */
int returnDiceRollCount(int i) 
{
    i = i + 1; 
    return i;
}
/**
 * @brief 
 * 
 * @param x 
 * @return int 
 */
int countDiceRolls(int x) 
{
    x = x + 1;
    return x;
}
/**
 * @brief 
 * 
 * @param x 
 * @return int 
 */
int resetDiceRolls(void) 
{
    return 0; 
}
/**
 * @brief 
 * 
 * @param i 
 */
void game(int i)
{
    
}
/**
 * @brief 
 * 
 * @return int 
 */
int comeOutRoll(void)
{
    DiceOne = rollDice();
    DiceTwo = rollDice(); 
    firstRollTotal = DiceOne + DiceTwo; 
    return firstRollTotal; 
}
/**
 * @brief Set the Come Out Roll object
 * 
 * @param sum 
 * @return int 
 */
int setComeOutRoll(int sum)
{
    return sum; 
}
/**
 * @brief 
 * 
 * @param sum 
 * @return true 
 * @return false 
 */
bool checkComeOutRollValue(int sum)
{
    bool winOrLose = true; 
    winOrLose = checkWinOrLose(sum);
    return winOrLose; 
}
/**
 * @brief 
 * 
 * @param wins 
 * @param losses 
 * @param totalGames 
 * @return float 
 */
float calculateWinPercentage(int wins, int losses, int totalGames) 
{
    float winPercentage = 0.0; 
    winPercentage = float (wins / totalGames); 
    return winPercentage;
}
/**
 * @brief Get the The Point object
 * 
 * @param x 
 * @return int 
 */
int getThePoint(int x)
{
    int thePoint = 0; 
    if ((x == 4) || (x == 5) || (x == 6) || (x == 8) || (x == 9) || (x == 10))
    {
        thePoint = x; 
    }
    return thePoint; 
}

void continueRolling(void)
{
    DiceOne = rollDice();
    DiceTwo = rollDice(); 
    firstRollTotal = DiceOne + DiceTwo; 
}
