/**
 * @file find_averages.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

void openFile(ifstream& file);
void displayFileContent(ifstream& file);
double getStandardDeviation(vector<double> &vec, double mean);
double getVariance(vector<double> &vec, double mean, double stdev);
void storeFileContentInVector(ifstream &file, vector<double> &numVector);
void quickSortVector(vector<double> &vec);
double getSum(const vector<double> &vec);
double getAverage(const vector<double> &vec);
double getQuartiles(const vector<double> &vec);
void displayFileOutputs(ifstream& file, const vector<double> &vec);
double splitArray(vector<double> &vec);
void getQuartiles(const vector<double> &vec, double &q1, double &q2, double &q3);
int main(int argc, char **argv);

void openFile(ifstream& file)
{
    file.open("doubles_list.txt");
    if (!file)
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    else
    {
        cout << "File opened successfully" << endl;
    }
}

void displayFileContent(ifstream& file)
{
    double next;
    while (file >> next)
    {
        cout << next << endl;
    }
}

void storeFileContentInVector(ifstream& file, vector<double> &numVector)
{
    double next;
    while (file >> next)
    {
        numVector.push_back(next);
    }
}

void quickSortVector(vector<double> &vec)
{
    sort(vec.begin(), vec.end());
}

double getSum(const vector<double> &vec)
{
    double sum = 0;
    for (const auto &value : vec)
    {
        sum += value;
    }
    return sum;
}

double getAverage(const vector<double> &vec)
{
    double sum = getSum(vec);
    return sum / vec.size();
}

void displayFileOutputs(ifstream &file, const vector<double> &vec)
{
    cout << "Sorted: " << endl;
    for (const auto &value : vec)
    {
        cout << value << endl;
    }
}

double getQuartiles(vector<double> &vec)
{
    int size = vec.size();
    int mid = size / 2;
    if (size % 2 == 0)
    {
        return (vec[mid] + vec[mid - 1]) / 2;
    }
    else
    {
        return vec[mid];
    }
}

double splitArray(vector<double> &vec)
{
    int size = vec.size();
    int mid = size / 2;
    if (size % 2 == 0)
    {
        vec.erase(vec.begin() + mid, vec.end());
    }
    else
    {
        vec.erase(vec.begin() + mid + 1, vec.end());
    }
    return 0;
}

void displayQuartiles(vector<double> &vec)
{
    int size = vec.size();
    int mid = size / 2;
    if (size % 2 == 0)
    {
        cout << "Q1: " << getQuartiles(vec) << endl;
        cout << "Q2: " << getQuartiles(vec) << endl;
        cout << "Q3: " << getQuartiles(vec) << endl;
    }
    else
    {
        cout << "Q1: " << getQuartiles(vec) << endl;
        cout << "Q2: " << getQuartiles(vec) << endl;
        cout << "Q3: " << getQuartiles(vec) << endl;
    }
}

void getQuartiles(const vector<double> &vec, double &q1, double &q2, double &q3)
{
    size_t size = vec.size();

    // Calculate the second quartile (Q2 or median)
    if (size % 2 == 0)
    {
        q2 = (vec[size / 2 - 1] + vec[size / 2]) / 2;
    }
    else
    {
        q2 = vec[size / 2];
    }

    // Calculate the first (Q1) and third (Q3) quartiles
    size_t q1_idx = size / 4;
    size_t q3_idx = size * 3 / 4;

    if (size % 4 == 0)
    {
        q1 = (vec[q1_idx - 1] + vec[q1_idx]) / 2;
        q3 = (vec[q3_idx - 1] + vec[q3_idx]) / 2;
    }
    else
    {
        q1 = vec[q1_idx];
        q3 = vec[q3_idx];
    }
}

double getStandardDeviation(vector<double> &vec, double mean)
{
    double sum = 0;
    for (const auto &value : vec)
    {
        sum += pow(value - mean, 2);
    }
    return sqrt(sum / vec.size());
}

double getVariance(vector<double> &vec, double mean, double stdev)
{
    double sum = 0;
    for (const auto &value : vec)
    {
        sum += pow(value - mean, 2);
    }
    return sum / vec.size();
}

int main(int argc, char **argv)
{
    ifstream file;
    openFile(file);
    vector<double> numVector;
    storeFileContentInVector(file, numVector);
    quickSortVector(numVector);
    displayFileOutputs(file, numVector);
    cout << "Sum: " << getSum(numVector) << endl;
    cout << "Average: " << getAverage(numVector) << endl;

    double q1, q2, q3;
    getQuartiles(numVector, q1, q2, q3);
    cout << "First Quartile (Q1): " << q1 << endl;
    cout << "Second Quartile (Q2 or Median): " << q2 << endl;
    cout << "Third Quartile (Q3): " << q3 << endl;
    cout << "Standard Deviation " << getStandardDeviation(numVector, getAverage(numVector)) << endl;
    cout << "Variance " << getVariance(numVector, getAverage(numVector), getStandardDeviation(numVector, getAverage(numVector))) << endl;

    return 0;
}
