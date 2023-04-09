/**
 * @file simpleClass.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include "simpleClass.h"

using namespace std;

SimpleClass::SimpleClass()
{
    cout << "SimpleClass constructor called" << endl;
}

SimpleClass::SimpleClass(int value)
{
    cout << "SimpleClass constructor called" << endl;
    cout << "Value is " << value << endl;
    cout << "Value + 1 is " << value + 1 << endl;
}

SimpleClass::~SimpleClass()
{
    cout << "SimpleClass destructor called" << endl;
}
