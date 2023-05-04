/**
 * @file pfArray.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PFARRAY_H
#define PFARRAY_H

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

namespace pfarray
{
    class PFArray
    {
        private:
            int capacity;
            int used;
        public:
            int *a;
            PFArray();
            PFArray(int capacityValue);
            PFArray(const PFArray &pfaObject);
            void addElement(int element);
            bool full() const;
            int getCapacity() const;
            int getNumberUsed() const;
            void emptyArray();
            int& operator[](int index);
            PFArray& operator =(const PFArray& rightSide);
            ~PFArray();
    };
} // namespace pfarray

namespace pfarray_derived
{
    class PFArrayD : public pfarray::PFArray
    {
        private:
            int capacity;
        public:
            PFArrayD();
            PFArrayD(int capacityValue);
            PFArrayD(const PFArrayD &pfaObject);
            void addElement(int element);
            int getCapacity() const;
            PFArrayD& operator =(const PFArrayD& rightSide);
            ~PFArrayD();
    };
} // namespace pfarray_derived

#endif // PFARRAY_H
