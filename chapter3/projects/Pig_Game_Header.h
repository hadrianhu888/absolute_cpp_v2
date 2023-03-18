/**
 * @file PigGame_v3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once 
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
void displayScore(int x);
int main(int argc, char ** argv); 
int rollDice(void); 
int humanTurn(int humanTotalScore); 
int computerTurn(int computerTotalScore); 
int getRollOrHold (void);
int getTurnsCount(int x); 
int incrementTurnsCount(int x);
int setTurnsCount(int x);
int getDiceValue(int x); 

