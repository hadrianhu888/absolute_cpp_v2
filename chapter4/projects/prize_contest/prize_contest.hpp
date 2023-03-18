/**
 * @file prize_contest.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PRIZE_CONTESTANT_HPP
#define PRIZE_CONTESTANT_HPP

#include "common.hpp"

#define DOOR1 1
#define DOOR2 2
#define DOOR3 3

typedef long long LONGLONG;
LONGLONG PRIZE = 1000000;
/**
 * @brief Select a random door that has the prize behind it
 * Only one door has the prize behind it
 * The other two doors have goats behind them.
 * The player can either stay with the chosen door or switch to the other door
 * This is a game of chance and the player has a 1/3 chance of winning if he
 * only chooses one door. If the player switches doors, he has a 2/3 chance of
 * winning.
 * Implement this logic in a function that returns the door number that has the
 * winning prize.
 *
 * @return int
 */

int select_random_winnnig_door(void);
int select_random_door(void);
int select_random_door(int door1, int door2);
int select_random_door(int door1, int door2, int door3);

void play_game(void);
void play_game(int &win, int &lose);

void play_game(int &win, int &lose, int &switch_win, int &switch_lose);

void play_game(int &win, int &lose, int &switch_win, int &switch_lose,
               int &stay_win, int &stay_loose);

void auto_play_game(int &win, int &lose, int &switch_win, int &switch_lose,
                    int &stay_win, int &stay_loose);

void play_10_thousand_games(int &win, int &lose); // 10,000 games

#endif /* PRIZE_CONTESTANT_HPP */