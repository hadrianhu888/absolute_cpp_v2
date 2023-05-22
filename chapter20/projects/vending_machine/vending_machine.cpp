/**
 * @file vending_machine.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

class VendingMachine
{
    private:
        int soft_drink_count;
        int juice_count;
        int water_count;
        double soft_drink_price;
        double juice_price;
        double water_price;
        double total_amount;
        double total_sales;
        void setSoftDrinkCount(int count){soft_drink_count = count;}
        int getSoftDrinkCount()
        {
            return soft_drink_count;
        }
        int getJuiceCount()
        {
            return juice_count;
        }
        int getWaterCount()
        {
            return water_count;
        }
        double getSoftDrinkPrice()
        {
            return soft_drink_price;
        }
        double getJuicePrice()
        {
            return juice_price;
        }
        double getWaterPrice()
        {
            return water_price;
        }
        double getTotalAmount()
        {
            return total_amount;
        }
        double getTotalSales()
        {
            return total_sales;
        }
        double setSoftDrinkPrice(double price)
        {
            soft_drink_price = price;
        }
        double setJuicePrice(double price)
        {
            juice_price = price;
        }
        double setWaterPrice(double price)
        {
            water_price = price;
        }
    public:
        VendingMachine();
        VendingMachine(int soft_drink_count, int juice_count, int water_count, double soft_drink_price, double juice_price, double water_price);
        void displayChoices();
        void buySoftDrink();
        void buyJuice();
        void buyWater();
        void displayTotalAmount();
        void displayTotalSales();
        void displayAll();
};

int main(int argc, char **argv);

VendingMachine::VendingMachine()
{
    soft_drink_count = 20;
    juice_count = 20;
    water_count = 20;
    soft_drink_price = 1.00;
    juice_price = 1.50;
    water_price = 0.75;
    total_amount = 0.0;
    total_sales = 0.0;
}

VendingMachine::VendingMachine(int soft_drink_count, int juice_count, int water_count, double soft_drink_price, double juice_price, double water_price)
{
    this->soft_drink_count = soft_drink_count;
    this->juice_count = juice_count;
    this->water_count = water_count;
    this->soft_drink_price = soft_drink_price;
    this->juice_price = juice_price;
    this->water_price = water_price;
    total_amount = 0.0;
    total_sales = 0.0;
}

void VendingMachine::displayChoices()
{
    cout << "1. Soft Drink" << endl;
    cout << "2. Juice" << endl;
    cout << "3. Water" << endl;
    cout << "4. Exit" << endl;
}

void VendingMachine::buySoftDrink()
{
    if (soft_drink_count > 0)
    {
        soft_drink_count--;
        total_amount += soft_drink_price;
        total_sales += soft_drink_price;
    }
    else
    {
        cout << "Soft drink is sold out." << endl;
    }
}

void VendingMachine::buyJuice()
{
    if (juice_count > 0)
    {
        juice_count--;
        total_amount += juice_price;
        total_sales += juice_price;
    }
    else
    {
        cout << "Juice is sold out." << endl;
    }
}

void VendingMachine::buyWater()
{
    if (water_count > 0)
    {
        water_count--;
        total_amount += water_price;
        total_sales += water_price;
    }
    else
    {
        cout << "Water is sold out." << endl;
    }
}

void VendingMachine::displayTotalAmount()
{
    cout << "Total amount: $" << total_amount << endl;
}

void VendingMachine::displayTotalSales()
{
    cout << "Total sales: $" << total_sales << endl;
}

void VendingMachine::displayAll()
{
    cout << "Soft drink count: " << soft_drink_count << endl;
    cout << "Juice count: " << juice_count << endl;
    cout << "Water count: " << water_count << endl;
    cout << "Soft drink price: $" << soft_drink_price << endl;
    cout << "Juice price: $" << juice_price << endl;
    cout << "Water price: $" << water_price << endl;
    cout << "Total amount: $" << total_amount << endl;
    cout << "Total sales: $" << total_sales << endl;
}

int main(int argc, char **argv)
{
    VendingMachine vending_machine;
    int choice;
    do
    {
        vending_machine.displayChoices();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                vending_machine.buySoftDrink();
                break;
            case 2:
                vending_machine.buyJuice();
                break;
            case 3:
                vending_machine.buyWater();
                break;
            case 4:
                vending_machine.displayTotalAmount();
                break;
            case 5:
                vending_machine.displayTotalSales();
                break;
            case 6:
                vending_machine.displayAll();
                break;
            case 7:
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 7);
    return 0;
}
