/**
 * @file sort_pattern_class.cpp
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
class SortPattern
{
public:
    SortPattern(T a[], int s);
    virtual void displayArray();
    virtual void sort() = 0;
    virtual ~SortPattern();
    virtual void swap(T &a, T &b);
    virtual void swap(T a[], int i, int j);
    virtual void selectionSort();
    virtual void insertionSort();
    virtual void bubbleSort();
    virtual void quickSort();
    virtual void mergeSort();
    virtual void heapSort();
    virtual void shellSort();
    virtual void radixSort();
    virtual void bucketSort();
    virtual void countingSort();
    virtual void pigeonholeSort();
    virtual void cocktailSort();
    virtual void combSort();
    virtual void cycleSort();
    virtual void gnomeSort();
protected:
    T *array;
    int size;
};

template <class T>
SortPattern<T>::SortPattern(T a[], int s)
{
    array = a;
    size = s;
}

template <class T>
SortPattern<T>::~SortPattern()
{
    delete[] array;
}

template <class T>
void SortPattern<T>::displayArray()
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <class T>
void SortPattern<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void SortPattern<T>::swap(T a[], int i, int j)
{
    T temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

template <class T>
class Sort
{
public:
    T *array;
    int size;
    Sort(int);
    void display();
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void shellSort();
    void mergeSort();
    void quickSort();
    void heapSort();
    void radixSort();
    void bucketSort();
    void countingSort();
    void pigeonholeSort();
    void cocktailSort();
    void cycleSort();
    void gnomeSort();
};

template <class T>
Sort<T>::Sort(int n)
{
    size = n;
    array = new T[size];
}

template <class T>
void Sort<T>::display()
{
    int i;
    for (i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <class T>
void Sort<T>::bubbleSort()
{
    int i, j, k, swapped;
    for (i = 0; i < size - 1; ++i)
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

template <class T>
void Sort<T>::selectionSort()
{
    int i, j, k, min;
    for (i = 0; i < size - 1; ++i)
    {
        min = i;
        for (j = i + 1; j < size; ++j)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(array[i], array[min]);
        }
    }
}

template <class T>
void Sort<T>::insertionSort()
{
    int i, j, k, item;
    for (i = 1; i < size; ++i)
    {
        item = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > item)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = item;
    }
}

template <class T>
void Sort<T>::shellSort()
{
    int i, j, k, gap, item;
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < size; ++i)
        {
            item = array[i];
            j = i - gap;
            while (j >= 0 && array[j] > item)
            {
                array[j + gap] = array[j];
                j -= gap;
            }
            array[j + gap] = item;
        }
    }
}

template <class T>
void Sort<T>::mergeSort()
{
    int i, j, k, mid;
    if (size > 1)
    {
        mid = size / 2;
        Sort<T> leftArray(mid);
        Sort<T> rightArray(size - mid);
        for (i = 0; i < mid; ++i)
        {
            leftArray.array[i] = array[i];
        }
        for (i = mid; i < size; ++i)
        {
            rightArray.array[i - mid] = array[i];
        }
        leftArray.mergeSort();
        rightArray.mergeSort();
        i = j = k = 0;
        while (i < leftArray.size && j < rightArray.size)
        {
            if (leftArray.array[i] < rightArray.array[j])
            {
                array[k++] = leftArray.array[i++];
            }
            else
            {
                array[k++] = rightArray.array[j++];
            }
        }
        while (i < leftArray.size)
        {
            array[k++] = leftArray.array[i++];
        }
        while (j < rightArray.size)
        {
            array[k++] = rightArray.array[j++];
        }
    }
}

template <class T>
void Sort<T>::quickSort()
{
    int i, j, k, pivot;
    if (size > 1)
    {
        pivot = array[size - 1];
        i = j = 0;
        for (k = 0; k < size - 1; ++k)
        {
            if (array[k] < pivot)
            {
                swap(array[k], array[i++]);
            }
            else
            {
                ++j;
            }
        }
        swap(array[i], array[size - 1]);
        Sort<T> leftArray(i);
        Sort<T> rightArray(j);
        for (k = 0; k < i; ++k)
        {
            leftArray.array[k] = array[k];
        }
        for (k = i + 1; k < size; ++k)
        {
            rightArray.array[k - i - 1] = array[k];
        }
        leftArray.quickSort();
        rightArray.quickSort();
        for (k = 0; k < leftArray.size; ++k)
        {
            array[k] = leftArray.array[k];
        }
        for (k = 0; k < rightArray.size; ++k)
        {
            array[k + i + 1] = rightArray.array[k];
        }
    }
}

template <class T>
void Sort<T>::heapSort()
{
    int i, j, k, item;
    for (i = 1; i < size; ++i)
    {
        item = array[i];
        j = i - 1;
        k = (j - 1) / 2;
        while (j >= 0 && array[k] < item)
        {
            array[j] = array[k];
            j = k;
            k = (j - 1) / 2;
        }
        array[j] = item;
    }
    for (i = size - 1; i > 0; --i)
    {
        item = array[i];
        array[i] = array[0];
        j = 0;
        if (i == 1)
        {
            k = -1;
        }
        else
        {
            k = 1;
        }
        if (i > 2 && array[2] > array[1])
        {
            k = 2;
        }
        while (k >= 0 && item < array[k])
        {
            array[j] = array[k];
            j = k;
            k = 2 * j + 1;
            if (k + 1 <= i - 1 && array[k] < array[k + 1])
            {
                ++k;
            }
            if (k > i - 1)
            {
                k = -1;
            }
        }
        array[j] = item;
    }
}

template <class T>
void Sort<T>::countingSort()
{
    int i, j, k, max, min;
    max = min = array[0];
    for (i = 1; i < size; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    Sort<T> countArray(max - min + 1);
    for (i = 0; i < size; ++i)
    {
        ++countArray.array[array[i] - min];
    }
    for (i = min, j = 0; i <= max; ++i)
    {
        for (k = 0; k < countArray.array[i - min]; ++k)
        {
            array[j++] = i;
        }
    }
}

template <class T>
void Sort<T>::radixSort()
{
    int i, j, k, max, min, radix, divisor, significantDigit;
    max = min = array[0];
    for (i = 1; i < size; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    radix = 10;
    divisor = 1;
    significantDigit = 1;
    while ((max - min) / divisor >= 1)
    {
        Sort<T> bucket(radix);
        for (i = 0; i < size; ++i)
        {
            ++bucket.array[(array[i] / divisor) % radix];
        }
        for (i = 1; i < radix; ++i)
        {
            bucket.array[i] += bucket.array[i - 1];
        }
        for (i = size - 1; i >= 0; --i)
        {
            array[--bucket.array[(array[i] / divisor) % radix]] = array[i];
        }
        divisor *= radix;
    }
}

template <class T>
void Sort<T>::bucketSort()
{
    int i, j, k, max, min, bucketSize, bucketCount;
    max = min = array[0];
    for (i = 1; i < size; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    bucketSize = 10;
    bucketCount = (max - min) / bucketSize + 1;
    Sort<T> *bucketArray = new Sort<T>[bucketCount];
    for (i = 0; i < bucketCount; ++i)
    {
        bucketArray[i].size = 0;
    }
    for (i = 0; i < size; ++i)
    {
        bucketArray[(array[i] - min) / bucketSize].array[bucketArray[(array[i] - min) / bucketSize].size++] = array[i];
    }
    for (i = 0; i < bucketCount; ++i)
    {
        bucketArray[i].insertionSort();
    }
    for (i = 0, k = 0; i < bucketCount; ++i)
    {
        for (j = 0; j < bucketArray[i].size; ++j)
        {
            array[k++] = bucketArray[i].array[j];
        }
    }
    delete[] bucketArray;
}


template <class T>
void Sort<T>::pigeonholeSort()
{
    int i, j, k, min, max, range, index;
    min = max = array[0];
    for (i = 1; i < size; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    range = max - min + 1;
    Sort<T> *hole = new Sort<T>[range];
    for (i = 0; i < range; ++i)
    {
        hole[i].size = 0;
    }
    for (i = 0; i < size; ++i)
    {
        hole[array[i] - min].array[hole[array[i] - min].size++] = array[i];
    }
    for (i = 0, index = 0; i < range; ++i)
    {
        for (j = 0; j < hole[i].size; ++j)
        {
            array[index++] = hole[i].array[j];
        }
    }
    delete[] hole;
}

template <class T>
void Sort<T>::cocktailSort()
{
    int i, j, k, temp, swapped;
    for (i = 0; i < size / 2; ++i)
    {
        swapped = 0;
        for (j = i; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
        swapped = 0;
        for (j = size - i - 2; j >= i; --j)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

template <class T>
void Sort<T>::gnomeSort()
{
    int i, j, k, temp;
    i = 0;
    while (i < size)
    {
        if (i == 0 || array[i - 1] <= array[i])
        {
            ++i;
        }
        else
        {
            temp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = temp;
            --i;
        }
    }
}

template <class T>
void Sort<T>::cycleSort()
{
    int writes = 0;

    for (int cycle_start = 0; cycle_start <= size - 2; cycle_start++) {
        T item = array[cycle_start];

        int pos = cycle_start;
        for (int i = cycle_start + 1; i < size; i++)
            if (array[i] < item)
                pos++;

        if (pos == cycle_start)
            continue;

        while (item == array[pos])
            pos += 1;

        if (pos != cycle_start) {
            swap(item, array[pos]);
            writes++;
        }

        while (pos != cycle_start) {
            pos = cycle_start;

            for (int i = cycle_start + 1; i < size; i++)
                if (array[i] < item)
                    pos += 1;

            while (item == array[pos])
                pos += 1;

            if (item != array[pos]) {
                swap(item, array[pos]);
                writes++;
            }
        }
    }
}

int ARRAY_SIZE = 100;

int main()
{
    srand(time(0));

    //create an array with random values
    int *array = new int[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
        array[i] = rand() % 1000; //random values between 0 and 999

    // Create a Sort object
    Sort<int> mySort(ARRAY_SIZE);

    // Populate the Sort object with values from the array
    for (int i = 0; i < ARRAY_SIZE; i++)
        mySort.array[i] = array[i];

    // Display the unsorted array
    cout << "Original Array: " << endl;
    mySort.display();
    cout << endl;

    // Call and test various sort functions here
    mySort.bubbleSort();
    cout << "Array after Bubble Sort: " << endl;
    mySort.display();
    cout << endl;

    // Reset the array
    for (int i = 0; i < ARRAY_SIZE; i++)
        mySort.array[i] = array[i];

    mySort.selectionSort();
    cout << "Array after Selection Sort: " << endl;
    mySort.display();19
