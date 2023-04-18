#ifndef NDARRAY_H
#define NDARRAY_H

#include <vector>

namespace nd
{

    template <typename T>
    class nDArray
    {

        public:
            // Constructor
            nDArray(const std::vector<int> &dimensions) : dimensions_(dimensions)
            {
                // Initialize the cumProd_ vector
                cumProd_.push_back(1);
                for (int i = 0; i < dimensions_.size(); i++)
                {
                    cumProd_.push_back(cumProd_[i] * dimensions_[i]);
                }

                // Initialize the data_ vector
                data_.resize(cumProd_[cumProd_.size() - 1]);
            }

            // Copy constructor
            nDArray(const nDArray<T> &other) : data_(other.data_), dimensions_(other.dimensions_), cumProd_(other.cumProd_)
            {
                for(int i = 0; i < data_.size(); i++)
                {
                    data_[i] = other.data_[i];
                }
            }

            // Destructor
            ~nDArray()
            {
                for(int i = 0; i < data_.size(); i++)
                {
                    data_[i] = 0;
                }
            }

            // Accessors
            std::vector<int> getDimensions() const
            {
                return dimensions_;
            }
            T &operator[](const std::vector<int> &indices);
            const T &operator[](const std::vector<int> &indices) const;

        private:
            // Member variables
            std::vector<T> data_;
            std::vector<int> dimensions_;
            std::vector<int> cumProd_;
    };

} // namespace nd

#include "nDArray.cpp"

#endif // NDARRAY_H
