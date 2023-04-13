/**
 * @file HelloWorldNamespace.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>

using namespace std;

namespace Hello
{
void message();
}

namespace Goodbye
{
void message();
}

void message();

int main()
{
    Hello::message();
    Goodbye::message();
    message();
    return 0;
}

void Hello::message()
{
    cout << "Hello from Hello::message" << endl;
}

void Goodbye::message()
{
    cout << "Hello from Goodbye::message" << endl;
}

void message()
{
    cout << "Hello from message" << endl;
}
