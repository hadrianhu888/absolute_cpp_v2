/**
 * @file functionTemplate.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template <class T>
void showStuff(T a, T b)
{
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

template <class T>
void showStuff(T a, T b, T c)
{
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
}

template <class T>
void sort(T arr[], int size)
{
    int startScan, minIndex;
    T minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = arr[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (arr[index] < minValue)
            {
                minValue = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minValue;
    }
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

template <class T>
void search(T arr[], int size,T element)
{
    int first = 0,
        last = size - 1,
        middle,
        position = -1;
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
    auto type = typeid(element).name();
    if (position == -1)
    {
        cout << endl;
        cout << "The number " << element << " was not found in the array." << endl;
    }
    else
    {
        cout << endl;
        cout << "The number " << element << " was found in the array." << endl;
        cout << "The position of the number is " << position << endl;
    }
    if (position == -1)
    {
        cout << endl;
        cout << "The number " << element << " was not found in the array." << endl;
    }
    else
    {
        cout << endl;
        cout << "The number " << element << " was found in the array." << endl;
        cout << "The position of the number is " << position << endl;
    }
}

template <class T>
void vectorTypeSearch(T begin, T end, T element)
{
    auto it = find(begin, end, element);
    if (it != end)
    {
        cout << "The number " << element << " was found in the array." << endl;
        cout << "The position of the number is " << it - begin << endl;
    }
    else
    {
        cout << "The number " << element << " was not found in the array." << endl;
    }
}

int main(int argc, char const *argv[])
{
    int a = 1, b = 2, c = 3;
    showStuff(a, b);
    showStuff(a, b, c);
    int array[] = {1, 2, 3, 4, 5};
    char arrayS [] = {'a', 'b', 'c', 'd', 'e'};
    double arrayD [] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float arrayF [] = {2.2, 3.3, 4.4, 5.5, 6.6};
    vector<int> v = {1, 2, 3, 4, 5};
    sort(array, 5);
    search(array, 5, 3);
    sort(arrayS, 5);
    search(arrayS, 5, 'c');
    sort(arrayD, 5);
    search(arrayD, 5, (double) 3.3);
    sort(arrayF, 5);
    search(arrayF, 5, (float) 3.3);
    sort(v.begin(), v.end());
    return 0;
}
