/**
 * @file spellCheckerHashMapping.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template <class T>
class HashTable {
    public:
        HashTable(int theDivisor = 11);
        bool search(const T& x) const;
        void insert(const T& x);
        void remove(const T& x);
        void output(ostream& out) const;
    private:
        int dSize;
        int divisor;
        vector<list<T>> table;
        int hash(const T& x) const;
};

template <class T>
class SpellingWordsHashMap
{
    public:
        SpellingWordsHashMap();
        void insert(const T& x);
        void remove(const T& x);
        bool search(const T& x) const;
        void output(ostream& out) const;
    private:
        HashTable<T> h;
};

template <class T>
SpellingWordsHashMap<T>::SpellingWordsHashMap() : h(1009)
{
    return;
}

template <class T>
bool SpellingWordsHashMap<T>::search(const T& x) const
{
    return h.search(x);
}

template <class T>
void SpellingWordsHashMap<T>::insert(const T& x)
{
    h.insert(x);
}

template <class T>
void SpellingWordsHashMap<T>::remove(const T& x)
{
    h.remove(x);
}

template <class T>
void SpellingWordsHashMap<T>::output(ostream& out) const
{
    h.output(out);
}

template <class T>
int HashTable<T>::hash(const T &x) const
{
    int hashVal = 0;
    for (char ch : x)
    {
        hashVal = 37 * hashVal + ch;
    }
    hashVal %= divisor;
    if (hashVal < 0)
    {
        hashVal += divisor;
    }
    return hashVal;
}

template <class T>
HashTable<T>::HashTable(int theDivisor) : divisor(theDivisor)
{
    dSize = 0;
    table.resize(divisor);
}

template <class T>
void HashTable<T>::insert(const T &x)
{
    int i = hash(x);
    table[i].push_back(x);
    ++dSize;
}

template <class T>
bool HashTable<T>::search(const T &x) const
{
    int i = hash(x);
    if (find(table[i].begin(), table[i].end(), x) != table[i].end())
    {
        return true;
    }
    return false;
}

template <class T>
void HashTable<T>::remove(const T &x)
{
    int i = hash(x);
    typename list<T>::iterator itr = find(table[i].begin(), table[i].end(), x);
    if (itr != table[i].end())
    {
        table[i].erase(itr);
        --dSize;
    }
}

template <class T>
void HashTable<T>::output(ostream &out) const
{
    for (int i = 0; i < divisor; ++i)
    {
        out << i << ":\t";
        for (typename list<T>::const_iterator itr = table[i].begin(); itr != table[i].end(); ++itr)
        {
            out << *itr << "\t";
        }
        out << endl;
    }
}

void openWordsFile(ifstream& wordsFile)
{
    string wordsFileName;
    cout << "Enter name of file containing the words to be looked up: ";
    cin >> wordsFileName;
    wordsFile.open(wordsFileName.c_str());
    if (!wordsFile)
    {
        cerr << "Cannot open " << wordsFileName << endl;
        exit(1);
    }
}

void printWordsFile(ifstream& wordsFile)
{
    string word;
    while (wordsFile >> word)
    {
        cout << word << endl;
    }
}

void openDictionaryFile(ifstream& dictionaryFile)
{
    string dictionaryFileName;
    cout << "Enter name of file containing the dictionary: ";
    cin >> dictionaryFileName;
    dictionaryFile.open(dictionaryFileName.c_str());
    if (!dictionaryFile)
    {
        cerr << "Cannot open " << dictionaryFileName << endl;
        exit(1);
    }
}

void printPossibleMisspellings(ifstream& wordsFile, SpellingWordsHashMap<string>& h)
{
    string word;
    while (wordsFile >> word)
    {
        if (!h.search(word))
        {
            cout << word << endl;
        }
    }
}

void readDictionaryFile(ifstream& dictionaryFile, SpellingWordsHashMap<string>& h)
{
    string word;
    while (dictionaryFile >> word)
    {
        h.insert(word);
    }
}

int main()
{
    ifstream wordsFile;
    openWordsFile(wordsFile);
    ifstream dictionaryFile;
    openDictionaryFile(dictionaryFile);
    SpellingWordsHashMap<string> h;
    readDictionaryFile(dictionaryFile, h);
    printPossibleMisspellings(wordsFile, h);
    return 0;
}
