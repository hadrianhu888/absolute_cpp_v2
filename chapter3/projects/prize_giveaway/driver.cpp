/**
 * @file driver.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
  * @brief Drives the prize giveaway program
  * 
  */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include "prizes.hpp"

using namespace std;

int main(int argc, char** argv); 

int main(int argc, char** argv) {
    /**
     * @brief Test drives the prizes program
     * Roll four times and display the roll number and the prize
     */
    int roll_number;
    int prize;
    int roll_values[ROLLS];
    int prize_values[ROLLS];
    int previous_roll_number = 0;
    int previous_prize = 0;
    int i = 0;  // loop counter
    for (i = 0; i < ROLLS; i++) {
        roll_number = roll();
        prize = get_prize(roll_number);
        if (check_unique_roll_number(roll_number, previous_roll_number)) {
            disp_roll_number(roll_number);
            disp_prize(prize);
        }
        else {
            cout << "The roll number is not unique. Try again." << endl;
        }
    }
}