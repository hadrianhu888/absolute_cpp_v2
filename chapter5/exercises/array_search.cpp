/**
 * @file array_search.cpp
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

const int DECLARED_SIZE = 5; 

void fillArray(int a[], int size);
void showArray(int a[], int size);
bool searchArray_alt(int a[], int size, int target);
int searchArray(int a[], int size, int target);
int main(int argc, char **argv); // main function prototype

bool searchArray_alt(int a[], int size, int target)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (a[i] == target)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    int i;
    int scores[DECLARED_SIZE];
    int target;
    int index;
    fillArray(scores, DECLARED_SIZE);
    showArray(scores, DECLARED_SIZE);
    cout << "Enter a number to search for: ";
    cin >> target;
    index = searchArray(scores, DECLARED_SIZE, target);
    if (index == -1)
    {
        cout << "The number " << target << " was not found." << endl;
    }
    else
    {
        cout << "The number " << target << " was found at index " << index+1 << endl;
    }
    index = searchArray_alt(scores, DECLARED_SIZE, target);
    if (index == -1)
    {
        cout << "The number " << target << " was not found." << endl;
    }
    else
    {
        cout << "The number " << target << " was found at index " << index+1 << endl;
    }
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

void showArray(int a[], int size)
{
    int i;
    cout << "The array contains the following values: " << endl;
    for (i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
}

int searchArray(int a[], int size, int target)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (a[i] == target)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Enter five numbers into an array
 * 
 */