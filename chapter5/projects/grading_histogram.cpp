/**
 * @file grading_histogram.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
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

/**
 * @brief This program reads the scores from the user input 
    and displays a histogram of the scores 
 * 
 */

int *student_scores; 
int *histogram_array;
int user_array_size; 
int *frequencies; 
void student_scores_input(int *student_scores,int user_array_size);
void display_scores(int *student_scores,int user_array_size);
int *return_histogram_array(int *student_scores,int user_array_size);
void display_histogram(int *histogram_array,int user_array_size);
void draw_histograms(int *frequencies,int user_array_size); 
void draw_vertical_histogram(int *frequencies,int user_array_size);
int main(int argc,char **argv);

void student_scores_input(int *student_scores,int user_array_size) {
    for (int i = 0; i < user_array_size; i++) {
        cout << "Enter the " << i + 1 << " student score: ";
        cin >> student_scores[i];
    }
}

void display_scores(int *student_scores,int user_array_size) {
    for (int i = 0; i < user_array_size; i++) {
        cout << "The " << i + 1 << " student score is: " << student_scores[i] << endl;
    }
}

int *return_histogram_array(int *student_scores,int user_array_size) {
    int *histogram_array = new int[user_array_size];
    for (int i = 0; i < user_array_size; i++) {
        histogram_array[i] = student_scores[i] / 10;
    }
    return histogram_array;
}

void display_histogram(int *histogram_array,int user_array_size) {
    int *frequencies = new int[10];
    for (int i = 0; i < 10; i++) {
        frequencies[i] = 0;
    }
    for (int i = 0; i < user_array_size; i++) {
        frequencies[histogram_array[i]]++;
    }
    for (int i = 0; i < 10; i++) {
        cout << i * 10 << "-" << (i + 1) * 10 - 1 << ": ";
        for (int j = 0; j < frequencies[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void draw_histograms(int *frequencies,int user_array_size) {
    for (int i = 0; i < 10; i++) {
        cout << i * 10 << "-" << (i + 1) * 10 - 1 << ": ";
        for (int j = 0; j < frequencies[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void draw_vertical_histograms(int *frequencies,int user_array_size) {
    int max_frequency = 0;
    for (int i = 0; i < 10; i++) {
        if (frequencies[i] > max_frequency) {
            max_frequency = frequencies[i];
        }
    }
    for (int i = max_frequency; i > 0; i--) {
        for (int j = 0; j < 10; j++) {
            if (frequencies[j] >= i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 10; i++) {
        cout << i * 10 << "-" << (i + 1) * 10 - 1 << " ";
    }
    cout << endl;
}

int main(int argc,char **argv)
{
    cout << "Enter the number of students: ";
    cin >> user_array_size;
    student_scores = new int[user_array_size];
    student_scores_input(student_scores,user_array_size);
    display_scores(student_scores,user_array_size);
    histogram_array = return_histogram_array(student_scores,user_array_size);
    display_histogram(histogram_array,user_array_size);
    draw_vertical_histograms(frequencies,user_array_size);
    return 0;
}