/**
 * @file two_dimensional_array.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
using namespace std;

int main(int argc, char **argv);

typedef int *IntArrayPtr;

int main(int argc, char **argv)
{
    int rows = 3;
    int cols = 4;
    int **p = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        p[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            p[i][j] = i + j;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "p[" << i << "][" << j << "] = " << p[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
