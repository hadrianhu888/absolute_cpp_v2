/**
 * @file compare_args.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv); // function prototype
void doStuff(int x, int& y, int& z);
void doStuff1(int x, int y, int z);

void doStuff(int x, int& y, int& z) {
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    x = 1;
    y = 2;
    z = 3;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
}

void doStuff1(int x, int y, int z) {
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    x = 1;
    y = 2;
    z = 3;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
}

int main(int argc, char** argv) {
    int x = 10, y = 20, z = 30;
    doStuff(x, y, z);
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    x = 100;
    y = 200;
    z = 300;
    doStuff(x, y, z);
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    x = 1000;
    y = 2000;
    z = 3000;
    doStuff1(x, y, z);
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    return 0;
}

