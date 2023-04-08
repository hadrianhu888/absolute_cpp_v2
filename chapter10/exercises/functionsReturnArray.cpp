/**
 * @file functionsReturnArray.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
using namespace std;

typedef int **intDynamicallyAllocatedArray;
typedef int *intDynamicallyAllocatedArray1D;

int *getArray(int size);
void printArray(int *p, int size);
int **getArray2D(int rows, int cols);
void printArray2D(intDynamicallyAllocatedArray p, int rows, int cols);
int main(int argc, char **argv);

int **getArray2D(int rows, int cols)
{
    int **p = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        p[i] = new int[cols];
    }
    return p;
}

void printArray2D(intDynamicallyAllocatedArray p, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "p[" << i << "][" << j << "] = " << p[i][j] << endl;
        }
    }
}

int *getArray(int size)
{
    int *p = new int[size];
    for (int i = 0; i < size; i++)
    {
        p[i] = i;
    }
    return p;
}

void printArray(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "p[" << i << "] = " << p[i] << endl;
    }
}

int main(int argc, char **argv)
{
    int *p = getArray(5);
    printArray(p, 5);
    int **p2D = getArray2D(2, 3);
    printArray2D(p2D, 2, 3);
    intDynamicallyAllocatedArray1D p1D = getArray(5);
    printArray(p1D, 5);
    intDynamicallyAllocatedArray p2D1 = getArray2D(2, 3);
    printArray2D(p2D1, 2, 3);
    int *entry;
    entry = new int[5];
    for(int i = 0; i < 5; i++)
    {
        entry[i] = i;
    }
    for(int i = 0; i < 5; i++)
    {
        cout << "entry[" << i << "] = " << entry[i] << endl;
    }
    delete [] entry;
    delete [] p;
    delete [] p1D;
    delete [] p2D;
    delete [] p2D1;

    return 0;
}
