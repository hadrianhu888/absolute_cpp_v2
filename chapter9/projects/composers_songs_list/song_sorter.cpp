#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Song {
    string artist;
    string title;
};

bool compare_songs(const Song& s1, const Song& s2) {
    if (s1.artist == s2.artist) {
        return s1.title < s2.title;
    } else {
        return s1.artist < s2.artist;
    }
}

vector<Song> read_songs(const string& filename) {
    vector<Song> songs;
    ifstream infile(filename);

    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        Song song;
        getline(iss, song.title, '-');
        getline(iss, song.artist);
        if (song.artist != "unknown artist") {
            songs.push_back(song);
        }
    }

    return songs;
}

void write_songs(const vector<Song>& songs, const string& filename) {
    ofstream outfile(filename);
    outfile << "Artist,Title" << endl;
    for (const auto& song : songs) {
        outfile << song.artist << "," << song.title << endl;
    }
}

int main() {
    vector<Song> songs = read_songs("songs.txt");
    sort(songs.begin(), songs.end(), compare_songs);
    write_songs(songs, "sorted_songs.csv");
    return 0;
}
