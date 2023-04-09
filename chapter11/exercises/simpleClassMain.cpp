/**
 * @file simpleClassMain.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <iostream>
#include "simpleClass.cpp"

using namespace std;

int main()
{
    SimpleClass simpleClass;
    SimpleClass simpleClass2(5);
    return 0;
}

/**
 * @brief The .h file for the SimpleClass class has the definitions.
 *      The .cpp file has the implementation.
 *  The main file has the code that uses the class.
 * Both the .h and .cpp files have the same name as the class has to be compiled.
 *The class implementation need to be compiled if implementation changes.
 */
