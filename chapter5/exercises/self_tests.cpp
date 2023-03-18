/**
 * @file self_tests.cpp
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

using namespace std;
using namespace std::chrono;

void oneMore(int a[], int size);
void oneLess(int a[], int size);
void too2(int a[], int size);
void output(double a[], int size);
void dropOdd(double a[], int size);
void outOfOrder(int a[], int size);

void too2(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = a[i] * 2;
    }
}

void output(double a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
}

void dropOdd(double a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            a[i] = 0;
        }
    }
}

void outOfOrder(int a[], int size)
{
    /**
     * @brief if out of order, print out a warning message and display the first value that is out of order
     * 
     */
    for (int i = 0; i < size; i++)
    {
        if (a[i] > a[i + 1])
        {
            cout << "Warning: out of order" << endl;
            cout << "The first value that is out of order is: " << a[i] << endl;
            break;
        }
    }
}

int main(int argc, char **argv); // main function prototype

void oneMore(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = a[i] + 1;
    }
}

void oneLess(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = a[i] - 1;
    }
}

int main(int argc, char **argv)
{
    int i;
    int scores[5];
    cout << "Enter five numbers: " << endl;
    for (i = 0; i < 5; i++)
    {
        cin >> scores[i];
    }
    cout << "The array contains the following values: " << endl;
    for (i = 0; i < 5; i++)
    {
        cout << scores[i] << endl;
    }
    oneMore(scores, 5);
    cout << "The array contains the following values: " << endl;
    for (i = 0; i < 5; i++)
    {
        cout << scores[i] << endl;
    }
    oneLess(scores, 5);
    cout << "The array contains the following values: " << endl;
    for (i = 0; i < 5; i++)
    {
        cout << scores[i] << endl;
    }
    too2(scores, 5);
    outOfOrder(scores, 5);
    double scores_new[5] = {1, 2, 3, 4, 5};
    output(scores_new, 5);
    dropOdd(scores_new, 5);    
    return 0;
}
