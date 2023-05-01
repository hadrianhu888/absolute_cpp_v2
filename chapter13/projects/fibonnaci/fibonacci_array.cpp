/**
 * @file fibonacci_array.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

long double *FIBONACCI;

long double fibonacci_memoization(long double *fib, int i)
{
    if (i == 0)
    {
        return 0;
    }
    else if (i == 1)
    {
        return 1;
    }
    else if (fib[i] != -1)
    {
        return fib[i];
    }
    else
    {
        fib[i] = fibonacci_memoization(fib, i - 1) + fibonacci_memoization(fib, i - 2);
        return fib[i];
    }
}

int main(int argc, char **argv)
{
    int MAX = 1000;
    FIBONACCI = new long double[MAX];
    fill_n(FIBONACCI, MAX, -1); // Initialize the FIBONACCI array with -1

    FIBONACCI[0] = 0;
    FIBONACCI[1] = 1;

    for (int i = 0; i < MAX; i++)
    {
        cout << fibonacci_memoization(FIBONACCI, i) << endl;
    }

    delete[] FIBONACCI; // Free the dynamically allocated memory
    return 0;
}
