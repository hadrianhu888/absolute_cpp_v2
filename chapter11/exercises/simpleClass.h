/**
 * @file simpleClass.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H

#include <iostream>

using namespace std;

class SimpleClass
{
    private:
        int m_value;
    public:
        SimpleClass();
        SimpleClass(int value);
        ~SimpleClass();
};


#endif /*SIMPLE_CLASS_H*/
