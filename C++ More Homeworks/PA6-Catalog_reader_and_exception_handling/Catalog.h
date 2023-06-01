#ifndef CATALOG_H
#define CATALOG_H

#include "Book.h"
#include "Music.h"
#include "Movie.h"
#include <string>
#include <algorithm>
#include <list>
#include "exceptions.h"
#include <vector>
#include <fstream>
#include <sstream>

namespace Catalg{
    template <class T>
    class Catalog {
        friend class Program;
        public:
            /*Default Constructor
            *Set size to zero
            */
            Catalog();
            /*                          Copy constructor
            */
            Catalog(const Catalog<T>& rightObject);
            /*                          Assign operator
            */
            Catalog<T>& operator =(const Catalog<T>& rightObject);
            /*                          Add template item to list items
            */
            void add(const T& item);
            /*                          Read line and sets member values for template class
            *@param outputFile         File of output.txt
            *@param line               One book line
            *@return vector<string>    Return information of one template class
            */
            vector<string> ReadData(ofstream& outputFile,string line);
            /*                          Sort and search command function
            *@param outputFile         File of output.txt
            */
            void Command(ofstream& outputFile);
            /*                          Getter functions
            */
            int getSize();
            list<T> getList();
            /*                          Search one keyword on items
            *                          Overload for each class
            *@param keyword            Keyword which will be searched
            *@param type               Type of class
            *@param const list<T>&     Items reference
            *@return string            Returns items with the keyword
            */
            void search(string keyword, string type, const list<Book>& book,ofstream& outputFile);
            void search(string keyword, string type, const list<Music>& music,ofstream& outputFile);
            void search(string keyword, string type, const list<Movie>& movie,ofstream& outputFile);
            /*                          Sort function
            *                          Overload for each class
            *@param type               Type of class
            *@param const list<T>&     Items reference
            */
            int sort(string type, const list<Book>& book);
            int sort(string type, const list<Music>& music);
            int sort(string type, const list<Movie>& movie);
            /*                          Prints the items
            */
            void print(ofstream& outputFile) {for(auto it = items.begin();it != items.end();++it) {
                string information = it->fileOutput();
                outputFile << information << endl;
                }
            }
        private:
            list<T> items; // List of template class items
            int size; // Size of list
    };
}


#endif