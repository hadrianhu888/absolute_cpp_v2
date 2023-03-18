/**
 * @file prize_door.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * @brief 
 * Select a random winning door (1,2,or 3)
    * Select a random door for the player to choose (1,2,or 3)
    * Select a random door to open (1,2,or 3)
    * If the door opened is the winning door, then select a random door to open
    * If the player chose the door, thn ask the player whether to keep the door or switch to another door
    * Compare the strategy of randomly keeping the original door versus switching door to see which strategy is better
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

int seed = system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);
uniform_int_distribution<int> distribution(1,3);

std::vector<int> winning_doors;

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
int set_computer_loses(void);
int get_computer_loses(void);
double get_player_win_percentage(void);
double get_player_lose_percentage(void);
double get_computer_win_percentage(void);
double get_computer_lose_percentage(void);
void play_game(void);
void play_game_switch(void);
void play_game_keep(void);
void play_thousand_games(void);
int main(int argc, char **argv); 

int get_winning_door(void)
{
    return rand() % 3 + 1;
}

int set_winning_door(void)
{
    random_winning_door = get_winning_door();
    return random_winning_door;
}

int get_player_door(void)
{
    return rand() % 3 + 1;
}

int set_player_door(void)
{
    player_random_door = get_player_door();
    return player_random_door;
}

int get_computer_door(void)
{
    return rand() % 3 + 1;
}

int set_computer_door(void)
{
    computer_random_door = get_computer_door();
    return computer_random_door;
}

int get_player_wins(void)
{
    return player_wins;
}

int set_player_wins(void)
{
    player_wins++;
    return player_wins;
}

int get_player_loses(void)
{
    return player_loses;
}

int set_player_loses(void)
{
    player_loses++;
    return player_loses;
}

int get_computer_wins(void)
{
    return computer_wins;
}

int set_computer_wins(void)
{
    computer_wins++;
    return computer_wins;
}

int get_computer_loses(void)
{
    return computer_loses;
}

int set_computer_loses(void)
{
    computer_loses++;
    return computer_loses;
}

double get_player_win_percentage(void)
{
    return (double)player_wins / (player_wins + player_loses) * 100;
}

double get_player_lose_percentage(void)
{
    return (double)player_loses / (player_wins + player_loses) * 100;
}

double get_computer_win_percentage(void)
{
    return (double)computer_wins / (computer_wins + computer_loses) * 100;
}

double get_computer_lose_percentage(void)
{
    return (double)computer_loses / (computer_wins + computer_loses) * 100;
}

void play_game(void)
{
    set_winning_door();
    set_player_door();
    set_computer_door();
    if (player_random_door == random_winning_door)
    {
        set_player_wins();
    }
    else
    {
        set_player_loses();
    }
    if (computer_random_door == random_winning_door)
    {
        set_computer_wins();
    }
    else
    {
        set_computer_loses();
    }
}

void play_game_switch(void)
{
    set_winning_door();
    set_player_door();
    set_computer_door();
    if (player_random_door == random_winning_door)
    {
        set_player_wins();
    }
    else
    {
        set_player_loses();
    }
    if (computer_random_door == random_winning_door)
    {
        set_computer_wins();
    }
    else
    {
        set_computer_loses();
    }
}

void play_game_keep(void)
{
    set_winning_door();
    set_player_door();
    set_computer_door();
    if (player_random_door == random_winning_door)
    {
        set_player_wins();
    }
    else
    {
        set_player_loses();
    }
    if (computer_random_door == random_winning_door)
    {
        set_computer_wins();
    }
    else
    {
        set_computer_loses();
    }
}

void play_thousand_games(void)
{
    for (int i = 0; i < 1000; i++)
    {
        play_game();
    }
}

int main(int argc, char **argv)
{
    play_thousand_games();
    cout << "Player wins: " << get_player_wins() << endl;
    cout << "Player loses: " << get_player_loses() << endl;
    cout << "Player win percentage: " << get_player_win_percentage() << endl;
    cout << "Player lose percentage: " << get_player_lose_percentage() << endl;
    cout << "Computer wins: " << get_computer_wins() << endl;
    cout << "Computer loses: " << get_computer_loses() << endl;
    cout << "Computer win percentage: " << get_computer_win_percentage() << endl;
    cout << "Computer lose percentage: " << get_computer_lose_percentage() << endl;
    return 0;
}
