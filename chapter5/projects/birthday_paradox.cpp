/**
 * @file birthday_paradox.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief This program
    calculates the probabilities of n people having the same birthday
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
#include <random>

using namespace std;
using namespace std::chrono;

#define MAX 100
int *n_array;
int size; 


int return_array_size(int *n_array); 
float return_probability(int n);
float return_array_probabilities(int *n_array); 
int assign_random_birthdays(int *n_array,int size);
int main(int argc,char **argv);

int return_array_size(int *n_array) {
    return sizeof(n_array) / sizeof(n_array[0]);
}

int assign_random_birthdays(int *n_array,int size) {
    for (int i = 0; i < size; i++) {
        n_array[i] = rand() % 365 + 1;
    }
    return 0;
}

float return_probability(int n) {
    float probability = 1.0;
    for (int i = 0; i < n; i++) {
        probability *= (365.0 - i) / 365.0;
    }
    return 1.0 - probability;
}

float return_array_probabilities(int *n_array) {
    int size = return_array_size(n_array);
    for (int i = 0; i < size; i++) {
        cout << "The probability of " << n_array[i] << " people having the same birthday is: " << return_probability(n_array[i]) << endl;
    }
    return 0;
}

int main(int argc,char **argv) {
    int size; 
    cout << "Enter the number of people: ";
    cin >> size;
    n_array = new int[size];
    assign_random_birthdays(n_array,size);
    return_array_probabilities(n_array);
    return 0;
}


