/**
 * @file p5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std; 

int main(int argc, char ** argv) {
    cout << endl << "These are the following solutions that meet the cryptarithmetic equation: " << endl; 
    for (int t = 0; t < 10; t++) {
        for (int o = 0; o < 10; o++) {
            for (int g = 0; g < 10; g++) {
                for (int d = 0; d < 10; d++) {
                    if ((4 * (t+o+o)) == (g+o+o+d) && ((t != o) && (o != g) && (g != d) && (t != d) && (o != d) && (o != g) && t != d)) {
                        cout << endl; 
                        cout << "t = " << t << endl; 
                        cout << "o = " << o << endl;
                        cout << "g = " << g << endl;
                        cout << "d = " << d << endl;
                        cout << endl; 
                    }
                }
            }
        }
    }
    return 0; 
} 