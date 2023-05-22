/**
 * @file quicksort.cpp
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
int split(T a[], int begin, int end);
template <class T>
void quicksort(T a[], int begin, int end);
template <class T>
void displayArray(T a[], int size);
template <class T>
void swap(T a[], int i, int j);

int main(int argc, char **argv);

template <class T>
int split(T a[], int begin, int end)
{
    T pivot = a[begin];
    int left = begin;
    int right = end;

    while (left < right)
    {
        while (a[right] > pivot)
        {
            --right;
        }

        while ((left < right) && (a[left] <= pivot))
        {
            ++left;
        }

        if (left < right)
        {
            swap(a, left, right);
        }
    }

    swap(a, begin, right);
    return right;
}

template <class T>
void quicksort(T a[], int begin, int end)
{
    int splitPoint;

    if (end > begin)
    {
        splitPoint = split(a, begin, end);
        quicksort(a, begin, splitPoint - 1);
        quicksort(a, splitPoint + 1, end);
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

template <class T>
void swap(T a[], int i, int j)
{
    T temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main(int argc, char **argv)
{
    int a[] = {7, 3, 9, 4, 6, 1, 2, 8, 5};
    int size = sizeof(a) / sizeof(a[0]);

    cout << "Before sorting: ";
    displayArray(a, size);

    quicksort(a, 0, size - 1);

    cout << "After sorting: ";
    displayArray(a, size);

    return 0;
}
