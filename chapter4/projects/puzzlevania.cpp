/**
 * @file puzzlevania.cpp
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
#include <time.h> 
#include <stdio.h>
#include <cstdlib> 
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <chrono> 
#include <thread>
#include <cassert> 
#include <fstream>
#include <sstream>
#include <chrono> 

using namespace std;
using namespace std::chrono;

/**
 * @brief Aaron chance of hitting his target is 33.3%
    * Bob chance of hitting his target is 50%
    * Charlie chance of hitting his target is 66.7%
 * Let a random number generator select a random number between 1 and 3 to represent Aaron, Bob, and Charlie
    * Let a random number generator select a random number between 1 and 100 to represent the chance of hitting the target
 */

int random_number; 
int random_number2;
int random_number3;
int aaron_shoot_first;
int bob_shoot_first;
int charlie_shoot_first;
int aaron_shoot_second;
int bob_shoot_second;
int charlie_shoot_second;
int aaron_shoot_third;
int bob_shoot_third;
int charlie_shoot_third;
double aaron_wins;
double aaron_loses;
double bob_wins;
double bob_loses;
double charlie_wins;
double charlie_loses;
double aaron_win_percentage;
double bob_win_percentage;
double charlie_win_percentage;
double aaron_lose_percentage;
double bob_lose_percentage;
double charlie_lose_percentage;
int seed = system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);
uniform_int_distribution<int> distribution(1,3);
uniform_int_distribution<int> distribution2(1,100);

/**
 * @brief Main function
 */

int get_random_number(void);
int set_random_number(void);
int get_random_number2(void);
int set_random_number2(void);
int get_random_number3(void);
int set_random_number3(void);
double get_aaron_wins(void);
double set_aaron_wins(void);
double get_bob_wins(void);
double set_bob_wins(void);
double get_charlie_wins(void);
double set_charlie_wins(void);
double get_aaron_loses(void);
double set_aaron_loses(void);
double get_bob_loses(void);
double set_bob_loses(void);
double get_charlie_loses(void);
double set_charlie_loses(void);
double get_player_percentages(void);
int play_game(void);
int play_ten_thousand_games(void);
int main(int argc, char **argv); 

double get_player_percentages(void)
{
    aaron_win_percentage = (aaron_wins / (aaron_wins + aaron_loses)) * 100;
    bob_win_percentage = (bob_wins / (bob_wins + bob_loses)) * 100;
    charlie_win_percentage = (charlie_wins / (charlie_wins + charlie_loses)) * 100;
    aaron_lose_percentage = (aaron_loses / (aaron_wins + aaron_loses)) * 100;
    bob_lose_percentage = (bob_loses / (bob_wins + bob_loses)) * 100;
    charlie_lose_percentage = (charlie_loses / (charlie_wins + charlie_loses)) * 100;
    cout << "Aaron win percentage: " << aaron_win_percentage << "%" << endl;    
    cout << "Bob win percentage: " << bob_win_percentage << "%" << endl;
    cout << "Charlie win percentage: " << charlie_win_percentage << "%" << endl;
    cout << "Aaron lose percentage: " << aaron_lose_percentage << "%" << endl;
    cout << "Bob lose percentage: " << bob_lose_percentage << "%" << endl;
    cout << "Charlie lose percentage: " << charlie_lose_percentage << "%" << endl;
    return 0;
}

int get_random_number(void)
{
    return rand() % 3 + 1;
}

int set_random_number(void)
{
    random_number = distribution(generator);
    return random_number;
}

int get_random_number2(void)
{
    return rand() % 100 + 1;
}

int set_random_number2(void)
{
    random_number2 = distribution2(generator);
    return random_number2;
}

int get_random_number3(void)
{
    return rand() % 100 + 1;
}

int set_random_number3(void)
{
    random_number3 = distribution2(generator);
    return random_number3;
}

double get_aaron_wins(void)
{
    return aaron_wins;
}

double set_aaron_wins(void)
{
    aaron_wins = 0;
    return aaron_wins;
}

double get_bob_wins(void)
{
    return bob_wins;
}

double set_bob_wins(void)
{
    bob_wins = 0;
    return bob_wins;
}

double get_charlie_wins(void)
{
    return charlie_wins;
}

double set_charlie_wins(void)
{
    charlie_wins = 0;
    return charlie_wins;
}

double get_aaron_loses(void)
{
    return aaron_loses;
}

double set_aaron_loses(void)
{
    aaron_loses = 0;
    return aaron_loses;
}

double get_bob_loses(void)
{
    return bob_loses;
}

double set_bob_loses(void)
{
    bob_loses = 0;
    return bob_loses;
}

double get_charlie_loses(void)
{
    return charlie_loses;
}

double set_charlie_loses(void)
{
    charlie_loses = 0;
    return charlie_loses;
}

/**
 * @brief Aaron will always miss his first shot
    * Bob will always hit his first shot
    * Charlie will always miss his first shot
    * After that, the shooters will shoot randomly
    * Keep track of each shooter's score
    * Return the number of wins for Aaron
 */

int play_game(void)
{
    set_random_number();
    set_random_number2();
    set_random_number3();
    aaron_shoot_first = 0;
    bob_shoot_first = 1;
    charlie_shoot_first = 0;
    aaron_shoot_second = random_number2;
    bob_shoot_second = random_number2;
    charlie_shoot_second = random_number2;
    aaron_shoot_third = random_number3;
    bob_shoot_third = random_number3;
    charlie_shoot_third = random_number3;
    if (random_number == 1)
    {
        if (aaron_shoot_first == 0 && aaron_shoot_second >= 34 && aaron_shoot_second <= 66 && aaron_shoot_third >= 67 && aaron_shoot_third <= 100)
        {
            aaron_wins++;
            return 1;
        }
        else
        {
            aaron_loses++;
            return 0;
        }
    }
    else if (random_number == 2)
    {
        if (bob_shoot_first == 1 && bob_shoot_second >= 1 && bob_shoot_second <= 50 && bob_shoot_third >= 51 && bob_shoot_third <= 100)
        {
            bob_wins++;
            return 1;
        }
        else
        {
            bob_loses++;
            return 0;
        }
    }
    else if (random_number == 3)
    {
        if (charlie_shoot_first == 0 && charlie_shoot_second >= 67 && charlie_shoot_second <= 100 && charlie_shoot_third >= 34 && charlie_shoot_third <= 66)
        {
            charlie_wins++;
            return 1;
        }
        else
        {
            charlie_loses++;
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int play_ten_thousand_games(void)
{
    for (int i = 0; i < 10000; i++)
    {
        play_game();
    }
}

int main(int argc, char **argv)
{
    set_aaron_wins();
    set_bob_wins();
    set_charlie_wins();
    set_aaron_loses();
    set_bob_loses();
    set_charlie_loses();
    play_ten_thousand_games();
    cout << "Aaron wins " << get_aaron_wins() << " times" << endl;
    cout << "Bob wins " << get_bob_wins() << " times" << endl;
    cout << "Charlie wins " << get_charlie_wins() << " times" << endl;
    cout << "Aaron loses " << get_aaron_loses() << " times" << endl;
    cout << "Bob loses " << get_bob_loses() << " times" << endl;
    cout << "Charlie loses " << get_charlie_loses() << " times" << endl;
    //return percentage of wins for each shooter
    aaron_win_percentage = get_aaron_wins() / 10000;
    bob_win_percentage = get_bob_wins() / 10000;
    charlie_win_percentage = get_charlie_wins() / 10000;
    aaron_lose_percentage = get_aaron_loses() / 10000;
    bob_lose_percentage = get_bob_loses() / 10000;
    charlie_lose_percentage = get_charlie_loses() / 10000;
    get_player_percentages();
    return 0;
}
