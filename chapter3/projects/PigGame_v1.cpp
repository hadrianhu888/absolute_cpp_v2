/**
 * @file PigGame_v1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) 2022
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
#include <windows.h> 

using namespace std; 

const int maxComputerPoints = 20;
const int maxPoints = 1e2;
const int SleepTime = 1e3; 
int humanTotalScore = 0; 
int computerTotalScore = 0; 
int randomNumber = ((rand() % 6) + 1); 
int tempHumanScore = 0; 
int tempComputerScore = 0; 
int countHumanTurns = 0; 
int countComputerTurns = 0; 
int totalHumanScore = 0; 
int totalComputerScore = 0;
int totalHumanTurns = 0; 
int totalComputerTurns = 0; 
char playerStatus = '0'; 

typedef enum HOLD_OR_ROLL
{
    HOLD = 0,
    ROLL = 1
}; 

typedef enum DICE
{
    ONE = 0,
    TWO = 2,
    THREE = 3,
    FOUR = 4, 
    FIVE = 5, 
    SIX = 6
}; 

void PigGame(void);
void displayDiceRollValue(int x);
int main(int argc, char ** argv); 
int rollDice(void); 
int humanTurn(int humanTotalScore); 
int computerTurn(int computerTotalScore); 
int getRollOrHold (void);
int getTurnsCount(int x); 
int incrementTurnsCount(int x);
int setTurnsCount(int x);
void displayScore(int x);

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main (int argc, char ** argv)
{
    PigGame();
    return 0;
}
/**
 * @brief 
 * 
 * @return int 
 */
int rollDice(void)
{
    Sleep(SleepTime);
    srand(time(NULL));
    randomNumber = rand() % 6 + 1;
    return randomNumber; 
}
/**
 * @brief 
 * 
 * @param humanTotalScore 
 * @return int 
 */
int humanTurn(int humanTotalScore)
{   
    cout << "Human Turn: " << "\t";
    if (getRollOrHold() == 1)
    {
        tempHumanScore = rollDice(); 
        displayDiceRollValue(tempHumanScore);
        if (tempHumanScore == 1)
        {
            humanTotalScore = ONE + tempHumanScore; 
            totalComputerScore = computerTurn(computerTotalScore);
            return humanTotalScore; 
        }
        switch(tempHumanScore)
        {
            case 2:
            {
                humanTotalScore = TWO + tempHumanScore; 
                return humanTotalScore; 
                break; 
            }
            case 3: 
            {
                humanTotalScore = THREE + tempHumanScore; 
                return humanTotalScore; 
                break; 
            }
            case 4: 
            {
                humanTotalScore = FOUR + tempHumanScore; 
                return humanTotalScore; 
                break; 
            }
            case 5: 
            {
                humanTotalScore = FIVE + tempHumanScore; 
                return humanTotalScore; 
                break; 
            }
            case 6: 
            {
                humanTotalScore = SIX + tempHumanScore; 
                return humanTotalScore; 
                break; 
            }
            default: 
            {
                return 0; 
                break; 
            }
        }
        totalHumanScore = humanTurn(humanTotalScore);   
        totalHumanTurns = setTurnsCount(countHumanTurns); 
        totalHumanTurns = incrementTurnsCount(countHumanTurns);      
    }
    else if (getRollOrHold() == 0)
    {     
        totalHumanTurns = setTurnsCount(countHumanTurns); 
        totalHumanTurns = getTurnsCount(countHumanTurns);  
        totalComputerTurns = computerTurn(computerTotalScore);
        return humanTotalScore; 
    }
    else 
    {
        /**
         * @brief empty 
         * 
         */
        totalComputerScore = computerTurn(computerTotalScore);
        return totalComputerScore; 
    }    
    displayScore(totalHumanScore); 
    return totalHumanScore; 
}
/**
 * @brief 
 * 
 * @param computerTotalScore 
 * @return int 
 */
int computerTurn(int computerTotalScore)
{   
    cout << "Computer Turn: " << "\t";
    if ((getRollOrHold() == 1 )&& (totalComputerScore <= maxComputerPoints))
    {
        tempComputerScore = rollDice(); 
        displayDiceRollValue(tempComputerScore);
        if (tempComputerScore == 1)
        {
            computerTotalScore = ONE + tempComputerScore; 
            totalHumanScore = humanTurn(humanTotalScore);
            return computerTotalScore; 
        }
        switch(tempComputerScore)
        {
            case 2:
            {
                computerTotalScore = TWO + tempComputerScore; 
                return computerTotalScore; 
                break; 
            }
            case 3: 
            {
                computerTotalScore = THREE + tempComputerScore; 
                return computerTotalScore; 
                break; 
            }
            case 4: 
            {
                computerTotalScore = FOUR + tempComputerScore; 
                return computerTotalScore; 
                break; 
            }
            case 5: 
            {
                computerTotalScore = FIVE + tempComputerScore; 
                return computerTotalScore; 
                break; 
            }
            case 6: 
            {
                computerTotalScore = SIX + tempComputerScore; 
                return computerTotalScore; 
                break; 
            }
            default: 
            {
                return 0; 
                break; 
            }
        }
        totalComputerScore = computerTurn(computerTotalScore);
        totalComputerTurns = setTurnsCount(countComputerTurns); 
        totalComputerTurns = incrementTurnsCount(countComputerTurns);     
        return totalComputerScore; 
    }
    else if (getRollOrHold() == 0)
    {
        computerTotalScore = tempComputerScore; 
        totalComputerTurns = setTurnsCount(countComputerTurns); 
        totalComputerTurns = getTurnsCount(countComputerTurns);  
        totalHumanScore = humanTurn(humanTotalScore);
        return computerTotalScore; 
    }
    else 
    {
        /**
         * @brief empty 
         * 
         */
        totalHumanScore = humanTurn(humanTotalScore);
        return totalHumanScore; 
    }   
    displayScore(totalComputerScore); 
    return totalComputerScore;
}
/**
 * @brief Get the Roll Or Hold object
 * 
 * @return int 
 */
int getRollOrHold (void)
{
    cout << "Hold or Roll? "; 
    cin >> playerStatus; 
    if (playerStatus == 'h' || playerStatus == 'H')
    {
        return HOLD; 
    }
    else if (playerStatus == 'r' || playerStatus == 'R')
    {
        return ROLL;         
    }
    else 
    {
        return 0; 
    }
}
/**
 * @brief 
 * 
 * @param human 
 * @param computer 
 */
void returnWinner(int human, int computer)
{
    if (human > computer)
    {
        cout << "The human won with total " << human << " points." << endl; 
    }
    else if (computer > human)
    {
        cout << "The computer won with total " << computer << " points." << endl; 
    }
    else 
    {
        /**
         * @brief empty 
         * 
         */
    }
}
/**
 * @brief 
 * 
 */
void PigGame(void)
{
    while ((humanTotalScore <= maxPoints) || (computerTotalScore <= maxPoints))
    {
        /**
         * @brief human go first, 
         * followed by computer, which is required to accumulate 
         * twenty points or relegate to the player 
         * 
         */
        totalHumanScore = humanTurn(humanTotalScore); 
        if (totalComputerScore >= maxComputerPoints)
        {
            totalHumanScore =humanTurn(humanTotalScore); 
        }
    }
    returnWinner(humanTotalScore, computerTotalScore);    
}
/**
 * @brief Get the Turns Count object
 * 
 * @param x 
 * @return int 
 */
int getTurnsCount(int x)
{
    int y = 0; 
    y = x; 
    return y; 
}
/**
 * @brief 
 * 
 * @param x 
 * @return int 
 */
int incrementTurnsCount(int x)
{
    x = x + 1; 
    return x; 
}
/**
 * @brief Set the Turns Count object
 * 
 * @param x 
 * @return int 
 */
int setTurnsCount(int x)
{
    return x; 
}
/**
 * @brief 
 * 
 * @param x 
 */
void displayDiceRollValue(int x)
{
    cout << endl << "Dice Roll Value: " << x << endl; 
}
/**
 * @brief 
 * 
 * @param x 
 */
void displayScore(int x)
{
    cout << endl << "Score: " << x << endl; 
}
