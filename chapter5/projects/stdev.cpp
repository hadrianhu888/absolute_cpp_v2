/**
 * @file stdev.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Calculates the standard deviation of a set of numbers
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime> 
#include <cmath> 
#include <chrono>
#include <cstdio>

using namespace std;
using namespace std::chrono;

// Function prototypes

int input_data[100];
int input_data_size; 
float average;
float standard_deviation; 
float correlation; 
string filename = "data.txt"; 

void read_data(string filename);
int get_data_size(string filename);
void print_data(void);
float get_avg(void);
float get_stdev(void);
int get_max(void);
int get_min(void);
int main(int argc, char **argv);
float get_corr(void); 

void read_data(string filename)
{
    ifstream infile;
    infile.open(filename);
    if (infile.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    string line;
    int i = 0;
    while (getline(infile, line))
    {
        stringstream ss(line);
        int data;
        ss >> data;
        input_data[i] = data;
        i++;
    }
    infile.close();
}

int get_data_size(string filename)
{
    ifstream infile;
    infile.open(filename);
    if (infile.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    string line;
    int i = 0;
    while (getline(infile, line))
    {
        i++;
    }
    infile.close();
    return i;
}

void print_data(void)
{
    for (int i = 0; i < input_data_size; i++)
    {
        cout << input_data[i] << endl;
    }
}

float get_avg(void)
{
    float sum = 0;
    for (int i = 0; i < input_data_size; i++)
    {
        sum += input_data[i];
    }
    return sum / input_data_size;
}

float get_stdev(void)
{
    float sum = 0;
    for (int i = 0; i < input_data_size; i++)
    {
        sum += pow(input_data[i] - average, 2);
    }
    return sqrt(sum / input_data_size);
}

int get_max(void)
{
    int max = input_data[0];
    for (int i = 1; i < input_data_size; i++)
    {
        if (input_data[i] > max)
        {
            max = input_data[i];
        }
    }
    return max;
}

int get_min(void)
{
    int min = input_data[0];
    for (int i = 1; i < input_data_size; i++)
    {
        if (input_data[i] < min)
        {
            min = input_data[i];
        }
    }
    return min;
}

float get_corr(void)
{
    float sum = 0;
    for (int i = 0; i < input_data_size; i++)
    {
        sum += input_data[i] * input_data[i];
    }
    return correlation =(float)(sum / input_data_size);
}

int main(int argc, char **argv)
{
    input_data_size = get_data_size(filename);
    read_data(filename);
    print_data();
    average = get_avg();
    standard_deviation = get_stdev();
    cout << "Average: " << average << endl;
    cout << "Standard Deviation: " << standard_deviation << endl;
    cout << "Correlation: " << correlation << endl;
    cout << "Max: " << get_max() << endl;
    cout << "Min: " << get_min() << endl;
    return 0;
}

