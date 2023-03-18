/**
 * @file test_prizes.cpp
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

int test_prizes(int argc, char **argv); // for testing
void test_get_random_number_in_range_one_two_three(void);
void test_get_choose_random_winning_door(void);
void test_get_random_door(void);

void test_get_random_number_in_range_one_two_three(void) {
  int random_number = get_random_number_in_range_one_two_three();
  assert(random_number >= 1 && random_number <= 3);
}

void test_choose_random_winning_door(void) {
  int winning_door = 0;
  choose_random_winning_door(winning_door);
  assert(winning_door >= 1 && winning_door <= 3);
}

void test_get_random_door(void) {
  int door = get_random_door();
  assert(door >= 1 && door <= 3);
}

