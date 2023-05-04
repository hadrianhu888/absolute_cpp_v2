/**
 * @file discount_sale.cpp
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
#include "discount_sale.h"

using namespace std;

int main()
{
    Sale s1(10, 2, 0.1);
    DiscountSale s2(10, 2, 0.1, 0.1);

    cout << "Sale s1:" << endl;
    s1.print();
    cout << endl;

    cout << "DiscountSale s2:" << endl;
    s2.print();
    cout << endl;

    cout << "Sale s1:" << endl;
    cout << "Actual price: " << s1.getActualPrice() << endl;
    cout << "Tax: " << s1.getTax() << endl;
    cout << "Final price: " << s1.getFinalPrice() << endl;
    cout << endl;

    cout << "DiscountSale s2:" << endl;
    cout << "Actual price: " << s2.getActualPrice() << endl;
    cout << "Tax: " << s2.getTax() << endl;
    cout << "Final price: " << s2.getFinalPrice() << endl;
    cout << endl;

    cout << "Sale s1:" << endl;
    cout << "Bill: " << s1.bill() << endl;
    cout << "Savings: " << s1.savings() << endl;
    cout << endl;

    cout << "DiscountSale s2:" << endl;
    cout << "Bill: " << s2.bill() << endl;
    cout << "Savings: " << s2.savings() << endl;
    cout << endl;

    return 0;
}
