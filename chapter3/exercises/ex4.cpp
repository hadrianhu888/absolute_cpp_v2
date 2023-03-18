/**
 * @file ex4.cpp
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

char mystery (int firstParameter, int secondParameter); 

char mystery(int firstParameter, int secondParameter) {
    if (firstParameter >= secondParameter) {
        return 'W'; 
    } else {
        return 'H'; 
    }
}

int main (int argc, char ** argv) {
    cout << mystery(10,9) << "ow\n"; 
    return 0;
}

