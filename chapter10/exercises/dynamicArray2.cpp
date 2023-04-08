/**
 * @file dynamicArray2.cpp
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

typedef int *IntPtr;

void fillArray(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        p[i] = i;
    }
}

void printArray(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "p[" << i << "] = " << p[i] << endl;
    }
}

int search(int *p, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (p[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void sort(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (p[i] > p[j])
            {
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main(int argc, char **argv)
{
    int *p = new int[5];
    fillArray(p, 5);
    printArray(p,5);
    sort(p,5); ;
    printArray(p, 5);
    search(p, 5, 3);
    delete[] p;
    return 0;
}
