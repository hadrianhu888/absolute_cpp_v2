/**
 * @file scores.cpp
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
#include <cmath> // for pow()

const int NUMBER_OF_PLANTS = 4;
using namespace std;
using namespace std::chrono;

/**
 * @brief Enter five numbers into an array 
 * 
 */
void getScores(int a[], int size);
void tripler(int &n); 
void showTheWorld(int a[], int size);
void showTheWorld(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    cout << endl;
    cout << "The array contains the following values: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
}
void tripler(int &n)
{
    n = 3*n; 
}
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
    cout << "The numbers you entered are: " << endl;
    for (i = 0; i < 5; i++)
    {
        cout << scores[i] << endl;
    }
    /**
     * @brief find max and min scores
     * 
     */
    int max = scores[0];
    int min = scores[0];
    for (i = 0; i < 5; i++)
    {
        if (scores[i] > max)
        {
            max = scores[i];
        }
        if (scores[i] < min)
        {
            min = scores[i];
        }
    }
    cout << "The max score is: " << max << endl;
    cout << "The min score is: " << min << endl;
    char symbol[3] = {'a', 'b', 'c'};
    for (int x = 0; x < 3; x++)
    {
        cout << symbol[x] << endl;
    }
    double a[3] = {1.1, 2.2, 3.3};
    cout << a[0] << endl << a[1] << endl << a[2] << endl;
    a[1] = a[2];
    cout << a[0] << endl << a[1] << endl << a[2] << endl;
    i = 0; 
    int temp[10]; 
    for (i = 0; i < 10; i++) 
    {
        temp[i] = 2*i; 
    }
    for (i = 0; i < 10; i++) 
    {
        cout << temp[i] << endl; 
    }
    int sampleArray[10]; 
    for (i = 0; i < 10; i++) //making an array using <= 10 will cause an error
    {
        sampleArray[i] = 3*i; 
    }
    int array1[10] = {-1, -9, 5, 8, 10, -11, 19, -6, 0, 3}; // error: cannot assign to array
    /**
     * @brief arrange the array in order and issue warning if a number is out of order 
     * 
     */
    for (i = 0; i < 10; i++)
    {
        if (array1[i] > array1[i+1])
        {
            cout << "Warning: the array is not in order" << endl;
        }
        /**
         * @brief order the array
         * 
         */
        for (i = 0; i < 10; i++)
        {
            if (array1[i] > array1[i+1])
            {
                int temp = array1[i];
                array1[i] = array1[i+1];
                array1[i+1] = temp;
            }
        }
    }
    /**
     * @brief call tripler function 
     * 
     */
    int x = 5;
    tripler(x);
    cout << x << endl;
    /**
     * @brief call showTheWorld function 
     * 
     */
    int a1[5] = {1,2,3,4,5};
    showTheWorld(a1, 5);
    return 0;
}

/**
 * @brief a[5] means the array has 5 elements. a[4] has four elements. 
    double score[5]; 
    Base type is double. 
    Array name is score.
    Array size is 5.
    Declared size is 5.
    Rnnge of values: 0 to 4.
    Index values: 0 to 4.
    int x[4] = {8,7,65,4,3}; // error: too many initializers
    int x[4] = {8,7,65,4}; // ok
    int x[] = {8,7,65,4}; // ok
    const int SIZE= 4; int x[SIZE] = {8,7,65,4}; // ok
 * 
 */