/**
 * @file PointerType.cpp
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

class PointerType
{
    public:
        PointerType(){} // Default constructor
        PointerType(int data = 0, PointerType *next = NULL) : data(data), next(next)
        {
            this->data = data;
            this->next = next;
        }
        int getData() const { return data; }
        PointerType *getNext() const { return next; }
        void setData(int data) { this->data = data; }
        void setNext(PointerType *next) { this->next = next; }
    private:
        int data;
        PointerType *next;
};

int main(int argc, char const *argv[]);

PointerType *head = NULL;

PointerType* sort(PointerType *head)
{
    PointerType *temp = head;
    PointerType *temp2 = head;
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

void print(PointerType *head)
{
    PointerType *temp = head;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    PointerType *pType[] = {new PointerType(1), new PointerType(2), new PointerType(3), new PointerType(4), new PointerType(5)};
    for(int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            head = pType[i];
        }
        else
        {
            pType[i-1]->setNext(pType[i]);
        }
    }
    print(head);
    return 0;
}

/**
 * @brief An empty head is in a linked list is represented by NULL.
 *
 */
