/**
 * @file prizes.cpp
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

extern int door; 
extern int winning_door;
extern int first_door;
extern int second_door;
extern int third_door;

extern int MAX; 
extern int number_of_games_played;
extern int number_of_games_won;
extern int number_of_games_lost;
extern int number_of_wins;
extern int number_of_losses;
extern int number_of_wins_per_game;
extern int number_of_losses_per_game;
extern int average_number_of_wins;
extern int average_number_of_losses;

extern double probability_of_winning_if_player_keeps_wrong_door;
extern double probability_of_winning_if_player_switches_door;

int number_of_games_played = MAX; 

extern int MAX; // maximum number of games to play

void print_results(void)
{
  cout << "Number of games played: " << number_of_games_played << endl;
  cout << "Number of games won: " << number_of_wins << endl;
  cout << "Number of games lost: " << number_of_losses << endl;
  cout << "Number of wins: " << number_of_wins_per_game << endl;
  cout << "Number of losses: " << number_of_losses_per_game << endl;
  cout << "Number of wins per game: " << number_of_wins_per_game << endl;
  cout << "Number of losses per game: " << number_of_losses_per_game << endl;
  cout << "Number of wins per game: " << number_of_wins_per_game << endl;
  cout << "Number of losses per game: " << number_of_losses_per_game << endl;
  cout << "Number of wins per game: " << number_of_wins_per_game << endl;
  cout << "Number of losses per game: " << number_of_losses_per_game << endl;
}

int get_random_number_in_range_one_two_three(void) {
  return (rand() % 3) + 1;
}

int get_random_winning_door(void) {
  return (rand() % 3) + 1;
}

int get_random_door(void) {
  return (rand() % 3) + 1;
}

int get_random_door(int winning_door) {
  int door = get_random_door();
  while (door == winning_door) {
    door = get_random_door();
  }
  return door;
}

int get_random_door(int winning_door, int first_door) {
  int door = get_random_door();
  while (door == winning_door || door == first_door) {
    door = get_random_door();
  }
  return door;
}

int get_random_door(int winning_door, int first_door, int second_door) {
  int door = get_random_door();
  while (door == winning_door || door == first_door || door == second_door) {
    door = get_random_door();
  }
  return door;
}

int get_random_door(int winning_door, int first_door, int second_door, int third_door) {
  int door = get_random_door();
  while (door == winning_door || door == first_door || door == second_door || door == third_door) {
    door = get_random_door();
  }
  return door;
}

void choose_random_winning_door(int &winning_door) {
  winning_door = get_random_winning_door();
}

void choose_random_door(int &door) {
  door = get_random_door();
}

void choose_random_door(int &door, int winning_door) {
  door = get_random_door(winning_door);
}

void choose_random_door(int &door, int winning_door, int first_door) {
  door = get_random_door(winning_door, first_door);
}

void choose_random_door(int &door, int winning_door, int first_door, int second_door) {
  door = get_random_door(winning_door, first_door, second_door);
}

void choose_random_door(int &door, int winning_door, int first_door, int second_door, int third_door)
{
  door = get_random_door(winning_door, first_door, second_door, third_door);
}

double calculate_probability_of_winning_if_player_keeps_wrong_door(void) {
  int winning_door = 0;
  int door = 0;
  int first_door = 0;
  int second_door = 0;
  int third_door = 0;
  int number_of_wins = 0;
  int number_of_games = 0;
  double probability_of_winning_if_player_keeps_wrong_door = 0.0;

  for (int i = 0; i < 1000000; i++) {
    choose_random_winning_door(winning_door);
    choose_random_door(door);
    choose_random_door(first_door, winning_door, door);
    choose_random_door(second_door, winning_door, door, first_door);
    choose_random_door(third_door, winning_door, door, first_door, second_door);
    if (door == winning_door) {
      number_of_wins++;
    }
    number_of_games++;
  }
  probability_of_winning_if_player_keeps_wrong_door = (double)number_of_wins / (double)number_of_games;
  return probability_of_winning_if_player_keeps_wrong_door;
}

double calculate_probability_of_winning_if_player_keeps_right_door(void) {
  int winning_door = 0;
  int door = 0;
  int first_door = 0;
  int second_door = 0;
  int third_door = 0;
  int number_of_wins = 0;
  int number_of_games = 0;
  double probability_of_winning_if_player_keeps_right_door = 0.0;

  for (int i = 0; i < 1000000; i++) {
    choose_random_winning_door(winning_door);
    choose_random_door(door, winning_door);
    choose_random_door(first_door, winning_door, door);
    choose_random_door(second_door, winning_door, door, first_door); 
    if (door == winning_door) {
      number_of_wins++;
    }
    number_of_games++;
  }
  probability_of_winning_if_player_keeps_right_door = (double)number_of_wins / (double)number_of_games;
  return probability_of_winning_if_player_keeps_right_door;
}

double calculate_probability_of_winning_if_player_switches_door(void) {
  int winning_door = 0;
  int door = 0;
  int first_door = 0;
  int second_door = 0;
  int third_door = 0;
  int number_of_wins = 0;
  int number_of_games = 0;
  double probability_of_winning_if_player_switches_door = 0.0;

  for (int i = 0; i < 1000000; i++) {
    choose_random_winning_door(winning_door);
    choose_random_door(door);
    choose_random_door(first_door, winning_door, door);
    choose_random_door(second_door, winning_door, door, first_door);
    choose_random_door(third_door, winning_door, door, first_door, second_door);
    if (door != winning_door) {
      number_of_wins++;
    }
    number_of_games++;
  }
  probability_of_winning_if_player_switches_door = (double)number_of_wins / (double)number_of_games;
  return probability_of_winning_if_player_switches_door;
}

void play_single_game(void)
{
  int winning_door = 0;
  int door = 0;
  int first_door = 0;
  int second_door = 0;
  int third_door = 0;
  int number_of_wins = 0;
  int number_of_games = 0;
  double probability_of_winning_if_player_keeps_wrong_door = 0.0;
  double probability_of_winning_if_player_keeps_right_door = 0.0;
  double probability_of_winning_if_player_switches_door = 0.0;

  choose_random_winning_door(winning_door);
  choose_random_door(door);
  choose_random_door(first_door, winning_door, door);
  choose_random_door(second_door, winning_door, door, first_door);
  choose_random_door(third_door, winning_door, door, first_door, second_door);
  if (door == winning_door) {
    number_of_wins++;
  }
  number_of_games++;
  probability_of_winning_if_player_keeps_wrong_door = (double)number_of_wins / (double)number_of_games;
  number_of_wins = 0;
  number_of_games = 0;
  choose_random_door(door, winning_door);
  choose_random_door(first_door, winning_door, door);
  choose_random_door(second_door, winning_door, door, first_door);
  if (door == winning_door) {
    number_of_wins++;
  }
  number_of_games++;
  probability_of_winning_if_player_keeps_right_door = (double)number_of_wins / (double)number_of_games;
  number_of_wins = 0;
  number_of_games = 0;
  choose_random_door(door);
  choose_random_door(first_door, winning_door, door);
  choose_random_door(second_door, winning_door, door, first_door);
  choose_random_door(third_door, winning_door, door, first_door, second_door);
  if (door != winning_door) {
    number_of_wins++;
  }
  number_of_games++;
  probability_of_winning_if_player_switches_door = (double)number_of_wins / (double)number_of_games;
  cout << "Probability of winning if player keeps wrong door: " << probability_of_winning_if_player_keeps_wrong_door << endl;
  cout << "Probability of winning if player keeps right door: " << probability_of_winning_if_player_keeps_right_door << endl;
}

void play_multiple_games(int number_of_games)
{
  int winning_door = 0;
  int door = 0;
  int first_door = 0;
  int second_door = 0;
  int third_door = 0;
  int number_of_wins = 0;  
  double probability_of_winning_if_player_keeps_wrong_door = 0.0;
  double probability_of_winning_if_player_keeps_right_door = 0.0;
  double probability_of_winning_if_player_switches_door = 0.0;
  double probability_of_winning_if_player_switches_door_2 = 0.0;
  double probability_of_winning_if_player_switches_door_3 = 0.0;
  /*
   * @brief play the game 10 thousand times and calculate the probability of winning if the player keeps the wrong door, the right door, and switches doors.
   * 
   */
  for (int i = 0; i < number_of_games; i++)
  {
    play_single_game();
  }
}
