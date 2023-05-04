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
#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"

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

class HourlyEmployee : public SalariedEmployee {
private:
    double hourlyRate;
    double hoursWorked;
public:
    HourlyEmployee(const std::string& name, double annualSalary, double hourlyRate, double hoursWorked)
        : SalariedEmployee(name, annualSalary), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double getHourlyRate() const { return hourlyRate; }
    void setHourlyRate(double hourlyRate) { this->hourlyRate = hourlyRate; }

    double getHoursWorked() const { return hoursWorked; }
    void setHoursWorked(double hoursWorked) { this->hoursWorked = hoursWorked; }

    virtual void printCheck() const override {
        std::cout << "Hourly Employee Check:" << std::endl;
        SalariedEmployee::printCheck();
    }
};

class CommissionedEmployee: public SalariedEmployee {
private:
    double commissionRate;
    double salesVolume;
public:
    CommissionedEmployee(const std::string& name, double annualSalary, double commissionRate, double salesVolume)
        : SalariedEmployee(name, annualSalary), commissionRate(commissionRate), salesVolume(salesVolume) {}

    double getCommissionRate() const { return commissionRate; }
    void setCommissionRate(double commissionRate) { this->commissionRate = commissionRate; }

    double getSalesVolume() const { return salesVolume; }
    void setSalesVolume(double salesVolume) { this->salesVolume = salesVolume; }

    virtual void printCheck() const override {
        std::cout << "Commissioned Employee Check:" << std::endl;
        SalariedEmployee::printCheck();
    }
};

class HourlyCommissionedEmployee: public HourlyEmployee {
private:
    double commissionRate;
    double salesVolume;
public:
    HourlyCommissionedEmployee(const std::string& name, double annualSalary, double hourlyRate, double hoursWorked, double commissionRate, double salesVolume)
        : HourlyEmployee(name, annualSalary, hourlyRate, hoursWorked), commissionRate(commissionRate), salesVolume(salesVolume) {}

    double getCommissionRate() const { return commissionRate; }
    void setCommissionRate(double commissionRate) { this->commissionRate = commissionRate; }

    double getSalesVolume() const { return salesVolume; }
    void setSalesVolume(double salesVolume) { this->salesVolume = salesVolume; }

    virtual void printCheck() const override {
        std::cout << "Hourly Commissioned Employee Check:" << std::endl;
        HourlyEmployee::printCheck();
    }
};

class HourlyCommissionedAdministrator: public HourlyCommissionedEmployee {
private:
    std::string title;
    std::string responsibility;
    std::string supervisor;
public:
    HourlyCommissionedAdministrator(const std::string& name, double annualSalary, double hourlyRate, double hoursWorked, double commissionRate, double salesVolume, const std::string& title, const std::string& responsibility, const std::string& supervisor)
        : HourlyCommissionedEmployee(name, annualSalary, hourlyRate, hoursWorked, commissionRate, salesVolume), title(title), responsibility(responsibility), supervisor(supervisor) {}

    const std::string& getTitle() const { return title; }
    void setTitle(const std::string& title) { this->title = title; }

    const std::string& getResponsibility() const { return responsibility; }
    void setResponsibility(const std::string& responsibility) { this->responsibility = responsibility; }

    const std::string& getSupervisor() const { return supervisor; }
    void setSupervisor(const std::string& supervisor) { this->supervisor = supervisor; }

    virtual void printCheck() const override {
        std::cout << "Hourly Commissioned Administrator Check:" << std::endl;
        HourlyCommissionedEmployee::printCheck();
    }
};

class Director: public HourlyCommissionedAdministrator {
private:
    std::string title;
    std::string responsibility;
    std::string supervisor;
public:
    Director(const std::string& name, double annualSalary, double hourlyRate, double hoursWorked, double commissionRate, double salesVolume, const std::string& title, const std::string& responsibility, const std::string& supervisor)
        : HourlyCommissionedAdministrator(name, annualSalary, hourlyRate, hoursWorked, commissionRate, salesVolume, title, responsibility, supervisor) {}

    virtual void printCheck() const override {
        std::cout << "Director Check:" << std::endl;
        HourlyCommissionedAdministrator::printCheck();
    }
};

class Executive: public HourlyCommissionedAdministrator {
private:
    std::string title;
    std::string responsibility;
    std::string supervisor;
public:
    Executive(const std::string& name, double annualSalary, double hourlyRate, double hoursWorked, double commissionRate, double salesVolume, const std::string& title, const std::string& responsibility, const std::string& supervisor)
        : HourlyCommissionedAdministrator(name, annualSalary, hourlyRate, hoursWorked, commissionRate, salesVolume, title, responsibility, supervisor) {}

    virtual void printCheck() const override {
        std::cout << "Executive Check:" << std::endl;
        HourlyCommissionedAdministrator::printCheck();
    }
};

int main() {
    Administrator admin("John Doe", 90000, "Director", "Managing Operations", "Jane Smith");
    admin.printCheck();
    HourlyEmployee hourly("John Doe", 90000, 50, 40);
    hourly.printCheck();
    CommissionedEmployee commissioned("John Doe", 90000, 0.1, 1000000);
    commissioned.printCheck();
    HourlyCommissionedEmployee hourlyCommissioned("John Doe", 90000, 50, 40, 0.1, 1000000);
    hourlyCommissioned.printCheck();
    HourlyCommissionedAdministrator hourlyCommissionedAdmin("John Doe", 90000, 50, 40, 0.1, 1000000, "Director", "Managing Operations", "Jane Smith");
    hourlyCommissionedAdmin.printCheck();
    Director director("John Doe", 90000, 50, 40, 0.1, 1000000, "Director", "Managing Operations", "Jane Smith");
    director.printCheck();
    Executive executive("John Doe", 90000, 50, 40, 0.1, 1000000, "Director", "Managing Operations", "Jane Smith");
    executive.printCheck();
    return 0;
}
