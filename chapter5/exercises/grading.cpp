/**
 * @file grading.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-24
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
#include <iomanip> 

using namespace std;
using namespace std::chrono;

const int NUMBER_OF_STUDENTS = 10;
const int NUMBER_OF_QUIZZES = 3;

void computeStAve(double a[], int size);
void computeQuizAve(double a[], int size);
void display(double a[], int size);
int main(int argc, char **argv); // main function prototype

void computeStAve(double a[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    cout << "The average score for this student is: " << sum / size << endl;
}

void computeQuizAve(double a[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    cout << "The average score for this quiz is: " << sum / size << endl;
}

void display(double a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
}

int main(int argc, char **argv)
{
    double scores[NUMBER_OF_STUDENTS][NUMBER_OF_QUIZZES];
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        for (int j = 0; j < NUMBER_OF_QUIZZES; j++)
        {
            cout << "Enter the score for student " << i + 1 << " on quiz " << j + 1 << ": ";
            cin >> scores[i][j];
        }
    }
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        computeStAve(scores[i], NUMBER_OF_QUIZZES);
    }
    for (int i = 0; i < NUMBER_OF_QUIZZES; i++)
    {
        computeQuizAve(scores[i], NUMBER_OF_STUDENTS);
    }
    return 0;
}

// Path: chapter5\exercises\grading.cpp


