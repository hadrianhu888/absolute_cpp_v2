/**
 * @file hash_table.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

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
        int hashFunction(T key)
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
            int index = hashFunction(data);
            table[index].insertAtHead(data);
        }

        void remove(T data)
        {
            int index = hashFunction(data);
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
            int index = hashFunction(data);
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

        string generateRandomHash(int size)
        {
            string hash = "";
            for (int i = 0; i < size; i++)
                hash += (char)(rand() % 26 + 97);
            return hash;
        }
};

template <class T>
class Student
{
    private:
        string name;
        int age;
        int rollNo;
        int nineDigitStudentNumber;

    public:
        Student()
        {

        }
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

        bool operator==(const Student &other)
        {
            return name == other.name && age == other.age && rollNo == other.rollNo && nineDigitStudentNumber  == other.nineDigitStudentNumber;
        }
};

void generateHashTable(int size, int data[])
{
    HashTable<int> *table = new HashTable<int>(size);
    for (int i = 0; i < size; i++)
        table->insert(data[i]);
    table->display();
    table->generateRandomHash(size);
    table->remove(5);
    table->display();
    cout << table->search(5) << endl;
    cout << table->search(6) << endl;
    delete table;
}

int main(int argc, char **argv)
{
    HashTable<int> *table = new HashTable<int>(10);
    for (int i = 0; i < 10; i++)
        table->insert(i);
    table->display();
    table->generateRandomHash(10);
    table->remove(5);
    table->display();
    cout << table->search(5) << endl;
    cout << table->search(6) << endl;
    delete table;
    Student<int> *student = new Student<int>("John", 20, 1, 123456789);
    cout << student->getName() << endl;
    cout << student->getAge() << endl;
    cout << student->getRollNo() << endl;
    cout << student->getNineDigitStudentNumber() << endl;
    generateHashTable(10, new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    delete student;
    return 0;
}
