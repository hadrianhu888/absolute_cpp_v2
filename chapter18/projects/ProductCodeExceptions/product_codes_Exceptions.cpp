/**
 * @file product_codes_Exceptions.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template <class T>
class ProductCode
{
public:
    ProductCode() = default;
    ProductCode(const T &data) : _data(data)
    {
        try
        {
            if (_data < 0)
            {
                throw _data;
            }
        }
        catch (int e)
        {
            cout << "Negative number: " << e << endl;
        }
    }
    friend ostream &operator<<(ostream &os, const ProductCode &pc)
    {
        os << "Negative number: " << pc._data << endl;
        return os;
    }
    int getCount() const
    {
        try
        {
            if (_data < 0)
            {
                throw _data;
            }
        }
        catch (int e)
        {
            cout << "Negative number: " << e << endl;
        }
        return _data;
    }
private:
    T _data;
};

int getProductID(int ids[], string names[], int numProducts, string target)
{
    for (int i = 0; i < numProducts; i++)
    {
        if (names[i] == target)
        {
            return ids[i];
        }
    }
    throw target;
}

int main()
{
    int productIds[] = {4, 5, 8, 10, 13};
    string products[] = {"computer", "flash drive", "mouse", "printer", "camera"};
    int numProducts = 5;
    string prodName;
    cout << "Enter a product name: ";
    cin >> prodName;
    try
    {
        int id = getProductID(productIds, products, numProducts, prodName);
        cout << "Product ID: " << id << endl;
    }
    catch (string target)
    {
        cout << "Sorry, " << target << " is not in the product list.\n";
    }
    return 0;
}
