/**
 * @file average_word_length.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

void openFile(ifstream &file);
void getWordLengths(ifstream &file, vector<int> &wordLengths);
void displayFileText(ifstream &file);
void printWordLengths(ifstream &file);
int getAverageWordLength(ifstream &file);
int getNumberOfWords(ifstream &file);
void findFrequentWord(ifstream &file);
int main(int argc, char **argv);

void openFile(ifstream &file)
{
    string fileName;
    cout << "Enter the name of the file: ";
    cin >> fileName;
    file.open(fileName.c_str());
    if (file.fail())
    {
        cout << "Error opening file. Exiting program." << endl;
        exit(1);
    }
}
void getWordLengths(ifstream &file, vector<int> &wordLengths)
{
    string word;
    while (file >> word)
    {
        wordLengths.push_back(word.length());
    }
}
void displayFileText(ifstream &file)
{
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
}
void printWordLengths(ifstream &file)
{
    vector<int> wordLengths;
    getWordLengths(file, wordLengths);
    for (int i = 0; i < wordLengths.size(); i++)
    {
        cout << wordLengths[i] << " ";
    }
}
int getAverageWordLength(ifstream &file)
{
    int sum = 0;
    int average = 0;
    int numberOfWords = 0;
    string word;
    while (file >> word)
    {
        sum += word.length();
        numberOfWords++;
    }
    average = sum / numberOfWords;
    return average;
}
int getNumberOfWords(ifstream &file)
{
    int numberOfWords = 0;
    string word;
    while (file >> word)
    {
        numberOfWords++;
    }
    return numberOfWords;
}
void findFrequentWord(ifstream &file)
{
    string word;
    string frequentWord;
    int frequentWordCount = 0;
    int wordCount = 0;
    while (file >> word)
    {
        if (word == frequentWord)
        {
            wordCount++;
        }
        else
        {
            wordCount = 0;
        }
        if (wordCount > frequentWordCount)
        {
            frequentWord = word;
            frequentWordCount = wordCount;
        }
    }
    cout << "The most frequent word is: " << frequentWord << endl;
    cout << "It occurs " << frequentWordCount << " times." << endl;
}
int main(int argc, char **argv)
{
    ifstream inputFile;
    openFile(inputFile);
    cout << "Number of words: " << getNumberOfWords(inputFile) << endl;
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    cout << "Average word length: " << getAverageWordLength(inputFile) << endl;
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    cout << "Word lengths: " << endl;
    printWordLengths(inputFile);
    findFrequentWord(inputFile);
    inputFile.close();
    return 0;
}
