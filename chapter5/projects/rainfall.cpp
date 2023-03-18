/**
 * @file rainfall.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include  <algorithm>
#include <numeric>
#include <cstdlib> 
#include <ctime>
#include <cstdio>

using namespace std;

// Function prototypes

int months[12];
double rainfall[12];
float average_rainfall; 

void read_rainfall_data(string filename);
void print_rainfall_data();
float get_avg_rainfall();
int get_max_rainfall();
int get_min_rainfall();
int main(int argc,char **argv);

void read_rainfall_data(string filename)
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
        string month;
        double rain;
        ss >> month >> rain;
        months[i] = i;
        rainfall[i] = rain;
        i++;
    }
    infile.close();
}

void print_rainfall_data()
{
    cout << "Month\tRainfall" << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << months[i] << "\t" << rainfall[i] << endl;
    }
}

float get_avg_rainfall()
{
    float sum = 0;
    for (int i = 0; i < 12; i++)
    {
        sum += rainfall[i];
    }
    return sum / 12;
}

int get_max_rainfall()
{
    int max = rainfall[0];
    for (int i = 0; i < 12; i++)
    {
        if (rainfall[i] > max)
        {
            max = rainfall[i];
        }
    }
    return max;
}

int get_min_rainfall()
{
    int min = rainfall[0];
    for (int i = 0; i < 12; i++)
    {
        if (rainfall[i] < min)
        {
            min = rainfall[i];
        }
    }
    return min;
}

int main(int argc,char **argv)
{
    read_rainfall_data("rainfall_data.txt");
    print_rainfall_data();
    cout << "Average rainfall: " << get_avg_rainfall() << endl;
    cout << "Max rainfall: " << get_max_rainfall() << endl;
    cout << "Min rainfall: " << get_min_rainfall() << endl;
    return 0;
}


