/**
 * @file generate_N_random_no_repeats_using_sets.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

set<int> generateRandomNumbers(int n, int max);
void printSet(set<int> &s);
void searchDuplicates(set<int> &s);
void sortSet(set<int> &s);
void removeDuplicates_GenerateNewRandomNumbers(set<int> &s);
int main(int argc, char **argv);

int main(int argc, char **argv)
{
    time_t start;
    time_t end;
    double diff;
    time(&start);
    int n = 20;
    int max;
    cout << "Enter a number: ";
    cin >> max;
    set<int> s = generateRandomNumbers(n,max);
    printSet(s);
    searchDuplicates(s);
    sortSet(s);
    printSet(s);
    searchDuplicates(s);
    cout << "Removing duplicates..." << endl;
    removeDuplicates_GenerateNewRandomNumbers(s);
    time(&end);
    diff=  difftime(end, start);
    cout << "Time taken: " << diff << " seconds" << endl;
    return 0;
}

set<int> generateRandomNumbers(int n, int max)
{
    set<int> s;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        /**
         * @brief only store the random number if it is less than n
         *
         */
        if(rand() % 100 < n)
        {
            s.insert(rand() % max);
        }
    }
    return s;
}

void printSet(set<int> &s)
{
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

void searchDuplicates(set<int> &s)
{
    for (auto i = s.begin(); i != s.end(); i++)
    {
        auto j = i;
        j++;
        for (; j != s.end(); j++)
        {
            if(*i == *j)
            {
                cout << "Duplicate found: " << *i << endl;
            }
        }
    }
}

void sortSet(set<int> &s)
{
    vector<int> v;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        v.push_back(*i);
    }
    sort(v.begin(), v.end());
    s.clear();
    for (auto i = v.begin(); i != v.end(); i++)
    {
        s.insert(*i);
    }
}

void removeDuplicates_GenerateNewRandomNumbers(set<int> &s)
{
    vector<int> v;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        v.push_back(*i);
    }
    s.clear();
    for (auto i = v.begin(); i != v.end(); i++)
    {
        s.insert(*i);
    }
    v.clear();
    srand(time(NULL));
    for (int i = 0; i < s.size(); i++)
    {
        /**
         * @brief only store the random number if it is less than n
         *
         */
        if(rand() % 100 < s.size())
        {
            v.push_back(rand() % 100);
        }
    }
    s.clear();
    for (auto i = v.begin(); i != v.end(); i++)
    {
        s.insert(*i);
    }
}
