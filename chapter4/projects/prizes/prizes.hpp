/**
 * @file prizes.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PRIZES_HPP
#define PRIZES_HPP

#include "common.hpp"

// function prototypes

void set_random_winning_door(int &winning_door);
void set_random_door(int &door);
void get_random_door(int &door);
void get_random_door(int &door, int winning_door);
void get_random_door(int &door, int winning_door, int first_door);
void get_random_door(int &door, int winning_door, int first_door, int second_door);
void get_random_door(int &door, int winning_door, int first_door, int second_door, int third_door);
int get_random_number_in_range_one_two_three(void);
int get_random_number_in_range_one_two_three(int winning_door);
int get_random_number_in_range_one_two_three(int winning_door, int first_door);
int get_random_number_in_range_one_two_three(int winning_door, int first_door, int second_door);
int get_random_number_in_range_one_two_three(int winning_door, int first_door, int second_door, int third_door);
void play_10_thousand_games(int &win, int &lose);
double get_winning_percentage(int win, int lose);
double get_losing_percentage(int win, int lose);
void play_game(int &win, int &lose);
void display_results(int win, int lose);

#endif /* PRIZES_HPP */
