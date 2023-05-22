/**
 * @file compare_two_text_files_cosine_comp.cpp
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

set<string> v1;
set<string> v2;
string filename;
istream *openFile(string filename);
void readTextFile(istream *in, set<string> &v);
void printSet(set<string> &v);
bool computeBinaryCosine(set<string> &v1, set<string> &v2);
bool calculateStringSetIntersection(set<string> &v1, set<string> &v2);
int countWordsInFile(string filename);
int computeSameWordsInFiles(string filename1, string filename2);
float computeBinaryCosineMathematically(set<string> &v1, set<string> &v2, string filename1, string filename2);
int main(int argc, char **argv);

istream *openFile(string filename)
{
    ifstream *in = new ifstream(filename);
    if (!in->is_open())
    {
        cout << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }
    return in;
}

void readTextFile(istream *in, set<string> &v)
{
    string line;
    while (getline(*in, line))
    {
        v.insert(line);
    }
}

void printSet(set<string> &v)
{
    for (auto &i : v)
    {
        cout << i << endl;
    }
}

bool computeBinaryCosine(set<string> &v1, set<string> &v2)
{
    int intersection = 0;
    int union_ = 0;
    for (auto &i : v1)
    {
        if (v2.find(i) != v2.end())
        {
            intersection++;
        }
    }
    union_ = v1.size() + v2.size() - intersection;
    cout << "Intersection: " << intersection << endl;
    cout << "Union: " << union_ << endl;
    return (intersection / union_);
}

bool calculateStringSetIntersection(set<string> &v1, set<string> &v2)
{
    int intersection = 0;
    int union_ = 0;
    for (auto &i : v1)
    {
        if (v2.find(i) != v2.end())
        {
            intersection++;
        }
    }
    union_ = v1.size() + v2.size() - intersection;
    cout << "Intersection: " << intersection << endl;
    cout << "Union: " << union_ << endl;
    return (intersection / union_);
}

int countWordsInFile(string filename)
{
    int count = 0;
    string line;
    ifstream in(filename);
    while (getline(in, line))
    {
        count++;
    }
    return count;
}

int computeSameWordsInFiles(string filename1, string filename2)
{
    int count = 0;
    string line;
    ifstream in1(filename1);
    ifstream in2(filename2);
    while (getline(in1, line))
    {
        if (getline(in2, line))
        {
            count++;
        }
    }
    return count;
}

float computeBinaryCosineMathematically(set<string> &v1, set<string> &v2, string filename1, string filename2)
{
    int intersection = computeSameWordsInFiles(filename1, filename2);
    int union_ = countWordsInFile(filename1) + countWordsInFile(filename2) - intersection;
    for (auto &i : v1)
    {
        if (v2.find(i) != v2.end())
        {
            intersection++;
        }
    }
    union_ = v1.size() + v2.size() - intersection;
    cout << "Intersection: " << intersection << endl;
    cout << "Union: " << intersection / sqrt(v1.size() * v2.size()) << endl;
    return (intersection / union_);
}

int main(int argc, char **argv)
{
    string filename1;
    string filename2;
    int count1;
    int count2;
    cout << "Enter filename 1: ";
    cin >> filename1;
    cout << "Enter filename 2: ";
    cin >> filename2;
    istream *in1 = openFile(filename1);
    istream *in2 = openFile(filename2);
    readTextFile(in1, v1);
    readTextFile(in2, v2);
    printSet(v1);
    printSet(v2);
    //cout << "Cosine similarity: " << computeBinaryCosine(v1, v2) << endl;
    cout << "Cosine similarity: " << computeBinaryCosineMathematically(v1, v2, filename1, filename2) << endl;
    delete in1;
    delete in2;
    return 0;
}
