/**
 * @file absolute_values.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template <class T>
T absolute_value(T x)
{
    if (x < 0)
    {
        return -x;
    }
    else
    {
        return x;
    }
}

template <class T>
T absolute_values(T x, T y)
{
    return absolute_value(x) + absolute_value(y);
}

int main(int argc, char **argv)
{
    int x = -5;
    int y = 10;
    cout << "The absolute value of " << x << " is " << absolute_value(x) << endl;
    cout << "The absolute value of " << y << " is " << absolute_value(y) << endl;
    cout << "The sum of the absolute values of " << x << " and " << y << " is " << absolute_values(x, y) << endl;
    float x2 = -5.5;
    float y2 = 10.5;
    cout << "The absolute value of " << x2 << " is " << absolute_value(x2) << endl;
    cout << "The absolute value of " << y2 << " is " << absolute_value(y2) << endl;
    cout << "The sum of the absolute values of " << x2 << " and " << y2 << " is " << absolute_values(x2, y2) << endl;
    long double x3 = -5.5;
    long double y3 = 10.5;
    cout << "The absolute value of " << x3 << " is " << absolute_value(x3) << endl;
    cout << "The absolute value of " << y3 << " is " << absolute_value(y3) << endl;
    cout << "The sum of the absolute values of " << x3 << " and " << y3 << " is " << absolute_values(x3, y3) << endl;
    return 0;
}
