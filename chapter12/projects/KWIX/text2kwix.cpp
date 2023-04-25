/**
 * @file text2kwix.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

string inFileName = "random_text.txt";
string outFileName = "kwix_table.txt";

unordered_set<string> technical_words = {
    "algorithm",   "class",    "function",  "inheritance", "polymorphism", "encapsulation", "constructor", "destructor",
    "overloading", "template", "library",   "pointer",     "reference",    "virtual",       "exception",   "inline",
    "static",      "dynamic",  "memory",    "recursion",   "optimization", "compiler",      "debugger",    "stack",
    "heap",        "syntax",   "semantics", "abstraction", "refactoring"};
map<string,string> technical_words_definitions =
{
    {"algorithm", "A sequence of instructions to perform a specific task."},
    {"class", "A user-defined type that contains data and functions."},
    {"function", "A named sequence of statements."},
    {"inheritance", "A mechanism for creating a new class from an existing class."},
    {"polymorphism", "The ability to use the same name for different functions."},
    {"encapsulation", "A mechanism for restricting access to some of the object's components."},
    {"constructor", "A special member function that is called when an object is created."},
    {"destructor", "A special member function that is called when an object is destroyed."},
    {"overloading", "The ability to use the same name for different functions."},
    {"template", "A mechanism for defining a family of classes."},
    {"library", "A collection of classes."},
    {"pointer", "An object that stores the address of another object."},
    {"reference", "An alternative name for an object."},
    {"virtual", "A mechanism for defining a family of classes."},
    {"exception", "An object that represents an error."},
    {"inline", "A request to the compiler to insert the function code at the function call."},
    {"static", "A storage class specifier that indicates a variable retains its value between function calls."},
    {"dynamic","A storage class specifier that indicates a variable does not retain its value between function calls."},
    {"memory", "The ability to store and retrieve information."},
    {"recursion", "A function that calls itself."},
    {"optimization", "The process of making a program more efficient."},
    {"compiler", "A program that translates a high-level language program into machine code."},
    {"debugger", "A program that helps find errors in a program."},
    {"stack", "A data structure that stores information using the last-in, first-out (LIFO) principle."},
    {"heap", "A data structure that stores information using the first-in, first-out (FIFO) principle."},
    {"syntax", "The form of a program."},
    {"semantics", "The meaning of a program."},
    {"abstraction", "The process of ignoring details of parts to focus attention on a higher level of a problem."},
    {"refactoring", "The process of restructuring a program without changing its behavior."},
    {"object", "An instance of a class."}
};


// Add other technical words and their definitions

int main(int argc, char **argv);
void readFile(ifstream &inStream);
void resetStreamPosition(ifstream &inStream);
void displayFile(ifstream &inStream);
void convert2KWIXTable(ifstream &inStream);
void writeKWIXTableToFile(ifstream &inStream, ofstream &outStream);
void displayKWIXTable(ifstream &inStream);
map<string,int> getUniqueWordCounts(ifstream &inStream);
void displayUniqueWordCounts(vector<int> &uniqueWordCounts);
map<string, int> countAllUniqueTerms(ifstream &inStream);

void readFile(ifstream &inStream)
{
    inStream.open(inFileName);
    if (inStream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
}
void displayFile(ifstream &inStream)
{
    string line;
    while (getline(inStream, line))
    {
        cout << line << endl;
    }
}
// Update the convert2KWIXTable() function
void convert2KWIXTable(ifstream &inStream)
{
    string line;
    int count = 0;
    unordered_set<string> unique_terms;
    while (getline(inStream, line))
    {
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            if (technical_words.find(word) != technical_words.end() && unique_terms.find(word) == unique_terms.end())
            {
                unique_terms.insert(word);
                cout << word << ": " << technical_words_definitions[word] << endl;
                count++;
            }
        }
    }
    cout << "Total unique technical terms: " << count << endl;
}
// Update the writeKWIXTableToFile() function
void writeKWIXTableToFile(ifstream &inStream, ofstream &outStream)
{
    outStream.open(outFileName);
    if (outStream.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    string line;
    int count = 0;
    unordered_set<string> unique_terms;
    while (getline(inStream, line))
    {
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            if (technical_words.find(word) != technical_words.end() && unique_terms.find(word) == unique_terms.end())
            {
                unique_terms.insert(word);
                outStream << word << ": " << technical_words_definitions[word] << endl;
                count++;
            }
        }
    }
    outStream << "Total unique technical terms: " << count << endl;
}
void displayKWIXTable(ifstream &inStream)
{
    string line;
    while (getline(inStream, line))
    {
        cout << line << endl;
    }
}
void resetStreamPosition(ifstream &inStream)
{
    inStream.clear();
    inStream.seekg(0, ios::beg);
}
map<string, int> getUniqueWordCounts (ifstream &inStream)
{
    std::map<std::string, int> uniqueWordCounts;
    string line;
    while (getline(inStream, line))
    {
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            if (technical_words.find(word) != technical_words.end())
            {
                uniqueWordCounts[word]++;
            }
        }
    }
    return uniqueWordCounts;
}

void displayUniqueWordCounts(std::map<std::string, int> &uniqueWordCounts)
{
    for (const auto &entry : uniqueWordCounts)
    {
        cout << entry.first << ": " << entry.second << endl;
    }
}
map<string,int> countAllUniqueTerms(ifstream &inStream)
{
    map<string,int> uniqueWordCounts;
    string line;
    while (getline(inStream, line))
    {
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            if (technical_words.find(word) != technical_words.end())
            {
                uniqueWordCounts[word]++;
            }
        }
    }
    return uniqueWordCounts;
}

int main(int argc, char **argv)
{
    ifstream inStream;
    ofstream outStream;
    readFile(inStream);
    displayFile(inStream);
    resetStreamPosition(inStream);
    convert2KWIXTable(inStream);
    resetStreamPosition(inStream);
    writeKWIXTableToFile(inStream, outStream);
    inStream.close();    // Close the input stream
    outStream.close();   // Close the output stream
    ifstream kwixStream; // Create a new ifstream to read the KWIX table
    kwixStream.open(outFileName);
    if (kwixStream.fail())
    {
        cout << "KWIX table file opening failed.\n";
        exit(1);
    }
    cout << "Displaying KWIX table from the output file:\n";
    displayKWIXTable(kwixStream);
    resetStreamPosition(kwixStream);
    map<string,int> uniqueWordCounts = getUniqueWordCounts(kwixStream);
    cout << "Displaying unique word counts:\n";
    displayUniqueWordCounts(uniqueWordCounts);
    resetStreamPosition(kwixStream);
    map<string,int> uniqueWordCounts2 = countAllUniqueTerms(kwixStream);
    cout << "Displaying unique word counts:\n";
    displayUniqueWordCounts(uniqueWordCounts2);
    kwixStream.close(); // Close the KWIX table stream
    return 0;
}
