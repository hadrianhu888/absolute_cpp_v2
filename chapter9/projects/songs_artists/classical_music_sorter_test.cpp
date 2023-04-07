/**
 * @file classical_music_sorter_test.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <cassert>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <istream>
#include "classical_music_sorter.cpp"

using namespace std;

void test_read_input_file()
{
    vector<string> songs;
    read_input_file("test_input.txt", songs);
    assert(songs.size() == 4);
    assert(songs[0] == "Beethoven: Symphony No. 5");
    assert(songs[1] == "Chopin: Nocturne in E-flat Major");
    assert(songs[2] == "Bach: Brandenburg Concerto No. 3");
    assert(songs[3] == "Mozart: Eine Kleine Nachtmusik");
    cout << "test_read_input_file passed." << endl;
}

void test_write_output_file()
{
    vector<string> songs = {"Beethoven: Symphony No. 5",
                            "Chopin: Nocturne in E-flat Major",
                            "Bach: Brandenburg Concerto No. 3",
                            "Mozart: Eine Kleine Nachtmusik"};
    write_output_file("test_output.txt", songs);
    // verify the file was written correctly
    ifstream fin("test_output.txt");
    string line;
    getline(fin, line);
    assert(line == "Bach: Brandenburg Concerto No. 3");
    getline(fin, line);
    assert(line == "Chopin: Nocturne in E-flat Major");
    getline(fin, line);
    assert(line == "Beethoven: Symphony No. 5");
    getline(fin, line);
    assert(line == "Mozart: Eine Kleine Nachtmusik");
    cout << "test_write_output_file passed." << endl;
}

void test_extract_last_name_first()
{
    assert(extract_last_name_first("Ludwig van Beethoven") == "Beethoven, Ludwig van");
    assert(extract_last_name_first("Johann Sebastian Bach") == "Bach, Johann Sebastian");
    assert(extract_last_name_first("Wolfgang Amadeus Mozart") == "Mozart, Wolfgang Amadeus");
    cout << "test_extract_last_name_first passed." << endl;
}

void test_format_songs()
{
    vector<string> songs = {"Beethoven: Symphony No. 5",
                            "Chopin: Nocturne in E-flat Major",
                            "Bach: Brandenburg Concerto No. 3",
                            "Mozart: Eine Kleine Nachtmusik"};
    format_songs(songs);
    assert(songs[0] == "Beethoven, Ludwig van: Symphony No. 5");
    assert(songs[1] == "Chopin, Frédéric: Nocturne in E-flat Major");
    assert(songs[2] == "Bach, Johann Sebastian: Brandenburg Concerto No. 3");
    assert(songs[3] == "Mozart, Wolfgang Amadeus: Eine Kleine Nachtmusik");
    cout << "test_format_songs passed." << endl;
}

void test_sort_songs()
{
    // arrange
    vector<string> songs = {"Symphony No. 9 - Beethoven",
                            "The Four Seasons - Vivaldi",
                            "Moonlight Sonata - Beethoven",
                            "Canon in D - Pachelbel",
                            "Ride of the Valkyries - Wagner"};

    vector<string> expected_sorted_songs = {"Canon in D - Pachelbel",
                                            "Moonlight Sonata - Beethoven",
                                            "Symphony No. 9 - Beethoven",
                                            "The Four Seasons - Vivaldi",
                                            "Ride of the Valkyries - Wagner"};

    // act
    sort_songs(songs);

    // assert
    assert(songs == expected_sorted_songs);
}
