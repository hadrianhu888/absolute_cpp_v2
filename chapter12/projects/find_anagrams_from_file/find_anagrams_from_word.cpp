/**
 * @file find_anagrams_from_word.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

string inFile = "words.txt";

void openFile(ifstream &file);
void selectRandomWord(ifstream &file, string &randomWord);
vector<string> storeWords(ifstream &file);
void displayRandomWord(string randomWord);
vector<string> findAnagramsFromWord(string randomWord, vector<string> words);
void displayAllAnagramsOfRandomWord(ifstream &file, string randomWord);
int main(int argc, char **argv);

void openFile(ifstream &file)
{
    file.open(inFile.c_str());
    while (file.fail())
    {
        cout << "Error opening file. Try again: ";
        cin >> inFile;
        file.open(inFile.c_str());
    }
}

void selectRandomWord(ifstream &file, string &randomWord)
{
    vector<string> words = storeWords(file);
    randomWord = words[rand() % words.size()];
}

vector<string> storeWords(ifstream &file)
{
    vector<string> words;
    string word;
    while (file >> word)
    {
        words.push_back(word);
    }
    return words;
}

void displayRandomWord(string randomWord)
{
    cout << "Random word: " << randomWord << endl;
}

vector<string> findAnagramsFromWord(string randomWord, vector<string> words)
{
    vector<string> anagrams;
    for (int i = 0; i < words.size(); i++)
    {
        if (randomWord.length() == words[i].length())
        {
            string temp = words[i];
            sort(temp.begin(), temp.end());
            if (randomWord == temp)
            {
                anagrams.push_back(words[i]);
            }
        }
    }
    return anagrams;
}

void displayAllAnagramsOfRandomWord(ifstream &file, string randomWord)
{
    vector<string> words = storeWords(file);
    vector<string> anagrams = findAnagramsFromWord(randomWord, words);
    cout << "Anagrams of " << randomWord << ": ";
    for (int i = 0; i < anagrams.size(); i++)
    {
        cout << anagrams[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    ifstream file;
    openFile(file);
    string randomWord;
    selectRandomWord(file, randomWord);
    displayRandomWord(randomWord);
    displayAllAnagramsOfRandomWord(file, randomWord);
    return 0;
}
