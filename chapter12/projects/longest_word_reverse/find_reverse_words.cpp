/**
 * @file find_reverse_words.cpp
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
vector<string> findReverseWords(string randomWord, vector<string> words);
void displayAllReverseWordsOfRandomWord(ifstream &file, string randomWord);
string reverseRandomlyChosenWord(string randomWord);
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

vector<string> findReverseWords(string randomWord, vector<string> words)
{
    vector<string> reverseWords;
    for (int i = 0; i < words.size(); i++)
    {
        string reverseWord = words[i];
        reverse(reverseWord.begin(), reverseWord.end());
        if (randomWord == reverseWord)
        {
            reverseWords.push_back(words[i]);
        }
    }
    return reverseWords;
}

void displayAllReverseWordsOfRandomWord(ifstream &file, string randomWord)
{
    vector<string> words = storeWords(file);
    vector<string> reverseWords = findReverseWords(randomWord, words);
    cout << "Reverse words of " << randomWord << ": ";
    for (int i = 0; i < reverseWords.size(); i++)
    {
        cout << reverseWords[i] << " ";
    }
    cout << endl;
}

string reverseRandomlyChosenWord(string randomWord)
{
    string reverseWord = randomWord;
    reverse(reverseWord.begin(), reverseWord.end());
    return reverseWord;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    ifstream file;
    openFile(file);
    string randomWord;
    selectRandomWord(file, randomWord);
    string reverseRandomWord;
    reverseRandomWord = reverseRandomlyChosenWord(randomWord);
    cout << "Reverse of " << randomWord << ": " << reverseRandomWord << endl;
    displayRandomWord(randomWord);
    displayAllReverseWordsOfRandomWord(file, randomWord);
    return 0;
}
