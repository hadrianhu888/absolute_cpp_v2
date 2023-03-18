/**
 * @file database.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

class DataBase 
{
    private: 
        string name;
        string address;
        string phone;
    public: 
        DataBase();
        DataBase(string name, string address, string phone);
        ~DataBase();
        string get_name();
        string get_address();
        string get_phone();
        void set_name(string name);
        void set_address(string address);
        void set_phone(string phone);
        void input();
        void output();
        void print();
        friend DataBase operator+(DataBase d1, DataBase d2);
        friend bool operator==(DataBase d1, DataBase d2);
        friend bool operator!=(DataBase d1, DataBase d2);
        friend bool operator<(DataBase d1, DataBase d2);
        friend bool operator<=(DataBase d1, DataBase d2);
        friend bool operator>(DataBase d1, DataBase d2);
        friend bool operator>=(DataBase d1, DataBase d2);
};

DataBase::DataBase()
{
    name = "";
    address = "";
    phone = "";
}

DataBase::DataBase(string name, string address, string phone)
{
    this->name = name;
    this->address = address;
    this->phone = phone;
}

DataBase::~DataBase()
{
}

string DataBase::get_name()
{
    return name;
}

string DataBase::get_address()
{
    return address;
}

string DataBase::get_phone()
{
    return phone;
}

void DataBase::set_name(string name)
{
    this->name = name;
}

void DataBase::set_address(string address)
{
    this->address = address;
}

void DataBase::set_phone(string phone)
{
    this->phone = phone;
}

void DataBase::input()
{
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter phone: ";
    getline(cin, phone);
}

void DataBase::output()
{
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
}

void DataBase::print()
{
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
}

DataBase operator+(DataBase d1, DataBase d2)
{
    DataBase temp;
    temp.name = d1.name + d2.name;
    temp.address = d1.address + d2.address;
    temp.phone = d1.phone + d2.phone;
    return temp;
}

bool operator==(DataBase d1, DataBase d2)
{
    return (d1.name == d2.name && d1.address == d2.address && d1.phone == d2.phone);
}

bool operator!=(DataBase d1, DataBase d2)
{
    return !(d1 == d2);
}

bool operator<(DataBase d1, DataBase d2)
{
    return (d1.name < d2.name && d1.address < d2.address && d1.phone < d2.phone);
}

bool operator<=(DataBase d1, DataBase d2)
{
    return (d1 < d2 || d1 == d2);
}

bool operator>(DataBase d1, DataBase d2)
{
    return !(d1 <= d2);
}

bool operator>=(DataBase d1, DataBase d2)
{
    return !(d1 < d2);
}

int main(int argc, char **argv)
{
    DataBase d1("John", "123 Main St", "555-1234");
    DataBase d2("Mary", "456 Main St", "555-5678");
    DataBase d3;
    d3 = d1 + d2;
    d3.print();
    if (d1 == d2)
        cout << "d1 and d2 are equal" << endl;
    else
        cout << "d1 and d2 are not equal" << endl;
    if (d1 != d2)
        cout << "d1 and d2 are not equal" << endl;
    else
        cout << "d1 and d2 are equal" << endl;
    if (d1 < d2)
        cout << "d1 is less than d2" << endl;
    else
        cout << "d1 is not less than d2" << endl;
    if (d1 <= d2)
        cout << "d1 is less than or equal to d2" << endl;
    else
        cout << "d1 is not less than or equal to d2" << endl;
    if (d1 > d2)
        cout << "d1 is greater than d2" << endl;
    else
        cout << "d1 is not greater than d2" << endl;
    if (d1 >= d2)
        cout << "d1 is greater than or equal to d2" << endl;
    else
        cout << "d1 is not greater than or equal to d2" << endl;
    return 0;
}