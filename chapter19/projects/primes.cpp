/**
 * @file primes.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

int main(int argc, char **argv);
void printPrimeValues(int n);
void printPrimeValuesUsing_Half_N(int n);
void printPrimeValuesUsing_Sqrt_N(int n);

int main(int argc, char **argv)
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    try
    {
        if (n < 0)
            throw runtime_error("Invalid input");
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    printPrimeValues(n);
    printPrimeValuesUsing_Half_N(n);
    printPrimeValuesUsing_Sqrt_N(n);
    return 0;
}

void printPrimeValues(int n)
{
    for (int num = 2; num <= n; num++)
    {
        bool is_prime = true;
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            cout << num << " ";
    }
    cout << endl;
}

void printPrimeValuesUsing_Half_N(int n)
{
    for (int num = 2; num <= n; num++)
    {
        bool is_prime = true;
        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            cout << num << " ";
    }
    cout << endl;
}

void printPrimeValuesUsing_Sqrt_N(int n)
{
    for (int num = 2; num <= n; num++)
    {
        bool is_prime = true;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            cout << num << " ";
    }
    cout << endl;
}
