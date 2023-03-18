/**
 * @file doors.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "common.hpp"
#include "doors.hpp"

extern int random_winning_door; // 1, 2, or 3
extern int player_random_door; // 1, 2, or 3
extern int computer_random_door; // 1, 2, or 3
extern int player_wins;
extern int player_loses;
extern int computer_wins;
extern int computer_loses;
extern int player_wins_switch;
extern int player_loses_switch;

int get_winning_door(void)
{
    srand(unsigned(time(0)));
    int winning_door = rand() % 3 + 1;
    return winning_door;
}

int set_winning_door(void)
{
    int winning_door = get_winning_door();
    return winning_door;
}

int get_player_door(void)
{
    srand(unsigned(time(0)));
    int player_door = rand() % 3 + 1;
    return player_door;
}

int set_player_door(void)
{
    int player_door = get_player_door();
    return player_door;
}

int get_computer_door(void)
{
    srand(unsigned(time(0)));
    int computer_door = rand() % 3 + 1;
    return computer_door;
}

int set_computer_door(void)
{
    int computer_door = get_computer_door();
    return computer_door;
}

int get_player_wins(void)
{
    return player_wins;
}

int get_player_loses(void)
{
    return player_loses;
}

int get_computer_wins(void)
{
    return computer_wins;
}

int get_computer_loses(void)
{
    return computer_loses;
}

int get_player_wins_switch(void)
{
    return player_wins_switch;
}


int get_player_loses_switch(void)
{
    return player_loses_switch;
}

double get_player_win_rate(void)
{
    double player_win_rate = (double)player_wins / (double)(player_wins + player_loses);
    return player_win_rate;
}

double get_player_lose_rate(void)
{
    double player_lose_rate = (double)player_loses / (double)(player_wins + player_loses);
    return player_lose_rate;
}

double get_computer_win_rate(void)
{
    double computer_win_rate = (double)computer_wins / (double)(computer_wins + computer_loses);
    return computer_win_rate;
}

double get_computer_lose_rate(void)
{
    double computer_lose_rate = (double)computer_loses / (double)(computer_wins + computer_loses);
    return computer_lose_rate;
}

void set_player_wins(void)
{
    player_wins++;
}

void set_player_loses(void)
{
    player_loses++;
}

void set_computer_wins(void)
{
    computer_wins++;
}

void set_computer_loses(void)
{
    computer_loses++;
}

void set_player_wins_switch(void)
{
    player_wins_switch++;
}

void set_player_loses_switch(void)
{
    player_loses_switch++;
}

void play_one_game(void)
{
    int winning_door = set_winning_door();
    int player_door = set_player_door();
    int computer_door = set_computer_door();
    if (winning_door == player_door)
    {
        set_player_wins();
    }
    else
    {
        set_player_loses();
    }
    if (winning_door == computer_door)
    {
        set_computer_wins();
    }
    else
    {
        set_computer_loses();
    }
}

void play_one_thousand_games(void)
{
    for (int i = 0; i < 1000; i++)
    {
        play_one_game();
    }
}

void play_one_thousand_games_switch(void)
{
    for (int i = 0; i < 1000; i++)
    {
        play_one_game();
        if (player_random_door == random_winning_door)
        {
            set_player_loses_switch();
        }
        else
        {
            set_player_wins_switch();
        }
    }
}

int main(int argc, char **argv)
{
    play_one_thousand_games();
    cout << "Player wins: " << get_player_wins() << endl;
    cout << "Player loses: " << get_player_loses() << endl;
    cout << "Player win rate: " << get_player_win_rate() << endl;
    cout << "Player lose rate: " << get_player_lose_rate() << endl;
    cout << "Computer wins: " << get_computer_wins() << endl;
    cout << "Computer loses: " << get_computer_loses() << endl;
    cout << "Computer win rate: " << get_computer_win_rate() << endl;
    cout << "Computer lose rate: " << get_computer_lose_rate() << endl;
    play_one_thousand_games_switch();
    cout << "Player wins (switch): " << get_player_wins_switch() << endl;
    cout << "Player loses (switch): " << get_player_loses_switch() << endl;
    return 0;
}