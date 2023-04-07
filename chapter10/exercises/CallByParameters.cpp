/**
 * @file CallByParameters.cpp
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

void sneaky(IntPtr temp)
{
    *temp = 100;
    cout << "temp = " << temp << endl;
}

int main(int argc, char** argv)
{
    int x = 5;
    int *p = &x;
    sneaky(p);
    cout << "x = " << x << endl;
    return 0;
}
