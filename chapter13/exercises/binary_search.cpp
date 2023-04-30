/**
 * @file binary_search.cpp
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

int binarySearch(int a[], int first, int last, int target);
int iterative_binary_search(int a[], int first, int last, int target);
int main(int argc, char **argv);

int binarySearch(int a[], int first, int last, int target)
{
    int mid;
    if (first > last)
    {
        return -1;
    }
    else
    {
        mid = (first + last) / 2;
        if (target == a[mid])
        {
            return mid;
        }
        else if (target < a[mid])
        {
            return binarySearch(a, first, mid - 1, target);
        }
        else
        {
            return binarySearch(a, mid + 1, last, target);
        }
    }
}

int iterative_binary_search(int a[], int first, int last, int target)
{
    int mid;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (target == a[mid])
        {
            return mid;
        }
        else if (target < a[mid])
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    int a[] = {1, 3, 5, 7, 9, 11};
    cout << binarySearch(a, 0, 5, 7) << endl;
    cout << binarySearch(a, 0, 5, 8) << endl;
    cout << iterative_binary_search(a, 0, 5, 7) << endl;
    cout << iterative_binary_search(a, 0, 5, 8) << endl;
    return 0;
}
