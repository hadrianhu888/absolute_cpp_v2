/**
 * @file sorted_songs.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Song struct
struct Song {
    string name;
    string artist;
};

// Helper function to trim leading/trailing spaces from a string
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == string::npos || end == string::npos) {
        return "";
    }
    return s.substr(start, end - start + 1);
}

// Comparator for sorting songs by artist and name
bool compareSongs(const Song& s1, const Song& s2) {
    if (s1.artist == s2.artist) {
        return s1.name < s2.name;
    }
    return s1.artist < s2.artist;
}

int main() {
    ifstream infile("songs.txt");
    if (!infile) {
        cerr << "Error: could not open input file." << endl;
        return 1;
    }

    // Read in songs and store in vector
    vector<Song> songs;
    string line;
    while (getline(infile, line)) {
        // Remove leading/trailing spaces
        line = trim(line);

        // Extract song name and artist
        size_t dash_pos = line.find(" - ");
        if (dash_pos == string::npos) {
            cerr << "Error: invalid input format." << endl;
            return 1;
        }
        string name = trim(line.substr(0, dash_pos));
        string artist = trim(line.substr(dash_pos + 3));

        // Remove extraneous words from song name
        size_t paren_pos = name.find("(");
        if (paren_pos != string::npos) {
            name = trim(name.substr(0, paren_pos));
        }
        size_t comma_pos = name.find(",");
        if (comma_pos != string::npos) {
            name = trim(name.substr(0, comma_pos));
        }
        size_t colon_pos = name.find(":");
        if (colon_pos != string::npos) {
            name = trim(name.substr(0, colon_pos));
        }

        // Remove numbers, period, and dash from artist
        artist.erase(remove_if(artist.begin(), artist.end(), [](char c) {
            return isdigit(c) || c == '.' || c == '-';
        }), artist.end());

        // Ignore songs with unknown artist
        if (artist.empty()) {
            continue;
        }

        songs.push_back({name, artist});
    }

    // Sort songs by artist and name
    sort(songs.begin(), songs.end(), compareSongs);

    // Write output to csv file
    ofstream outfile("songs_ordered.csv");
    if (!outfile) {
        cerr << "Error: could not open output file." << endl;
        return 1;
    }
    outfile << "Artist,Name" << endl;
    for (const Song& song : songs) {
        outfile << song.artist << "," << song.name << endl;
    }

    cout << "Successfully ordered songs." << endl;

    return 0;
}
