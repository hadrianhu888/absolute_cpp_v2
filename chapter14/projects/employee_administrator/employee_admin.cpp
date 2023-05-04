/**
 * @file employee_admin.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:\\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;

namespace emp
{
    class employee
    {
        public:
            string first_name;
            string middle_name;
            string last_name;
            long int employee_id;
            long int sin;
            string address;
            long double salary;
            employee();
            employee(string first_name,
                     string middle_name,
                     string last_name,
                     long int employee_id,
                     long int sin,
                     string address);
            string setFirst_Name(string first_name);
            string getFirst_Name() const;
            string setMiddle_Name(string middle_name);
            string getMiddle_Name() const;
            string setLast_Name(string last_name);
            string getLast_Name() const;
            long int setEmployee_Id(long int employee_id);
            long int getEmployee_Id() const;
            long int setSin(long int sin);
            long int getSin() const;
            string setAddress(string address);
            string getAddress() const;
            long double setSalary(long double salary);
            long double getSalary() const;
            employee getEmployee() const;
            employee copy();
            employee deleteFromFile(string filename);
            employee searchEmployee(string employee_id, string address);
            employee updateEmployee(string employee_id, string address);
            employee displayAllEmployees();
            ~employee();
    };
} // namespace emp

namespace sal
{
    class SalariedEmployee:public emp::employee
    {
        public:
            string first_name;
            string middle_name;
            string last_name;
            long int employee_id;
            long int sin;
            string address;
            long double salary;
            SalariedEmployee();
            SalariedEmployee(string first_name,
                             string middle_name,
                             string last_name,
                             long int employee_id,
                             long int sin,
                             string address,
                             long double salary);
            long double setSalary(long double salary);
            long double getSalary() const;
            SalariedEmployee getEmployee() const;
            SalariedEmployee copy();
            SalariedEmployee deleteFromFile(string filename);
            SalariedEmployee searchEmployee(string employee_id, string address);
            SalariedEmployee updateEmployee(string employee_id, string address);
            SalariedEmployee displayAllEmployees();
            ~SalariedEmployee();
    };
}

namespace admin
{
    class Administrator:public sal::SalariedEmployee
    {
        public:
            string first_name;
            string middle_name;
            string last_name;
            long int employee_id;
            long int sin;
            string address;
            long double salary;
            Administrator();
            Administrator(string first_name,
                          string middle_name,
                          string last_name,
                          long int employee_id,
                          long int sin,
                          string address,
                          long double salary);
            Administrator getEmployee() const;
            Administrator copy();
            Administrator deleteFromFile(string filename);
            Administrator searchEmployee(string employee_id, string address);
            Administrator updateEmployee(string employee_id, string address);
            Administrator displayAllEmployees();
            ~Administrator();
    };
}

namespace officer
{
    class Officer:public admin::Administrator
    {
        public:
            string first_name;
            string middle_name;
            string last_name;
            long int employee_id;
            long int sin;
            string address;
            long double salary;
            Officer();
            Officer(string first_name,
                    string middle_name,
                    string last_name,
                    long int employee_id,
                    long int sin,
                    string address,
                    long double salary);
            Officer getEmployee() const;
            Officer copy();
            Officer deleteFromFile(string filename);
            Officer searchEmployee(string employee_id, string address);
            Officer updateEmployee(string employee_id, string address);
            Officer displayAllEmployees();
            ~Officer();
    };
}

namespace exec
{
    class Executive:public officer::Officer
    {
        public:
            string first_name;
            string middle_name;
            string last_name;
            long int employee_id;
            long int sin;
            string address;
            long double salary;
            Executive();
            Executive(string first_name,
                      string middle_name,
                      string last_name,
                      long int employee_id,
                      long int sin,
                      string address,
                      long double salary);
            Executive getEmployee() const;
            Executive copy();
            Executive deleteFromFile(string filename);
            Executive searchEmployee(string employee_id, string address);
            Executive updateEmployee(string employee_id, string address);
            Executive displayAllEmployees();
            ~Executive();
    };
}

namespace hourly
{
    class HourlyEmployee:public emp::employee
    {
        public:
            string first_name;
            string middle_name;
            string last_name;
            long int employee_id;
            long int sin;
            string address;
            long double salary;
            HourlyEmployee();
            HourlyEmployee(string first_name,
                           string middle_name,
                           string last_name,
                           long int employee_id,
                           long int sin,
                           string address,
                           long double salary);
            long double setSalary(long double salary);
            long double getSalary() const;
            HourlyEmployee getEmployee() const;
            HourlyEmployee copy();
            HourlyEmployee deleteFromFile(string filename);
            HourlyEmployee searchEmployee(string employee_id, string address);
            HourlyEmployee updateEmployee(string employee_id, string address);
            HourlyEmployee displayAllEmployees();
            ~HourlyEmployee();
    };
}

namespace comm
{
    class CommissionEmployee:public hourly::HourlyEmployee
    {
        public:
            string first_name;
            string middle_name;
            string last_name;
            long int employee_id;
            long int sin;
            string address;
            long double salary;
            CommissionEmployee();
            CommissionEmployee(string first_name,
                               string middle_name,
                               string last_name,
                               long int employee_id,
                               long int sin,
                               string address,
                               long double salary);
            CommissionEmployee getEmployee() const;
            CommissionEmployee copy();
            CommissionEmployee deleteFromFile(string filename);
            CommissionEmployee searchEmployee(string employee_id, string address);
            CommissionEmployee updateEmployee(string employee_id, string address);
            CommissionEmployee displayAllEmployees();
            ~CommissionEmployee();
    };
}

namespace sales
{
    class SalesEmployee:public comm::CommissionEmployee
    {
        public:
            string first_name;
            string middle_name;
            string last_name;
            long int employee_id;
            long int sin;
            string address;
            long double salary;
            SalesEmployee();
            SalesEmployee(string first_name,
                          string middle_name,
                          string last_name,
                          long int employee_id,
                          long int sin,
                          string address,
                          long double salary);
            SalesEmployee getEmployee() const;
            SalesEmployee copy();
            SalesEmployee deleteFromFile(string filename);
            SalesEmployee searchEmployee(string employee_id, string address);
            SalesEmployee updateEmployee(string employee_id, string address);
            SalesEmployee displayAllEmployees();
            ~SalesEmployee();
    };
}

emp::employee::employee()
{
    this->first_name = "";
    this->middle_name = "";
    this->last_name = "";
    this->employee_id = 0;
    this->sin = 0;
    this->address = "";
    this->salary = 0.0;
}

emp::employee::employee(string first_name,
                     string middle_name,
                     string last_name,
                     long int employee_id,
                     long int sin,
                     string address)
{
    this->first_name = first_name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->employee_id = employee_id;
    this->sin = sin;
    this->address = address;
    this->salary = salary;
}

long double emp::employee::setSalary(long double salary)
{
    this->salary = salary;
    return this->salary;
}

long double emp::employee::getSalary() const
{
    return this->salary;
}

emp::employee emp::employee::getEmployee() const
{
    for(int i = 0; i < 1; i++)
    {
        cout << "First Name: " << this->first_name << endl;
        cout << "Middle Name: " << this->middle_name << endl;
        cout << "Last Name: " << this->last_name << endl;
        cout << "Employee ID: " << this->employee_id << endl;
        cout << "SIN: " << this->sin << endl;
        cout << "Address: " << this->address << endl;
        cout << "Salary: " << this->salary << endl;
    }
}

emp::employee emp::employee::copy()
{
    for(int i = 0; i < 1; i++)
    {
        cout << "First Name: " << this->first_name << endl;
        cout << "Middle Name: " << this->middle_name << endl;
        cout << "Last Name: " << this->last_name << endl;
        cout << "Employee ID: " << this->employee_id << endl;
        cout << "SIN: " << this->sin << endl;
        cout << "Address: " << this->address << endl;
        cout << "Salary: " << this->salary << endl;
    }
}

emp::employee emp::employee::deleteFromFile(string filename)
{
    filename = "";
}

emp::employee emp::employee::searchEmployee(string employee_id, string address)
{
    return *this;
}

emp::employee emp::employee::updateEmployee(string employee_id, string address)
{
    return *this;
}

emp::employee emp::employee::displayAllEmployees()
{
    return *this;
}

emp::employee::~employee()
{
    this->first_name = "";
    this->middle_name = "";
    this->last_name = "";
    this->employee_id = 0;
    this->sin = 0;
    this->address = "";
    this->salary = 0.0;
}

admin::Administrator::Administrator()
{
    this->first_name = "";
    this->middle_name = "";
    this->last_name = "";
    this->employee_id = 0;
    this->sin = 0;
    this->address = "";
    this->salary = 0.0;
}

admin::Administrator::Administrator(string first_name,
                                    string middle_name,
                                    string last_name,
                                    long int employee_id,
                                    long int sin,
                                    string address,
                                    long double salary)
{
    this->first_name = first_name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->employee_id = employee_id;
    this->sin = sin;
    this->address = address;
    this->salary = salary;
}

admin::Administrator admin::Administrator::getEmployee() const
{
    return *this;
}

admin::Administrator admin::Administrator::copy()
{
    return *this;
}

admin::Administrator admin::Administrator::deleteFromFile(string filename)
{
    return *this;
}

officer::Officer::Officer()
{
    this->first_name = "";
    this->middle_name = "";
    this->last_name = "";
    this->employee_id = 0;
    this->sin = 0;
    this->address = "";
    this->salary = 0.0;
}

officer::Officer::Officer(string first_name,
                          string middle_name,
                          string last_name,
                          long int employee_id,
                          long int sin,
                          string address,
                          long double salary)
{
    this->first_name = first_name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->employee_id = employee_id;
    this->sin = sin;
    this->address = address;
    this->salary = salary;
}

officer::Officer officer::Officer::getEmployee() const
{
    return *this;
}

officer::Officer officer::Officer::copy()
{
    return *this;
}

officer::Officer officer::Officer::deleteFromFile(string filename)
{
    return *this;
}

hourly::HourlyEmployee::HourlyEmployee()
{
    this->first_name = "";
    this->middle_name = "";
    this->last_name = "";
    this->employee_id = 0;
    this->sin = 0;
    this->address = "";
    this->salary = 0.0;
}

hourly::HourlyEmployee::HourlyEmployee(string first_name,
                                       string middle_name,
                                       string last_name,
                                       long int employee_id,
                                       long int sin,
                                       string address,
                                       long double salary)
{
    this->first_name = first_name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->employee_id = employee_id;
    this->sin = sin;
    this->address = address;
    this->salary = salary;
}

hourly::HourlyEmployee hourly::HourlyEmployee::getEmployee() const
{
    return *this;
}

hourly::HourlyEmployee hourly::HourlyEmployee::copy()
{
    return *this;
}

hourly::HourlyEmployee hourly::HourlyEmployee::deleteFromFile(string filename)
{
    return *this;
}

sales::SalesEmployee::SalesEmployee()
{
    this->first_name = "";
    this->middle_name = "";
    this->last_name = "";
    this->employee_id = 0;
    this->sin = 0;
    this->address = "";
    this->salary = 0.0;
}

sales::SalesEmployee::SalesEmployee(string first_name,
                                    string middle_name,
                                    string last_name,
                                    long int employee_id,
                                    long int sin,
                                    string address,
                                    long double salary)
{
    this->first_name = first_name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->employee_id = employee_id;
    this->sin = sin;
    this->address = address;
    this->salary = salary;
}

sales::SalesEmployee sales::SalesEmployee::getEmployee() const
{
    return *this;
}

sales::SalesEmployee sales::SalesEmployee::copy()
{
    return *this;
}

sales::SalesEmployee sales::SalesEmployee::deleteFromFile(string filename)
{
    return *this;
}

using namespace emp;
using namespace admin;
using namespace officer;
using namespace hourly;
using namespace sales;

int main(int argc, char **argv)
{
    Administrator admin;
    Officer officer;
    HourlyEmployee hourly;
    SalesEmployee sales;

    return 0;
}
