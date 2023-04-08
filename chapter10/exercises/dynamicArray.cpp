/**
 * @file dynamicArray.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#include  <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int *p = new int;
    *p = 5;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    delete p;
    p = new int[5];
    for (int i = 0; i < 5; i++)
    {
        p[i] = i;
        cout << "p[" << i << "] = " << p[i] << endl;
    }
    return 0;
}
