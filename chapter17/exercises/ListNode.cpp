/**
 * @file ListNode.cpp
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

typedef struct ListNode
{
    int data;
    string name;
    string item;
    int count;
    ListNode *next;
} ListNode;

ListNode *ListNodePtr;

int main(int argc, char const *argv[]);

int main(int argc, char const *argv[])
{
    ListNodePtr = new ListNode;
    ListNodePtr->data = 5;
    ListNodePtr->next = NULL;
    cout << ListNodePtr->data << endl;
    cout << ListNodePtr->next << endl;
    ListNodePtr = new ListNode;
    ListNodePtr->data = 6;
    ListNodePtr->name = "Wilbur's Brother Orville";
    ListNodePtr->item = "Bicycle";
    ListNodePtr->count = 2;
    ListNodePtr->next = NULL;
    cout << ListNodePtr->data << endl;
    cout << ListNodePtr->name << endl;
    cout << ListNodePtr->item << endl;
    cout << ListNodePtr->count << endl;
    delete ListNodePtr;
    return 0;
}
