/**
 * @file maps.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

#include <map>

using namespace std;

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    map<int, string> container;
    for(int i = 0; i < 10; i++)
    {
        container[i] = "Hello";
    }
    cout << "Here is what is in the container: " << endl;
    map<int, string>::iterator p;
    for(p = container.begin(); p != container.end(); p++)
    {
        cout << p->first << " " << p->second << endl;
    }
    map<string, string> planets;
    planets["Mercury"] = "The smallest planet and closest to the Sun";
    planets["Venus"] = "The second planet from the Sun";
    planets["Earth"] = "The third planet from the Sun";
    planets["Mars"] = "The fourth planet from the Sun";
    planets["Jupiter"] = "The fifth planet from the Sun";
    planets["Saturn"] = "The sixth planet from the Sun";
    planets["Uranus"] = "The seventh planet from the Sun";
    planets["Neptune"] = "The eighth planet from the Sun";
    planets["Pluto"] = "The ninth planet from the Sun";
    cout << "Here is what is in the container: " << endl;
    map<string, string>::iterator p2;
    for(p2 = planets.begin(); p2 != planets.end(); p2++)
    {
        cout << p2->first << " " << p2->second << endl;
    }
    return 0;
}
