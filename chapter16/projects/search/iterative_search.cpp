/**
 * @file iterative_search.cpp
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
void iterative_search(T arr[], int size, T element)
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (arr[middle] == element)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle] > element)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    if (position == -1)
    {
        cout << "The element " << element << " was not found in the array." << endl;
    }
    else
    {
        cout << "The element " << element << " was found at position " << position << " in the array." << endl;
    }
}

template <class T>
void recursive_search(T arr[], int first, int last, T element)
{
    int middle;
    if (first > last)
    {
        cout << "The element " << element << " was not found in the array." << endl;
    }
    else
    {
        middle = (first + last) / 2;
        if (arr[middle] == element)
        {
            cout << "The element " << element << " was found at position " << middle << " in the array." << endl;
        }
        else if (arr[middle] > element)
        {
            recursive_search(arr, first, middle - 1, element);
        }
        else
        {
            recursive_search(arr, middle + 1, last, element);
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    int element = 3;
    iterative_search(arr, size, element);
    recursive_search(arr, 0, size - 1, element);
    return 0;
}
