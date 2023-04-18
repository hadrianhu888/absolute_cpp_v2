/**
 * @file nDVector.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace nv
{
    template <typename T>
    class nDVector
    {
    public:
        nDVector(const vector<int> &dimensions)
        {
            m_dimensions = dimensions;
            int size = 1;
            for (int i = 0; i < m_dimensions.size(); i++)
            {
                size *= m_dimensions[i];
            }
            m_data.resize(size);
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

    private:
        vector<int> m_dimensions;
        vector<T> m_data;
    };
} // namespace nd
