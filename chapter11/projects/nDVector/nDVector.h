#ifndef NDVECTOR_H
#define NDVECTOR_H

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

namespace nv
{
    template <typename T>
    class nDVector
        {
        public:
            nDVector()
            {
                //constructor
            }
            void setDimensions(const vector<int> &dimensions)
            {
                m_dimensions = dimensions;
                m_data.resize(accumulate(m_dimensions.begin(), m_dimensions.end(), 1, multiplies<int>()));
            }
            void setDimensions(int numDimensions, ...)
            {
                va_list args;
                va_start(args, numDimensions);
                m_dimensions.resize(numDimensions);
                for (int i = 0; i < numDimensions; i++)
                {
                    m_dimensions[i] = va_arg(args, int);
                }
                va_end(args);
                m_data.resize(accumulate(m_dimensions.begin(), m_dimensions.end(), 1, multiplies<int>()));
            }
            T &operator[](const vector<int> &indices)
            {
                int index = 0;
                for (int i = 0; i < indices.size(); i++)
                {
                    index += indices[i] * m_dimensions[i];
                }
                return m_data[index];
            }
            const T &operator[](const vector<int> &indices) const
            {
                int index = 0;
                for (int i = 0; i < indices.size(); i++)
                {
                    index += indices[i] * m_dimensions[i];
                }
                return m_data[index];
            }
            const vector<int> &getDimensions() const
            {
                return m_dimensions;
            }
            int getDimension(int index) const
            {
                return m_dimensions[index];
            }
            int getNumDimensions() const
            {
                return m_dimensions.size();
            }
            int getNumElements() const
            {
                return m_data.size();
            }
            int getNumElements(int dimension) const
            {
                return m_dimensions[dimension];
            }
            int getNumElements(int startDimension, int endDimension) const
            {
                int numElements = 1;
                for (int i = startDimension; i <= endDimension; i++)
                {
                    numElements *= m_dimensions[i];
                }
                return numElements;
            }
            ~nDVector()
            {
                //destructor
            }
        private:
            vector<int> m_dimensions;
            vector<T> m_data;
        };
    // Deduction guide
    vector<int> make_vector(int numDimensions, ...);
} // namespace nv

#include "nDVector.cpp"
#endif /* NDVECTOR_H */
