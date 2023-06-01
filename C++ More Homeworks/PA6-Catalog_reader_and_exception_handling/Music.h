#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
using namespace std;

namespace Catalg{
    const int MUSICFIELDSIZE = 4;

    class Music {
        template<class T> friend class Catalog;
        friend class Program;
        public:
            /*Default Constructor
            *Sets member values to ""
            */
            Music();
            /*                          Gets member value parameters and sets
            */
            Music(string title, string artists, string year, string genre);
            /*                          Copy constructor
            */
            Music(const Music& rightObject);
            /*                          Destructor
            */
            ~Music();
            /*                          Assign operator
            */
            Music& operator =(const Music& rightObject);
            /*                          Setter and getter functions
            */
            string getTitle() const;
            string getArtists() const;
            string getYear() const;
            string getGenre() const;
            void setTitle(string title);
            void setArtists(string artists);
            void setYear(string year);
            void setGenre(string genre);
            /*                          Return informations as a one line format
            */
            string fileOutput() const;
            /*                          Return number of member values
            */
            static int fieldCount();
            /*                          Compare functions for sort string sort function
            */
            static bool compareByTitle(const Music& obj1, const Music& obj2);
            static bool compareByArtists(const Music& obj1, const Music& obj2);
            static bool compareByYear(const Music& obj1, const Music& obj2);
            static bool compareByGenre(const Music& obj1, const Music& obj2);
            friend ostream& operator <<(ostream &outputStream, const Music& other);
        private:
            string title,artists,year,genre;
    };
}


#endif