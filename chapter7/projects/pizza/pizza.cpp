/**
 * @file pizza.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

class Pizza
{
    private:
        int diameter;
        int slices;
        int toppings;
        int price;
    public:
        Pizza(int diameter, int slices, int toppings, int price);
        void print();
        int getDiameter();
        void setDiameter(int diameter);
        int getSlices();
        void setSlices(int slices);
        int getToppings();
        void setToppings(int toppings);
        int getPrice();
        void setPrice(int price);
        void calculatePrice();
        void calculatePrice(int diameter, int slices, int toppings);
};

Pizza::Pizza(int diameter, int slices, int toppings, int price)
{
    this->diameter = diameter;
    this->slices = slices;
    this->toppings = toppings;
    this->price = price;
}

void Pizza::print()
{
    cout << "diameter = " << diameter << endl;
    cout << "slices = " << slices << endl;
    cout << "toppings = " << toppings << endl;
    cout << "price = " << price << endl;
}

int Pizza::getDiameter()
{
    return diameter;
}

void Pizza::setDiameter(int diameter)
{
    this->diameter = diameter;
}

int Pizza::getSlices()
{
    return slices;
}

void Pizza::setSlices(int slices)
{
    this->slices = slices;
}

int Pizza::getToppings()
{
    return toppings;
}

void Pizza::setToppings(int toppings)
{
    this->toppings = toppings;
}

int Pizza::getPrice()
{
    return price;
}

void Pizza::setPrice(int price)
{
    this->price = price;
}

void Pizza::calculatePrice()
{
    price = 10 + 2 * diameter + 2 * toppings;
}

void Pizza::calculatePrice(int diameter, int slices, int toppings)
{
    price = 10 + 2 * diameter + 2 * toppings;
}

int main(int argc, char **argv)
{
    /**
     * @brief create a vector of pizzas and then print the details of each pizza - and find the total price of all the pizzas
     * 
     */
    vector<Pizza> pizzas;
    pizzas.push_back(Pizza(12, 8, 2, 0));
    pizzas.push_back(Pizza(14, 10, 3, 0));
    pizzas.push_back(Pizza(16, 12, 4, 0));
    pizzas.push_back(Pizza(18, 14, 5, 0));
    pizzas.push_back(Pizza(20, 16, 6, 0));
    pizzas.push_back(Pizza(22, 18, 7, 0));
    pizzas.push_back(Pizza(24, 20, 8, 0));
    for (int i = 0; i < pizzas.size(); i++)
    {
        pizzas[i].calculatePrice();
        pizzas[i].print();
    }
    /**
     * @brief find total price of all the pizzas
     * 
     */
    int total_price = 0;
    for (int i = 0; i < pizzas.size(); i++)
    {
        total_price += pizzas[i].getPrice();
    }
    /**
     * @brief print the total price of all the pizzas
     * 
     */
    cout << "total price = " << total_price << endl;
    return 0;
}