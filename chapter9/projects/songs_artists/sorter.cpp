/**
 * @file sorter.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    ifstream infile("input.txt"); // open the input file
    if (!infile)
    {
        cerr << "Error: failed to open input file." << endl;
        return 1;
    }

    vector<string> songs;
    string line;
    cout << "Original File:" << endl;
    while (getline(infile, line))
    { // read each line from the input file
        // remove song number and leading/trailing whitespace
        line = line.substr(line.find(" ") + 1);
        line.erase(0, line.find_first_not_of(" "));
        line.erase(line.find_last_not_of(" ") + 1);
        songs.push_back(line);
        cout << line << endl; // print the line to the terminal
    }

    infile.close(); // close the input file

    // sort the songs alphabetically by artist name, then by song name
    sort(songs.begin(), songs.end(), [](const string &a, const string &b) {
        size_t separator_pos_a =
            a.find(", "); // find the position of the separator between artist name and song name in string a
        string artist_name_a = a.substr(separator_pos_a + 2); // extract the artist name from string a
        size_t separator_pos_b =
            b.find(", "); // find the position of the separator between artist name and song name in string b
        string artist_name_b = b.substr(separator_pos_b + 2); // extract the artist name from string b
        if (artist_name_a == artist_name_b)
        { // if the artist names are the same, sort by song name
            string song_name_a = a.substr(0, separator_pos_a); // extract the song name from string a
            string song_name_b = b.substr(0, separator_pos_b); // extract the song name from string b
            return song_name_a < song_name_b;
        }
        else
        { // otherwise, sort by artist name
            return artist_name_a < artist_name_b;
        }
    });

    ofstream outfile("output.csv"); // open the output file
    if (!outfile)
    {
        cerr << "Error: failed to open output file." << endl;
        return 1;
    }

    // write the songs in CSV format to the output file
    outfile << "Artist Name, Song Name" << endl;
    for (const string &song : songs)
    {
        size_t separator_pos =
            song.find(", "); // find the position of the separator between artist name and song name
        string artist_name = song.substr(separator_pos + 2); // extract the artist name
        string song_name = song.substr(0, separator_pos);    // extract the song name
        outfile << artist_name << ", " << song_name
                << endl; // write the artist name and song name in CSV format to the output file
    }

    outfile.close(); // close the output file

    ifstream outstream("output.csv"); // open the output file for reading
    if (!outstream)
    {
        cerr << "Error: failed to open output file for reading." << endl;
        return 1;
    }

    cout << "Output File:" << endl;
    while (getline(outstream, line))
    {                         // read each line from the output file
        cout << line << endl; // print the line to the terminal
    }

    outstream.close(); // close the output file

    return 0;
}
