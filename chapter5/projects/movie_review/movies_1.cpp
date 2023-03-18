/**
 * @file movies_1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <fstream> 
#include <sstream>
#include <map>
#include <set>
#include <iterator>
#include <functional>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <memory>
#include <utility>
#include <limits>
#include <typeinfo>
#include <stdexcept>
#include <exception>
#include <new>
#include <initializer_list>
#include <tuple>
#include <array>
#include <regex>
#include <chrono>
#include <random>
#include <thread>
#include <future>

using namespace std;
using namespace std::chrono; 

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);
std::uniform_int_distribution<int> distribution(1,100);

int user_rating;
float user_ratings[10];
float nearest_neighbour[10];

void read_movies_from_file(void);
void print_movies(void);
void print_movies_by_rating(void);
void get_user_ratings(void);
void print_user_ratings(void);
void find_nearest_neighbour(void);
void print_nearest_neighbour(void);
void print_recommendations(void);
int main(int argc, char **argv);
int random_number_generator(void);
float get_nearest_neighbour(float *arr, int size, int target);

/**
 * @brief implement the above prototypes
 * 
 */

void read_movies_from_file(void)
{
    ifstream in_file;
    in_file.open("movies.txt");
    if(!in_file)
    {
        cerr << "Problem opening file" << endl;
        exit(1);
    }
    string line;
    while(getline(in_file, line))
    {
        cout << line << endl;
    }
    in_file.close();
}

void print_movies(void)
{
    cout << "Movies" << endl;
    cout << "=======" << endl;
    read_movies_from_file();
}

void print_movies_by_rating(void)
{
    cout << "Movies by rating" << endl;
    cout << "================" << endl;
    read_movies_from_file();
}

void get_user_ratings(void)
{
    cout << "Enter your ratings for the movies" << endl;
    cout << "================================" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << "Enter your rating for movie " << i + 1 << ": ";
        cin >> user_ratings[i];
    }
}

void print_user_ratings(void)
{
    cout << "Your ratings" << endl;
    cout << "============" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << "Your rating for movie " << i + 1 << ": " << user_ratings[i] << endl;
    }
}

void find_nearest_neighbour(void)
{
    cout << "Finding nearest neighbour" << endl;
    cout << "=========================" << endl;
    for(int i = 0; i < 10; i++)
    {
        nearest_neighbour[i] = get_nearest_neighbour(user_ratings, 10, user_ratings[i]);
    }
}

void print_nearest_neighbour(void)
{
    cout << "Nearest neighbour" << endl;
    cout << "=================" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << "Nearest neighbour for movie " << i + 1 << ": " << nearest_neighbour[i] << endl;
    }
}

void print_recommendations(void)
{
    cout << "Recommendations" << endl;
    cout << "===============" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << "Recommendation for movie " << i + 1 << ": " << nearest_neighbour[i] << endl;
    }
}

int main(int argc, char **argv)
{
    print_movies();
    print_movies_by_rating();
    get_user_ratings();
    print_user_ratings();
    find_nearest_neighbour();
    print_nearest_neighbour();
    print_recommendations();
    return 0;
}

int random_number_generator(void)
{
    return distribution(generator);
}

float get_nearest_neighbour(float *arr, int size, int target)
{
    float min = 100;
    float max = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    if(target == min)
    {
        return max;
    }
    else
    {
        return min;
    }
}