/**
 * @file NodeStruct.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

typedef struct Node
{
    int data;
    Node *next;
    Node *previous;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *pointer[] = {head, tail};
Node *sort(Node *head);
void print(Node *head);

Node *sort(Node *head)
{
    Node *temp = head;
    Node *temp2 = head;
    while (temp != NULL)
    {
        while (temp2 != NULL)
        {
            if (temp->data > temp2->data)
            {
                int tempData = temp->data;
                temp->data = temp2->data;
                temp2->data = tempData;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void deleteTail(Node *tail)
{
    Node *temp = tail;
    tail = tail->previous;
    tail->next = NULL;
    delete temp;
}

void deleteTailRecursionNumber(Node *tail, int recursionNumber)
{
    if (recursionNumber == 0)
    {
        Node *temp = tail;
        tail = tail->previous;
        tail->next = NULL;
        delete temp;
    }
    else
    {
        deleteTailRecursionNumber(tail->previous, recursionNumber - 1);
    }
}

int main(int argc, char const *argv[])
{
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;
    Node *node4 = new Node;
    Node *node5 = new Node;
    Node *node6 = new Node;
    Node *node7 = new Node;
    Node *node8 = new Node;
    Node *node9 = new Node;
    Node *node10 = new Node;

    node1->data = 1;
    node1->next = node2;
    node1->previous = NULL;

    node2->data = 2;
    node2->next = node3;
    node2->previous = node1;

    node3->data = 3;
    node3->next = node4;
    node3->previous = node2;

    node4->data = 4;
    node4->next = node5;
    node4->previous = node3;

    node5->data = 5;
    node5->next = node6;
    node5->previous = node4;

    node6->data = 6;
    node6->next = node7;
    node6->previous = node5;

    node7->data = 7;
    node7->next = node8;
    node7->previous = node6;

    node8->data = 8;
    node8->next = node9;
    node8->previous = node7;

    node9->data = 9;
    node9->next = node10;
    node9->previous = node8;

    node10->data = 10;
    node10->next = NULL;
    node10->previous = node9;

    head = node1;
    tail = node10;

    print(head);
    cout << endl;
    head = sort(head);
    print(head);
    cout << endl;
    deleteTailRecursionNumber(tail, 2);
    print(head);

    return 0;
}
