/**
 * @file html_to_text.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

string html_file_name = "html_page.html";
string text_file_name = "text_page.txt";
string cpp_file_name = "test_cpp.cpp";
string cpp_html_file_name = "test_html.html";

void openHtmlFile(ifstream &html_file);
void openTextFile(ofstream &text_file);
void openCppFile(ifstream &cpp_file);
void displayHtmlFile(ifstream &html_file);
void convertHTML2Text(ifstream &html_file, ofstream &text_file);
void openCppFile(ifstream &cpp_file);
void convertCppToHTML(ifstream &cpp_file, ofstream &html_file);
void displayCppFile(ifstream &html_file, ofstream &text_file);
void displayConvertedCppHTMLFile(ifstream &html_file);
int main(int argc, char **argv);

void openCppFile(ifstream &cpp_file)
{
    cpp_file.open(cpp_file_name);
    if (!cpp_file)
    {
        cout << "Error opening input file." << endl;
        exit(1);
    }
}
void openHtmlFile(ifstream &html_file)
{
    html_file.open(html_file_name);
    if (!html_file)
    {
        cout << "Error opening input file." << endl;
        exit(1);
    }
}
void openTextFile(ofstream &text_file)
{
    text_file.open(text_file_name);
    if (!text_file)
    {
        cout << "Error opening output file." << endl;
        exit(1);
    }
}
void displayHtmlFile(ifstream &html_file)
{
    string line;
    while (getline(html_file, line))
    {
        cout << line << endl;
    }
}
void convertHTML2Text(ifstream &html_file, ofstream &text_file)
{
    string line;
    while (getline(html_file, line))
    {
        bool insideTag = false;
        for (char c : line)
        {
            if (c == '<')
            {
                insideTag = true;
            }
            else if (c == '>')
            {
                insideTag = false;
            }
            else if (!insideTag)
            {
                text_file << c;
            }
        }
        text_file << endl;
    }
}
void displayCppFile(ifstream &html_file, ofstream &text_file)
{
    string line;
    while (getline(html_file, line))
    {
        cout << line << endl;
    }
}
void displayConvertedCppHTMLFile(ifstream &html_file)
{
    string line;
    while (getline(html_file, line))
    {
        cout << line << endl;
    }
}
void convertCppToHTML(ifstream &cpp_file, ofstream &html_file)
{
    string line;
    while (getline(cpp_file, line))
    {
        bool insideComment = false;
        for (char c : line)
        {
            if (c == '/')
            {
                insideComment = true;
            }
            else if (c == '/')
            {
                insideComment = false;
            }
            else if (!insideComment)
            {
                html_file << c;
            }
        }
        html_file << endl;
    }

}
int main(int argc, char **argv)
{
    ifstream html_file;
    ofstream text_file;
    ifstream cpp_file;
    ofstream html_cpp_file;
    ofstream cpp_text_file;
    ifstream cpp_html_file;

    openHtmlFile(html_file);
    openTextFile(text_file);
    displayHtmlFile(html_file);
    html_file.clear();  // Clear EOF flag
    html_file.seekg(0); // Set the get pointer back to the beginning
    convertHTML2Text(html_file, text_file);
    openCppFile(cpp_file);
    displayCppFile(cpp_file, cpp_text_file);
    convertCppToHTML(cpp_file, html_cpp_file);
    displayConvertedCppHTMLFile(cpp_html_file);

    html_file.close();
    text_file.close();

    return 0;
}
