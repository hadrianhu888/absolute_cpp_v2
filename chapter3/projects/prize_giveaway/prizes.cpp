/**
 * @file prizes.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <string>
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
bool check_unique_roll_number(int roll_number, int& previous_roll_number)
{
    /** @brief check if the roll number is unique
     * 
     */
    if (roll_number == previous_roll_number)
    {
        return false;
    }
    else
    {
        previous_roll_number = roll_number;
        return true;
    }    
}

void disp_roll_number(int roll_number)
{
    /** @brief display the roll number
     * 
     */
    cout << "Roll number: " << roll_number << endl;
}

void disp_prize(int prize)
{
    /** @brief display the prize
     * 
     */
    cout << "Prize: " << prize << endl;
}

int main (int argc, char* argv[]) {
    int roll_number = 0;
    int prize = 0;
    int previous_roll_number = 0;
    int roll_number_array[ROLLS];
    int prize_array[ROLLS];
    int i = 0;
    for (i = 0; i < ROLLS; i++)
    {
        roll_number = roll();
        while (check_unique_roll_number(roll_number, previous_roll_number) == false)
        {
            roll_number = roll();
        }
        roll_number_array[i] = roll_number;
        prize = roll();
        disp_roll_number(roll_number_array[i]);
        prize_array[i] = prize;
        disp_prize(prize_array[i]);
    }
    return 0;
}