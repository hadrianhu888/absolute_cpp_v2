/**
 * @file prizes.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "common.hpp"
#include "prizes.hpp"

extern int total_games_played;
extern int total_games; // total games played
extern int total_wins;
extern int total_losses;
extern int total_games_won;
extern int total_games_lost;
extern int total_wins_lost; // total wins lost
extern int total_losses_lost;
extern int total_games_played_this_game;
extern int total_wins_this_game;
extern int total_losses_this_game;
extern int total_games_won_this_game;
extern int total_games_lost_this_game;
extern int total_wins_lost_this_game;
extern int total_losses_lost_this_game;
extern int total_games_won_this_game;
extern int total_games_lost_this_game;
extern int total_wins_lost_this_game;
extern int total_losses_lost_this_game;
extern int total_games_won;
extern int total_games_lost;
extern int total_wins;
extern int total_losses;
extern int total_games_won;
extern int total_games_lost;
extern int total_wins;
extern int total_losses;
extern int total_games_won;
extern int total_games_lost;
extern int total_wins;
extern int total_losses;
extern int total_games_won;
extern double win_rate;
extern double lose_rate;
extern int total_losses_lost;

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

int get_player_choice(void)
{
    int player_choice;
    cout << "Choose a door (1, 2, or 3): ";
    cin >> player_choice;
    return player_choice;
}

int set_player_choice(void)
{
    int player_choice = get_player_choice();
    return player_choice;
}

bool is_correct_door(int door)
{
    if (door == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int choose_random_door(void)
{
    srand(unsigned(time(0)));
    int door = rand() % 3 + 1;
    return door;
}

int get_door_to_open(void)
{
    int door_to_open = choose_random_door();
    return door_to_open;
}

int set_door_to_open(void)
{
    int door_to_open = get_door_to_open();
    return door_to_open;
}

int get_win_rate(void)
{
    win_rate = total_wins / total_games;
    return win_rate;
}

int get_lose_rate(void)
{
    lose_rate = total_losses / total_games;
    return lose_rate;
}

double get_average_win_rate(void)
{
    double average_win_rate = total_wins / total_games;
    return average_win_rate;
}

double get_average_lose_rate(void)
{
    double average_lose_rate = total_losses / total_games;
    return average_lose_rate;
}

int get_total_games_played(void)
{
    total_games_played = total_games_won + total_games_lost;
    return total_games_played;
}

int get_total_games_won(void)
{
    total_games_won = total_wins + total_losses;
    return total_games_won;
}

int get_total_games_lost(void)
{
    total_games_lost = total_wins + total_losses;
    return total_games_lost;
}

double get_average_games_played(void)
{
    double average_games_played = total_games_played / total_games;
    return average_games_played;
}

double get_average_games_won(void)
{
    double average_games_won = total_games_won / total_games;
    return average_games_won;
}

double get_average_games_lost(void)
{
    double average_games_lost = total_games_lost / total_games;
    return average_games_lost;
}

int get_total_wins(void)
{
    total_wins = total_wins_lost + total_wins_won;
    return total_wins;
}

int get_total_losses(void)
{
    total_losses = total_losses_lost + total_losses_won;
    return total_losses;
}

double get_average_wins(void)
{
    double average_wins = total_wins / total_games;
    return average_wins;
}

void play_game(void)
{
    int winning_door = set_winning_door();
    int player_choice = set_player_choice();
    int door_to_open = set_door_to_open();
    bool is_correct = is_correct_door(winning_door);
    if (is_correct)
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "You lose!" << endl;
    }
}

int main(int argc, char *argv[])
{
    int winning_door = set_winning_door();
    int player_choice = set_player_choice();
    int door_to_open = set_door_to_open();
    bool is_correct = is_correct_door(winning_door);
    if (is_correct)
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "You lose!" << endl;
    }
    return 0;
}



