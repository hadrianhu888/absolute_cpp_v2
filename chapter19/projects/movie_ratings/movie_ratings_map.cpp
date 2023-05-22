/**
 * @file movie_ratings_map.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

string filename = "movie_ratings.txt";
vector<int> movie_ratings_vector;
vector<string> movie_names;
map<vector<string>, vector<int>> movie_ratings_map;
vector<int> count_ratings_per_movie;

int main(int argc, char **argv);
void readMovieRatingsFile(string filename);
vector<string> storeMovieNames(string line);
vector<int> storeMovieRatings(string line);
void storeMovieNamesAndRatingsInMap(vector<string> &movie_names, vector<int> &movie_ratings_vector);
void printMovieRatingsVector(vector<int> &movie_ratings_vector);
float calculateAverageMovieRating(vector<int> &movie_ratings_vector);
void displayMovieRatingDataAndAverages(map<vector<string>, vector<int>> &movie_ratings_map);

int main(int argc, char **argv)
{
    readMovieRatingsFile(filename);
    printMovieRatingsVector(movie_ratings_vector);
    calculateAverageMovieRating(movie_ratings_vector);
    displayMovieRatingDataAndAverages(movie_ratings_map);
}

/**
 * @brief read movie ratings file
 *
 * @param filename
 */

void readMovieRatingsFile(string filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }

    string line;
    string current_movie;
    while (getline(file, line))
    {
        // Check if line is a number (movie rating)
        if (isdigit(line[0]))
        {
            int movie_rating = stoi(line);
            movie_ratings_vector.push_back(movie_rating);
            movie_ratings_map[movie_names].push_back(movie_rating);
        }
        // If it's not a number, it's a movie title
        else
        {
            current_movie = line;
            movie_names.push_back(current_movie);
        }
    }
}

/**
 * @brief print movie ratings vector
 *
 * @param movie_ratings_vector
 */

void printMovieRatingsVector(vector<int> &movie_ratings_vector)
{
    for (int i = 0; i < movie_ratings_vector.size(); i++)
    {
        cout << movie_ratings_vector[i] << endl;
    }
}

/**
 * @brief calculate average movie rating
 *
 * @param movie_ratings_vector
 * @return float
 */

float calculateAverageMovieRating(vector<int> &movie_ratings_vector)
{
    float sum = 0;
    for (int i = 0; i < movie_ratings_vector.size(); i++)
    {
        sum += movie_ratings_vector[i];
    }
    float average = sum / movie_ratings_vector.size();
    cout << "Average movie rating: " << average << endl;
    return average;
}

void displayMovieRatingDataAndAverages(map<vector<string>, vector<int>> &movie_ratings_map)
{
    for (auto &movie : movie_ratings_map)
    {
        for (auto &name : movie.first)
        {
            cout << name << " ";
        }

        for (auto &rating : movie.second)
        {
            cout << rating << " ";
        }

        cout << endl;
    }
}

vector<string> storeMovieNames(string line)
{
    vector<string> movie_names;
    movie_names.push_back(line);
    return movie_names;
}
vector<int> storeMovieRatings(string line)
{
    vector<int> movie_ratings_vector;
    int movie_rating = stoi(line);
    movie_ratings_vector.push_back(movie_rating);
    return movie_ratings_vector;
}
void storeMovieNamesAndRatingsInMap(vector<string> &movie_names, vector<int> &movie_ratings_vector)
{
    movie_ratings_map[movie_names] = movie_ratings_vector;
}
vector<int> storeNumberOfMovieRatings(vector<int> &movie_ratings_vector)
{
    vector<int> count_ratings_per_movie;
    count_ratings_per_movie.push_back(movie_ratings_vector.size());
    return count_ratings_per_movie;
}
