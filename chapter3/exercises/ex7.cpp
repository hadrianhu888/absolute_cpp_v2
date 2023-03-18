/**
 * @file ex7.cpp
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

void friendly(void); 
void shy (int audienceCount); 
void returnProductThreeNumbers(int a, int b, int c);
void main_1(void);
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @param c 
 */
void returnProductThreeNumbers(int a, int b, int c) {
    cout << (a * b * c) << endl; 
}
/**
 * @brief 
 * 
 */
void friendly(void) {
    cout << "Hello" << endl; 
}
/**
 * @brief 
 * 
 * @param audienceCount 
 */
void shy (int audienceCount) {
    if (audienceCount < 5) {
        return; 
    } 
    cout << "Goodbye" << endl; 
}
/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main (int argc, char ** argv) {
    friendly(); 
    shy(6); 
    cout << "One more time" << endl; 
    shy(2); 
    friendly(); 
    cout << "End of program" << endl; 
    /**
     * @brief if the return statement is forgotten, the program will still run. The results will just be unexpected values or NaN (divide by zero error)
     * 
     */
    returnProductThreeNumbers(1,2,3);
    main_1(); 
    /**
     * @brief sqrt precondition: the input must be of type double or float
     * sqrt postcondition: returns a double of the square root of the original input float or double value 
     * 
     */
    /**
     * place the function parameters inside the function definition
     * Compile: yes. It will run. No error message. Correct output is expected. 
     * A comment that accompanies a function definition sets up the parameters and output value
     * procedural abstraction: we only need to know the program works, not how it works 
     * a black box - procedural abstraction. We implement to an interface not an abstract class or another class 
     * 
     */ 
    int x = 1; 
    cout << x << endl; 
    {
        cout << x << endl; 
        int x = 2; 
        cout << x << endl; 
        {
            cout << x << endl; 
            int x = 3; 
            cout << x << endl; 
        }
        cout << x << endl; 
    }
    cout << x << endl; 
    return 0; 
}
/**
 */
void main_1(void) {
    cout << "This is the other main with void returns and void inputs." << endl;  
}
