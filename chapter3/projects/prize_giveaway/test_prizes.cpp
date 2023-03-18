/**
 * @file test_prizes.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-05
 * 
 * @copyright Copyright (c) 2023
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

int roll(void)
{
    /** @brief roll a number between 1 and 25 and do not allow for the next roll to be the same number as the previous roll
     * 
     */
    int rolled_value = rand() % MAX + 1;
    return rolled_value;
}

int get_roll_number(int roll_number)
{
    /** @brief get the roll number
     * 
     */
    return roll_number;
}

int get_prize(int prize)
{
    /** @brief get the prize
     * 
     */
    return prize;
}

int set_roll_number(int roll_number)
{
    /** @brief set the roll number
     * 
     */
    return roll_number;
}

int set_prize(int prize)
{
    /** @brief set the prize
     * 
     */
    return prize;
}

int main(int argc, char *argv[]) {
    /**
     * @brief Pick random numbers between 1 and 25 and do not allow for repeats until 4 numbers have been picked
     * 
     */
    int roll_number;
    int prize;
    int previous_roll_number;
    int previous_prize;
    int roll_number_array[ROLLS];
    int prize_array[ROLLS];
    int roll_number_array_size = sizeof(roll_number_array) / sizeof(roll_number_array[0]);
    int prize_array_size = sizeof(prize_array) / sizeof(prize_array[0]);
    int roll_number_array_index = 0;
    int prize_array_index = 0;
    for (int i = 0; i < ROLLS; i++)
    {
        roll_number = roll();
        prize = PRIZE;
        if (check_unique_roll_number(roll_number, previous_roll_number))
        {
            roll_number_array[roll_number_array_index] = roll_number;
            prize_array[prize_array_index] = prize;
            roll_number_array_index++;
            prize_array_index++;
        }
        else
        {
            i--;
        }
    }
    for (int i = 0; i < roll_number_array_size; i++)
    {
        cout << "Roll number: " << roll_number_array[i] << endl;
        cout << "Prize: " << prize_array[i] << endl;
    }
    return 0;
}