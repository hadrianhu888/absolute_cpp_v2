/**
 * @file pizza.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

class Pizza
{
    private:
        int diameter;
        int slices;
        float price;
        float smallPizza = 10.00;
        float mediumPizza = 12.00;
        float largePizza = 14.00;
        float topping = 2.00;
    public:
        Pizza();
        Pizza(int newDiameter, int newSlices, float newPrice);
        void setDiameter(int newDiameter);
        void setSlices(int newSlices);
        void setPrice(float newPrice);
        int getDiameter();
        int getSlices();
        float getPrice();
        void print();
        Pizza creator();
        int getNumToppings();
        int getPizzaSize();
        Pizza destructor();
};

int main(int argc, char **argv); 
Pizza::Pizza()
{
    diameter = 0;
    slices = 0;
    price = 0;
}

Pizza::Pizza(int newDiameter, int newSlices, float newPrice)
{
    diameter = newDiameter;
    slices = newSlices;
    price = newPrice;
}

void Pizza::setDiameter(int newDiameter)
{
    diameter = newDiameter;
}

void Pizza::setSlices(int newSlices)
{
    slices = newSlices;
}

void Pizza::setPrice(float newPrice)
{
    price = newPrice;
}

int Pizza::getDiameter()
{
    return diameter;
}

int Pizza::getSlices()
{
    return slices;
}

int Pizza::getNumToppings()
{
    /**
     * @brief return number of toppings 
     * 
     */
    int numToppings;
    cout << "How many toppings would you like? ";
    cin >> numToppings;
    return numToppings;
}

int Pizza::getPizzaSize()
{
    /**
     * @brief return pizza size 
     * 1 is small. 2 is medium. 3 is large
     */
    int pizzaSize;
    if (diameter == 10)
    {
        pizzaSize = 1;
    }
    else if (diameter == 12)
    {
        pizzaSize = 2;
    }
    else if (diameter == 14)
    {
        pizzaSize = 3;
    }
    return pizzaSize;
}

float Pizza::getPrice()
{
    /**
     * @brief return price depending on pizza size and number of toppings 
     * 
     */
    int pizzaSize = getPizzaSize();
    int numToppings = getNumToppings();
    if (pizzaSize == 1)
    {
        price = smallPizza + (topping * numToppings);
    }
    else if (pizzaSize == 2)
    {
        price = mediumPizza + (topping * numToppings);
    }
    else if (pizzaSize == 3)
    {
        price = largePizza + (topping * numToppings);
    }
    return price;
}

void Pizza::print()
{
    cout << "Diameter: " << diameter << endl;
    cout << "Slices: " << slices << endl;
    cout << "Price: " << price << endl;
}

Pizza Pizza::creator()
{
    Pizza newPizza;
    return newPizza;
}

Pizza Pizza::destructor()
{
    Pizza newPizza;
    return newPizza;
}

int main(int argc, char **argv)
{
    Pizza pizza1;
    pizza1.setDiameter(10);
    pizza1.setSlices(8);
    pizza1.setPrice(10.00);
    pizza1.print();
    cout << "The price of your pizza is: $" << endl; 
    cout << "Price: " << pizza1.getPrice() << endl;
    return 0;
}



