/**
 * @file Box.cpp
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

typedef struct Box
{
    int length;
    int width;
    int height;
    string name;
    int number;
    Box *prev;
    Box *next;
} Box;

Box *BoxPtr;

int main(int argc, char const *argv[]);

int main(int argc, char const *argv[])
{
    BoxPtr = new Box;
    BoxPtr->length = 5;
    BoxPtr->width = 10;
    BoxPtr->height = 15;
    BoxPtr->name = "Sally";
    BoxPtr->number = 18;
    BoxPtr->prev = NULL;
    BoxPtr->next = NULL;
    cout << BoxPtr->length << endl;
    cout << BoxPtr->width << endl;
    cout << BoxPtr->height << endl;
    cout << BoxPtr->name << endl;
    cout << BoxPtr->number << endl;
    cout << BoxPtr->prev << endl;
    cout << BoxPtr->next << endl;
    delete BoxPtr;
    return 0;
}
