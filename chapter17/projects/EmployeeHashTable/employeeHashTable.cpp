/**
 * @file employeeHashTable.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

class Node
{
public:
    string _name;
    int _id;
    Node *_next;

    Node(const string &name, int id, Node *next = NULL) : _name(name), _id(id), _next(next) {}
};

class Employee
{
public:
    string _name;
    int _id;

    Employee(const string &name = "", int id = 0) : _name(name), _id(id) {}
};

class EmployeeHashTable
{
private:
    Node **_table;
    int _size;
public:
    EmployeeHashTable(int size = 100);
    ~EmployeeHashTable();
    void insert(const Employee &employee);
    void remove(const string &name);
    void print() const;
    int hash(const string &name) const;
};

EmployeeHashTable::EmployeeHashTable(int size) : _size(size)
{
    _table = new Node *[_size];
    for (int i = 0; i < _size; ++i)
    {
        _table[i] = NULL;
    }
}

EmployeeHashTable::~EmployeeHashTable()
{
    for (int i = 0; i < _size; ++i)
    {
        Node *p = _table[i];
        while (p != NULL)
        {
            Node *temp = p;
            p = p->_next;
            delete temp;
        }
    }
    delete[] _table;
}

void EmployeeHashTable::insert(const Employee &employee)
{
    int index = hash(employee._name);
    _table[index] = new Node(employee._name, employee._id, _table[index]);
}

void EmployeeHashTable::remove(const string &name)
{
    int index = hash(name);
    Node *p = _table[index];
    if (p == NULL)
    {
        return;
    }
    if (p->_name == name)
    {
        _table[index] = p->_next;
        delete p;
        return;
    }
    while (p->_next != NULL && p->_next->_name != name)
    {
        p = p->_next;
    }
    if (p->_next != NULL)
    {
        Node *temp = p->_next;
        p->_next = p->_next->_next;
        delete temp;
    }
}

void EmployeeHashTable::print() const
{
    for (int i = 0; i < _size; ++i)
    {
        Node *p = _table[i];
        while (p != NULL)
        {
            cout << p->_name << " " << p->_id << endl;
            p = p->_next;
        }
    }
}

int EmployeeHashTable::hash(const string &name) const
{
    int sum = 0;
    for (int i = 0; i < name.length(); ++i)
    {
        sum += name[i];
    }
    return sum % _size;
}

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    /**
     * @brief test EmployeeHashTable
     *
     */
    EmployeeHashTable employeeHashTable;
    employeeHashTable.insert(Employee("John", 123));
    employeeHashTable.insert(Employee("Mary", 234));
    employeeHashTable.insert(Employee("Tom", 345));
    employeeHashTable.insert(Employee("David", 456));
    employeeHashTable.insert(Employee("Rose", 567));
    employeeHashTable.insert(Employee("Alice", 678));
    employeeHashTable.print();
    for(int i = 0; i < 10; ++i)
    {
        employeeHashTable.insert(Employee("John", 123));
    }
    employeeHashTable.print();
    cout << endl;
    employeeHashTable.remove("John");
    employeeHashTable.remove("Mary");
    employeeHashTable.remove("Tom");
    employeeHashTable.remove("David");
    employeeHashTable.remove("Rose");
    employeeHashTable.remove("Alice");
    employeeHashTable.print();
    employeeHashTable.~EmployeeHashTable();
    cout << endl;
    return 0;
}
