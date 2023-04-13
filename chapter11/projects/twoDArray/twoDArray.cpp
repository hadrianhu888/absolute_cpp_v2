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
        TwoDArrayClass();
        TwoDArrayClass(int rows, int cols);
        void set(int row, int col, int value);
        void inputArrayElements();
        void inputArrayElements(int row, int col);
        void printArrayElements();
        void printArrayElements(int row, int col);
        void saveArrayElementsToFile();
        void printArrayElementFromFile();
        int get(int row, int col);
        int add_arrays(TwoDArrayClass &twoDArrayClass)
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
                return -1;
            }
        }
        int subtract_arrays(TwoDArrayClass &twoDArrayClass)
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
                return -1;
            }
        }
        int multiply_arrays(TwoDArrayClass &twoDArrayClass)
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
                return -1;
            }
        }
        int divide_arrays(TwoDArrayClass &twoDArrayClass)
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
                return -1;
            }
        }
        int inverse_array()
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
        int transpose()
        {
            int **tempArray = new int *[cols];
            for (int i = 0; i < cols; i++)
            {
                tempArray[i] = new int[rows];
            }
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    tempArray[j][i] = array[i][j];
                }
            }
            for (int i = 0; i < rows; i++)
            {
                delete[] array[i];
            }
            delete[] array;
            array = tempArray;
            int temp = rows;
            rows = cols;
            cols = temp;
            return 0;
        }
        bool operator==(TwoDArrayClass &twoDArrayClass)
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
        bool operator!=(TwoDArrayClass &twoDArrayClass)
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
        bool operator<(TwoDArrayClass &twoDArrayClass)
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
        bool operator>(TwoDArrayClass &twoDArrayClass)
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
        bool operator<=(TwoDArrayClass &twoDArrayClass)
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
        bool operator>=(TwoDArrayClass &twoDArrayClass)
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
        TwoDArrayClass &operator=(TwoDArrayClass &twoDArrayClass)
        {
            if (this != &twoDArrayClass)
            {
                for (int i = 0; i < rows; i++)
                {
                    delete[] array[i];
                }
                delete[] array;
                rows = twoDArrayClass.rows;
                cols = twoDArrayClass.cols;
                array = new int *[rows];
                for (int i = 0; i < rows; i++)
                {
                    array[i] = new int[cols];
                }
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        array[i][j] = twoDArrayClass.array[i][j];
                    }
                }
            }
            return *this;
        }
        TwoDArrayClass &operator+(TwoDArrayClass &twoDArrayClass)
        {
            if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
            {
                TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        temp->array[i][j] = array[i][j] + twoDArrayClass.array[i][j];
                    }
                }
                return *temp;
            }
            else
            {
                cout << "Error: Cannot add two arrays of different sizes" << endl;
                return *this;
            }
        }
        TwoDArrayClass &operator-(TwoDArrayClass &twoDArrayClass)
        {
            if (rows == twoDArrayClass.rows && cols == twoDArrayClass.cols)
            {
                TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        temp->array[i][j] = array[i][j] - twoDArrayClass.array[i][j];
                    }
                }
                return *temp;
            }
            else
            {
                cout << "Error: Cannot subtract two arrays of different sizes" << endl;
                return *this;
            }
        }
        TwoDArrayClass &operator+=(TwoDArrayClass &twoDArrayClass)
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
                return *this;
            }
            else
            {
                cout << "Error: Cannot add two arrays of different sizes" << endl;
                return *this;
            }
        }
        TwoDArrayClass &operator-=(TwoDArrayClass &twoDArrayClass)
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
                return *this;
            }
            else
            {
                cout << "Error: Cannot subtract two arrays of different sizes" << endl;
                return *this;
            }
        }
        TwoDArrayClass &operator++()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    array[i][j]++;
                }
            }
            return *this;
        }
        TwoDArrayClass &operator++(int)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->array[i][j] = array[i][j];
                    array[i][j]++;
                }
            }
            return *temp;
        }
        TwoDArrayClass &operator--()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    array[i][j]--;
                }
            }
            return *this;
        }
        TwoDArrayClass &operator--(int)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->array[i][j] = array[i][j];
                    array[i][j]--;
                }
            }
            return *temp;
        }
        TwoDArrayClass &operator*(int value)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->array[i][j] = array[i][j] * value;
                }
            }
            return *temp;
        }
        TwoDArrayClass &operator*=(int value)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    array[i][j] *= value;
                }
            }
            return *this;
        }
        TwoDArrayClass &operator/(int value)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->array[i][j] = array[i][j] / value;
                }
            }
            return *temp;
        }
        TwoDArrayClass &operator/=(int value)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    array[i][j] /= value;
                }
            }
            return *this;
        }
        TwoDArrayClass &operator%=(int value)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    array[i][j] %= value;
                }
            }
            return *this;
        }
        TwoDArrayClass &operator<(int value)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->array[i][j] = array[i][j] < value;
                }
            }
            return *temp;
        }
        TwoDArrayClass &operator<=(int value)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->array[i][j] = array[i][j] <= value;
                }
            }
            return *temp;
        }
        TwoDArrayClass &operator>(int value)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->array[i][j] = array[i][j] > value;
                }
            }
            return *temp;
        }
        TwoDArrayClass &operator>=(int value)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->array[i][j] = array[i][j] >= value;
                }
            }
            return *temp;
        }
        TwoDArrayClass &operator==(int value)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->array[i][j] = array[i][j] == value;
                }
            }
            return *temp;
        }
        friend ostream &operator<<(ostream &out, TwoDArrayClass &obj)
        {
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    out << obj.array[i][j] << " ";
                }
                out << endl;
            }
            return out;
        }
        friend istream &operator>>(istream &in, TwoDArrayClass &obj)
        {
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    in >> obj.array[i][j];
                }
            }
            return in;
        }
        friend TwoDArrayClass &operator+(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] + value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator-(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] - value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator*(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] * value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator/(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] / value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator%(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] % value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator<(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] < value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator<=(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] <= value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator>(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] > value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator>=(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] >= value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator==(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] == value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator!=(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] != value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator&&(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] && value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator||(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] || value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator&(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] & value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator|(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] | value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator^(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] ^ value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator<<(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] << value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator>>(int value, TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = obj.array[i][j] >> value;
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator~(TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = ~obj.array[i][j];
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator!(TwoDArrayClass &obj)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj.rows, obj.cols);
            for (int i = 0; i < obj.rows; i++)
            {
                for (int j = 0; j < obj.cols; j++)
                {
                    temp->array[i][j] = !obj.array[i][j];
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator+(TwoDArrayClass &obj1, TwoDArrayClass &obj2)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj1.rows, obj1.cols);
            for (int i = 0; i < obj1.rows; i++)
            {
                for (int j = 0; j < obj1.cols; j++)
                {
                    temp->array[i][j] = obj1.array[i][j] + obj2.array[i][j];
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator-(TwoDArrayClass &obj1, TwoDArrayClass &obj2)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj1.rows, obj1.cols);
            for (int i = 0; i < obj1.rows; i++)
            {
                for (int j = 0; j < obj1.cols; j++)
                {
                    temp->array[i][j] = obj1.array[i][j] - obj2.array[i][j];
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator*(TwoDArrayClass &obj1, TwoDArrayClass &obj2)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj1.rows, obj1.cols);
            for (int i = 0; i < obj1.rows; i++)
            {
                for (int j = 0; j < obj1.cols; j++)
                {
                    temp->array[i][j] = obj1.array[i][j] * obj2.array[i][j];
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator/(TwoDArrayClass &obj1, TwoDArrayClass &obj2)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj1.rows, obj1.cols);
            for (int i = 0; i < obj1.rows; i++)
            {
                for (int j = 0; j < obj1.cols; j++)
                {
                    temp->array[i][j] = obj1.array[i][j] / obj2.array[i][j];
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator%(TwoDArrayClass &obj1, TwoDArrayClass &obj2)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj1.rows, obj1.cols);
            for (int i = 0; i < obj1.rows; i++)
            {
                for (int j = 0; j < obj1.cols; j++)
                {
                    temp->array[i][j] = obj1.array[i][j] % obj2.array[i][j];
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator*=(TwoDArrayClass &obj1, TwoDArrayClass &obj2)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj1.rows, obj1.cols);
            for (int i = 0; i < obj1.rows; i++)
            {
                for (int j = 0; j < obj1.cols; j++)
                {
                    temp->array[i][j] = obj1.array[i][j] *= obj2.array[i][j];
                }
            }
            return *temp;
        }
        friend TwoDArrayClass &operator/=(TwoDArrayClass &obj1, TwoDArrayClass &obj2)
        {
            TwoDArrayClass *temp = new TwoDArrayClass(obj1.rows, obj1.cols);
            for (int i = 0; i < obj1.rows; i++)
            {
                for (int j = 0; j < obj1.cols; j++)
                {
                    temp->array[i][j] = obj1.array[i][j] /= obj2.array[i][j];
                }
            }
            return *temp;
        }
        //copy function
        TwoDArrayClass &copy()
        {
            TwoDArrayClass *temp = new TwoDArrayClass(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    temp->array[i][j] = array[i][j];
                }
            }
            return *temp;
        }
        //copy constructor
        TwoDArrayClass(const TwoDArrayClass &obj)
        {
            rows = obj.rows;
            cols = obj.cols;
            array = new int *[rows];
            for (int i = 0; i < rows; i++)
            {
                array[i] = new int[cols];
            }
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    array[i][j] = obj.array[i][j];
                }
            }
        }
    };
}

TwoDArray::TwoDArrayClass::TwoDArrayClass()
{
    rows = 0;
    cols = 0;
    array = NULL;
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

int main(int argc, char **argv)
{
    //test all of the functions in this class above
    TwoDArray::TwoDArrayClass twoDArrayClass(3, 3);
    twoDArrayClass.inputArrayElements();
    twoDArrayClass.printArrayElements();
    twoDArrayClass.saveArrayElementsToFile();
    twoDArrayClass.printArrayElementFromFile();
    //test print functions
    twoDArrayClass.printArrayElements(1, 1);
    twoDArrayClass.printArrayElements(2, 2);
    //test set function
    twoDArrayClass.set(1, 1, 5);
    twoDArrayClass.printArrayElements(1, 1);
    //test input function
    twoDArrayClass.inputArrayElements(2, 2);
    twoDArrayClass.printArrayElements(2, 2);
    //test overloaded operators
    TwoDArray::TwoDArrayClass twoDArrayClass2(3, 3);
    twoDArrayClass2.inputArrayElements();
    twoDArrayClass2.printArrayElements();
    if (twoDArrayClass == twoDArrayClass2)
    {
        cout << "The two arrays are equal" << endl;
    }
    else
    {
        cout << "The two arrays are not equal" << endl;
    }
    twoDArrayClass2.set(1, 1, 5);
    if (twoDArrayClass == twoDArrayClass2)
    {
        cout << "The two arrays are equal" << endl;
    }
    else
    {
        cout << "The two arrays are not equal" << endl;
    }
    //test copy constructor
    TwoDArray::TwoDArrayClass copy(twoDArrayClass);
    copy.printArrayElements();
    //test comparison operators
    if (twoDArrayClass < twoDArrayClass2)
    {
        cout << "The first array is less than the second array" << endl;
    }
    else
    {
        cout << "The first array is not less than the second array" << endl;
    }
    if (twoDArrayClass > twoDArrayClass2)
    {
        cout << "The first array is greater than the second array" << endl;
    }
    else
    {
        cout << "The first array is not greater than the second array" << endl;
    }
    if (twoDArrayClass <= twoDArrayClass2)
    {
        cout << "The first array is less than or equal to the second array" << endl;
    }
    else
    {
        cout << "The first array is not less than or equal to the second array" << endl;
    }
    if (twoDArrayClass >= twoDArrayClass2)
    {
        cout << "The first array is greater than or equal to the second array" << endl;
    }
    else
    {
        cout << "The first array is not greater than or equal to the second array" << endl;
    }
    //test add arrays function
    twoDArrayClass.add_arrays(twoDArrayClass2);
    twoDArrayClass.printArrayElements();
    //test subtract arrays function
    twoDArrayClass.subtract_arrays(twoDArrayClass2);
    twoDArrayClass.printArrayElements();
    //test multiply arrays function
    twoDArrayClass.multiply_arrays(twoDArrayClass2);
    //test divide arrays function
    twoDArrayClass.divide_arrays(twoDArrayClass2);
    //test inverse function
    twoDArrayClass.inverse_array();
    twoDArrayClass.printArrayElements();
    //test transpose function
    twoDArrayClass.transpose();
    twoDArrayClass.printArrayElements();
    //test operators
    twoDArrayClass = twoDArrayClass2;
    twoDArrayClass.printArrayElements();
    twoDArrayClass += twoDArrayClass2;
    twoDArrayClass.printArrayElements();
    twoDArrayClass -= twoDArrayClass2;
    twoDArrayClass.printArrayElements();
    twoDArrayClass *= twoDArrayClass2;
    twoDArrayClass.printArrayElements();
    twoDArrayClass /= twoDArrayClass2;
    twoDArrayClass.printArrayElements();
    twoDArrayClass++;
    twoDArrayClass.printArrayElements();
    twoDArrayClass--;
    twoDArrayClass.printArrayElements();
    //test overloaded operators
    TwoDArray::TwoDArrayClass twoDArrayClass4(3, 3);
    twoDArrayClass4.inputArrayElements();
    twoDArrayClass4.printArrayElements();
    if (twoDArrayClass == twoDArrayClass4)
    {
        cout << "The two arrays are equal" << endl;
    }
    else
    {
        cout << "The two arrays are not equal" << endl;
    }
    return 0;
}
