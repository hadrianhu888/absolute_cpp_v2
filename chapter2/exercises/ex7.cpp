/**
 * @file ex7.cpp
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
    int exam = 90; 
    int programsDone = 11; 
    if ((exam >= 60) && (programsDone >= 10)) {
        printf("Passed\n"); 
    } else {
        printf("Failed\n");
    }
    return 0;
}
