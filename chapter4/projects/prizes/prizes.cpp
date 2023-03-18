/**
 * @file prizes.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "common.hpp"
#include "prizes.hpp"

void set_random_winning_door(int &winning_door) {
  winning_door = get_random_number_in_range_one_two_three();
}

void set_random_door(int &door) {
  door = get_random_number_in_range_one_two_three();
}

void get_random_door(int &door) {
  door = get_random_number_in_range_one_two_three();
}

void get_random_door(int &door, int winning_door) {
  door = get_random_number_in_range_one_two_three(winning_door);
}

void get_random_door(int &door, int winning_door, int first_door) {
  door = get_random_number_in_range_one_two_three(winning_door, first_door);
}

void get_random_door(int &door, int winning_door, int first_door, int second_door) {
  door = get_random_number_in_range_one_two_three(winning_door, first_door, second_door);
}

void get_random_door(int &door, int winning_door, int first_door, int second_door, int third_door) {
  door = get_random_number_in_range_one_two_three(winning_door, first_door, second_door, third_door);
}

int get_random_number_in_range_one_two_three(void) {
  return (rand() % 3) + 1;
}

int get_random_number_in_range_one_two_three(int winning_door) {
  int door = get_random_number_in_range_one_two_three();
  while (door == winning_door) {
    door = get_random_number_in_range_one_two_three();
  }
  return door;
}

int get_random_number_in_range_one_two_three(int winning_door, int first_door) {
  int door = get_random_number_in_range_one_two_three();
  while (door == winning_door || door == first_door) {
    door = get_random_number_in_range_one_two_three();
  }
  return door;
}

int get_random_number_in_range_one_two_three(int winning_door, int first_door, int second_door) {
  int door = get_random_number_in_range_one_two_three();
  while (door == winning_door || door == first_door || door == second_door) {
    door = get_random_number_in_range_one_two_three();
  }
  return door;
}

int get_random_number_in_range_one_two_three(int winning_door, int first_door, int second_door, int third_door) {
  int door = get_random_number_in_range_one_two_three();
  while (door == winning_door || door == first_door || door == second_door || door == third_door) {
    door = get_random_number_in_range_one_two_three();
  }
  return door;
}

void play_10_thousand_games(int &win, int &lose) {
  for (int i = 0; i < 10000; i++) {
    play_game(win, lose);
	display_results(win, lose);
  }
}

double get_winning_percentage(int win, int lose) {
  return (double)win / (win + lose) * 100;
}

double get_losing_percentage(int win, int lose) {
  return (double)lose / (win + lose) * 100;
}

void play_game(int &win, int &lose) {
  int winning_door = 0;
  int first_door = 0;
  int second_door = 0;
  int third_door = 0;
  int door = 0;

  set_random_winning_door(winning_door);
  set_random_door(first_door);
  get_random_door(second_door, winning_door, first_door);
  get_random_door(third_door, winning_door, first_door, second_door);

  if (first_door == winning_door) {
    win++;
  } else {
    lose++;
  }
}

void play_game(int &win, int &lose, int &winning_door, int &first_door, int &second_door, int &third_door) {
  set_random_winning_door(winning_door);
  set_random_door(first_door);
  get_random_door(second_door, winning_door, first_door);
  get_random_door(third_door, winning_door, first_door, second_door);

  if (first_door == winning_door) {
	win++;
  } else {
	lose++;
  }
}

void display_results(int win, int lose) {
  cout << "Winning percentage: " << get_winning_percentage(win, lose) << "%" << endl;
  cout << "Losing percentage: " << get_losing_percentage(win, lose) << "%" << endl;
}


