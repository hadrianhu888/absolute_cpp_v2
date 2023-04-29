/**
 * @file score_tracker.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Player
{
private:
    string name;
    int score;

public:
    Player();
    Player(string name);
    Player(string name, int score);
    void setName(string name);
    void setScore(int score);
    string getName();
    int getScore();
    void displayPlayer();
};

string score_file = "score_file.txt";

void openScoreFile(ifstream &file_name);
void openScoreFile(string name, ifstream &score_file);
void displayScoreFile(string name, ifstream &score_file);
map<string, int> storeFileDataInMap(ifstream &score_file);
int findMaxFromMap(map<string, int> score_map);
void displayMaxScore(map<string, int> score_map, int max_score);
int main(int argc, char **argv);

Player::Player()
{
    name = "";
    score = 0;
}

Player::Player(string name)
{
    this->name = name;
    score = 0;
}

Player::Player(string name, int score)
{
    this->name = name;
    this->score = score;
}

void Player::setName(string name)
{
    this->name = name;
}

void Player::setScore(int score)
{
    this->score = score;
}

string Player::getName()
{
    return name;
}

int Player::getScore()
{
    return score;
}

void Player::displayPlayer()
{
    cout << "Name: " << name << endl;
    cout << "Score: " << score << endl;
}

void openScoreFile(string name, ifstream &score_file)
{
    score_file.open(name);
    if (!score_file)
    {
        cout << "Error opening input file." << endl;
        exit(1);
    }
}

void openScoreFile(ifstream &file_name)
{
    file_name.open(score_file);
    if (!file_name)
    {
        cout << "Error opening input file." << endl;
        exit(1);
    }
}

void displayScoreFile(string name, ifstream &score_file)
{
    string line;
    openScoreFile(name, score_file);
    while (getline(score_file, line))
    {
        cout << line << endl;
    }
    score_file.close();
}

map<string, int> storeFileDataInMap(ifstream &score_file)
{
    string line;
    map<string, int> score_map;
    openScoreFile(score_file);
    while (getline(score_file, line))
    {
        string name = line.substr(0, line.find(","));
        string score = line.substr(line.find(",") + 1);
        score_map[name] = stoi(score);
    }
    score_file.close();
    return score_map;
}

int findMaxFromMap(map<string,int> score_map)
{
    int max_score = 0;
    for (auto it = score_map.begin(); it != score_map.end(); it++)
    {
        if (it->second > max_score)
        {
            max_score = it->second;
        }
    }
    return max_score;
}

void displayMaxScore(map<string,int> score_map, int max_score)
{
    for (auto it = score_map.begin(); it != score_map.end(); it++)
    {
        if (it->second == max_score)
        {
            cout << "Name: " << it->first << endl;
            cout << "Score: " << it->second << endl;
        }
    }
}

int main(int argc, char **argv)
{
    ifstream score_file;
    map<string,int> score_map;
    int max_score;
    score_map = storeFileDataInMap(score_file);
    max_score = findMaxFromMap(score_map);
    displayMaxScore(score_map, max_score);
    return 0;
}
