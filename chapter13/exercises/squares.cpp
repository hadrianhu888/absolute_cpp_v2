/**
 * @file squares.cpp
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

int square(int n);
int main(int argc, char **argv);

int square(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return square(n - 1) + 2 * n - 1;
    }
}

int main(int argc, char **argv)
{
    cout << square(4) << endl;
    for (int i = 1; i < 10; i++)
    {
        cout << i << " " << square(i) << endl;
    }
    return 0;
}
