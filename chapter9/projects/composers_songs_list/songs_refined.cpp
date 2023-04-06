#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream infile("songs_ordered.csv"); // Open input file
    std::ofstream outfile("songs_refined.csv"); // Open output file

    std::string line;
    while (std::getline(infile, line))
    { // Read each line
        size_t pos = line.find(". "); // Find position of first dot character
        if (pos != std::string::npos)
        { // If found
            line = line.substr(pos + 2); // Extract substring starting from position after dot character
        }
        outfile << line << "\n"; // Write modified line to output file
    }
    //concatenate the artist and song name after removing the number
    //write the new line to the output file
    while(std::getline(infile, line))
    {
        size_t pos = line.find(" "); // Find position of first space character
        if (pos != std::string::npos)
        { // If found
            line = line.substr(pos + 1); // Extract substring starting from position after comma character
        }
        outfile << line << "\n"; // Write modified line to output file
    }
    infile.close(); // Close input file
    outfile.close(); // Close output file

    return 0;
}
