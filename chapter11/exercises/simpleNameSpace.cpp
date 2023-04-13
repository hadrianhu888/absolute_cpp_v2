/**
 * @file simpleNameSpace.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

using namespace std;

namespace Space1
{
    void greetings1()
    {
        cout << "Hello from Space1" << endl;
    }
}

namespace Space2
{
    void greetings2()
    {
        cout << "Hello from Space2" << endl;
    }
}

void bigGreetings();

void bigGreetings()
{
    cout << "Hello from bigGreetings" << endl;
}

int main()
{
    Space1::greetings1();
    Space2::greetings2();
    bigGreetings();
    return 0;
}
