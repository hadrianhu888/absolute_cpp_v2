/**
 * @file longest_vowels.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-27
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

string inFIle = "words.txt";
string outFile = "vowels.txt";

int main(int argc, char **argv);
void openFile(ifstream& file);
void displayFile(ifstream& file);
void getWordLengths(ifstream& file, int& longestWord, int& longestVowelWord);
void getLongestVowelWords(ifstream& file, int longestWord, int longestVowelWord, string& longestWordString, string& longestVowelWordString);
void displayAllVowelWords(ifstream& file);
void saveVowelsToVowelsFile(ifstream &file, ofstream &vowelsFile);
bool isVowel(string word);
bool isVowel(char word);
bool isVowel(char word[]);
void countVowelWords(ifstream &file, int &vowelWords);
void displayOnlyOneRandomLongestVowelWord(string longestVowelWordString);


    void openFile(ifstream &file)
{
    file.open(inFIle.c_str());
    while (file.fail())
    {
        cout << "Error opening file. Try again: ";
        cin >> inFIle;
        file.open(inFIle.c_str());
    }
}
void displayFile(ifstream &file)
{
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
}
void getWordLengths(ifstream &file, int &longestWord, int &longestVowelWord)
{
    string word;
    while (file >> word)
    {
        if (word.length() > longestWord)
        {
            longestWord = word.length();
        }
        if (isVowel(word[0]) && word.length() > longestVowelWord)
        {
            longestVowelWord = word.length();
        }
    }
}
void getLongestVowelWords(ifstream &file,
                          int longestWord,
                          int longestVowelWord,
                          string &longestWordString,
                          string &longestVowelWordString)
{
    string word;
    while (file >> word)
    {
        if (word.length() == longestWord)
        {
            longestWordString += word + " ";
        }
        if (isVowel(word[0]) && word.length() == longestVowelWord)
        {
            longestVowelWordString += word + " ";
        }
    }
}
void displayAllVowelWords(ifstream &file)
{
    string word;
    while (file >> word)
    {
        if (isVowel(word[0]))
        {
            cout << word << endl;
        }
    }
}
void saveVowelsToVowelsFile(ifstream &file, ofstream &vowelsFile)
{
    string word;
    while (file >> word)
    {
        if (isVowel(word[0]))
        {
            vowelsFile << word << endl;
        }
    }
}
bool isVowel(string word)
{
    return word == "a" || word == "e" || word == "i" || word == "o" || word == "u";
}
bool isVowel(char word)
{
    return word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u';
}
bool isVowel(char word[])
{
    return word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u';
}
void countVowelWords(ifstream &file, int &vowelWords)
{
    string word;
    while (file >> word)
    {
        if (isVowel(word[0]))
        {
            vowelWords++;
        }
    }
}
void displayOnlyOneRandomLongestVowelWord(string longestVowelWordString)
{
    int random = rand() % longestVowelWordString.length();
    int i = 0;
    string word = "";
    while (longestVowelWordString[i] != ' ')
    {
        word += longestVowelWordString[i];
        i++;
    }
    cout << "Random longest vowel word: " << word << endl;
}
int main(int argc, char **argv)
{
    ifstream file;
    ofstream vowelsFile;
    openFile(file);
    displayFile(file);
    file.close();
    openFile(file);
    int longestWord = 0;
    int longestVowelWord = 0;
    getWordLengths(file, longestWord, longestVowelWord);
    cout << "Longest word: " << longestWord << endl;
    cout << "Longest vowel word: " << longestVowelWord << endl;
    file.close();
    openFile(file);
    string longestWordString = "";
    string longestVowelWordString = "";
    getLongestVowelWords(file, longestWord, longestVowelWord, longestWordString, longestVowelWordString);
    cout << "Longest word(s): " << longestWordString << endl;
    cout << "Longest vowel word(s): " << longestVowelWordString << endl;
    file.close();
    openFile(file);
    displayAllVowelWords(file);
    file.close();
    openFile(file);
    vowelsFile.open(outFile.c_str());
    saveVowelsToVowelsFile(file, vowelsFile);
    vowelsFile.close();
    file.close();
    openFile(file);
    int vowelWords = 0;
    countVowelWords(file, vowelWords);
    cout << "Number of vowel words: " << vowelWords << endl;
    file.close();
    openFile(file);
    displayOnlyOneRandomLongestVowelWord(longestVowelWordString);
    file.close();
    return 0;
}
