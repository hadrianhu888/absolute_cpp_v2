/**
 * @file min_max_ints_from_file.cpp
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

int main(int argc, char **argv);
void openFile(ifstream& file);
void readInts(ifstream& file, int& min, int& max);
void storeArrayFromFile(ifstream &file, int *numArray);
void sortFileNumbers(ifstream &file, ofstream &sorted);
void quickSort(int *numArray, int left, int right);
int returnMax(ifstream& file, int& max);
int returnMin(ifstream& file, int& min);
void displayFile(ifstream& file);

void openFile(ifstream& file)
{
    file.open("numbers.txt");
    if (!file)
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
}

void readInts(ifstream& file, int& min, int& max)
{
    int next;
    file >> next;
    min = next;
    max = next;
    while (file >> next)
    {
        if (next > max)
        {
            max = next;
        }
        if (next < min)
        {
            min = next;
        }
    }
}

int returnMax(ifstream& file, int& max)
{
    return max;
}

int returnMin(ifstream& file, int& min)
{
    return min;
}

void displayFile(ifstream& file)
{
    int next;
    while (file >> next)
    {
        cout << next << endl;
    }
}

void storeArrayFromFile(ifstream& file, int *numArray)
{
    int next;
    int i = 0;
    while (file >> next)
    {
        numArray[i] = next;
        i++;
    }
}

void quickSort(int *numArray, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = numArray[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (numArray[i] < pivot)
            i++;
        while (numArray[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = numArray[i];
            numArray[i] = numArray[j];
            numArray[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(numArray, left, j);
    if (i < right)
        quickSort(numArray, i, right);
}

void sortFileNumbers(ifstream& file, ofstream &sorted)
{
    int next;
    int *numArray;
    storeArrayFromFile(file, numArray);
    quickSort(numArray, 0, next);
    while (file >> next)
    {
        sorted << next << endl;
    }
}

int main(int argc, char **argv)
{
    ifstream file;
    int min, max;
    openFile(file);
    readInts(file, min, max);
    cout << "The minimum value is: " << returnMin(file, min) << endl;
    cout << "The maximum value is: " << returnMax(file, max) << endl;
    displayFile(file);
    return 0;
}
