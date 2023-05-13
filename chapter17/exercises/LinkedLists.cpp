/**
 * @file LinkedLists.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

namespace LinkedLists
{
    class IntNode
    {
        public:
            IntNode(){} // Default constructor
            IntNode(IntNode * link) { this->link = link;}
            IntNode(int data = 0, IntNode *link = NULL) : data(data), link(link)
            {
                this->data = data;
                this->link = link;
            }
            int getData() const { return data; }
            IntNode *getLink() const { return link; }
            void setData(int data) { this->data = data; }
            void setLink(IntNode *link) { this->link = link; }
        private:
            int data;
            IntNode *link;
    };
}

using namespace LinkedLists;

int main(int argc, char const *argv[]);

IntNode *head = NULL;

IntNode* sort(IntNode *head)
{
    IntNode *temp = head;
    IntNode *temp2 = head;
    while (temp != NULL)
    {
        while (temp2 != NULL)
        {
            if (temp->getData() > temp2->getData())
            {
                int tempData = temp->getData();
                temp->setData(temp2->getData());
                temp2->setData(tempData);
            }
            temp2 = temp2->getLink();
        }
        temp = temp->getLink();
    }
    return head;
}

IntNode* reverse(IntNode *head)
{
    IntNode *prev = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {
        next = current->getLink();
        current->setLink(prev);
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

IntNode* search(IntNode *head, int target)
{
    IntNode *temp = head;
    while (temp != NULL)
    {
        if (temp->getData() == target)
        {
            return temp;
        }
        temp = temp->getLink();
    }
    return temp;
}

void headInsert(IntNode *&head, int data)
{
    IntNode *newNode = new IntNode(data, head);
}

void insert(IntNode *previous, int data)
{
    IntNode *newNode = new IntNode(data, previous->getLink());
    previous->setLink(newNode);
}

void tailInsert(IntNode *&head, int data)
{
    if(head == NULL)
    {
        head = new IntNode(data);
    }
    else
    {
        IntNode *temp = head;
        while (temp->getLink() != NULL)
        {
            temp = temp->getLink();
        }
        temp->setLink(new IntNode(data));
    }
}

void printLinkedList(IntNode *head)
{
    IntNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->getData() << endl;
        temp = temp->getLink();
    }
}

int main(int argc, char const *argv[])
{
    IntNode *node1 = new IntNode(5);
    IntNode *node2 = new IntNode(6);
    IntNode *node3 = new IntNode(7);
    IntNode *node4 = new IntNode(8);
    IntNode *node5 = new IntNode(9);
    IntNode *node6 = new IntNode(10);
    IntNode *node7 = new IntNode(11);
    IntNode *node8 = new IntNode(12);
    IntNode *node9 = new IntNode(13);
    IntNode *node10 = new IntNode(14);
    IntNode *head = node1;
    IntNode *sorted = sort(head);
    IntNode *reversed = reverse(head);
    IntNode *searched = search(head, 8);
    node1->setLink(node2);
    node2->setLink(node3);
    node3->setLink(node4);
    node4->setLink(node5);
    node5->setLink(node6);
    node6->setLink(node7);
    node7->setLink(node8);
    node8->setLink(node9);
    node9->setLink(node10);
    reversed = reverse(head);
    while(reversed != NULL)
    {
        cout << reversed->getData() << endl;
        reversed = reversed->getLink();
    }
    searched = search(head, 8);
    cout << "Sorted: " << endl;
    while (sorted != NULL)
    {
        cout << sorted->getData() << endl;
        sorted = sorted->getLink();
    }
    cout << sorted->getData() << endl;
    while(sorted != NULL)
    {
        cout << sorted->getData() << endl;
        sorted = sorted->getLink();
    }
    sorted = sorted->getLink();
    IntNode *newInsert = new IntNode(15);
    headInsert(head, 4);
    insert(node1, 5);
    tailInsert(head, 16);
    printLinkedList(head);
    return 0;
}
