/**
 * @file hash_maps.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include <unordered_map>

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
};

template <class T>
class Stack : public LinkedList<T>
{
public:
    Stack() : LinkedList<T>()
    {
    }

    void push(T data)
    {
        this->insertAtHead(data);
    }

    T pop()
    {
        return this->deleteAtHead();
    }

    bool isEmpty()
    {
        return this->head == NULL;
    }
};

template <class T>
class Queue : public LinkedList<T>
{
public:
    Queue() : LinkedList<T>()
    {
    }

    void enqueue(T data)
    {
        this->insertAtHead(data);
    }

    T dequeue()
    {
        if (this->isEmpty())
            throw std::out_of_range("Queue is empty");

        Node<T> *current = this->head;
        Node<T> *previous = NULL;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }

        T data = current->data;
        delete current;
        if (previous != NULL)
            previous->next = NULL;
        else
            this->head = NULL;
        return data;
    }

    bool isEmpty()
    {
        return this->head == NULL;
    }
};

template <class T>
class HashMap
{
private:
    int size;
    LinkedList<T> **buckets;

    int hashFunction(T key)
    {
        return key % size;
    }
public:
    HashMap(int size)
    {
        this->size = size;
        buckets = new LinkedList<T> *[size];
        for (int i = 0; i < size; i++)
            buckets[i] = new LinkedList<T>();
    }

    void insert(T key)
    {
        int index = hashFunction(key);
        if (buckets[index] == NULL)
            buckets[index] = new LinkedList<T>();
        buckets[index]->insertAtHead(key);
    }

    bool search(T key)
    {
        int index = hashFunction(key);
        if (buckets[index] == NULL)
            return false;
        Node<T> *current = buckets[index]->head;
        while (current != NULL)
        {
            if (current->data == key)
                return true;
            current = current->next;
        }
        return false;
    }

    void remove(T key)
    {
        int index = hashFunction(key);
        if (buckets[index] == NULL)
            return;
        Node<T> *current = buckets[index]->head;
        Node<T> *previous = NULL;
        while (current != NULL)
        {
            if (current->data == key)
            {
                if (previous == NULL)
                {
                    Node<T> *nextNode = current->next;
                    buckets[index]->head = nextNode;
                }
                else
                {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << ": ";
            Node<T> *current = buckets[i]->head;
            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    void generateHash(const char *key)
    {
        int index = 0;
        int length = strlen(key);
        for (int i = 0; i < length; i++)
        {
            index += key[i];
        }
        cout << index << endl;
    }
};

int main()
{
    HashMap<int> buckets(10);
    buckets.insert(1);
    buckets.insert(2);
    buckets.insert(3);
    buckets.insert(4);
    buckets.insert(5);
    buckets.insert(6);
    buckets.insert(7);
    buckets.insert(8);
    buckets.insert(9);
    buckets.insert(10);
    for(int i = 0; i < 10;)
    {
        if (buckets.search(i))
        {
            buckets.remove(i);
            i++;
        }
        else
            i++;
    }
    buckets.print();
    for(int i = 0; i < 10; i++)
    {
        buckets.insert(i);
        buckets.generateHash(to_string(i).c_str());
    }
    buckets.print();
    return 0;
}
