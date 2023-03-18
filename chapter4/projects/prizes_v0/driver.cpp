/**
 * @file driver.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "common.hpp"
#include "prizes.hpp"
#include "prizes.cpp"

extern int door; 
extern int winning_door;
extern int first_door;
extern int second_door;
extern int third_door;

extern int number_of_games_played;
extern int number_of_games_won;
extern int number_of_games_lost;
extern int number_of_wins;
extern int number_of_losses;
extern int number_of_wins_per_game;
extern int number_of_losses_per_game;
extern int average_number_of_wins;
extern int average_number_of_losses;

extern double average_number_of_wins_per_game;
extern double average_number_of_losses_per_game;

int main(int argc, char *argv[]); // default main

int main(int argc, char *argv[])
{
    play_multiple_games(number_of_games_played);
}

