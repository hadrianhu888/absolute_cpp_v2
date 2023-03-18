/**
 * @file class_string.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    string phrase = "Hello";
    string adjective = "beautiful";
    string noun = "world";
    string sentence = phrase + " " + adjective + " " + noun;
    cout << sentence << endl;
    cout << sentence.length() << endl;
    for (int i = 0; i < sentence.length(); i++)
    {
        cout << sentence[i] << endl;
    }
    cout << sentence.substr(0, 5) << endl;
    cout << sentence.substr(6, 9) << endl;
    cout << sentence.substr(16, 5) << endl;
    cout << sentence.substr(0, 5) + " " + sentence.substr(6, 9) + " " + sentence.substr(16, 5) << endl;
    return 0;
}