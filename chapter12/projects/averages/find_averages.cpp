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

using namespace std;

void openFile(ifstream& file);
void displayFileContent(ifstream& file);
void storeFileContentInVector(ifstream& file, vector<double> &numVector);
void quickSortVector(vector<double> &vec);
double getSum(const vector<double> &vec);
double getAverage(const vector<double> &vec);
double getQuartiles(const vector<double> &vec);
void displayFileOutputs(ifstream& file, const vector<double> &vec);
double splitArray(vector<double> &vec);
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
    displayQuartiles(numVector);
    return 0;
}
