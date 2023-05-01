/**
 * @file fibonacci.cpp
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
using namespace chrono;

class Timer
{
public:
    Timer(const string &label) : label_(label), start_(high_resolution_clock::now())
    {
    }

    ~Timer()
    {
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start_);
        double elapsed_seconds = static_cast<double>(duration.count()) / 1000000;
        cout << fixed << setprecision(6) << label_ << " elapsed time: " << elapsed_seconds << " seconds" << endl;
    }

private:
    string label_;
    time_point<high_resolution_clock> start_;
};

int MAX = 1000;
long long int *FIBONACCI;

int fibonacci(int n);
int fibonacci_iterative(int n);
long long int fibonacci_memoization(long long int *fib);

int fibonacci(int n)
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
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int fibonacci_iterative(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int f0 = 0;
    int f1 = 1;
    int f2 = 1;
    for (int i = 2; i <= n; i++)
    {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    return f2;
}

long long int fibonacci_memoization(long long int *fib)
{
    if (fib[0] == 0)
    {
        fib[0] = 0;
    }
    if (fib[1] == 0)
    {
        fib[1] = 1;
    }
    if (fib[2] == 0)
    {
        fib[2] = 1;
    }
    for (int i = 3; i <= MAX; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[MAX];
}

int main()
{
    cout << fibonacci(4) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << " " << fibonacci(i) << endl;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << i << " " << fibonacci_iterative(i) << endl;
    }
    cout << fixed << setprecision(6);
    {
    Timer timer("Recursive function");
    fibonacci(10);
    }
    {
    Timer timer("Iterative function");
    fibonacci_iterative(10);
    }
    for (int i = 0; i <10; i++)
    {
        cout << i << " " << fibonacci_memoization(FIBONACCI) << endl;
    }
    return 0;
}
