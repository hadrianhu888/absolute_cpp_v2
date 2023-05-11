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
void vectorTypeSearch(vector<T>, T element, int size, int position)
{
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
void sort(vector<T> v)
{
    int startScan, minIndex;
    T minValue;

    for (startScan = 0; startScan < (v.size() - 1); startScan++)
    {
        minIndex = startScan;
        minValue = v[startScan];
        for (int index = startScan + 1; index < v.size(); index++)
        {
            if (v[index] < minValue)
            {
                minValue = v[index];
                minIndex = index;
            }
        }
        v[minIndex] = v[startScan];
        v[startScan] = minValue;
    }
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

template <class T>
class DayOfYear
{
private:
    int day;
    static string monthName[];
    static int monthNumber[];
    static int monthDays[];
    public:
    DayOfYear(int d)
    {
        day = d;
    }
    void print();
    void print(int);
    void sort();
};

template <class T>
string DayOfYear<T>::monthName[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                                    "October", "November", "December"};

template <class T>
int DayOfYear<T>::monthNumber[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
                                   10, 11, 12};

template <class T>
int DayOfYear<T>::monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30,
                                 31, 30, 31};

template <class T>
void DayOfYear<T>::print()
{
    int index = 0;
    while (day > monthDays[index])
    {
        day -= monthDays[index];
        index++;
    }
    cout << monthName[index] << " " << day << endl;
}

template <class T>
void DayOfYear<T>::print(int d)
{
    int index = 0;
    while (d > monthDays[index])
    {
        d -= monthDays[index];
        index++;
    }
    cout << monthName[index] << " " << d << endl;
}

template <class T>
void DayOfYear<T>::sort()
{
    int startScan, minIndex;
    T minValue;

    for (startScan = 0; startScan < (12 - 1); startScan++)
    {
        minIndex = startScan;
        minValue = monthNumber[startScan];
        for (int index = startScan + 1; index < 12; index++)
        {
            if (monthNumber[index] < minValue)
            {
                minValue = monthNumber[index];
                minIndex = index;
            }
        }
        monthNumber[minIndex] = monthNumber[startScan];
        monthNumber[startScan] = minValue;
    }
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << monthNumber[i] << " ";
    }
}

template <class T>
void swapValues(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
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
    vector<char> vS = {'a', 'b', 'c', 'd', 'e'};
    sort(array, 5);
    search(array, 5, 3);
    sort(arrayS, 5);
    search(arrayS, 5, 'c');
    sort(arrayD, 5);
    search(arrayD, 5, (double) 3.3);
    sort(arrayF, 5);
    search(arrayF, 5, (float) 3.3);
    sort(v.begin(), v.end());
    vectorTypeSearch(v, 3, 5, 2);
    sort(vS.begin(), vS.end());
    vectorTypeSearch(vS, 'c', 5, 2);
    sort(vS);
    //over loading the template function with a vector type is permitted in C++.
    /**
     * @brief Sort by DayOfYear type
     *
     */
    DayOfYear<int> day(32);
    day.print();
    day.print(32);
    day.sort();
    int x = 1, y = 2;
    cout << x << " " << y << endl;
    swapValues(x, y);
    cout << x << " " << y << endl;
    return 0;
}
