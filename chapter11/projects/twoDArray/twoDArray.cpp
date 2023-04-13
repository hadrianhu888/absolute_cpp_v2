/**
 * @file twoDArray.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace TwoDArray
{
    class TwoDArrayClass
    {
    private:
        int **array;
        int rows;
        int cols;
        int value;
        int row;
        int col;
        fstream file;
        string fileName;
        string line;
        string word;
        vector<string> words;
        vector<vector<string>> lines;
        vector<vector<int>> intLines;
        vector<int> intWords;
        int intWord;
        int intLine;
        int intWordCount;
        int intLineCount;
        int intWordCountMax;
        int intLineCountMax;
        int intWordCountMin;
        int intLineCountMin;
    public:
        TwoDArrayClass(int rows, int cols);
        void set(int row, int col, int value);
        void inputArrayElements();
        void inputArrayElements(int row, int col);
        void printArrayElements();
        void printArrayElements(int row, int col);
        void saveArrayElementsToFile();
        void printArrayElementFromFile();
        int get(int row, int col);
        int add_arrays(TwoDArrayClass &twoDArrayClass);
        int subtract_arrays(TwoDArrayClass &twoDArrayClass);
        int multiply_arrays(TwoDArrayClass &twoDArrayClass);
        int divide_arrays(TwoDArrayClass &twoDArrayClass);
        int inverse_array();
        bool operator==(TwoDArrayClass &twoDArrayClass);
        bool operator!=(TwoDArrayClass &twoDArrayClass);
        bool operator<(TwoDArrayClass &twoDArrayClass);
        bool operator>(TwoDArrayClass &twoDArrayClass);
        bool operator<=(TwoDArrayClass &twoDArrayClass);
        bool operator>=(TwoDArrayClass &twoDArrayClass);

    };
}

TwoDArray::TwoDArrayClass::TwoDArrayClass(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    array = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[cols];
    }
}

void TwoDArray::TwoDArrayClass::set(int row, int col, int value)
{
    array[row][col] = value;
}

void TwoDArray::TwoDArrayClass::inputArrayElements()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter value for row " << i << " and column " << j << ": ";
            cin >> array[i][j];
        }
    }
}

void TwoDArray::TwoDArrayClass::inputArrayElements(int row, int col)
{
    cout << "Enter value for row " << row << " and column " << col << ": ";
    cin >> array[row][col];
}

void TwoDArray::TwoDArrayClass::printArrayElements()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Value for row " << i << " and column " << j << ": " << array[i][j] << endl;
        }
    }
}

void TwoDArray::TwoDArrayClass::printArrayElements(int row, int col)
{
    cout << "Value for row " << row << " and column " << col << ": " << array[row][col] << endl;
}

void TwoDArray::TwoDArrayClass::saveArrayElementsToFile()
{
    cout << "Enter file name: ";
    cin >> fileName;
    file.open(fileName, ios::out);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            file << array[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}

void TwoDArray::TwoDArrayClass::printArrayElementFromFile()
{
    cout << "Enter file name: ";
    cin >> fileName;
    file.open(fileName, ios::in);
    while (file >> intWord)
    {
        intWords.push_back(intWord);
    }
    file.close();
    intWordCount = 0;
    intLineCount = 0;
    intWordCountMax = 0;
    intLineCountMax = 0;
    intWordCountMin = 0;
    intLineCountMin = 0;
    for (int i = 0; i < intWords.size(); i++)
    {
        if (intWords[i] == 10)
        {
            intLineCount++;
            intWordCount = 0;
        }
        else
        {
            intWordCount++;
        }
        if (intWordCount > intWordCountMax)
        {
            intWordCountMax = intWordCount;
        }
        if (intLineCount > intLineCountMax)
        {
            intLineCountMax = intLineCount;
        }
        if (intWordCount < intWordCountMin)
        {
            intWordCountMin = intWordCount;
        }
        if (intLineCount < intLineCountMin)
        {
            intLineCountMin = intLineCount;
        }
    }
    intLines.resize(intLineCountMax + 1);
    for (int i = 0; i < intLines.size(); i++)
    {
        intLines[i].resize(intWordCountMax + 1);
    }
    intWordCount = 0;
    intLineCount = 0;
    for (int i = 0; i < intWords.size(); i++)
    {
        if (intWords[i] == 10)
        {
            intLineCount++;
            intWordCount = 0;
        }
        else
        {
            intLines[intLineCount][intWordCount] = intWords[i];
            intWordCount++;
        }
    }
    for (int i = 0; i < intLines.size(); i++)
    {
        for (int j = 0; j < intLines[i].size(); j++)
        {
            cout << intLines[i][j] << " ";
        }
        cout << endl;
    }
}

int TwoDArray::TwoDArrayClass::add_arrays(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                array[i][j] += twoDArrayClass.array[i][j];
            }
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

int TwoDArray::TwoDArrayClass::subtract_arrays(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                array[i][j] -= twoDArrayClass.array[i][j];
            }
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

int TwoDArray::TwoDArrayClass::multiply_arrays(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                array[i][j] *= twoDArrayClass.array[i][j];
            }
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

int TwoDArray::TwoDArrayClass::divide_arrays(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                array[i][j] /= twoDArrayClass.array[i][j];
            }
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

int TwoDArray::TwoDArrayClass::inverse_array()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = -array[i][j];
        }
    }
    return 0;
}

bool TwoDArray::TwoDArrayClass::operator==(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (array[i][j] != twoDArrayClass.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool TwoDArray::TwoDArrayClass::operator!=(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (array[i][j] != twoDArrayClass.array[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}

bool TwoDArray::TwoDArrayClass::operator==(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (array[i][j] != twoDArrayClass.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool TwoDArray::TwoDArrayClass::operator!=(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (array[i][j] != twoDArrayClass.array[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}

bool TwoDArray::TwoDArrayClass::operator<(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (array[i][j] >= twoDArrayClass.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool TwoDArray::TwoDArrayClass::operator>(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (array[i][j] <= twoDArrayClass.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool TwoDArray::TwoDArrayClass::operator<=(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (array[i][j] > twoDArrayClass.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool TwoDArray::TwoDArrayClass::operator>=(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (array[i][j] < twoDArrayClass.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool TwoDArray::TwoDArrayClass::operator<(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (array[i][j] >= twoDArrayClass.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool TwoDArray::TwoDArrayClass::operator>(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (array[i][j] <= twoDArrayClass.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool TwoDArray::TwoDArrayClass::operator<=(TwoDArrayClass &twoDArrayClass)
{
    if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (array[i][j] > twoDArrayClass.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
