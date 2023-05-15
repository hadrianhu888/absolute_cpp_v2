/**
 * @file linked_list_lib.cpp
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
class linked_list
{
    public:
        linked_list(T data = 0, linked_list *next = NULL) : data(data), next(next)
        {
            this->data = data;
            this->next = next;
        }
        T getData() const { return data; }
        linked_list *getNext() const { return next; }
        void setData(T data) { this->data = data; }
        void setNext(linked_list *next) { this->next = next; }
    private:
        T data;
        linked_list *next;
};

template <class T>
linked_list<T> *head = NULL;

template <class T>
class linked_list_lib
{
    public:
        linked_list_lib(){} // Default constructor
        void insert(T data);
        void insertAt(T data, int position);
        void deleteAt(int position);
        void display();
        void sort();
        void reverse();
        void search(T data);
        void update(T data, int position);
        void deleteAll();
        void deleteFirst();
        void deleteLast();
        void insertFirst(T data);
        void insertLast(T data);
        void insertAfter(T data, int position);
        void insertBefore(T data, int position);
        void deleteAfter(int position);
        void deleteBefore(int position);
        void insertAtBeginning(T data);
        void insertAtEnd(T data);
        void deleteAllOccurences(T data);
        void deleteFirstOccurence(T data, int position);
        void deleteLastOccurence(T data, int position);
        void deleteAllOccurences(T data, int position);
        void deleteAllOccurences(T data, int position, int count, int &counter, int &occurence, int &positionOfOccurence, int &positionOfOccurenceCounter, int &positionOfOccurenceCounter2, int &positionOfOccurenceCounter3);
        void print();
    private:
        linked_list<T> *head = NULL;
};

template <class T>
void linked_list_lib<T>::insert(T data)
{
    linked_list<T> *temp = new linked_list<T>;
    temp->setData(data);
    temp->setNext(NULL);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        linked_list<T> *temp2 = head;
        while (temp2->getNext() != NULL)
        {
            temp2 = temp2->getNext();
        }
        temp2->setNext(temp);
    }
}

template <class T>
void linked_list_lib<T>::insertAt(T data, int position)
{
    linked_list<T> *temp = new linked_list<T>;
    temp->setData(data);
    temp->setNext(NULL);
    if (position == 1)
    {
        temp->setNext(head);
        head = temp;
    }
    else
    {
        linked_list<T> *temp2 = head;
        for (int i = 0; i < position - 2; i++)
        {
            temp2 = temp2->getNext();
        }
        temp->setNext(temp2->getNext());
        temp2->setNext(temp);
    }
}

template <class T>
void linked_list_lib<T>::deleteAt(int position)
{
    linked_list<T> *temp = head;
    if (position == 1)
    {
        head = temp->getNext();
        delete temp;
    }
    else
    {
        for (int i = 0; i < position - 2; i++)
        {
            temp = temp->getNext();
        }
        linked_list<T> *temp2 = temp->getNext();
        temp->setNext(temp2->getNext());
        delete temp2;
    }
}

template <class T>
void linked_list_lib<T>::display()
{
    linked_list<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

template <class T>
void linked_list_lib<T>::sort()
{
    linked_list<T> *temp = head;
    linked_list<T> *temp2 = NULL;
    T data;
    while (temp != NULL)
    {
        temp2 = temp->getNext();
        while (temp2 != NULL)
        {
            if (temp->getData() > temp2->getData())
            {
                data = temp->getData();
                temp->setData(temp2->getData());
                temp2->setData(data);
            }
            temp2 = temp2->getNext();
        }
        temp = temp->getNext();
    }
}

template <class T>
void linked_list_lib<T>::reverse()
{
    linked_list<T> *current = head;
    linked_list<T> *prev = NULL;
    linked_list<T> *next = NULL;
    while (current != NULL)
    {
        next = current->getNext();
        current->setNext(prev);
        prev = current;
        current = next;
    }
    head = prev;
}

template <class T>
void linked_list_lib<T>::search(T data)
{
    linked_list<T> *temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->getData() == data)
        {
            cout << "Found at position " << position << endl;
            return;
        }
        temp = temp->getNext();
        position++;
    }
    cout << "Not found" << endl;
}

template <class T>
void linked_list_lib<T>::update(T data, int position)
{
    linked_list<T> *temp = head;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->getNext();
    }
    temp->setData(data);
}

template <class T>
void linked_list_lib<T>::deleteAll()
{
    linked_list<T> *temp = head;
    linked_list<T> *temp2 = NULL;
    while (temp != NULL)
    {
        temp2 = temp->getNext();
        delete temp;
        temp = temp2;
    }
    head = NULL;
}

template <class T>
void linked_list_lib<T>::deleteFirst()
{
    linked_list<T> *temp = head;
    head = temp->getNext();
    delete temp;
}

template <class T>
void linked_list_lib<T>::deleteLast()
{
    linked_list<T> *temp = head;
    linked_list<T> *temp2 = NULL;
    while (temp->getNext() != NULL)
    {
        temp2 = temp;
        temp = temp->getNext();
    }
    temp2->setNext(NULL);
    delete temp;
}

template <class T>
void linked_list_lib<T>::deleteAllOccurences(T data, int position)
{
    linked_list<T> *temp = head;
    linked_list<T> *temp2 = NULL;
    while (temp != NULL)
    {
        if (temp->getData() == data)
        {
            if (temp == head)
            {
                head = temp->getNext();
                delete temp;
                temp = head;
            }
            else
            {
                temp2->setNext(temp->getNext());
                delete temp;
                temp = temp2->getNext();
            }
        }
        else
        {
            temp2 = temp;
            temp = temp->getNext();
        }
    }
}

template <class T>
void linked_list_lib<T>::deleteAllOccurences(T data, int position, int count, int &counter, int &occurence, int &positionOfOccurence, int &positionOfOccurenceCounter, int &positionOfOccurenceCounter2, int &positionOfOccurenceCounter3)
{
    linked_list<T> *temp = head;
    linked_list<T> *temp2 = NULL;
    while (temp != NULL)
    {
        if (temp->getData() == data)
        {
            if (temp == head)
            {
                head = temp->getNext();
                delete temp;
                temp = head;
                counter++;
                if (counter == count)
                {
                    occurence++;
                    positionOfOccurence = position;
                    positionOfOccurenceCounter = positionOfOccurenceCounter2;
                    positionOfOccurenceCounter2 = positionOfOccurenceCounter3;
                }
                positionOfOccurenceCounter3++;
            }
            else
            {
                temp2->setNext(temp->getNext());
                delete temp;
                temp = temp2->getNext();
                counter++;
                if (counter == count)
                {
                    occurence++;
                    positionOfOccurence = position;
                    positionOfOccurenceCounter = positionOfOccurenceCounter2;
                    positionOfOccurenceCounter2 = positionOfOccurenceCounter3;
                }
                positionOfOccurenceCounter3++;
            }
        }
        else
        {
            temp2 = temp;
            temp = temp->getNext();
            position++;
        }
    }
}

template <class T>
void linked_list_lib<T>::insertAtBeginning(T data)
{
    linked_list<T> *temp = new linked_list<T>;
    temp->setData(data);
    temp->setNext(head);
    head = temp;
}

template <class T>
void linked_list_lib<T>::insertAtEnd(T data)
{
    linked_list<T> *temp = new linked_list<T>;
    temp->setData(data);
    temp->setNext(NULL);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        linked_list<T> *temp2 = head;
        while (temp2->getNext() != NULL)
        {
            temp2 = temp2->getNext();
        }
        temp2->setNext(temp);
    }
}

template <class T>
void linked_list_lib<T>::print()
{
    linked_list<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

int main()
{
    linked_list_lib<int> l;
    int choice, data, position, count, counter = 0, occurence = 0, positionOfOccurence = 0, positionOfOccurenceCounter = 0, positionOfOccurenceCounter2 = 0, positionOfOccurenceCounter3 = 0;
    while (1)
    {
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete at beginning" << endl;
        cout << "5. Delete at end" << endl;
        cout << "6. Delete at position" << endl;
        cout << "7. Delete all occurences" << endl;
        cout << "8. Delete all occurences with count" << endl;
        cout << "9. Update" << endl;
        cout << "10. Display" << endl;
        cout << "11. Sort" << endl;
        cout << "12. Reverse" << endl;
        cout << "13. Search" << endl;
        cout << "14. Delete all" << endl;
        cout << "15. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            l.insertAtBeginning(data);
            l.print();
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            l.insertAtEnd(data);
            l.print();
            break;
        case 3:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> position;
            l.insertAt(data, position);
            l.print();
            break;
        case 4:
            l.deleteFirst();
            l.print();
            break;
        case 5:
            l.deleteLast();
            l.print();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> position;
            l.deleteAt(position);
            l.print();
            break;
        case 7:
            cout << "Enter data: ";
            cin >> data;
            l.deleteAllOccurences(data, position);
            l.print();
            break;
        case 8:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter count: ";
            cin >> count;
            l.deleteAllOccurences(data, position, count, counter, occurence, positionOfOccurence, positionOfOccurenceCounter, positionOfOccurenceCounter2, positionOfOccurenceCounter3);
            cout << "Occurence: " << occurence << endl;
            cout << "Position of occurence: " << positionOfOccurence << endl;
            cout << "Position of occurence counter: " << positionOfOccurenceCounter << endl;
            cout << "Position of occurence counter 2: " << positionOfOccurenceCounter2 << endl;
            cout << "Position of occurence counter 3: " << positionOfOccurenceCounter3 << endl;
            l.print();
            break;
        case 9:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> position;
            l.update(data, position);
            l.print();
            break;
        case 10:
            l.display();
            l.print();
            break;
        case 11:
            l.sort();
            l.print();
            break;
        case 12:
            l.reverse();
            l.print();
            break;
        case 13:
            cout << "Enter data: ";
            cin >> data;
            l.search(data);
            l.print();
            break;
        case 14:
            l.deleteAll();
            l.print();
            break;
        case 15:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
