/**
 * @file vector_container.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    vector<int> container;
    for(int i = 0; i < 10; i++)
    {
        container.push_back(i);
    }
    cout << "Here is what is in the container: " << endl;
    for(int i = 0; i < container.size(); i++)
    {
        cout << container[i] << " ";
    }
    cout <<  "Set entries to zeroes." << endl;
    for(int i = 0; i < container.size(); i++)
    {
        container[i] = 0;
    }
    cout << "Here is what is in the container: " << endl;
    for(int i = 0; i < container.size(); i++)
    {
        cout << container[i] << " ";
    }
    vector<int>::iterator p;
    p = container.begin();
    for(int i = 0; i < container.size(); i++)
    {
        *p = i;
        p++;
    }
    cout << "Here is what is in the container: " << endl;
    for(int i = 0; i < container.size(); i++)
    {
        cout << container[i] << " ";
    }
    vector<char> char_container;
    for(int i = 0; i < 10; i++)
    {
        char_container.push_back('a' + i);
    }
    cout << "Here is what is in the char_container: " << endl;
    for(int i = 0; i < char_container.size(); i++)
    {
        cout << char_container[i] << " ";
    }
    vector<char> :: iterator p2;
    for(p2 = char_container.begin(); p2 != char_container.end(); p2++)
    {
        cout << *p2 << " ";
    }
    /**
     * @brief Create an iterator for upper case letters, A,B,C,D....etc
     *
     */
    vector<char> upper_case_letters;
    for(int i = 0; i < 26; i++)
    {
        upper_case_letters.push_back('A' + i);
    }
    cout << "\n\nHere is what is in the upper_case_letters: " << endl;
    for(int i = 0; i < upper_case_letters.size(); i++)
    {
        cout << upper_case_letters[i] << " ";
    }
    /**
     * Create a reverse iterator
    */
    vector<char> :: reverse_iterator p3;
    for(p3 = upper_case_letters.rbegin(); p3 != upper_case_letters.rend(); p3++)
    {
        cout << "\n" << *p3 << " ";
    }
    cout << endl;
    for(p3 = upper_case_letters.rbegin(); p3 != upper_case_letters.rend(); p3++)
    {
        *p3 = tolower(*p3);
    }
    return 0;
    vector<char> :: iterator p4;
    for(p4 = upper_case_letters.begin(); p4 != upper_case_letters.end(); p4++)
    {
        p4++;
        p4--;
        cout << *p4 << " ";
        p4--;
    }
}

/**
 * @brief
 * v.begin means start of the vector
 * v.end means end of the vector
 * if *p is an iterator, then ++p means move to the next element
 *
 *
 */
