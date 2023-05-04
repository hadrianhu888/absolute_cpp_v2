/**
 * @file doctor.cpp
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

class Employee
{
protected:
    string name;
    double payRate;
public:
    Employee(const string& name, double payRate)
        : name(name), payRate(payRate) {}

    const string& getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    double getPayRate() const { return payRate; }
    void setPayRate(double payRate) { this->payRate = payRate; }

    virtual void printCheck() const {
        cout << "Pay to the order of: " << name << endl;
        cout << "Amount: $" << payRate / 24 << endl;
    }
};

class SalariedEmployee:public Employee
{
protected:
    double annualSalary;
public:
    SalariedEmployee(const string& name, double annualSalary)
        : Employee(name, annualSalary), annualSalary(annualSalary) {}

    double getAnnualSalary() const { return annualSalary; }
    void setAnnualSalary(double salary) { annualSalary = salary; }

    virtual void printCheck() const override {
        cout << "SalariedEmployee Check:" << endl;
        Employee::printCheck();
    }
};

class Doctor:public SalariedEmployee
{
protected:
    string specialty;
    string license;
public:
    Doctor(const string& name, double annualSalary, const string& specialty, const string& license)
        : SalariedEmployee(name, annualSalary), specialty(specialty), license(license) {}

    const string& getSpecialty() const { return specialty; }
    void setSpecialty(const string& specialty) { this->specialty = specialty; }

    const string& getLicense() const { return license; }
    void setLicense(const string& license) { this->license = license; }
    void copy(const Doctor& d) {
        name = d.name;
        payRate = d.payRate;
        annualSalary = d.annualSalary;
        specialty = d.specialty;
        license = d.license;
    }
    virtual void printCheck() const override {
        cout << "Doctor Check:" << endl;
        SalariedEmployee::printCheck();
    }
    ~Doctor() {}
};

int main(int argc, char **argv)
{
    Doctor d("Dr. John Doe", 100000, "Pediatrics", "123456789");
    d.printCheck();
    return 0;
}
