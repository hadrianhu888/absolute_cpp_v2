/**
 * @file employee_admin_simple.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>

using namespace std;

// SalariedEmployee class
class SalariedEmployee {
protected:
    std::string name;
    double annualSalary;

public:
    SalariedEmployee(const std::string& name, double annualSalary)
        : name(name), annualSalary(annualSalary) {}

    double getAnnualSalary() const { return annualSalary; }
    void setAnnualSalary(double salary) { annualSalary = salary; }

    virtual void printCheck() const {
        std::cout << "Pay to the order of: " << name << std::endl;
        std::cout << "Amount: $" << annualSalary / 24 << std::endl;
    }
};

// Administrator class derived from SalariedEmployee
class Administrator : public SalariedEmployee {
private:
    std::string title;
    std::string responsibility;
    std::string supervisor;

public:
    Administrator(const std::string& name, double annualSalary, const std::string& title, const std::string& responsibility, const std::string& supervisor)
        : SalariedEmployee(name, annualSalary), title(title), responsibility(responsibility), supervisor(supervisor) {}

    const std::string& getTitle() const { return title; }
    void setTitle(const std::string& title) { this->title = title; }

    const std::string& getResponsibility() const { return responsibility; }
    void setResponsibility(const std::string& responsibility) { this->responsibility = responsibility; }

    const std::string& getSupervisor() const { return supervisor; }
    void setSupervisor(const std::string& supervisor) { this->supervisor = supervisor; }

    // Override the printCheck() method
    virtual void printCheck() const override {
        std::cout << "Administrator Check:" << std::endl;
        SalariedEmployee::printCheck();
    }
};

int main() {
    Administrator admin("John Doe", 90000, "Director", "Managing Operations", "Jane Smith");
    admin.printCheck();

    return 0;
}
