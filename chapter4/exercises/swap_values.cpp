/**
 * @file swap_values.cpp
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

int main(int argc, char const *argv[]); // function prototype

void swapValues(int& x, int& y);
void swap_Values(int x, int y);
void change_values_to_zeroes(int& x, int& y);

void swapValues(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void swap_Values(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void change_values_to_zeroes(int& x, int& y) {
    x = 0;
    y = 0;
}

int main(int argc, char const *argv[])
{
    int x = 10, y = 20;
    swap_Values(x, y);
    cout << "x = " << x << ", y = " << y << endl;
    x = 100; y = 200;
    swapValues(x, y);
    cout << "x = " << x << ", y = " << y << endl;
    x = 1; y = 2;
    change_values_to_zeroes(x, y);
    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}