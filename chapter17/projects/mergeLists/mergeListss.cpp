/**
 * @file meregeLists.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void insert(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    void reverse()
    {
        Node *current, *prev, *next;
        current = head;
        prev = NULL;
        while (current != NULL)
        {
            next = current->next; // next = &head
            current->next = prev; // head->next = NULL
            prev = current;       // prev = &head
            current = next;       // current = &head
        }
        head = prev;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next; // Advance the temp pointer
        }
        cout << endl;
    }
    void merge(Node *l1, Node *l2)
    {
        Node *temp = new Node();
        temp->next = NULL;
        Node *dummy = temp;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->data < l2->data)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1 != NULL)
        {
            temp->next = l1;
        }
        if (l2 != NULL)
        {
            temp->next = l2;
        }
        this->head = dummy->next;
        delete dummy; // delete the temporary node we created
    }
};

void insert(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

void reverse()
{
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next; // next = &head
        current->next = prev; // head->next = NULL
        prev = current;       // prev = &head
        current = next;       // current = &head
    }
    head = prev;
}

void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
    }
    cout << endl;
}

void mergeTwoLists(Node *l1, Node *l2)
{
    Node *temp = new Node();
    temp->data = 0;
    temp->next = NULL;
    Node *head = temp;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if (l1 != NULL)
    {
        temp->next = l1;
    }
    if (l2 != NULL)
    {
        temp->next = l2;
    }
    head = head->next;
}

int main()
{
    LinkedList *l1 = new LinkedList();
    LinkedList *l2 = new LinkedList();
    l1->insert(2);
    l1->insert(3);
    l1->insert(4);
    l2->insert(1);
    l2->insert(3);
    l2->insert(4);
    l1->merge(l1->head, l2->head);
    l1->display();
    return 0;
}
