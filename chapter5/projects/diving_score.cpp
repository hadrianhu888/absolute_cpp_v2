/**
 * @file diving_score.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Read the diving_scores.txt file and calculate the diving score based on:
    Delete the highest and lowest scores and save the remaining scores in a new array
    Add the remaining scores 
    Multiply by a difficulty factor between 1.2 and 3.8 
    Multiply by 0.6 to get actual score
 * 
 */

#include <iostream>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <chrono> 

using namespace std;
using namespace std::chrono;

#define MAX 10
#define MIN 1

string file_name;
int *score_array;
int *new_score_array;
float score;
float difficulty;
float actual_score;
float factor = 0.6;

void read_file(string file_name);
void display_file(string file_name);
int *return_modified_array(int *score_array,int size);
void display_array(int *array,int size);
float calculate_score(int *new_score_array,int size,float difficulty);
float calculate_actual_score(float score,float factor);
int main(int argc,char  **argv);

void read_file(string file_name) {
    ifstream file;
    file.open(file_name);
    if (file.is_open()) {
        string line;
        int i = 0;
        while (getline(file,line)) {
            stringstream ss(line);
            string word;
            while (ss >> word) {
                score_array[i] = stoi(word);
                i++;
            }
        }
    }
    file.close();
}

void display_file(string file_name) {
    ifstream file;
    file.open(file_name);
    if (file.is_open()) {
        string line;
        while (getline(file,line)) {
            cout << line << endl;
        }
    }
    file.close();
}

void display_array(int *array,int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int *return_modified_array(int *score_array,int size) 
{
    int *new_score_array = new int[size-2];
    int max = score_array[0];
    int min = score_array[0];
    int max_index = 0;
    int min_index = 0;
    for (int i = 0; i < size; i++) {
        if (score_array[i] > max) {
            max = score_array[i];
            max_index = i;
        }
        if (score_array[i] < min) {
            min = score_array[i];
            min_index = i;
        }
    }
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i != max_index && i != min_index) {
            new_score_array[j] = score_array[i];
            j++;
        }
    }
    return new_score_array;
}

float calculate_score(int *new_score_array,int size,float difficulty) {
    float score = 0;
    for (int i = 0; i < size; i++) {
        score += new_score_array[i];
    }
    score *= difficulty;
    return score;
}

float calculate_actual_score(float score,float factor) {
    float actual_score = score * factor;
    return actual_score;
}

int main(int argc,char **argv) {
    file_name = "diving_scores.txt";
    score_array = new int[MAX];
    new_score_array = new int[MAX-2];
    read_file(file_name);
    display_file(file_name);
    cout << "Enter the difficulty factor: ";
    cin >> difficulty;
    display_array(score_array,MAX);
    new_score_array = return_modified_array(score_array,MAX);
    display_array(new_score_array,MAX-2);
    score = calculate_score(new_score_array,MAX,difficulty);
    actual_score = calculate_actual_score(score,factor);
    cout << "The actual score is: " << actual_score << endl;
    return 0;
}


