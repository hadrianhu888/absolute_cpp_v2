/**
 * @file sets.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-15
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
        Node<T> *tail;
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

        void print()
        {
            Node<T> *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        bool search(T data)
        {
            Node<T> *temp = head;
            while (temp != NULL)
            {
                if (temp->data == data)
                    return true;
                temp = temp->next;
            }
            return false;
        }

        void deleteNode(T data)
        {
            if (isEmpty())
                throw std::out_of_range("List is empty");

            if (head->data == data)
            {
                deleteAtHead();
                return;
            }

            Node<T> *temp = head;
            while (temp->next != NULL)
            {
                if (temp->next->data == data)
                {
                    Node<T> *nodeToDelete = temp->next;
                    temp->next = temp->next->next;
                    delete nodeToDelete;
                    return;
                }
                temp = temp->next;
            }
        }
};

template <class T>
class Set
{
public:
    LinkedList<T> *buckets;
    int size;
    int numBuckets;

    Set(int numBuckets)
    {
        this->numBuckets = numBuckets;
        buckets = new LinkedList<T>[numBuckets];
        size = 0;
    }

    int hashCode(T key) const
    {
        return key % numBuckets;
    }

    void insert(T key)
    {
        int bucketIndex = hashCode(key);
        if (!buckets[bucketIndex].search(key)) // Check for existing key before insertion
        {
                buckets[bucketIndex].insertAtHead(key);
                size++;
        }
    }

    bool search(T data) const
    {
        int bucketIndex = hashCode(data);
        return buckets[bucketIndex].search(data);
    }


    void deleteKey(T key)
    {
        int bucketIndex = hashCode(key);
        buckets[bucketIndex].deleteNode(key);
        size--;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void print()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            cout << "Bucket " << i << ": ";
            buckets[i].print();
        }
    }

    ~Set()
    {
        delete[] buckets;
    }

    static Set difference(const Set &a, const Set &b)
    {
        Set<T> result(a.numBuckets > b.numBuckets ? a.numBuckets : b.numBuckets);
        for (int i = 0; i < a.numBuckets; i++)
        {
            Node<T> *temp = a.buckets[i].head;
            while (temp != NULL)
            {
                    if (!b.search(temp->data))
                        result.insert(temp->data);
                    temp = temp->next;
            }
        }
        return result;
    }
};

int main()
{
    Set<int> set(7);
    set.insert(10);
    set.insert(20);
    set.insert(15);
    set.insert(7);
    set.insert(22);
    set.insert(35);
    set.insert(7);
    set.insert(22);
    set.insert(7);
    set.insert(22);
    set.isEmpty();
    Set<int> set1(8);
    set1.insert(10);
    set1.insert(20);
    set1.insert(15);
    set1.insert(7);
    set1.insert(22);
    set1.insert(35);
    set1.insert(7);
    set1.insert(22);
    set1.insert(7);
    Set<int> diffSet = Set<int>::difference(set, set1);
    diffSet.print();
    return 0;
}
