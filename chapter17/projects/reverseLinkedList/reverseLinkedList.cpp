/**
 * @file reverseLinkedList.cpp
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

int main()
{
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(8);
    cout << "Before reverse: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    reverse();
    cout << "After reverse: ";
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
