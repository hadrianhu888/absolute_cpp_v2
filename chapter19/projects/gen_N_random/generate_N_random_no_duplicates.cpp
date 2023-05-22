/**
 * @file generate_N_random_no_duplicates.cpp
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

vector<int> generateRandomNumbers(int n);
void printVector(vector<int> &v);
void searchDuplicates(vector<int> &v);
void sortVector(vector<int> &v);
void removeDuplicates_GenerateNewRandomNumbers(vector<int> &v);
vector<int> generateRandomNumbers(int n,int max);
void find(vector<int> &v, int random_number);
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
    vector<int> v = generateRandomNumbers(n,max);
    printVector(v);
    searchDuplicates(v);
    sortVector(v);
    printVector(v);
    searchDuplicates(v);
    cout << "Removing duplicates..." << endl;
    removeDuplicates_GenerateNewRandomNumbers(v);
    time(&end);
    diff=  difftime(end, start);
    cout << "Time taken: " << diff << " seconds" << endl;
    find(v, 5);
    return 0;
}

vector<int> generateRandomNumbers(int n)
{
    vector<int> v;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        /**
         * @brief only store the random number if it is less than n
         *
         */
        if(rand() % 100 < n)
        {
            v.push_back(rand() % 100);
        }
        else
        {
            i--;
        }
    }
    return v;
}

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    }
    cout << endl;
}

void searchDuplicates(vector<int> &v)
{
    int count[v.size()];
    /* for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] == v[j])
            {
                cout << "Duplicate found: " << v[i] << endl;
            }
        }
    } */
    /**
     * @brief for each duplicate found, count how many instances occur in the vector
     *
     */
    for (int i = 0; i < v.size(); i++)
    {
        count[i] = 0;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] == v[j])
            {
                count[i]++;
                /**
                 * @brief display the number of instances of each duplicate
                 *
                 */
                cout << "Duplicate found: " << v[i] << " occurs " << count[i] << " times" << endl;
            }
        }
    }
}

void sortVector(vector<int> &v)
{
    sort(v.begin(), v.end());
}

void removeDuplicates_GenerateNewRandomNumbers(vector<int> &v)
{
    vector<int> new_v;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != v[i + 1])
        {
            new_v.push_back(v[i]);
        }
    }
    v = new_v;
    printVector(v);
    searchDuplicates(v);
}

vector<int> generateRandomNumbers(int n,int max)
{
    vector<int> v;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        /**
         * @brief only store the random number if it is less than n
         *
         */
        if(rand() % 100 < max)
        {
            v.push_back(rand() % max);
        }
        /**
         * @brief if a duplicate, generate another random number and store it
         *
         */
        if(find(v.begin(),v.end(),v[i]) != v.end())
        {
            v.push_back(rand() % max);
        }
        else
        {
            i--;
        }
    }
    return v;
}

void find(vector<int> &v, int random_number)
{
    if(find(v.begin(),v.end(),random_number) != v.end())
    {
        cout << "Found" << endl;
        cout << "Index: " << find(v.begin(),v.end(),random_number) - v.begin() << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}
