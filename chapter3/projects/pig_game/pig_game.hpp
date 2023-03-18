/**
 * @file pig_game.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PIG_GAME_HPP
#define PIG_GAME_HPP

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>

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
char userInput = '0';	

#define HUMAN_SCORE 0
#define COMPUTER_SCORE 0
#define HUMAN_TURNS 1
#define COMPUTER_TURNS 1

typedef struct HUMAN_OR_COMPUTER
{
    bool human;
    bool computer;
} HUMAN_OR_COMPUTER;

typedef struct COUNTER
{
    int score;
    int turns;
} COUNTER;

typedef struct PLAYER
{
    int score;
    int turns;
} PLAYER;

typedef struct PLAYER_STATUS
{
    bool human;
    bool computer;
} PLAYER_STATUS;

typedef struct PLAYER_SCORE
{
    int human;
    int computer;
} PLAYER_SCORE;

typedef struct PLAYER_TURNS
{
    int human;
    int computer;
} PLAYER_TURNS;

typedef struct HOLD_OR_ROLL
{
    bool hold;
    bool roll;
} HOLD_OR_ROLL;

typedef enum DICE
{
    ONE = 0,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6
} DICE;

/**
 * @brief 
 * 
 * @return If roll a one, return 1, else return 0
 */

void PigGame(void);
void roll_one_condition(void);
void swap_players(void);
int keep_human_score(void);
int get_human_score(void);
int get_computer_score(void);
int get_human_turns(void);
int get_computer_turns(void);
int get_total_human_score(void);
int get_total_computer_score(void);
int get_total_human_turns(void);
int get_total_computer_turns(void);
int set_human_score(int x);
int set_computer_score(int x);
int set_human_turns(int x);
int set_computer_turns(int x);
int set_total_human_score(int x);
int set_total_computer_score(int x);
int set_total_human_turns(int x);
int set_total_computer_turns(int x);
void displayDiceRollValue(int x);
bool is_human_turn(void);
bool is_computer_turn(void);
bool is_hold(void);
bool is_roll(void);
void computerTurn(int x);
void humanTurn(int x);
void displayHumanScore(void);
void displayComputerScore(void);
int main(int argc, char **argv);

#endif /* PIG_GAME_HPP */