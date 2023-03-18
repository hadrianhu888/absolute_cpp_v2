/**
 * @file ex6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cmath>
#include <cstring>

using namespace std; 

bool inOrder (int a, int b, int c); 
bool checkEven (int num);
bool isDigit (char c); 

bool isDigit (char c) {
    if ((c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9')) {
        return true; 
    } else {
        return false; 
    }
}

bool checkEven (int num) {
    if (0 == (num % 2)) {
        return true; 
    } else {
        return false; 
    }
}

bool inOrder (int a, int b, int c) {
    if ((a <= b) && (b <= c)) {
        return true; 
    } else {
        return false;
    }
}
int main (int argc, char ** argv) {
    cout << isDigit('1') << endl; 
    cout << checkEven(3332) << endl; 
    cout << inOrder(2,3,5) << endl; 
    cout << inOrder(5,4,5) << endl; 
    return 0; 
}
