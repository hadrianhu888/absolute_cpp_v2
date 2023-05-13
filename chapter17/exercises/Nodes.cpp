/**
 * @file Nodes.cpp
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

namespace Nodes
{
    class IntNode
    {
        public:
            IntNode(){} // Default constructor
            IntNode(IntNode * next, IntNode * previous) { this->next = next; this->previous = previous;}
            IntNode(int data = 0, IntNode *next = NULL, IntNode *previous = NULL) : data(data), next(next), previous(previous)
            {
                this->data = data;
                this->next = next;
                this->previous = previous;
            }
            int getData() const { return data; }
            IntNode *getNext() const { return next; }
            IntNode *getPrevious() const { return previous; }
            void setData(int data) { this->data = data; }
            void setNext(IntNode *next) { this->next = next; }
            void setPrevious(IntNode *previous) { this->previous = previous; }
        private:
            int data;
            IntNode *next;
            IntNode *previous;
    };
}

using namespace Nodes;

int main(int argc, char const *argv[]);
IntNode* sort(IntNode *head);

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
            temp2 = temp2->getNext();
        }
        temp = temp->getNext();
    }
    return head;
}

void printNodes(IntNode *head)
{
    IntNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    IntNode *node1[] = {new IntNode(1), new IntNode(2), new IntNode(3), new IntNode(4), new IntNode(5)};
    for(int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            node1[i]->setPrevious(NULL);
            node1[i]->setNext(node1[i+1]);
        }
        else if (i == 4)
        {
            node1[i]->setPrevious(node1[i-1]);
            node1[i]->setNext(NULL);
        }
        else
        {
            node1[i]->setPrevious(node1[i-1]);
            node1[i]->setNext(node1[i+1]);
        }
    }
    head = node1[0];
    printNodes(head);
    return 0;
}
