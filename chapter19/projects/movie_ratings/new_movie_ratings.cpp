/**
 * @file new_movie_ratings.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

std::map<std::string, std::vector<int>> readFile(const std::string &filename)
{
    std::ifstream inFile(filename);
    std::map<std::string, std::vector<int>> movie_reviews;
    std::string line;
    int score;

    if (!inFile)
    {
        std::cerr << "Unable to open file";
        exit(1);
    }

    while (getline(inFile, line))
    {
        score = std::stoi(line);
        getline(inFile, line);
        movie_reviews[line].push_back(score);
    }

    inFile.close();
    return movie_reviews;
}

void calculateAndPrintData(const std::map<std::string, std::vector<int>> &movie_reviews)
{
    for (auto const &pair : movie_reviews)
    {
        std::cout << "Movie: " << pair.first << "\n";
        std::cout << "Number of reviews: " << pair.second.size() << "\n";
        double avg = std::accumulate(pair.second.begin(), pair.second.end(), 0.0) / pair.second.size();
        std::cout << "Average score: " << avg << "\n\n";
    }
}

int main()
{
    std::string filename = "movie_ratings.txt"; // replace with your file name
    auto movie_reviews = readFile(filename);
    calculateAndPrintData(movie_reviews);
    return 0;
}
