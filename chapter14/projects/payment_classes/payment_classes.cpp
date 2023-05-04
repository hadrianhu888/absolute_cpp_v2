/**
 * @file payment_classes.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;

class Payment
{
protected:
    double amount;
public:
    Payment(double amount)
        : amount(amount) {}

    double getAmount() const { return amount; }
    void setAmount(double amount) { this->amount = amount; }

    virtual void paymentDetails() const {
        cout << "Payment amount: $" << amount << endl;
    }
    ~Payment() {}
};

class CashPayment:public Payment
{
public:
    CashPayment(double amount)
        : Payment(amount) {}

    virtual void paymentDetails() const override {
        cout << "Cash payment amount: $" << amount << endl;
    }
    ~CashPayment() {}
};

class CreditCardPayment:public Payment
{
protected:
    string name;
    string expirationDate;
    string number;
public:
    CreditCardPayment(double amount, const string& name, const string& expirationDate, const string& number)
        : Payment(amount), name(name), expirationDate(expirationDate), number(number) {}

    const string& getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    const string& getExpirationDate() const { return expirationDate; }
    void setExpirationDate(const string& expirationDate) { this->expirationDate = expirationDate; }

    const string& getNumber() const { return number; }
    void setNumber(const string& number) { this->number = number; }

    virtual void paymentDetails() const override {
        cout << "Credit card payment amount: $" << amount << endl;
        cout << "Name: " << name << endl;
        cout << "Expiration date: " << expirationDate << endl;
        cout << "Number: " << number << endl;
    }
    ~CreditCardPayment() {}
};

int main()
{
    Payment* payment1 = new Payment(100.0);
    payment1->paymentDetails();
    delete payment1;

    Payment* payment2 = new CashPayment(100.0);
    payment2->paymentDetails();
    delete payment2;

    Payment* payment3 = new CreditCardPayment(100.0, "John Doe", "12/25", "1234567890");
    payment3->paymentDetails();
    delete payment3;

    return 0;
}
