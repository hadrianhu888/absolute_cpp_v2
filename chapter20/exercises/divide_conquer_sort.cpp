/**
 * @file divide_conquer_sort.cpp
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
void mergeSort(T a[], int begin, int end);
template <class T>
void merge(T a[], int begin, int mid, int end);
template <class T>
void swap(T &a, T &b);
template <class T>
void swap(T a[], int i, int j);
template <class T>
void selectionSort(T a[], int size);

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
void mergeSort(T a[], int begin, int end)
{
    int mid;

    if (begin < end)
    {
        mid = (begin + end) / 2;
        mergeSort(a, begin, mid);
        mergeSort(a, mid + 1, end);
        merge(a, begin, mid, end);
    }
}

template <class T>
void merge(T a[], int begin, int mid, int end)
{
    T tempArray[100];
    int first1 = begin;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = end;
    int index = first1;

    for (; (first1 <= last1) && (first2 <= last2); ++index)
    {
        if (a[first1] < a[first2])
        {
            tempArray[index] = a[first1];
            ++first1;
        }
        else
        {
            tempArray[index] = a[first2];
            ++first2;
        }
    }

    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = a[first1];
    }

    for (; first2 <= last2; ++first2, ++index)
    {
        tempArray[index] = a[first2];
    }

    for (index = begin; index <= end; ++index)
    {
        a[index] = tempArray[index];
    }
}

template <class T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void swap(T a[], int i, int j)
{
    T temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

template <class T>
void selectionSort(T a[], int size)
{
    int i, j, index_of_largest;

    if (size == 0)
    {
        return;
    }

    for (i = size - 1; i > 0; --i)
    {
        index_of_largest = 0;

        for (j = 1; j <= i; ++j)
        {
            if (a[j] > a[index_of_largest])
            {
                index_of_largest = j;
            }
        }

        swap(a, i, index_of_largest);
    }
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

    cout << "Before sorting: ";
    displayArray(a, size);

    mergeSort(a, 0, size - 1);

    cout << "After sorting: ";
    displayArray(a, size);

    cout << "Before sorting: ";
    displayArray(a, size);

    selectionSort(a, size);

    cout << "After sorting: ";
    displayArray(a, size);

    return 0;
}
