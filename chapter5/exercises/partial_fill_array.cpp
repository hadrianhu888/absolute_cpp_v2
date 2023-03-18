/**
 * @file partial_fill_array.cpp
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
#include <cmath> 
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>
#include <time.h>
#include <stdio.h>

using namespace std;
using namespace std::chrono;

const int MAX_NUMBER_OF_SCORES = 5;

void fillArray(int a[], int size);
double computeAverage(int a[], int size);
void showDifference(int a[], int size, double average);
int main(int argc, char **argv); // main function prototype

int main(int argc, char **argv)
{
    int scores[MAX_NUMBER_OF_SCORES];
    int i;
    double average;
    fillArray(scores, MAX_NUMBER_OF_SCORES);
    average = computeAverage(scores, MAX_NUMBER_OF_SCORES);
    showDifference(scores, MAX_NUMBER_OF_SCORES, average);
    return 0;
}

void fillArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "Enter a score: ";
        cin >> a[i];
    }
}

double computeAverage(int a[], int size)
{
    int i;
    double sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += a[i];
    }
    return sum / size;
}

void showDifference(int a[], int size, double average)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "The score " << a[i] << " is " << a[i] - average << " points away from the average." << endl;
    }
}

// Path: chapter5\exercises\partial_fill_array.cpp
