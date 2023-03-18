/**
 * @file p10.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-25
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

const int maxComputerPoints = 20;
const int maxPoints = 1e2;
const int SleepTime = 1e3; 
int humanScore = 0; 
int computerScore = 0;
bool HoldOrRoll = true; 

void PigGame(void); 
int main(int argc, char ** argv); 
int getScoreOnRoll(int x); 
int setScoreOnRoll(int x);
int rollDice(void); 
int humanTurn(int humanTotalScore); 
int computerTurn(int computerTotalScore); 
void Delay(void);
int checkLastScore(int x);
bool getHoldOrRoll(int x); 

void PigGame(void)
{
    humanTurn(humanScore);
}
int main(int argc, char ** argv)
{
    PigGame();
    return 0;
}
int getScoreOnRoll(int x)
{
    switch(x)
    {
        case 1: 
        {
            return 0;
        }
        case 2: 
        {
            return 2; 
            break; 
        }
        case 3:
        {
            return 3; 
            break; 
        }
        case 4: 
        {
            return 4; 
            break; 
        }
        case 5: 
        {
            return 5; 
            break; 
        }
        case 6: 
        {
            return 6; 
            break; 
        }
        default: 
        {            
            return 0; 
            break; 
        }
    }
}
int setScoreOnRoll(int x)
{
    x = x;
    return x;
}
int rollDice(void)
{
    srand(time(NULL)); 
    int diceValue; 
    diceValue = rand() % 6 + 1; 
}
int * storePointsArray(int playStatus, int pointEarned)
{
    int points[500]; 
    int i = 0; 
    if (playStatus == 0)
    {
        points[i] = pointEarned;
        i = i + 1; 
    }
    else if (playStatus == 1)
    {
        points[i] = 0; 
        i = i + 1; 
    }
    return points;
}
int humanTurn(int humanTotalScore)
{
    humanTotalScore = 0;
    srand(time(NULL));
    bool play = getHoldOrRoll(rand() % 6 + 1); 
    while (play == true)
    {
        int score = getScoreOnRoll(rand() % 6 + 1);
        int * scoreArray = storePointsArray(int(play), score); 
    }
}
int computerTurn(int computerTotalScore)
{
    
}
void Delay(void)
{
    Sleep(SleepTime);
}
int checkLastScore(int * x)
{
   if (x[-1] == 1)
   {
       return 0; 
   }
   else 
   {
       return  * x; 
   }
}
bool getHoldOrRoll(int x)
{
    if ((x % 2)== 1)
    {
        return true; 
    }
    else if ((x % 2) == 0)
    {
        return false; 
    }
}



