/**
 * @file exercises.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

const int MAX = 100;
const int MIN = 0;

class Sample
{
    private:
        int array[MAX];
        int size;
    public:
        Sample();
        Sample(int newSize);
        void setSize(int newSize);
        int getSize();
        void read();
        void print();
        int findMax();
        int findMin();
        int findSum();
        double findAverage();
        void sort();
        void findValue(int value);
        void reverse();
        void output() const;
};

int main(int argc, char **argv);

Sample::Sample()
{
    size = 0;
}

Sample::Sample(int newSize)
{
    size = newSize;
}

void Sample::setSize(int newSize)
{
    size = newSize;
}

int Sample::getSize()
{
    return size;
}

void Sample::read()
{
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}

void Sample::print()
{
    cout << "The array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int Sample::findMax()
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

int Sample::findMin()
{
    int min = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

int Sample::findSum()
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

double Sample::findAverage()
{
    double average = 0;
    for (int i = 0; i < size; i++)
    {
        average += array[i];
    }
    average /= size;
    return average;
}

void Sample::sort()
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void Sample::findValue(int value)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            count++;
        }
    }
    cout << "The value " << value << " occurs " << count << " times." << endl;
}

void Sample::reverse()
{
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

void Sample:: output() const
{
    cout << "The array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    Sample sample;
    int size;
    int value;
    cout << "Enter the size of the array: ";
    cin >> size;
    sample.setSize(size);
    sample.read();
    sample.print();
    cout << "The maximum value is: " << sample.findMax() << endl;
    cout << "The minimum value is: " << sample.findMin() << endl;
    cout << "The sum of the values is: " << sample.findSum() << endl;
    cout << "The average of the values is: " << sample.findAverage() << endl;
    sample.sort();
    sample.print();
    cout << "Enter a value to find: ";
    cin >> value;
    sample.findValue(value);
    sample.reverse();
    sample.print();
    return 0;
}

/**
 * @brief input cannot be a const because it is being changed
 * the difference between call by value and call by reference is that call by value is a copy of the variable. Call by reference is the actual variable.
 */
