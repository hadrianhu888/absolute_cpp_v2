/**
 * @file nestedNamespaces.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

using namespace std;

namespace Outer
{
    namespace Inner
    {
        void message()
        {
            cout << "Hello from Outer::Inner::message" << endl;
        }
    }
}

namespace Outer
{
    void message()
    {
        cout << "Hello from Outer::message" << endl;
    }
}

int main(int argc, char **argv)
{
    Outer::message();
    Outer::Inner::message();
    return 0;
}
