#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

namespace Catalg{
    const int BOOKFIELDSIZE = 4;

    class Book {
        template<class T> friend class Catalog;
        friend class Program;
        public:
            /*Default Constructor
            *Sets member values to ""
            */
            Book();
            /*                          Gets member value parameters and sets
            */
            Book(string title, string authors, string year, string tags);
            /*                          Copy constructor
            */
            Book(const Book& rightObject);
            /*                          Destructor
            */
            ~Book();
            /*                          Assign operator
            */
            Book& operator =(const Book& rightObject);
            /*                          Setter and getter functions
            */
            string getTitle() const;
            string getAuthors() const;
            string getYear() const;
            string getTags() const;
            void setTitle(string title);
            void setAuthors(string authors);
            void setYear(string year);
            void setTags(string tags);
            /*                          Return informations as a one line format
            */
            string fileOutput() const;
            /*                          Return number of member values
            */
            static int fieldCount();
            /*                          Compare functions for sort string sort function
            */
            static bool compareByTitle(const Book& obj1, const Book& obj2);
            static bool compareByAuthors(const Book& obj1, const Book& obj2);
            static bool compareByYear(const Book& obj1, const Book& obj2);
            static bool compareByTags(const Book& obj1, const Book& obj2);
            friend ostream& operator <<(ostream &outputStream, const Book& other);
        private:
            string title,authors,year,tags;
    };
}

#endif