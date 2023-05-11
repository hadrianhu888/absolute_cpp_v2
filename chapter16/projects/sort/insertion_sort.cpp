/**
 * @file insertion_sort.cpp
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
void insertion_sort(T arr[], int size)
{
    int i, j;
    T key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) // arr[j] > key is the condition for ascending order
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "\n\nThe sorted array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(int argc, char** argv)
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);
    float arr2[] = {5.5, 2.2, 4.4, 6.6, 1.1, 3.3};
    size = sizeof(arr2) / sizeof(arr2[0]);
    insertion_sort(arr2, size);
    long double arr3[] = {5.5, 2.2, 4.4, 6.6, 1.1, 3.3};
    size = sizeof(arr3) / sizeof(arr3[0]);
    insertion_sort(arr3, size);
    return 0;
}
