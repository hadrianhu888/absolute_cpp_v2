/**
 * @file movies.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-04
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
using namespace std::chrono_literals;
using namespace std::this_thread;

/**
 * @brief Program to read movie reviews from a file and display the average
 * Ask the user for the reviews of three movies
    * Store the reviews in a file
    * Read the reviews from the file and display the average
    * Based on the movies.txt file - find the three movies closest to the user's average score based on 'nearest neighbor' algorithm
 */

/**
 * @brief point fstream to movies.txt file 
 * 
 */

fstream in_file("movies.txt", ios::in);
float average(vector<int> &reviews);
float nearest_neighbor(vector<string> &movies, vector<int> &reviews, float user_average);
void read_movies(ifstream &in_file, vector<string> &movies, vector<int> &reviews);
void read_user_reviews(vector<int> &user_reviews);
void write_user_reviews(vector<int> &user_reviews);
float calculate_average(vector<int> &user_reviews);
void locate_nearest_neighbour(vector<string> &movies, vector<int> &reviews, float user_average);
int main(int argc, char const **argv); 

/**
 * @brief implement the functions above 
 * 
 */

void locate_nearest_neighbour(vector<string> &movies, vector<int> &reviews, float user_average)
{
    float min_diff = 1000;
    float min_index = 0;
    for (int i = 0; i < reviews.size(); i++)
    {
        float diff = abs(user_average - reviews[i]);
        if (diff < min_diff)
        {
            min_diff = diff;
            min_index = i;
        }
    }
    cout << "The movie closest to your average is: " << movies[min_index] << endl;
}

float average(vector<int> &reviews)
{
    float sum = 0;
    for (int i = 0; i < reviews.size(); i++)
    {
        sum += reviews[i];
    }
    return sum / reviews.size();
}

float nearest_neighbor(vector<string> &movies, vector<int> &reviews, float user_average)
{
    float min_diff = 1000;
    float min_index = 0;
    for (int i = 0; i < reviews.size(); i++)
    {
        float diff = abs(user_average - reviews[i]);
        if (diff < min_diff)
        {
            min_diff = diff;
            min_index = i;
        }
    }
    return min_index;
}

void read_movies(ifstream &in_file, vector<string> &movies, vector<int> &reviews)
{
    string line;
    while (getline(in_file, line))
    {
        stringstream ss(line);
        string movie;
        int review;
        ss >> movie >> review;
        movies.push_back(movie);
        reviews.push_back(review);
    }
}

void read_user_reviews(vector<int> &user_reviews)
{
    for (int i = 0; i < 3; i++)
    {
        int review;
        cout << "Enter your review for movie " << i + 1 << ": ";
        cin >> review;
        user_reviews.push_back(review);
    }
}

void write_user_reviews(vector<int> &user_reviews)
{
    fstream out_file("user_reviews.txt", ios::out);
    for (int i = 0; i < user_reviews.size(); i++)
    {
        out_file << user_reviews[i] << endl;
    }
    out_file.close();
}

float calculate_average(vector<int> &user_reviews)
{
    float sum = 0;
    for (int i = 0; i < user_reviews.size(); i++)
    {
        sum += user_reviews[i];
    }
    return sum / user_reviews.size();
}

int main(int argc, char const **argv)
{
    vector<string> movies;
    vector<int> reviews;
    /**
     * @brief read the file movies.txt
     * use a new function to read the file
     */
    while (in_file)
    {
        if(in_file.is_open())
        {
            /**
             * @brief display the file contents
             * 
             */
            while(in_file)
            {
                string line;
                getline(in_file, line);
                cout << line << endl;
            }
        }
        else
        {
            cout << "File not found" << endl;
        }
    }
    vector<int> user_reviews;
    read_user_reviews(user_reviews);
    write_user_reviews(user_reviews);
    float user_average = calculate_average(user_reviews);
    cout << "Your average review is: " << user_average << endl;
    float min_index = nearest_neighbor(movies, reviews, user_average);
    //cout << "The movie closest to your average is: " << endl; 
    locate_nearest_neighbour(movies, reviews, user_average);
    return 0;
}

