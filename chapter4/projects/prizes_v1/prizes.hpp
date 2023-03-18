/**
 * @file prizes.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PRIZES_HPP
#define PRIZES_HPP

#include "common.hpp"

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

#include <iostream>

int total_games_played;
int total_games; // total games played
int total_wins;
int total_losses;

int total_games_won;
int total_games_lost;

int total_games_played_this_game;
int total_wins_this_game;
int total_losses_this_game;

int total_games_won_this_game;
int total_games_lost_this_game;

int total_wins_won; 
int total_losses_lost;
int total_wins_lost;
int total_losses_won;

double win_rate; 
double lose_rate;

using namespace std;

int get_winning_door(void);
int set_winning_door(void);

int get_player_choice(void);
int set_player_choice(void);

bool is_correct_door(int door);
int choose_random_door(void);

int get_door_to_open(void);
int set_door_to_open(void);

int get_win_rate(void);
int set_win_rate(void);

int get_lose_rate(void);
int set_lose_rate(void);

int get_total_games(void);
int set_total_games(void);

int get_total_wins(void);
int set_total_wins(void);

int get_total_losses(void);
int set_total_losses(void);

int get_total_games_played(void);
int set_total_games_played(void);

double calculate_win_rate(void);
double calculate_lose_rate(void);

void print_winning_door(void);
void print_player_choice(void);
void print_door_to_open(void);

void play_game(void);

int main(int argc, char *argv[]);

#endif // PRIZES_HPP