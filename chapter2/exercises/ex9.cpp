/**
 * @file ex9.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

using namespace std;

int main(int argc, char ** argv) {
    int score = 88; 
    if (score >= 100) {
        cout << "High\n"; 
    } else if (score <= 100) {
        cout << "Low\n";
    }
    return 0;
}