/**
 * @file gas_pump.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

class Gas_Pump
{
    public:
        void setGallons(int newGallons);
        void setPrice(int newPrice);
        void setTotal(int newTotal);
        int getGallons();
        int getPrice();
        int getTotal();
        int setGallonsPrice(int newGallons, int newPrice);
        int getGallonsPrice(int &gallons, int &price);
        int calculateTotal(int gallons, int price);
        int resetGasPump();
        int resetGasPump(int newGallons, int newPrice);
        void print();
    private:
        int gallons;
        int price;
        int total;
}; 

int main(int argc,char **argv);

/**
 * @brief function definitions for class Gas_Pump
 * 
 */

void Gas_Pump::setGallons(int newGallons) { gallons = newGallons; }
void Gas_Pump::setPrice(int newPrice) { price = newPrice; }
void Gas_Pump::setTotal(int newTotal) { total = newTotal; }
int Gas_Pump::getGallons() { return gallons; }
int Gas_Pump::getPrice() { return price; }
int Gas_Pump::getTotal() { return total; }
int Gas_Pump::setGallonsPrice(int newGallons, int newPrice) {
    gallons = newGallons;
    price = newPrice;
    return gallons * price;
}
int Gas_Pump::getGallonsPrice(int &gallons, int &price) {
    gallons = this->gallons;
    price = this->price;
    return gallons * price;
}
int Gas_Pump::calculateTotal(int gallons, int price) {
    total = gallons * price;
    return total;
}
void Gas_Pump::print() {
    cout << "Gallons: " << gallons << endl;
    cout << "Price: " << price << endl;
    cout << "Total: " << total << endl;
}
int Gas_Pump::resetGasPump() {
    gallons = 0;
    price = 0;
    total = 0;
    return 0;
}
int Gas_Pump::resetGasPump(int newGallons, int newPrice) {
    gallons = newGallons;
    price = newPrice;
    total = gallons * price;
    return total;
}
int main(int argc,char **argv) {
    Gas_Pump pump1;
    pump1.setGallons(10);
    pump1.setPrice(2);
    pump1.calculateTotal(pump1.getGallons(), pump1.getPrice());
    pump1.print();
    /**
     * @brief test reset functionality
     * 
     */
    cout << "Resetting Gas Pump" << endl;
    pump1.resetGasPump();
    pump1.print();
    return 0;
}


