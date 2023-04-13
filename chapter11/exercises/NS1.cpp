/**
 * @file NS1.cpp
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

namespace NS1
{
    void greetings1()
    {
        cout << "Hello from NS1" << endl;
    }
    void greetings3(int howManyTimes)
    {
        for (int i = 0; i < howManyTimes; i++)
        {
            cout << "Hello from NS1" << endl;
        }
    }
}
     // namespace NS1
