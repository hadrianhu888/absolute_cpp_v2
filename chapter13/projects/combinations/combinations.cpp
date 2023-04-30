/**
 * @file combinations.cpp
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

int combinations(int n, int r);
int main(int argc, char **argv);

int combinations(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    else
    {
        return combinations(n - 1, r - 1) + combinations(n - 1, r);
    }
}

int main(int argc, char **argv)
{
    cout << combinations(4, 2) << endl;
    cout << combinations(5, 2) << endl;
    cout << combinations(6, 2) << endl;
    cout << combinations(7, 2) << endl;
    cout << combinations(8, 2) << endl;
    cout << combinations(9, 2) << endl;
    cout << combinations(10, 2) << endl;
    return 0;
}
