/**
 * @file self_tests_2.cpp
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

#include <iomanip> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

using namespace std;
using namespace std::chrono;

const int SIZE = 4;
const int SIZE2 = 5;

void fillArray(int a[SIZE][SIZE2], int r, int c);
void echo(int a[SIZE][SIZE2], int r, int c);
int main(int argc, char **argv); // main function prototype

void fillArray(int a[SIZE][SIZE2], int r, int c)
{
    int i;
    int j;
    int k = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            a[i][j] = k;
            k++;
        }
    }
}

void echo(int a[SIZE][SIZE2], int r, int c)
{
    int i;
    int j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    int myArray[4][4];
    int i; 
    int j; 
    int k = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            myArray[i][j] = k;
            k++;
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int newArray[4][5];
    fillArray(newArray, 4, 5);
    echo(newArray, 4, 5);
    return 0;
}