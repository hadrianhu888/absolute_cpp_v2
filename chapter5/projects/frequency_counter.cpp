/**
 * @file frequency_counterer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <numeric>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

/**
 * @brief counters the frequency of each number read from a file 
    The file contains multiple numbers separated by spaces
 * 
 */

string filename; 
int numbers_array[100];
int total_counter; 
int frequencies[100];
int number;
int counter;
int i;
int j;
int k;

void read_file(void);
void display_file(void);
void counter_frequency(void);
void print_frequency(void);
void display_frequencies(void);
int main(int argc, char **argv);

void read_file(void) {
    ifstream file;
    file.open(filename);
    if (file.is_open()) {
        while (file >> number) {
        numbers_array[total_counter] = number;
        total_counter++;
        }
    }
    file.close();
}

void display_file(void) {
    cout << "The numbers in the file are: ";
    for (i = 0; i < total_counter; i++) {
        cout << numbers_array[i] << " ";
    }
    cout << endl;
}

void counter_frequency(void) {
    for (i = 0; i < total_counter; i++) {
        counter = 1;
        for (j = i + 1; j < total_counter; j++) {
        if (numbers_array[i] == numbers_array[j]) {
            counter++;
            frequencies[j] = counter;
        }
        }
        if (frequencies[i] != 0) {
        frequencies[i] = counter;
        }
    }
}

void print_frequency(void) {
    cout << "The frequency of each number is: " << endl;
    for (i = 0; i < total_counter; i++) {
        if (frequencies[i] != 0) {
        cout << numbers_array[i] << " occurs " << frequencies[i] << " times" << endl;
        }
    }
}

void display_frequencies(void) {
    cout << "The frequencies are: ";
    for (i = 0; i < total_counter; i++) {
        cout << frequencies[i] << " ";
    }
    cout << endl;
}


int main(int argc, char **argv) {
    cout << "Enter the name of the file: ";
    cin >> filename;
    read_file();
    display_file();
    counter_frequency();
    print_frequency();
    display_frequencies();
    return 0;
}

