/**
 * @file ex8.cpp
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
    int temperature = 150;
    int pressure = 223; 
    if (temperature >= 100 && pressure >= 200) {
        cout << "Warni ng" << endl; 
    } else {
        cout << "Okay"<< endl; 
    }
    return 0;
}