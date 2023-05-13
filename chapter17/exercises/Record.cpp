/**
 * @file Record.cpp
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

typedef struct Record
{
    int data;
    int number;
    int grade;
    Record *next;
} Record;

Record *RecordPtr;

int main(int argc, char const *argv[]);

int main(int argc, char const *argv[])
{
    RecordPtr = new Record;
    RecordPtr->data = 5;
    RecordPtr->number = 10;
    RecordPtr->grade = 15;
    RecordPtr->next = NULL;
    cout << RecordPtr->data << endl;
    cout << RecordPtr->number << endl;
    cout << RecordPtr->grade << endl;
    cout << RecordPtr->next << endl;
    RecordPtr = new Record;
    RecordPtr->data = 6;
    RecordPtr->number = 11;
    RecordPtr->grade = 16;
    RecordPtr->next = NULL;
    cout << RecordPtr->data << endl;
    cout << RecordPtr->number << endl;
    cout << RecordPtr->grade << endl;
    cout << RecordPtr->next << endl;
    delete RecordPtr;
    return 0;
}
