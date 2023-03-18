/**
 * @file prizes.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PRIZES_HPP
#define PRIZES_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>

#define ROLLS 4
#define PRIZE 100
#define MAX 25

int roll_number;
int prize;

using namespace std;

/**
 * @brief roll a random number between 1 and 25 and do not allow for the next roll to be the same number as the previous roll
 * 
 */

int roll(void);
int get_roll_number(int roll_number);
int get_prize(int prize);
int set_roll_number(int roll_number);
int set_prize(int prize);
int main(int argc, char *argv[]);
bool check_unique_roll_number(int roll_number, int& previous_roll_number);
void disp_roll_number(int roll_number);
void disp_prize(int prize);

#endif // PRIZES_HPP