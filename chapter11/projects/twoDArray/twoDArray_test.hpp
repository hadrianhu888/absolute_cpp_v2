/**
 * @file twoDArray.h
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

#ifndef TWO_D_ARRAY_HPP
#define TWO_D_ARRAY_HPP

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
        void print();
        void print(const int row);
        void print(int row, int col);
        void print(const int row, const int col, const int value);
        void saveToFile();
        void printFromFile();
        friend ostream &operator<<(ostream &out, TwoDArrayClass &TwoDArrayClass);
        friend istream &operator>>(istream &in, TwoDArrayClass &TwoDArrayClass);
        friend TwoDArrayClass &operator+(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator-(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator*(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator/(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator%(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator^(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator&(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator|(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator<<(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator>>(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator~(TwoDArrayClass &TwoDArrayClass1);
        friend TwoDArrayClass &operator!(TwoDArrayClass &TwoDArrayClass1);
        friend TwoDArrayClass &operator==(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator!=(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator<(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator>(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator<=(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator>=(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator&&(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator||(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator+=(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator-=(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator*=(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator/=(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        friend TwoDArrayClass &operator%=(TwoDArrayClass &TwoDArrayClass1, TwoDArrayClass &TwoDArrayClass2);
        ~TwoDArrayClass();
    };
}; // namespace TwoDArrayClass

#endif // TWO_D_ARRAY_H
