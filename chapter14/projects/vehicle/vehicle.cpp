/**
 * @file vehicle.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;

class Person
{
    protected:
        string name;
        string address;
        string telephone;
    public:
        Person(const string& name, const string& address, const string& telephone)
            : name(name), address(address), telephone(telephone) {}

        const string& getName() const { return name; }
        void setName(const string& name) { this->name = name; }

        const string& getAddress() const { return address; }
        void setAddress(const string& address) { this->address = address; }

        const string& getTelephone() const { return telephone; }
        void setTelephone(const string& telephone) { this->telephone = telephone; }

        virtual void print() const {
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Telephone: " << telephone << endl;
        }
};

class Vehicle
{
protected:
    string manufacturer;
    int cylinders;
    Person owner;
public:
    Vehicle(const string& manufacturer, int cylinders, const Person& owner)
        : manufacturer(manufacturer), cylinders(cylinders), owner(owner) {}

    const string& getManufacturer() const { return manufacturer; }
    void setManufacturer(const string& manufacturer) { this->manufacturer = manufacturer; }

    int getCylinders() const { return cylinders; }
    void setCylinders(int cylinders) { this->cylinders = cylinders; }

    const Person& getOwner() const { return owner; }
    void setOwner(const Person& owner) { this->owner = owner; }

    virtual void print() const {
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Cylinders: " << cylinders << endl;
        cout << "Owner: " << owner.getName() << endl;
    }
};

class Truck: public Vehicle
{
protected:
    double loadCapacity;
    int towingCapacity;
public:
    Truck(const string& manufacturer, int cylinders, const Person& owner, double loadCapacity, int towingCapacity)
        : Vehicle(manufacturer, cylinders, owner), loadCapacity(loadCapacity), towingCapacity(towingCapacity) {}

    double getLoadCapacity() const { return loadCapacity; }
    void setLoadCapacity(double loadCapacity) { this->loadCapacity = loadCapacity; }

    int getTowingCapacity() const { return towingCapacity; }
    void setTowingCapacity(int towingCapacity) { this->towingCapacity = towingCapacity; }

    virtual void print() const override {
        cout << "Truck:" << endl;
        Vehicle::print();
        cout << "Load Capacity: " << loadCapacity << endl;
        cout << "Towing Capacity: " << towingCapacity << endl;
    }
};

int main(int argc, char **argv)
{
    Person owner("John Doe", "123 Main St.", "555-1234");
    Truck truck("Ford", 8, owner, 2000, 10000);
    truck.print();

    return 0;
}
