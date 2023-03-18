/**
 * @file movie_review.cpp
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
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <array> 
#include <numeric>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstddef>
#include <cassert>
#include <memory>
#include <utility>
#include <functional>
#include <limits>
#include <typeinfo>
#include <stdexcept>
#include <exception>
#include <chrono> 
#include <random>
#include <iterator>
#include <list>
#include <forward_list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <complex> 

using namespace std;
using namespace std::chrono;

/**
 * @brief generate an array of 3 by 5 of movie reviews with random numbers from 1 to 10 in each cell. 
 * Save the array to a file called movie_review.txt
 * Read the file and display the average of each row and the average of each column
 * Find out what the user's favorite movie is and display the average of the user's favorite movie
 */

/**
 * @brief initialize the array with random numbers from 1 to 10
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int movie_review[3][5];
int movie_review_2D[3][5];

/**
 * @brief set a seed for random number generator
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int seed = time(0);
mt19937 generator(seed);
int main(int argc, char **argv); 
/**
 * @brief write to file and read from file
 * 
 */
void write_to_file(void);
void read_from_file(void);
void write_movie_review_to_file(void);
void read_movie_review_from_file(void);
void display_average_of_each_row(void);
void display_average_of_each_column(void);
void display_average_of_user_favorite_movie(void);
void display_movie_review(void);
void display_movie_review_average(void);
void display_movie_review_average_of_each_row(void);
void display_movie_review_average_of_each_column(void);
void display_movie_review_average_of_user_favorite_movie(void);
void fill_movie_review_with_random_numbers(void);
void display_user_outputs(void);

/**
 * @brief use a 2D array to store movie review
 * 
 */
void write_movie_review_to_file_2D(void);
void read_movie_review_from_file_2D(void);

void display_user_outputs(void)
{
    cout << "Movie Review" << endl;
    display_movie_review();
    cout << "Movie Review Average" << endl;
    display_movie_review_average();
    cout << "Movie Review Average of Each Row" << endl;
    display_movie_review_average_of_each_row();
    cout << "Movie Review Average of Each Column" << endl;
    display_movie_review_average_of_each_column();
    cout << "Movie Review Average of User Favorite Movie" << endl;
    display_movie_review_average_of_user_favorite_movie();
}

void fill_movie_review_with_random_numbers(void)
{
    uniform_int_distribution<int> distribution(1, 10);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            /**
             * @brief fill the array with random numbers from 1 to 10
             * 
             */
            movie_review[i][j] = distribution(generator);
        }
    }
}

void write_to_file(void)
{
    ofstream out_file;
    out_file.open("movie_review.txt");
    if (out_file.fail())
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }
    out_file << "Movie 1" << endl;
    out_file << "Movie 2" << endl;
    out_file << "Movie 3" << endl;
    out_file << "Movie 4" << endl;
    out_file << "Movie 5" << endl;
    out_file.close();
}

void read_from_file(void)
{
    ifstream in_file;
    in_file.open("movie_review.txt");
    if (in_file.fail())
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }
    string line;
    while (getline(in_file, line))
    {
        cout << line << endl;
    }
    in_file.close();
}

void write_movie_review_to_file(void)
{
    ofstream out_file;
    out_file.open("movie_review.txt");
    if (out_file.fail())
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            out_file << movie_review[i][j] << " ";
        }
        out_file << endl;
    }
    out_file.close();
}

void read_movie_review_from_file(void)
{
    ifstream in_file;
    in_file.open("movie_review.txt");
    if (in_file.fail())
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            in_file >> movie_review[i][j];
        }
    }
    in_file.close();
}

void display_average_of_each_row(void)
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += movie_review[i][j];
        }
        cout << "Average of row " << i + 1 << " is " << sum / 5 << endl;
    }
}

void display_average_of_each_column(void)
{
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += movie_review[j][i];
        }
        cout << "Average of column " << i + 1 << " is " << sum / 3 << endl;
    }
}

void display_average_of_user_favorite_movie(void)
{
    int movie_number;
    cout << "Enter your favorite movie number: ";
    cin >> movie_number;
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += movie_review[i][movie_number - 1];
    }
    cout << "Average of your favorite movie is " << sum / 3 << endl;
}

void display_movie_review(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << movie_review[i][j] << " ";
        }
        cout << endl;
    }
}

void display_movie_review_average(void)
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum += movie_review[i][j];
        }
    }
    cout << "Average of all movie reviews is " << sum / 15 << endl;
}

void display_movie_review_average_of_each_row(void)
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += movie_review[i][j];
        }
        cout << "Average of row " << i + 1 << " is " << sum / 5 << endl;
    }
}

void display_movie_review_average_of_each_column(void)
{
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += movie_review[j][i];
        }
        cout << "Average of column " << i + 1 << " is " << sum / 3 << endl;
    }
}

void display_movie_review_average_of_user_favorite_movie(void)
{
    int movie_number;
    cout << "Enter your favorite movie number: ";
    cin >> movie_number;
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += movie_review[i][movie_number - 1];
    }
    cout << "Average of your favorite movie is " << sum / 3 << endl;
}

void write_movie_review_to_file_2D()
{
    ofstream out_file;
    out_file.open("movie_review.txt");
    if (out_file.fail())
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            /**
             * @brief write random numbers from 1 to 10 to file 
             * 
             */
            out_file << rand() % 10 + 1 << " ";
        }
        out_file << endl;
    }
    out_file.close();
}

void read_movie_review_from_file_2D()
{
    ifstream in_file;
    in_file.open("movie_review.txt");
    if (in_file.fail())
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            in_file >> movie_review_2D[i][j];
        }
    }
    in_file.close();
}

void display_movie_review_2D()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << movie_review_2D[i][j] << " ";
        }
        cout << endl;
    }
}

void display_movie_review_average_2D()
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum += movie_review_2D[i][j];
        }
    }
    cout << "Average of all movie reviews is " << sum / 15 << endl;
}

void display_movie_review_average_of_each_row_2D()
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += movie_review_2D[i][j];
        }
        cout << "Average of row " << i + 1 << " is " << sum / 5 << endl;
    }
}

void display_movie_review_average_of_each_column_2D()
{
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += movie_review_2D[j][i];
        }
        cout << "Average of column " << i + 1 << " is " << sum / 3 << endl;
    }
}

int main(int argc, char **argv)
{
    int choice;
    do
    {
        cout << "1. Write movie review to file" << endl;
        cout << "2. Read movie review from file" << endl;
        cout << "3. Display movie review" << endl;
        cout << "4. Display average of all movie reviews" << endl;
        cout << "5. Display average of each row" << endl;
        cout << "6. Display average of each column" << endl;
        cout << "7. Display average of user favorite movie" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            write_movie_review_to_file();
            /**
             * @brief display output of write_movie_review_to_file() function
             * 
             */
            display_user_outputs();
            break;
        case 2:
            read_movie_review_from_file();
            /**
             * @brief display output of read_movie_review_from_file() function
             * 
             */
            display_user_outputs();
            break;
        case 3:
            display_movie_review();
            display_user_outputs();
            break;
        case 4:
            display_movie_review_average();
            display_user_outputs();
            break;
        case 5:
            display_movie_review_average_of_each_row();
            display_user_outputs();
            break;
        case 6:
            display_movie_review_average_of_each_column();
            display_user_outputs();
            break;
        case 7:
            display_movie_review_average_of_user_favorite_movie();
            display_user_outputs();
            break;
        case 8:
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 8);
    return 0;
}