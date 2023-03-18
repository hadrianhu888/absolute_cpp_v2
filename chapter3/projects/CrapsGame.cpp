/**
 * @file singleCrapsGame.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-23
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
#include <windows.h>

using namespace std; 

int DiceOne = 0; 
int DiceTwo = 0; 
int Sum = 0; 
int winning = 0; 
int losing = 0;
int winCount = 0;
int lostCount = 0; 
int j = 0; 
const int maxGames = 10000; 
int sleepTimer = 500; 
int WinTotal = 0; 
int LostTotal = 0;
int totalGames = 0;
bool win = true; 
bool innerWin = true; 
float win2loseRatio = 0.0;
const float PercentileValue = 100.0; 

void game(int i);
void printValue(int x);
void printStatement(bool x);
void innerGame (void);
void checkConditionForInnerGame (int Sum);
int main (int argc, char ** argv); 
int getRandomRoll_1(void);
int getRandomRoll_2(void);
int getSum(int x, int y);
int getWins(bool x); 
int getLoses(bool x);
int setWins(int x);
int setLoses(int x);
int getTotalGames(int x, int y);
bool winLoseCases(int x); 
bool checkSecondRollScore (int x);
float getWinLoseRatio(int x, int y);

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main (int argc, char ** argv) 
{
    cout << "#\tD1\tD2\tSum\tStatus\t\tWins\tLosses" << endl;
    for (int j = 0; j < maxGames; j++)
    {
        game(j);
        Sleep(sleepTimer);
    }
    WinTotal = setWins(winCount); 
    LostTotal = setLoses(lostCount);
    cout << "Wins:\t"; 
    printValue(WinTotal); 
    cout << "\tLosses:\t";
    printValue(LostTotal); 
    totalGames = getTotalGames(WinTotal, LostTotal); 
    win2loseRatio = getWinLoseRatio(WinTotal,LostTotal);
    cout << endl << "Win Percentage: " << win2loseRatio << " %\n" << endl; 
    return 0;
}
/**
 * @brief Get the Random Roll object
 * 
 * @return int 
 */
int getRandomRoll_1(void)
{
    srand((time(NULL) * 3) % (time(NULL))); 
    return (rand() % 6 + 1);
}
int getRandomRoll_2(void)
{
    srand(time(NULL) * time(NULL)); 
    return (rand() % 6 + 1);
}
/**
 * @brief Get the Sum object
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int getSum(int x, int y)
{
    return (x + y); 
}
/**
 * @brief 
 * 
 * @param x 
 * @return true 
 * @return false 
 */
bool checkSecondRollScore (int x)
{
    switch (x)
    {
        case 4:
        case 5: 
        case 6: 
        case 7: 
        case 8: 
        case 9: 
        case 10: 
        {
            return true; 
            break; 
        }
        case 2: 
        case 3: 
        case 11: 
        case 12: 
        default: 
        {
            return false; 
            break;
        }
    }
}
void innerGame (void)
{
    Sleep(sleepTimer);
    DiceOne = getRandomRoll_1(); 
    printValue(DiceOne); 
    Sleep(sleepTimer);
    DiceTwo = getRandomRoll_2(); 
    printValue(DiceTwo); 
    Sum = getSum(DiceOne, DiceTwo);
    printValue(Sum);
    innerWin = winLoseCases(Sum); 
    printStatement(win);
    innerWin = checkSecondRollScore(win);
    winCount = getWins(innerWin); 
    lostCount = getLoses(innerWin);
    printValue(winCount); 
    printValue(lostCount); 
    cout << endl;
}
bool winLoseCases(int x)
{
    switch(x)
    {
        case 4:
        case 5: 
        case 6: 
        case 7: 
        case 8: 
        case 9: 
        case 10: 
        case 11: 
        {
            return true; 
            break; 
        }
        case 2: 
        case 3: 
        case 12: 
        default: 
        {
            return false; 
            break;
        }
    }
}
/**
 * @brief 
 * 
 * @param x 
 */
void printValue(int x)
{
    cout << x << "\t";
}
/**
 * @brief 
 * 
 * @param x CCCC©©©©©©
 */
void printStatement(bool x)
{
    if (x == true)
    {
        cout << "You won!" << "\t" ; 
    }
    else 
    {
        cout << "You lost!" << "\t" ;
    }
}
/**
 * @brief Get the Wins object
 * 
 * @param x 
 * @return int 
 */
int getWins(bool x)
{
    if (x == true)
    {
        winning = winning + 1; 
    }
    else 
    {
        winning = winning; 
    }
    return winning; 
}
/**
 * @brief Get the Loses object
 * 
 * @param x 
 * @return int 
 */
int getLoses(bool x)
{
    if (x == false)
    {
        losing = losing + 1; 
    }
    else 
    {
        losing = losing; 
    }
    return losing; 
}
void game(int i)
{
    DiceOne = getRandomRoll_1(); 
    cout << i+1 << "\t";
    printValue(DiceOne); 
    Sleep(sleepTimer);
    DiceTwo = getRandomRoll_2(); 
    printValue(DiceTwo); 
    Sum = getSum(DiceOne, DiceTwo);
    printValue(Sum);
    checkConditionForInnerGame(Sum);
    win = winLoseCases(Sum); 
    printStatement(win);
    winCount = getWins(win); 
    lostCount = getLoses(win);
    printValue(winCount); 
    printValue(lostCount); 
    cout << endl;
}
/**
 * @brief Set the Wins object
 * 
 * @param x 
 * @return int 
 */
int setWins(int x)
{
    return x;
}
/**
 * @brief Set the Loses object
 * 
 * @param x 
 * @return int 
 */
int setLoses(int x)
{
    return x;
}
/**
 * @brief Get the Total Games object
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int getTotalGames(int x, int y)
{
    return (x + y); 
}
/**
 * @brief Get the Win Lose Ratio object
 * 
 * @param x 
 * @param y 
 * @return float 
 */
float getWinLoseRatio(int x, int y)
{
    int totalGames = getTotalGames(x,y);
    return float((float(x)/totalGames) * PercentileValue);
}
void checkConditionForInnerGame (int Sum)
{
    bool innerGameCondition = true; 
    innerGameCondition = checkSecondRollScore(Sum); 
    if (innerGameCondition == true)
    {
        innerGame(); 
    }
    else
    {
        /** nothing happens here **/ 
    }
}

