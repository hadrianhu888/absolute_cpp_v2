/**
 * @file reverseWord.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

using namespace std;

int main(int argc, char **argv);
class reverseString
{
private:
    string str;
    string revStr;
    char *head;
    char *tail;
    char *next;
public:
    reverseString(string str)
    {
        this->str = str;
        this->revStr = "";
        this->head = &str[0];
        this->tail = &str[str.length() - 1];
        this->next = &str[0];
    }

    void reverse()
    {
        while (next <= tail)
        {
            revStr += *tail;
            tail--;
        }
    }

    void print()
    {
        cout << revStr << endl;
    }
};

int main(int argc, char **argv)
{
    string str = "Hello World!";
    reverseString revStr(str);
    revStr.reverse();
    revStr.print();
    return 0;
}
