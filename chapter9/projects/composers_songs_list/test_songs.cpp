/**
 * @file test_songs.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cassert>
#include "song_sorter.hpp"

void test_read_songs() {
    std::vector<Song> songs = read_songs("test_songs.txt");
    assert(songs.size() == 3);
    assert(songs[0].artist == "Beethoven");
    assert(songs[0].title == "Adagio \"MoonLight\" Sonata");
    assert(songs[1].artist == "Handel");
    assert(songs[1].title == "Coronation Anthem");
    assert(songs[2].artist == "Mendelssohn");
    assert(songs[2].title == "The Hebrides");
}

void test_compare_songs() {
    Song s1 = {"Handel", "The Water Music"};
    Song s2 = {"Handel", "The Messiah"};
    Song s3 = {"Mendelssohn", "The Hebrides"};
    assert(compare_songs(s1, s2) == true);
    assert(compare_songs(s2, s1) == false);
    assert(compare_songs(s1, s3) == true);
    assert(compare_songs(s3, s1) == false);
    assert(compare_songs(s2, s3) == true);
    assert(compare_songs(s3, s2) == false);
}

int main() {
    test_read_songs();
    test_compare_songs();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
