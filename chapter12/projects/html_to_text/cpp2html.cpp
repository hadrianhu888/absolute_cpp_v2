#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string cpp_file_name = "source_code.cpp";
string html_file_name = "converted_cpp.html";

void openCppFile(ifstream &cpp_file);
void convertCppToHTML(ifstream &cpp_file, ofstream &html_file);
void displayCppFile(ifstream &cpp_file);
void displayConvertedCppHTMLFile(ifstream &html_file);

void openCppFile(ifstream &cpp_file)
{
    cpp_file.open(cpp_file_name);
    if (!cpp_file)
    {
        cout << "Error opening input file." << endl;
        exit(1);
    }
}

void convertCppToHTML(ifstream &cpp_file, ofstream &html_file)
{
    string line;

    html_file << "<!DOCTYPE html>\n";
    html_file << "<html lang=\"en\">\n<head>\n";
    html_file << "<meta charset=\"UTF-8\">\n";
    html_file << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    html_file << "<title>Converted C++ File to HTML</title>\n";
    html_file << "<style>\npre { background-color: #f8f8f8; padding: 20px; overflow-x: auto; }\n</style>\n";
    html_file << "</head>\n<body>\n<pre><code>";

    while (getline(cpp_file, line))
    {
        for (char c : line)
        {
            if (c == '<')
            {
                html_file << "&lt;";
            }
            else if (c == '>')
            {
                html_file << "&gt;";
            }
            else if (c == '&')
            {
                html_file << "&amp;";
            }
            else
            {
                html_file << c;
            }
        }
        html_file << "\n";
    }

    html_file << "</code></pre>\n</body>\n</html>";
}

void displayCppFile(ifstream &cpp_file)
{
    string line;
    while (getline(cpp_file, line))
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

int main(int argc, char **argv)
{
    ifstream cpp_file;
    ofstream html_file;

    openCppFile(cpp_file);
    html_file.open(html_file_name);
    if (!html_file)
    {
        cout << "Error opening output file." << endl;
        exit(1);
    }

    displayCppFile(cpp_file);
    cpp_file.clear();  // Clear EOF flag
    cpp_file.seekg(0); // Set the get pointer back to the beginning
    convertCppToHTML(cpp_file, html_file);

    cpp_file.close();
    html_file.close();

    ifstream converted_html_file;
    converted_html_file.open(html_file_name);
    if (!converted_html_file)
    {
        cout << "Error opening converted HTML file." << endl;
        exit(1);
    }
    displayConvertedCppHTMLFile(converted_html_file);
    converted_html_file.close();

    return 0;
}
