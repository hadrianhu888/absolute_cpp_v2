/**
 * @file ex1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream> 
#include <stdlib.h>
#include <cstdio>

using namespace std; 

const int count = 0; 
const int limit = 10; 
const int x = 1; 
const int y = 1; 

int main(int argc, char ** argv) {
    bool a1 = ((count == 0) && (limit < 20));
    bool a2 = count == 0 && limit < 20; 
    bool a3 = (limit > 20) || (count < 5); 
    bool a4 = !(count == 12); 
    bool a5 = (count == 1) && (x < y); 
    bool a6 = (count < 10) || (x < y); 
    bool a7 = !((count < 10) || (x < y) && (count >= 0)); 
    bool a8 = ((limit / count) > 7) || (limit < 20);
    bool a9 = ((limit < 20) || (limit/count) > 7);
    bool a10 = ((limit / count) > 7) && (limit < 0); 
    bool a11 = (limit < 0) && ((limit/count) > 7); 
    bool a12 = (5 && 7) + (!6); 
    cout << a1 << endl; 
    cout << a2 << endl; 
    cout << a3 << endl; 
    cout << a4 << endl; 
    cout << a5 << endl; 
    cout << a6 << endl; 
    cout << a7 << endl; 
    cout << a8 << endl; 
    cout << a9 << endl; 
    cout << a10 << endl; 
    cout << a11 << endl; 
    cout << a12 << endl; 
    return 0; 
}