/**
 * @file self_test_3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv); // function prototype

void figureMeOut(int& x, int y, int& z);

int main(int argc, char** argv) {
    int x = 10, y = 20, z = 30;
    figureMeOut(x, y, z);
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    x = 100;
    y = 200;
    z = 300;
    figureMeOut(x, y, z);
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    return 0;
}

void figureMeOut(int &x, int y, int &z) {
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    x = 1;
    y = 2;
    z = 3;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
}
