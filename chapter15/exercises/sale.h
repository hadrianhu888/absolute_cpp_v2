/**
 * @file sale.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SALE_H
#define SALE_H

#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;

class Sale
{
private:
    float original_price;
    float discount;
    float tax_rate;
public:
    Sale() {}
    Sale(float original_price, float discount, float tax_rate)
        : original_price(original_price), discount(discount), tax_rate(tax_rate) {}

    float getOriginalPrice() const { return original_price; }
    void setOriginalPrice(float original_price) { this->original_price = original_price; }

    float getDiscount() const { return discount; }
    void setDiscount(float discount) { this->discount = discount; }

    float getTaxRate() const { return tax_rate; }
    void setTaxRate(float tax_rate) { this->tax_rate = tax_rate; }

    float getActualPrice() const { return original_price - discount; }
    float getTax() const { return getActualPrice() * tax_rate; }
    float getFinalPrice() const { return getActualPrice() + getTax(); }

    virtual float bill() const { return getFinalPrice(); }
    virtual float savings() const { return original_price - getActualPrice(); }

    void print() const {
        cout << "Original price: " << original_price << endl;
        cout << "Discount: " << discount << endl;
        cout << "Tax rate: " << tax_rate << endl;
        cout << "Actual price: " << getActualPrice() << endl;
        cout << "Tax: " << getTax() << endl;
        cout << "Final price: " << getFinalPrice() << endl;
    }
    ~Sale() {}
};

#endif //SALE_H
