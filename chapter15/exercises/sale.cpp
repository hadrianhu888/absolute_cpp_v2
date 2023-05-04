/**
 * @file sale.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"
#include "sale.h"

using namespace std;

class DiscountSale:public Sale
{
private:
    float discount_rate;
public:
    DiscountSale() {}
    DiscountSale(float original_price, float discount, float tax_rate, float discount_rate)
        : Sale(original_price, discount, tax_rate), discount_rate(discount_rate) {}

    float getDiscountRate() const { return discount_rate; }
    void setDiscountRate(float discount_rate) { this->discount_rate = discount_rate; }

    float getActualPrice() const { return (1 - discount_rate) * getOriginalPrice(); }
    float getFinalPrice() const { return getActualPrice() + getTax(); }

    float bill() const { return getFinalPrice(); }
    float savings() const { return getOriginalPrice() - getActualPrice(); }

    void print() const {
        cout << "Original price: " << getOriginalPrice() << endl;
        cout << "Discount: " << getDiscount() << endl;
        cout << "Tax rate: " << getTaxRate() << endl;
        cout << "Discount rate: " << discount_rate << endl;
        cout << "Actual price: " << getActualPrice() << endl;
        cout << "Tax: " << getTax() << endl;
        cout << "Final price: " << getFinalPrice() << endl;
    }

    ~DiscountSale() {}
};

int main()
{
    Sale s1(100, 10, 0.1);
    DiscountSale s2(100, 10, 0.1, 0.1);

    cout << "Sale s1:" << endl;
    s1.print();
    cout << endl;

    cout << "DiscountSale s2:" << endl;
    s2.print();
    cout << endl;

    cout << "Sale s2:" << endl;
    s1 = s2;
    s1.print();
    cout << endl;

    cout << "DiscountSale s1:" << endl;
    s2.print();
    cout << endl;

    return 0;
}
