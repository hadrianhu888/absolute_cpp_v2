/**
 * @file twoDimArray.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
using namespace std;

class twoDimArray
{
private:
    int **a;
    int rows;
    int cols;
public:
    twoDimArray();
    twoDimArray(int rowsValue, int colsValue);
    twoDimArray(const twoDimArray& pfaObject);
    void addElement(int element);
    bool full() const;
    int getCapacity() const;
    int getNumberUsed() const;
    void emptyArray();
    int& operator[](int index);
    twoDimArray& operator =(const twoDimArray& rightSide);
    ~twoDimArray();
};

void testtwoDimArray(void);

int main(int argc, char **argv)
{
    testtwoDimArray();
    return 0;
}

twoDimArray::twoDimArray()
{
    rows = 50;
    cols = 50;
    a = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        a[i] = new int[cols];
    }
}

twoDimArray::twoDimArray(int rowsValue, int colsValue)
{
    if (rowsValue < 1)
    {
        cout << "Capacity of the array must be positive. Creating an array of size 50." << endl;
        rows = 50;
    }
    else
    {
        rows = rowsValue;
    }
    if (colsValue < 1)
    {
        cout << "Capacity of the array must be positive. Creating an array of size 50." << endl;
        cols = 50;
    }
    else
    {
        cols = colsValue;
    }
    a = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        a[i] = new int[cols];
    }
}

twoDimArray::twoDimArray(const twoDimArray& pfaObject)
{
    rows = pfaObject.rows;
    cols = pfaObject.cols;
    a = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        a[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a[i][j] = pfaObject.a[i][j];
        }
    }
}

void testtwoDimArray()
{
    int row, col;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;
    int** a = new int*[row];
    for(int i = 0; i < row; i++)
    {
        a[i] = new int[col];
        for(int j = 0; j < col; j++)
        {
            cout << "Enter element a " << i << ", " << j << ": ";
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // don't forget to free memory allocated for array
    for(int i = 0; i < row; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}

twoDimArray::~twoDimArray()
{
    for (int i = 0; i < rows; i++)
    {
        delete [] a[i];
    }
    delete [] a;
}

twoDimArray& twoDimArray::operator =(const twoDimArray& rightSide)
{
    if (this != &rightSide)
    {
        for (int i = 0; i < rows; i++)
        {
            delete [] a[i];
        }
        delete [] a;
        rows = rightSide.rows;
        cols = rightSide.cols;
        a = new int*[rows];
        for (int i = 0; i < rows; i++)
        {
            a[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                a[i][j] = rightSide.a[i][j];
            }
        }
    }
    return *this;
}

int& twoDimArray::operator[](int index)
{
    return *a[index];
}

void twoDimArray::addElement(int element)
{
    if (full())
    {
        cout << "The array is full. Cannot add an element." << endl;
    }
    else
    {
        a[rows][cols] = element;
        cols++;
        if (cols == 50)
        {
            rows++;
            cols = 0;
        }
    }
}

bool twoDimArray::full() const
{
    return (rows == 50 && cols == 50);
}

int twoDimArray::getCapacity() const
{
    return rows * cols;
}

int twoDimArray::getNumberUsed() const
{
    return rows * cols;
}

void twoDimArray::emptyArray()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a[i][j] = 0;
        }
    }
}
