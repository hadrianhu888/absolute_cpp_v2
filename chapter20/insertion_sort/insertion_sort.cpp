/**
 * @file insertion_sort.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template <class T>
void insertionSort(T a[], int size);
template <class T>
void displayArray(T a[], int size);

int main(int argc, char **argv);

template <class T>
void insertionSort(T a[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        T next = a[i];
        int j = i;
        while ((j > 0) && (a[j - 1] > next))
        {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = next;
    }
}

template <class T>
void displayArray(T a[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    int a[] = {5, 7, 3, 2, 1, 9, 8, 4, 6};
    int size = sizeof(a) / sizeof(a[0]);

    cout << "Before sorting: ";
    displayArray(a, size);

    insertionSort(a, size);

    cout << "After sorting: ";
    displayArray(a, size);

    return 0;
}
