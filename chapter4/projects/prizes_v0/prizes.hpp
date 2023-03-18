/**
 * @file prizes.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PRIZES_HPP
#define PRIZES_HPP

#ifndef COMMON_HPP
#define COMMON_HPP

int MAX=10000; // maximum number of games to play

#include "common.hpp"

typedef enum DOORS {
    DOOR_1 = 1,
    DOOR_2 = 2,
    DOOR_3 = 3
} DOORS;

int door; 
int winning_door;
int first_door;
int second_door;
int third_door;

int number_of_games_played; 
int number_of_wins; 
int number_of_losses; 
int number_of_draws;
int number_of_wins_per_game;
int number_of_losses_per_game;
int number_of_draws_per_game;
int average_number_of_wins;
int average_number_of_losses;
int average_number_of_draws;

double probability_of_winning_if_player_keeps_wrong_door = 0.0;
double probability_of_winning_if_player_switches_door = 0.0; 

/**************************************************************************************************************
 * @brief Let the player select one of three random doors (1, 2 or 
 * 3).
 * Select a random winning door (1, 2 or 3).
 * The player can select a door (1, 2 or 3).
    * If the player selects the winning door, the player wins a prize.
    * If the player selected a door that is not the winning door, the 
    * the player can choose between keeping the wrong door or selecting any one of the remaining doors. 
    * Calculate the probability of selecting the winning door if the player keeps the wrong door.
    * Calculate the probability of selecting the winning door if the player selects any one of the remaining doors.
 **************************************************************************************************************/

void print_result(void); 

int get_random_number_in_range_one_two_three(void);
int get_random_number_in_range_one_two_three(int winning_door);
int get_random_number_in_range_one_two_three(int winning_door, int first_door);
int get_random_number_in_range_one_two_three(int winning_door, int first_door, int second_door);
int get_random_number_in_range_one_two_three(int winning_door, int first_door, int second_door, int third_door);
/**
 * @brief Let the player select one of three random doors (1, 2 or 
 * 3).
 * Select a random winning door (1, 2 or 3).
**/

void choose_random_winning_door(int &winning_door);
void choose_random_door(int &door);
void choose_random_door(int &door, int winning_door);
void choose_random_door(int &door, int winning_door, int first_door);
void choose_random_door(int &door, int winning_door, int first_door, int second_door);
void choose_random_door(int &door, int winning_door, int first_door, int second_door, int third_door);

double calculate_probability_of_winning_if_player_keeps_wrong_door(void);
double calculate_probability_of_winning_if_player_switches_door(void);

void play_single_game(void);
void play_multiple_games(int number_of_games);

#endif /* COMMON_HPP */
#endif /* PRIZES_HPP */

