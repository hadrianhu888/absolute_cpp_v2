/**
 * @file doors.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DOORS_HPP
#define DOORS_HPP

#ifndef COMMON_HPP
#include "common.hpp"

#include <vector>
#include <string>
#include <iostream>

/**
 * @brief Let the computer select a random winning door (1,2,or 3)
 * Let the computer select a random door for the player to choose (1,2,or 3)
    * Let the computer select a random door to open (1,2,or 3)
    * If the door opened is the winning door, then the computer will select a random door to open
    * If the door opened is not the winning door, then the computer will select the door that is not the winning door or the door that the player chose
    * If the player chose the winning door, then the player wins
    * If the player did not choose the winning door, then the player loses
    * Give the player the option to choose between keeping the original door or switching to another door
    * If the player chooses to keep the original door and the door is not the winning door, then the player loses
    * If the player chooses to keep the original door and the door is the winning door, then the player wins
    * Keep track of wins and loses for each scenario
    * Display the results of the winning door, and the number of wins and loses for each scenario
 */

int random_winning_door; // 1, 2, or 3
int player_random_door; // 1, 2, or 3
int computer_random_door; // 1, 2, or 3
int player_wins;
int player_loses;
int computer_wins;
int computer_loses;
int player_wins_switch;
int player_loses_switch;

int get_winning_door(void); 
int set_winning_door(void);
int get_player_door(void);
int set_player_door(void);
int get_computer_door(void);
int set_computer_door(void);
int get_player_wins(void);
int set_player_wins(void);
int get_player_loses(void);
int set_player_loses(void);
int get_computer_wins(void);
int set_computer_wins(void);
int get_computer_loses(void);
int set_computer_loses(void);
int get_player_wins_switch(void);
int set_player_wins_switch(void);
int get_player_loses_switch(void);
int set_player_loses_switch(void);

double get_win_rate(void);
double get_lose_rate(void);

void play_one_game(void);
void play_one_thousand_games_loop(void);

int main(int argc, char **argv);

#endif /* COMMON_HPP */
#endif // DOORS_HPP