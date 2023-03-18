/**
 * @file array_sort.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream> 
#include <algorithm> 
#include <vector>
#include <iterator>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

void fillArray(int a[], int size);
void showArray(int a[], int size);
void sortArray(int a[], int size);
void swap(int &a, int &b);
int main(int argc, char **argv); // main function prototype

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
    sort(scores, scores + 5);
    cout << "The array contains the following values: " << endl;
    for (i = 0; i < 5; i++)
    {
        cout << scores[i] << endl;
    }
    return 0;
}

void fillArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 100;
    }
}

void showArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortArray(int a[], int size)
{
    /**
     * @brief Do not use the sort function. 
     * 
     */
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

