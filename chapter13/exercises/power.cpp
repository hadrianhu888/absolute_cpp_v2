/**
 * @file power.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

double power(double base, int exponent);
int main(int argc, char **argv);

double power(double base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    else if(exponent < 0)
    {
        return 1 / power(base, -exponent);
    }
    else
    {
        return base * power(base, exponent - 1);
    }
}

int main(int argc, char **argv)
{
    cout << power(2, 3) << endl;
    cout << power(2, -3) << endl;
    cout << power(2, 0) << endl;
    return 0;
}
