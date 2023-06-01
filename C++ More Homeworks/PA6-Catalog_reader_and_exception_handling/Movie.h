#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
using namespace std;

namespace Catalg{
    const int MOVIEFIELDSIZE = 5;

    class Movie {
        template<class T> friend class Catalog;
        friend class Program;
        public:
            /*Default Constructor
            *Sets member values to ""
            */
            Movie();
            /*                          Gets member value parameters and sets
            */
            Movie(string title, string director, string year, string genre, string starring);
            /*                          Copy constructor
            */
            Movie(const Movie& rightObject);
            /*                          Destructor
            */
            ~Movie();
            /*                          Assign operator
            */
            Movie& operator =(const Movie& rightObject);
            /*                          Setter and getter functions
            */
            string getTitle() const;
            string getDirector() const;
            string getYear() const;
            string getGenre() const;
            string getStarring() const;
            void setTitle(string title);
            void setDirector(string director);
            void setYear(string year);
            void setGenre(string genre);
            void setStarring(string starring);
            /*                          Return informations as a one line format
            */
            string fileOutput() const;
            /*                          Return number of member values
            */
            static int fieldCount();
            /*                          Compare functions for sort string sort function
            */
            static bool compareByTitle(const Movie& obj1, const Movie& obj2);
            static bool compareByDirector(const Movie& obj1, const Movie& obj2);
            static bool compareByYear(const Movie& obj1, const Movie& obj2);
            static bool compareByGenre(const Movie& obj1, const Movie& obj2);
            static bool compareByStarring(const Movie& obj1, const Movie& obj2);
            friend ostream& operator <<(ostream &outputStream, const Movie& other);
        private:
            string title,director,year,genre,starring;
    };
}

#endif