/**
 * @file pointers.cpp
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

int main(int argc, char **argv)
{
    int x = 5;
    int *p = &x;
    int *q = new int;
    q = p;
    p = new int;
    int y= 88;
    *p = y;
    cout << "x = " << x << endl;
    cout << "x = " << x << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    return 0;
}
