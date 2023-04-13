/**
 * @file namespacesExercises.cpp
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

namespace Sally
{
    int num;
    void print()
    {
        cout << "Sally's number is " << num << endl;
    }
}

namespace
{
    int num;
    void print()
    {
        cout << "Sally's number is " << num << endl;
    }
}

namespace John
{
    int num;
    void print()
    {
        cout << "John's number is " << num << endl;
    }
}

namespace Outside
{
    namespace Middle
    {
        namespace Inside
        {
            int num;
            void print()
            {
                cout << "Inside's number is " << num << endl;
            }
            void print2()
            {
                cout << "Inside's number is " << num << endl;
            }
        }
        void print3()
        {
            cout << "Inside's number is " << Inside::num << endl;
        }
    }
    void print4()
    {
        cout << "Inside's number is " << Middle::Inside::num << endl;
    }
}

int main(int argc, char **argv)
{
    Sally::num = 12;
    Sally::print();
    John::num = 24;
    John::print();
    Outside::Middle::Inside::num = 36;
    Outside::Middle::Inside::print();
    Outside::Middle::Inside::print2();
    Outside::Middle::print3();
    Outside::print4();
    return 0;
}
