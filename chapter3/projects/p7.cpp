/**
 * @file p7.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/**
 * http://www.cplusplus.com/forum/beginner/184940/ - this is where the code was borrowed from 
*/
#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cmath>
#include <string> 
#include <cstring>
#include <cctype> 
#include <string> 

using namespace std; 

int main(int argc, char ** argv); 
string tenString(int x); 
string oneString(int x); 
string teenString(int x); 
string singleString(int x); 
string Title(void); 
string songLyricsLine1(int x); 
string songLyricsLine2(int x); 
string songLyricsLine3(int x); 
string songLyricsLine4(int x); 
void printSongLyrics(int i, int x, int y); 

int main(int argc, char ** argv)
{
    int ones;
    int tens;
    int teens; 
    int single;
    int empty = 0; 
    int i = 99;
    cout << Title() << endl;   
    while (i >= 20) 
    {
        tens = i / 10; 
        ones = i % 10;  
        printSongLyrics(i,tens,ones);        
        i--;
    }
    i = 19; 
    while (i > 10)
    {
        teens = i; 
        printSongLyrics(i,teens, empty);
        i--; 

    }
    i = 10; 
    while (i >= 0)
    {
        single = i; 
        printSongLyrics(i, single, empty); 
        i--;
    }
    return 0;
}

string tenString(int x)
{
    switch (x)
    {
        case 9: 
        {
            return "Ninety"; 
            break; 
        }
        case 8: 
        {
            return "Eighty"; 
            break;
        }
        case 7: 
        {
            return "Seventy"; 
            break; 
        }
        case 6: 
        {
            return "Sixty"; 
            break; 
        }
        case 5: 
        {
            return "Fifty"; 
            break; 
        }
        case 4: 
        {
            return "Fourty"; 
            break; 
        }
        case 3: 
        {
            return "Thirty"; 
            break; 
        }
        case 2: 
        {
            return "Twenty"; 
            break; 
        }
        case 1: 
        {
            return ""; 
            break; 
        }
        default: 
        {
            return ""; 
            break; 
        }
    }   
}
string oneString(int x)
{
    switch (x)
    {
        case 9: 
        {
            return "Nine"; 
            break; 
        }
        case 8: 
        {
            return "Eight"; 
            break; 
        }
        case 7: 
        {
            return "Seven"; 
            break; 
        }
        case 6: 
        {
            return "Six"; 
            break; 
        }
        case 5: 
        {
            return "Five"; 
            break; 
        }
        case 4: 
        {
            return "Four"; 
            break; 
        }
        case 3: 
        {
            return "Three"; 
            break; 
        }
        case 2: 
        {
            return "Two"; 
            break; 
        }
        case 1: 
        {
            return "One"; 
            break; 
        }
        case 0: 
        {
            return ""; 
            break; 
        }
        default: 
        {
            return ""; 
            break; 
        }
    }
}
string teensString(int x)
{
    switch(x)
    {
        case 19: 
        {
            return "Nineteen"; 
            break; 
        }
        case 18: 
        {
            return "Eigthteen"; 
            break; 
        }
        case 17: 
        {
            return "Seventeen";
            break; 
        }
        case 16: 
        {
            return "Sixteen"; 
            break; 
        }
        case 15: 
        {
            return "Fifteen"; 
            break; 
        }
        case 14: 
        {
            return "Fourteen";
            break; 
        }
        case 13: 
        {
            return "Thirteen";
            break;
        }
        case 12: 
        {
            return "Twelve"; 
            break; 
        }
        case 11: 
        {
            return "Eleven"; 
            break; 
        }
        default: 
        {
            return ""; 
            break; 
        }
    }
}
string singleString(int x)
{
    switch (x)
    {
        case 9: 
        {
            return "Nine"; 
            break; 
        }
        case 8: 
        {
            return "Eight"; 
            break; 
        }
        case 7: 
        {
            return "Seven"; 
            break; 
        }
        case 6: 
        {
            return "Six"; 
            break; 
        }
        case 5: 
        {
            return "Five"; 
            break; 
        }
        case 4: 
        {
            return "Four"; 
            break; 
        }
        case 3: 
        {
            return "Three"; 
            break; 
        }
        case 2: 
        {
            return "Two"; 
            break; 
        }
        case 1: 
        {
            return "One"; 
            break; 
        }
        case 0: 
        {
            return "Zero"; 
            break; 
        }
        default: 
        {
            return ""; 
            break; 
        }
    }
}
string teenString(int x)
{
    switch(x)
    {
        case 19: 
        {
            return "Nineteen"; 
            break; 
        }
        case 18: 
        {
            return "Eigthteen"; 
            break; 
        }
        case 17: 
        {
            return "Seventeen";
            break; 
        }
        case 16: 
        {
            return "Sixteen"; 
            break; 
        }
        case 15: 
        {
            return "Fifteen"; 
            break; 
        }
        case 14: 
        {
            return "Fourteen";
            break; 
        }
        case 13: 
        {
            return "Thirteen";
            break;
        }
        case 12: 
        {
            return "Twelve"; 
            break; 
        }
        case 11: 
        {
            return "Eleven"; 
            break; 
        }
        default: 
        {
            return ""; 
            break; 
        }
    }
}

string Title(void)
{
    return "Ninety-Nine Bottles of Beer on the Wall\n\n";     
}
string songLyricsLine1(int x)
{
    if (x > 1)
    {
        return " bottles of beer on the wall,\n";
    }
    else if (x == 1) {
        return " bottle of beer on the wall,\n";
    }
    else if (x == 0) {
        return " bottle of beer on the wall.\n";
    }
}
string songLyricsLine2(int x)
{
    if (x > 1)
    {
        return " bottles of beer,\n";
    }
    else if (x == 1) {
        return " bottle of beer,\n";
    }
    else if (x == 0) {
        return "\n";
    }
}
string songLyricsLine3(int x)
{
    if (x >= 1)
    {
        return "\nTake one down, pass it around,\n";
    }
    else if (x == 0) {
        return "\n";
    }
}
string songLyricsLine4(int x)
{
    if (x > 1)
    {
        return " bottles of beer on the wall,\n";
    }
    else if (x == 1) {
        return " bottle of beer on the wall,\n";
    }
    else if (x == 0) {
        return "\n";
    }
}

void printSongLyrics(int i, int x, int y)
{
    if (x > 20) 
    {
        cout << endl << tenString(x) << " " << oneString(y); 
        cout << songLyricsLine1(i); 
        cout << endl << tenString(x) << " " << oneString(y); 
        cout << songLyricsLine2(i); 
        cout << songLyricsLine3(i); 
        cout << endl << tenString(x) << " " << oneString(y); 
        cout << songLyricsLine4(i); 
    }
    else if (i > 10)
    {
        cout << endl << teenString(x); 
        cout << songLyricsLine1(i); 
        cout << endl << teenString(x); 
        cout << songLyricsLine2(i); 
        cout << songLyricsLine3(i); 
        cout << endl << teenString(x); 
        cout << songLyricsLine4(i); 
    }
    else if (x > 0 && x < 10) 
    {
        cout << endl << singleString(x);
        cout << songLyricsLine1(i); 
        cout << endl << singleString(x);
        cout << songLyricsLine2(i); 
        cout << songLyricsLine3(i); 
        cout << endl << singleString(x);
        cout << songLyricsLine4(i); 
    } 
    else if (x == 0)
    {
        cout << endl << singleString(x);
        cout << songLyricsLine1(i); 
        cout << endl << singleString(x);
        cout << songLyricsLine2(i); 
        cout << songLyricsLine3(i); 
        cout << endl << singleString(x);
        cout << songLyricsLine4(i);
    }
}
