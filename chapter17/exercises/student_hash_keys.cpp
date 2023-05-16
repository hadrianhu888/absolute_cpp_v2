/**
 * @file student_hash_keys.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <class T>
class LinkedList
{
public:
    Node<T> *head;

    LinkedList() : head(NULL)
    {
    }

    void insertAtHead(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    T deleteAtHead()
    {
        if (isEmpty())
            throw std::out_of_range("List is empty");

        T data = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        return data;
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

template <class T>
class HashTable
{
private:
    LinkedList<T> *table;
    int size;
    int hashFunction(int key)
    {
        return key % size;
    }

public:
    HashTable(int size)
    {
        this->size = size;
        table = new LinkedList<T>[size];
    }

    void insert(T data)
    {
        int index = hashFunction(data.getHashKey());
        table[index].insertAtHead(data);
    }

    void remove(T data)
    {
        int index = hashFunction(data.getHashKey());
        Node<T> *temp = table[index].head;
        Node<T> *prev = NULL;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                if (prev == NULL)
                    table[index].head = temp->next;
                else
                    prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    bool search(T data)
    {
        int index = hashFunction(data.getHashKey());
        Node<T> *temp = table[index].head;
        while (temp != NULL)
        {
            if (temp->data == data)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << ": ";
            table[i].display();
        }
    }

    ~HashTable()
    {
        delete[] table;
    }
};

class Student
{
private:
    string name;
    int age;
    int rollNo;
    int nineDigitStudentNumber;

public:
    Student () {}
    Student(string name, int age, int rollNo, int nineDigitStudentNumber)
    {
        this->name = name;
        this->age = age;
        this->rollNo = rollNo;
        this->nineDigitStudentNumber = nineDigitStudentNumber;
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    int getAge()
    {
        return age;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    int getRollNo()
    {
        return rollNo;
    }

    void setRollNo(int rollNo)
    {
        this->rollNo = rollNo;
    }

    int getNineDigitStudentNumber()
    {
        return nineDigitStudentNumber;
    }

    void setNineDigitStudentNumber(int nineDigitStudentNumber)
    {
        this->nineDigitStudentNumber = nineDigitStudentNumber;
    }

    int getHashKey() const
    {
        return nineDigitStudentNumber;
    }

    bool operator==(const Student &other) const
    {
        return name == other.name && age == other.age && rollNo == other.rollNo &&
            nineDigitStudentNumber == other.nineDigitStudentNumber;
    }

    friend ostream &operator<<(ostream &os, const Student &student)
    {
        os << student.name;
        return os;
    }
};

void outputHashTable(HashTable<Student> *table)
{
    for (int i = 0; i < 10; i++)
    {
        cout << i << ": ";
        table[i].display();
    }
}

int main(int argc, char **argv)
{
    HashTable<Student> *table = new HashTable<Student>(10);
    for (int i = 0; i < 10; i++)
        table->insert(Student("Student" + to_string(i), 20, i, i));
    table->display();
    table->remove(Student("Student5", 20, 5, 5));
    table->display();
    cout << table->search(Student("Student5", 20, 5, 5)) << endl;
    cout << table->search(Student("Student6", 20, 6, 6)) << endl;
    outputHashTable(table);
    delete table;
    return 0;
}
