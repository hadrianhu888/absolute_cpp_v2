/**
 * @file employee.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

namespace base
{
    class Employee
    {
        private:
            string name;
            string ssn;
            double net_pay;
        public:
            Employee();
            Employee(const string &the_name, const string &the_number);
            string get_name() const;
            string get_ssn() const;
            double get_net_pay() const;
            void set_name(const string &new_name);
            void set_ssn(const string &new_ssn);
            void set_net_pay(double new_net_pay);
            void print_check() const;
    };
} // namespace base

namespace derived
{
    class HourlyEmployee : public base::Employee
    {
        private:
            double wage_rate;
            double hours;
        public:
            HourlyEmployee();
            HourlyEmployee(const string &the_name, const string &the_ssn, double the_wage_rate, double the_hours);
            void set_rate(double new_wage_rate);
            double get_rate() const;
            void set_hours(double hours_worked);
            double get_hours() const;
            void print_check();
    };
} // namespace derived

namespace derived
{
    class SalariedEmployee : public base::Employee
    {
        private:
            double salary;
        public:
            SalariedEmployee();
            SalariedEmployee(const string &the_name, const string &the_ssn, double the_weekly_salary);
            void set_salary(double new_salary);
            double get_salary() const;
            void print_check();
    };
} // namespace derived

namespace derived
{
    class ContractorEmployee : public base::Employee
    {
        private:
            double hourly_rate;
            double hours;
        public:
            ContractorEmployee();
            ContractorEmployee(const string &the_name, const string &the_ssn, double the_hourly_rate, double the_hours);
            void set_rate(double new_hourly_rate);
            double get_rate() const;
            void set_hours(double hours_worked);
            double get_hours() const;
            void print_check();
    };
} // namespace derived

namespace derived
{
class TitledEmployee : public SalariedEmployee
{
        private:
            string title;

        public:
            TitledEmployee();
            TitledEmployee(const string &the_name,
                           const string &the_ssn,
                           double the_weekly_salary,
                           const string &the_title);
            void set_title(const string &new_title);
            string get_title() const;
            void print_check();
};
} // namespace derived


int main(int argc, char **argv);

int main(int argc, char **argv)
{
    derived::HourlyEmployee joe("Mighty Joe", "123456789", 20.50, 40);
    derived::SalariedEmployee boss("Mr. Big Shot", "987654321", 10500);
    derived::ContractorEmployee john("John Smith", "111111111", 60, 40);
    derived::TitledEmployee jane("Jane Doe", "222222222", 10000, "CEO");

    joe.print_check();
    cout << endl;
    boss.print_check();
    cout << endl;
    john.print_check();
    cout << endl;
    jane.print_check();
    cout << endl;

    return 0;
}

base::Employee::Employee() : name("No name yet"), ssn("No number yet"), net_pay(0)
{
    // empty
}

base::Employee::Employee(const string &the_name, const string &the_number) : name(the_name), ssn(the_number), net_pay(0)
{
    // empty
}

string base::Employee::get_name() const
{
    return name;
}

string base::Employee::get_ssn() const
{
    return ssn;
}

double base::Employee::get_net_pay() const
{
    return net_pay;
}

void base::Employee::set_name(const string &new_name)
{
    name = new_name;
}

void base::Employee::set_ssn(const string &new_ssn)
{
    ssn = new_ssn;
}

void base::Employee::set_net_pay(double new_net_pay)
{
    net_pay = new_net_pay;
}

void base::Employee::print_check() const
{
    cout << "\nERROR: print_check FUNCTION CALLED FOR AN \n"
         << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
         << "Check with the author of the program about this bug.\n";
    exit(1);
}

derived::HourlyEmployee::HourlyEmployee() : base::Employee(), wage_rate(0), hours(0)
{
    // empty
}

derived::HourlyEmployee::HourlyEmployee(const string &the_name, const string &the_ssn, double the_wage_rate, double the_hours) : base::Employee(the_name, the_ssn), wage_rate(the_wage_rate), hours(the_hours)
{
    // empty
}

void derived::HourlyEmployee::set_rate(double new_wage_rate)
{
    wage_rate = new_wage_rate;
}

double derived::HourlyEmployee::get_rate() const
{
    return wage_rate;
}

void derived::HourlyEmployee::set_hours(double hours_worked)
{
    hours = hours_worked;
}

double derived::HourlyEmployee::get_hours() const
{
    return hours;
}

void derived::HourlyEmployee::print_check()
{
    set_net_pay(hours * wage_rate);

    cout << "\n________________________________________________\n";
    cout << "Pay to the order of " << get_name() << endl;
    cout << "The sum of " << get_net_pay() << " Dollars\n";
    cout << "________________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << get_ssn() << endl;
    cout << "Hourly Employee. \nHours worked: " << hours << " Rate: " << wage_rate << " Pay: " << get_net_pay() << endl;
    cout << "_________________________________________________\n";
}

derived::SalariedEmployee::SalariedEmployee() : base::Employee(), salary(0)
{
    // empty
}

derived::SalariedEmployee::SalariedEmployee(const string &the_name, const string &the_ssn, double the_weekly_salary) : base::Employee(the_name, the_ssn), salary(the_weekly_salary)
{
    // empty
}

void derived::SalariedEmployee::set_salary(double new_salary)
{
    salary = new_salary;
}

double derived::SalariedEmployee::get_salary() const
{
    return salary;
}

void derived::SalariedEmployee::print_check()
{
    set_net_pay(salary);

    cout << "\n________________________________________________\n";
    cout << "Pay to the order of " << get_name() << endl;
    cout << "The sum of " << get_net_pay() << " Dollars\n";
    cout << "________________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << get_ssn() << endl;
    cout << "Salaried Employee. Regular Pay: " << salary << endl;
    cout << "_________________________________________________\n";
}

derived::ContractorEmployee::ContractorEmployee() : base::Employee(), hourly_rate(0), hours(0)
{
    // empty
}

derived::ContractorEmployee::ContractorEmployee(const string &the_name, const string &the_ssn, double the_hourly_rate, double the_hours) : base::Employee(the_name, the_ssn), hourly_rate(the_hourly_rate), hours(the_hours)
{
    // empty
}

void derived::ContractorEmployee::set_rate(double new_hourly_rate)
{
    hourly_rate = new_hourly_rate;
}

double derived::ContractorEmployee::get_rate() const
{
    return hourly_rate;
}

void derived::ContractorEmployee::set_hours(double hours_worked)
{
    hours = hours_worked;
}

double derived::ContractorEmployee::get_hours() const
{
    return hours;
}

void derived::ContractorEmployee::print_check()
{
    set_net_pay(hours * hourly_rate);

    cout << "\n________________________________________________\n";
    cout << "Pay to the order of " << get_name() << endl;
    cout << "The sum of " << get_net_pay() << " Dollars\n";
    cout << "________________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << get_ssn() << endl;
    cout << "Contractor Employee. \nHours worked: " << hours << " Rate: " << hourly_rate << " Pay: " << get_net_pay() << endl;
    cout << "_________________________________________________\n";
}

derived::TitledEmployee::TitledEmployee() : SalariedEmployee(), title("No title yet")
{
    // empty
}

derived::TitledEmployee::TitledEmployee(const string &the_name, const string &the_ssn, double the_weekly_salary, const string &the_title) : SalariedEmployee(the_name, the_ssn, the_weekly_salary), title(the_title)
{
    // empty
}

void derived::TitledEmployee::print_check()
{
    set_net_pay(get_salary());

    cout << "\n________________________________________________\n";
    cout << "Pay to the order of " << get_name() << endl;
    cout << "The sum of " << get_net_pay() << " Dollars\n";
    cout << "________________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << get_ssn() << endl;
    cout << "Titled Employee. Title: " << title << " Regular Pay: " << get_salary() << endl;
    cout << "_________________________________________________\n";
}

void showEmployeeData(base::Employee &object)
{
    cout << "Name: " << object.get_name() << endl;
    cout << "SSN: " << object.get_ssn() << endl;
    cout << "Net Pay: " << object.get_net_pay() << endl;
}
