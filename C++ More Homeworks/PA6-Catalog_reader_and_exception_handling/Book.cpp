#include "Book.h"

namespace Catalg{ 
    Book::Book() {
        // Sets values to ""
        title = "";
        authors = "";
        year = "";
        tags = "";
    }
    Book::Book(string title, string authors, string year, string tags) {
        // Sets values
        this->title = title;
        this->authors = authors;
        this->year = year;
        this->tags = tags;
    }
    Book::Book(const Book& rightObject) {
        // Sets values
        title = rightObject.title;
        authors = rightObject.authors;
        year = rightObject.year;
        tags = rightObject.tags;
    }
    Book& Book::operator =(const Book& rightObject) {
        // If it has the same address with parameter
        if(this == &rightObject) {
            return *this; // Returns same object
        }
        // Sets values
        title = rightObject.title;
        authors = rightObject.authors;
        year = rightObject.year;
        tags = rightObject.tags;
        return *this;
    }

    Book::~Book() {
    }

    string Book::getTitle() const{
        return title;
    }
    string Book::getAuthors() const{
        return authors;
    }
    string Book::getYear() const{
        return year;
    }
    string Book::getTags() const{
        return tags;
    }
    void Book::setTitle(string title) {
        this->title = title;
    }
    void Book::setAuthors(string authors) {
        this->authors = authors;
    }
    void Book::setYear(string year) {
        this->year = year;
    }
    void Book::setTags(string tags) {
        this->tags = tags;
    }
    string Book::fileOutput() const{
        return "\"" + title + "\" \"" + authors + "\" \"" + year + "\" \"" + tags + "\"";
    }
    int Book::fieldCount() {
        return BOOKFIELDSIZE;
    }
    // Compare the two objects and return
    bool Book::compareByTitle(const Book& obj1, const Book& obj2) {
        return obj1.getTitle() < obj2.getTitle();
    }
    bool Book::compareByAuthors(const Book& obj1, const Book& obj2) {
        return obj1.getAuthors() < obj2.getAuthors();
    }
    bool Book::compareByYear(const Book& obj1, const Book& obj2) {
        return obj1.getYear() < obj2.getYear();
    }
    bool Book::compareByTags(const Book& obj1, const Book& obj2) {
        return obj1.getTags() < obj2.getTags();
    }
    ostream& operator <<(ostream &outputStream, const Book& other) {
        outputStream << "\"" << other.title << "\" \"" << other.authors << "\" \"" << other.year << "\" \"" << other.tags << "\"";
        return outputStream;
    }
}