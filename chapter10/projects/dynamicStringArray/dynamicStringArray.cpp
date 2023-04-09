/**
 * @file dynamicStringArray.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>

using   namespace   std ;

int   main ( int   argc ,   char   ** argv );

class   dynamicStringArray
{
private:
    vector < string >  strings;
    string  str;
    int   size;
    int   capacity;
    int   index;
    int   count;
public:
        dynamicStringArray ();
        void   getStrings ();
        void   printStrings ();
        void  deleteEntry ();
        void  getEntry ();
        void setEntry();
        void  insertEntry ();
        void replaceEntry ();
        void sortStrings ();
        void copyStrings();
        void copyStrings(string target);
        ~ dynamicStringArray ();
    };

    dynamicStringArray :: dynamicStringArray ()
    {
        this -> size = 0 ;
        this -> capacity = 0 ;
        this -> index = 0 ;
        this -> count = 0 ;
    }

    void   dynamicStringArray :: getStrings ()
    {
        cout   <<   "Enter strings (\"quit\" to quit): " ;
        while ( str  !=  "quit" )
        {
            cin   >>  str;
            if ( str  !=  "quit" )
            {
                strings.push_back( str );
                this -> size ++;
                this -> capacity ++;
            }
        }
    }

    void   dynamicStringArray :: printStrings ()
    {
        cout   <<   "Enter index: " ;
        cin   >>  index;
        cout   <<   "Enter count: " ;
        cin   >>  count;
        if ( index  <  size  &&  count  <  capacity)
        {
            for ( int  i = index; i < count; i ++)
            {
                cout   <<  strings[i] <<  " " ;
            }
        }
        else
        {
            cout   <<   "Invalid index or count"   <<  endl;
        }
    }

    void dynamicStringArray:: deleteEntry()
    {
        cout << "Enter index: ";
        cin >> index;
        if (index < size)
        {
            strings.erase(strings.begin() + index);
            this->size--;
            this->capacity--;
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }

    void dynamicStringArray::getEntry()
    {
        cout << "Enter index: ";
        cin >> index;
        if (index < size)
        {
            cout << strings[index] << endl;
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }

    void dynamicStringArray::insertEntry()
    {
        cout << "Enter index: ";
        cin >> index;
        cout << "Enter string: ";
        cin >> str;
        if (index < size)
        {
            strings.insert(strings.begin() + index, str);
            this->size++;
            this->capacity++;
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }

    void dynamicStringArray::setEntry()
    {
        cout << "Enter index: ";
        cin >> index;
        cout << "Enter string: ";
        cin >> str;
        if (index < size)
        {
            strings[index] = str;
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }

    void dynamicStringArray::replaceEntry()
    {
        cout << "Enter index: ";
        cin >> index;
        cout << "Enter string: ";
        cin >> str;
        if (index < size)
        {
            strings[index] = str;
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }

    void dynamicStringArray::sortStrings()
    {
        sort(strings.begin(), strings.end());
    }

    void dynamicStringArray::copyStrings()
    {
        vector<string> copy = strings;
        for (int i = 0; i < copy.size(); i++)
        {
            cout << copy[i] << " ";
        }
        cout << endl;
    }

    void dynamicStringArray::copyStrings(string target)
    {
        vector<string> copy = strings;
        for (int i = 0; i < copy.size(); i++)
        {
            cout << copy[i] << " ";
        }
        cout << endl;
    }

    dynamicStringArray :: ~ dynamicStringArray ()
    {

    };

int main(int argc, char **argv)
{
    dynamicStringArray strArray;
    strArray.getStrings();
    strArray.printStrings();
    strArray.deleteEntry();
    strArray.getEntry();
    strArray.insertEntry();
    strArray.setEntry();
    strArray.replaceEntry();
    strArray.sortStrings();
    strArray.copyStrings();
    strArray.copyStrings("target");
    return 0;
}
