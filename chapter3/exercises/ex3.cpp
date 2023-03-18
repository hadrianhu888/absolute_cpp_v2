/**
 * @file ex3.cpp
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

int main(int argc, char ** argv) {
    int seed = 0; 
    int i = 0; 
    int size = 10; 
    cout << "Enter a seed number: "; 
    cin >> seed; 
    srand(seed); 
    for (i = 0; i < size; i++) {
        cout << ((RAND_MAX - rand()) / (double) RAND_MAX) << endl; 
    }
    return 0; 
}