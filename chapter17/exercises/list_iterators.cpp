/**
 * @file list_iterators.cpp
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

        void insertAtTail(T data)
        {
            Node<T> *newNode = new Node<T>(data);
            if (isEmpty())
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void print()
        {
            Node<T> *temp = head;
            if (temp != NULL)
            {
                cout << temp->data;
                temp = temp->next;
            }
            while (temp != NULL)
            {
                cout << "-> " << temp->data;
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
class ListIterator
{
    private:
        Node<T> *current;

    public:
        ListIterator(Node<T> *head)
        {
            current = head;
        }

        bool hasNext()
        {
            return current != NULL;
        }

        T next()
        {
            if (!hasNext())
                throw std::out_of_range("No more elements");

            T data = current->data;
            current = current->next;
            return data;
        }

        T peek()
        {
            if (!hasNext())
                throw std::out_of_range("No more elements");

            return current->data;
        }

        T last()
        {
            if (!hasNext())
                throw std::out_of_range("No more elements");

            Node<T> *temp = current;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            return temp->data;
        }
};

template <class T>
class Queue
{
    private:
        LinkedList<T> list;

    public:
        void enqueue(T data)
        {
            list.insertAtTail(data);
        }

        T dequeue()
        {
            return list.deleteAtHead();
        }

        bool isEmpty()
        {
            return list.isEmpty();
        }

        void print()
        {
            list.print();
        }

        bool inQ(T target)
        {
            Node<T> *temp = list.head;
            while (temp)
            {
                if (temp->data == target)
                    return true;
                temp = temp->next;
            }
            return false;
        }
};

template<class T>
class Stack
{
    private:
        LinkedList<T> list;

    public:
        void push(T data)
        {
            list.insertAtHead(data);
        }

        T pop()
        {
            return list.deleteAtHead();
        }

        bool isEmpty()
        {
            return list.isEmpty();
        }

        void print()
        {
            list.print();
        }
};
template <class T>
Node<T> *head;

template<class T>
class Tree
{
    private:
        LinkedList<T> list;

    public:
        Node<T> *head;
        void push(T data)
        {
            list.insertAtHead(data);
        }
        void insert(T data)
        {
            list.insertAtHead(data);
        }
        T remove()
        {
            return list.deleteAtHead();
        }

        bool isEmpty()
        {
            return list.isEmpty();
        }

        void print()
        {
            list.print();
        }

        bool searchTree(T target)
        {
            Node<T> *temp = list.head;
            while (temp)
            {
                if (temp->data == target)
                    return true;
                temp = temp->next;
            }
            return false;
        }

        bool sortTree(T target)
        {
            Node<T> *temp = list.head;
            while (temp)
            {
                if (temp->data == target)
                    return true;
                temp = temp->next;
            }
            return false;
        }

        bool printTreeStructure(T target)
        {
            Node<T> *temp = list.head;
            while (temp)
            {
                if (temp->data == target)
                    return true;
                temp = temp->next;
            }
            return false;
        }

        bool printTree(T target)
        {
            Node<T> *temp = list.head;
            while (temp)
            {
                if (temp->data == target)
                    return true;
                temp = temp->next;
            }
            return false;
        }

        ~Tree()
        {
            Node<T> *temp = head;
            while (temp != NULL)
            {
                Node<T> *next = temp->next;
                delete temp;
                temp = next;
            }
            cout << "Tree has been deleted" << endl;
        }
};

template<class T>
class Graph
{
    private:
        LinkedList<T> list;

    public:
        Node<T> *head;
        void push(T data)
        {
            list.insertAtHead(data);
        }
        void insert(T data)
        {
            list.insertAtHead(data);
        }
        T remove()
        {
            return list.deleteAtHead();
        }

        bool isEmpty()
        {
            return list.isEmpty();
        }

        void print()
        {
            list.print();
        }
        T pull(T data)
        {
            return list.deleteAtHead();
        }
        bool searchGraph(T target)
        {
            Node<T> *temp = list.head;
            while (temp)
            {
                if (temp->data == target)
                    return true;
                temp = temp->next;
            }
            return false;
        }
        bool sortGraph(T target)
        {
            Node<T> *temp = list.head;
            while (temp)
            {
                if (temp->data == target)
                    return true;
                temp = temp->next;
            }
            return false;
        }
        bool printGraphStructure(T target)
        {
            Node<T> *temp = list.head;
            while (temp)
            {
                if (temp->data == target)
                    return true;
                temp = temp->next;
            }
            return false;
        }
        bool printGraph(T target)
        {
            Node<T> *temp = list.head;
            while (temp)
            {
                if (temp->data == target)
                    return true;
                temp = temp->next;
            }
            return false;
        }
        ~Graph()
        {
            Node<T> *temp = head;
            while (temp != NULL)
            {
                Node<T> *next = temp->next;
                delete temp;
                temp = next;
            }
            cout << "Graph has been deleted" << endl;
        }
};

int main()
{
    LinkedList<int> list;
    list.insertAtHead(5);
    list.insertAtHead(10);
    list.insertAtHead(2);
    list.insertAtHead(12);
    list.insertAtHead(19);
    list.insertAtHead(20);
    list.insertAtHead(20);
    list.insertAtHead(20);
    list.insertAtHead(20);
    list.insertAtHead(20);
    list.print();
    //create queue and test inQ function
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(2);
    q.enqueue(12);
    q.enqueue(19);
    q.inQ(5) ? cout << "5 is in queue" << endl : cout << "5 is not in queue" << endl;
    q.print();
    // test tree
    Tree<int> t;
    t.insert(5);
    t.insert(10);
    t.insert(2);
    t.insert(12);
    t.printTree(5) ? cout << "5 is in tree" << endl : cout << "5 is not in tree" << endl;
    t.sortTree(5) ? cout << "5 is in tree" << endl : cout << "5 is not in tree" << endl;
    t.print();
    // test graph
    Graph<int> g;
    g.insert(5);
    g.insert(10);
    g.insert(2);
    g.insert(12);
    g.print();
    // test stack
    Stack<int> s;
    s.push(5);
    s.push(10);
    s.push(2);
    s.push(12);
    s.print();
    return 0;
}
