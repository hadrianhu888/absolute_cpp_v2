/**
 * @file mystery.cpp
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

int mystery(int n);
int main(int argc, char **argv);

int mystery(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    else
    {
        return mystery(n-1 )+n;
    }
}

int main(int argc, char **argv)
{
    cout << mystery(4) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << " " << mystery(i) << endl;
    }
    return 0;
}
