/**
 * @file pig_game.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pig_game.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>
#include <time.h>
#include <Windows.h>
/**
#include "unistd.h"
*/
using namespace std;

/**
 * @brief function prototypes are defined below
 * 
 * @param arg 
 * @param argv 
 * @return int 
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
int main(int argc, char **argv);

void roll_one_condition(void){
    if (randomNumber == 1){
        tempHumanScore = 0;
        cout << "You rolled a 1. Your turn is over." << endl;
        cout << "Your score is " << humanTotalScore << endl;
        cout << "The computer's score is " << computerTotalScore << endl;
        Sleep(SleepTime);
        swap_players();
    }
}

void swap_players(void){
    if (playerStatus == 'H'){
        playerStatus = 'C';
    }
    else if (playerStatus == 'C'){
        playerStatus = 'H';
    }
}

int keep_human_score(void){
    humanTotalScore += tempHumanScore;
    return humanTotalScore;
}

int get_human_score(void){
    return humanTotalScore;
}

int get_computer_score(void){
    return computerTotalScore;
}

int get_human_turns(void){
    return countHumanTurns;
}

int get_computer_turns(void){
    return countComputerTurns;
}

int get_total_human_score(void){
    return totalHumanScore;
}

int get_total_computer_score(void){
    return totalComputerScore;
}

int get_total_human_turns(void){
    return totalHumanTurns;
}

int get_total_computer_turns(void){
    return totalComputerTurns;
}

int set_human_score(int x){
    humanTotalScore = x;
    return humanTotalScore;
}

int set_computer_score(int x){
    computerTotalScore = x;
    return computerTotalScore;
}

int set_human_turns(int x){
    countHumanTurns = x;
    return countHumanTurns;
}

int set_computer_turns(int x){
    countComputerTurns = x;
    return countComputerTurns;
}

int set_total_human_score(int x){
    totalHumanScore = x;
    return totalHumanScore;
}

int set_total_computer_score(int x){
    totalComputerScore = x;
    return totalComputerScore;
}

int set_total_human_turns(int x){
    totalHumanTurns = x;
    return totalHumanTurns;
}

int set_total_computer_turns(int x){
    totalComputerTurns = x;
    return totalComputerTurns;
}

void displayDiceRollValue(int x){
    cout << "You rolled a " << x << endl;
}

bool is_computer_turn(void){
    if (playerStatus == 'C'){
        return true;
    }
    else{
        return false;
    }
}

bool is_human_turn(void){
    if (playerStatus == 'H'){
        return true;
    }
    else{
        return false;
    }
}

bool is_hold(void){
    if (randomNumber == 1){
        return true;
    }
    else{
        return false;
    }
}

bool is_roll(void){
    if (randomNumber != 1){
        return true;
    }
    else{
        return false;
    }
}

void computerTurn(void){
    while (is_computer_turn()){
        randomNumber = rand() % 6 + 1;
        displayDiceRollValue(randomNumber);
        if (is_roll()){
            tempComputerScore += randomNumber;
            cout << "The computer's score is " << tempComputerScore << endl;
            Sleep(SleepTime);
        }
        else if (is_hold()){
            computerTotalScore += tempComputerScore;
            tempComputerScore = 0;
            cout << "The computer's score is " << computerTotalScore << endl;
            Sleep(SleepTime);
            swap_players();
        }
    }
}

void humanTurn(void){
    while (is_human_turn()){
        cout << "Press 'r' to roll or 'h' to hold" << endl;
        cin >> userInput;
        userInput = toupper(userInput);
        if (userInput == 'R'){
            randomNumber = rand() % 6 + 1;
            displayDiceRollValue(randomNumber);
            if (is_roll()){
                tempHumanScore += randomNumber;
                cout << "Your score is " << tempHumanScore << endl;
                Sleep(SleepTime);
            }
            else if (is_hold()){
                humanTotalScore += tempHumanScore;
                tempHumanScore = 0;
                cout << "Your score is " << humanTotalScore << endl;
                Sleep(SleepTime);
                swap_players();
            }
        }
        else if (userInput == 'H'){
            humanTotalScore += tempHumanScore;
            tempHumanScore = 0;
            cout << "Your score is " << humanTotalScore << endl;
            Sleep(SleepTime);
            swap_players();
        }
    }
}

void displayHumanScore(void){
    cout << "Your score is " << humanTotalScore << endl;
}

void displayComputerScore(void){
    cout << "The computer's score is " << computerTotalScore << endl;
}

int main(int argc, char **argv){
    PigGame();
    return 0;
}

void PigGame(void){
    srand(time(NULL));
    int randomNumber = 0;
    int tempHumanScore = 0;
    int tempComputerScore = 0;
    int humanTotalScore = 0;
    int computerTotalScore = 0;
    int countHumanTurns = 0;
    int countComputerTurns = 0;
    int totalHumanScore = 0;
    int totalComputerScore = 0;
    int totalHumanTurns = 0;
    int totalComputerTurns = 0;
    char playerStatus = 'H';
    int SleepTime = 1000;
    char userInput = ' ';
    bool is_roll = false;
    bool is_hold = false;
    bool is_computer_turn = false;
    bool is_human_turn = false;
    /**
     * @brief use a while loop to keep track of the score and let the computer go first
    * If the computer rolls a one first, the human player will roll next 
    * If the computer scores more than 20 points, switch to the humans go next 
    * If the human rolls a one, the computer will roll next
    * If the human scores more than 20 points, switch to the computers go next
    * Make sure the computer plays its turns (roll or hold)
    * If computer rolls a one, the human will roll next
    * If computer scores more than 20 points, switch to the humans go next
    * If the human or computer scores 100 points, the game is over
     * 
     */
    while (humanTotalScore < 100 && computerTotalScore < 100) {
        if (playerStatus == 'C'){
            computerTurn();
            displayHumanScore();
        } else if (playerStatus == 'H') {
            humanTurn();
            displayComputerScore();
        }
    }
}
