/**
 * @file fibonnaci.cpp
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

int fibonnaci(int n);
int main(int argc, char **argv);

int fibonnaci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonnaci(n - 1) + fibonnaci(n - 2);
    }
}

int main(int argc, char **argv)
{
    cout << fibonnaci(4) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << " " << fibonnaci(i) << endl;
    }
    return 0;
}
