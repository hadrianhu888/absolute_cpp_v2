/**
 * @file nDArray.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

namespace nDA
{
    class nDArray
    {
    private:
        int *array;
        int *dimensions;
        int *multipliers;
        int n;
    public:
        nDArray(int n, int *dimensions);
        int &operator[](int *indices);
        int &operator[](int index);
        int &operator()(int *indices);
        int &operator()(int index);
        nDArray &operator=(const nDArray &rhs);
        nDArray &operator=(const int &rhs);
        nDArray &operator+=(const nDArray &rhs);
        nDArray &operator+=(const int &rhs);
        nDArray &operator-=(const nDArray &rhs);
        nDArray &operator-=(const int &rhs);
        nDArray &operator*=(const nDArray &rhs);
        nDArray &operator*=(const int &rhs);
        nDArray &operator/=(const nDArray &rhs);
        nDArray &operator/=(const int &rhs);
        nDArray &operator%=(const nDArray &rhs);
        nDArray &operator%=(const int &rhs);
        nDArray &operator++();
        nDArray &operator++(int);
        nDArray &operator--();
        nDArray &operator--(int);
        nDArray &operator-();
        nDArray &operator+();
        nDArray &operator!();
        nDArray &operator~();
        nDArray &operator&(const nDArray &rhs);
        nDArray &operator&(const int &rhs);
        nDArray &operator|(const nDArray &rhs);
        nDArray &operator|(const int &rhs);
        nDArray &operator^(const nDArray &rhs);
        nDArray &operator^(const int &rhs);
        nDArray &operator<<(const nDArray &rhs);
        nDArray &operator<<(const int &rhs);
        nDArray &operator>>(const nDArray &rhs);
        nDArray &operator>>(const int &rhs);
        nDArray &operator&&(const nDArray &rhs);
        nDArray &operator&&(const int &rhs);
        nDArray &operator||(const nDArray &rhs);
        nDArray &operator||(const int &rhs);
        nDArray &operator==(const nDArray &rhs);
        nDArray &operator==(const int &rhs);
        nDArray &operator!=(const nDArray &rhs);
        nDArray &operator!=(const int &rhs);
        nDArray &operator<(const nDArray &rhs);
        nDArray &operator<(const int &rhs);
        nDArray &operator<=(const nDArray &rhs);
        nDArray &operator<=(const int &rhs);
        nDArray &operator>(const nDArray &rhs);
        nDArray &operator>(const int &rhs);
        nDArray &operator>=(const nDArray &rhs);
        nDArray &operator>=(const int &rhs);
        nDArray &operator,(const nDArray &rhs);
        nDArray &operator,(const int &rhs);
        nDArray &operator[](const nDArray &rhs);
        nDArray &operator[](const int &rhs);
        nDArray &operator()(const nDArray &rhs);
        nDArray &operator()(const int &rhs);
        nDArray &operator=(const nDArray &rhs) const;
        nDArray &operator=(const int &rhs) const;
        nDArray &operator+=(const nDArray &rhs) const;
        nDArray &operator+=(const int &rhs) const;
        nDArray &operator-=(const nDArray &rhs) const;
        nDArray &operator-=(const int &rhs) const;
        friend ostream &operator<<(ostream &out, const nDArray &rhs);
        friend istream &operator>>(istream &in, nDArray &rhs);
        friend nDArray &operator+(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator+(const nDArray &lhs, const int &rhs);
        friend nDArray &operator+(const int &lhs, const nDArray &rhs);
        friend nDArray &operator-(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator-(const nDArray &lhs, const int &rhs);
        friend nDArray &operator-(const int &lhs, const nDArray &rhs);
        friend nDArray &operator*(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator*(const nDArray &lhs, const int &rhs);
        friend nDArray &operator*(const int &lhs, const nDArray &rhs);
        friend nDArray &operator/(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator/(const nDArray &lhs, const int &rhs);
        friend nDArray &operator/(const int &lhs, const nDArray &rhs);
        friend nDArray &operator%(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator%(const nDArray &lhs, const int &rhs);
        friend nDArray &operator%(const int &lhs, const nDArray &rhs);
        friend nDArray &operator&(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator&(const nDArray &lhs, const int &rhs);
        friend nDArray &operator&(const int &lhs, const nDArray &rhs);
        friend nDArray &operator|(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator|(const nDArray &lhs, const int &rhs);
        friend nDArray &operator|(const int &lhs, const nDArray &rhs);
        friend nDArray &operator^(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator^(const nDArray &lhs, const int &rhs);
        friend nDArray &operator^(const int &lhs, const nDArray &rhs);
        friend nDArray &operator<<(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator<<(const nDArray &lhs, const int &rhs);
        friend nDArray &operator<<(const int &lhs, const nDArray &rhs);
        friend nDArray &operator>>(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator>>(const nDArray &lhs, const int &rhs);
        friend nDArray &operator>>(const int &lhs, const nDArray &rhs);
        friend nDArray &operator&&(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator&&(const nDArray &lhs, const int &rhs);
        friend nDArray &operator&&(const int &lhs, const nDArray &rhs);
        friend nDArray &operator||(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator||(const nDArray &lhs, const int &rhs);
        friend nDArray &operator||(const int &lhs, const nDArray &rhs);
        friend nDArray &operator==(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator==(const nDArray &lhs, const int &rhs);
        friend nDArray &operator==(const int &lhs, const nDArray &rhs);
        friend nDArray &operator!=(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator!=(const nDArray &lhs, const int &rhs);
        friend nDArray &operator!=(const int &lhs, const nDArray &rhs);
        friend nDArray &operator<(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator<(const nDArray &lhs, const int &rhs);
        friend nDArray &operator<(const int &lhs, const nDArray &rhs);
        friend nDArray &operator<=(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator<=(const nDArray &lhs, const int &rhs);
        friend nDArray &operator<=(const int &lhs, const nDArray &rhs);
        friend nDArray &operator>(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator>(const nDArray &lhs, const int &rhs);
        friend nDArray &operator>(const int &lhs, const nDArray &rhs);
        friend nDArray &operator>=(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator>=(const nDArray &lhs, const int &rhs);
        friend nDArray &operator>=(const int &lhs, const nDArray &rhs);
        friend nDArray &operator,(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator,(const nDArray &lhs, const int &rhs);
        friend nDArray &operator,(const int &lhs, const nDArray &rhs);
        friend nDArray &operator+=(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator+=(const nDArray &lhs, const int &rhs);
        friend nDArray &operator+=(const int &lhs, const nDArray &rhs);
        friend nDArray &operator-=(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator-=(const nDArray &lhs, const int &rhs);
        friend nDArray &operator-=(const int &lhs, const nDArray &rhs);
        friend nDArray &operator*=(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator*=(const nDArray &lhs, const int &rhs);
        friend nDArray &operator*=(const int &lhs, const nDArray &rhs);
        friend nDArray &operator/=(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator/=(const nDArray &lhs, const int &rhs);
        friend nDArray &operator/=(const int &lhs, const nDArray &rhs);
        friend nDArray &operator%=(const nDArray &lhs, const nDArray &rhs);
        friend nDArray &operator%=(const nDArray &lhs, const int &rhs);
        friend nDArray &operator%=(const int &lhs, const nDArray &rhs);
        void inputArray();
        void printArray();
        void printArray(int);
        void writeArrayToFile(std::string);
        void writeArrayToFile(std::string, int *array, int size);
        void readArrayFromFile(std::string);
        void readArrayFromFile(std::string, int *array, int size);
        void printArrayToFile(std::string);
        void printArrayToFile(std::string, int *);
        void getUserInput();
        int returnArrayDimensions(int *array);
        nDArray inverse_array();
        nDArray transpose_array();
        float returnDeterminant();
        nDArray returnCofactor();
        nDArray returnAdjoint();
        nDArray returnInverse();
        nDArray returnTranspose();
        void getUserInput(int *array);
        nDArray set(int *array, int size);
        nDArray get(int *array, int size);
        ~nDArray();
    };
} // namespace nDA
