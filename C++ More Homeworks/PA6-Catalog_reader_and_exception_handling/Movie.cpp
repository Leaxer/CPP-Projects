#include "Movie.h"

namespace Catalg{
    Movie::Movie() {
        title = "";
        director = "";
        year = "";
        genre = "";
        starring = "";
    }
    Movie::Movie(string title, string director, string year, string genre, string starring) {
        this->title = title;
        this->director = director;
        this->year = year;
        this->genre = genre;
        this->starring = starring;
    }
    Movie::Movie(const Movie& rightObject) {
        title = rightObject.title;
        director = rightObject.director;
        year = rightObject.year;
        genre = rightObject.genre;
        starring = rightObject.starring;
    }
    Movie& Movie::operator =(const Movie& rightObject) {
        // If it has the same address with parameter
        if(this == &rightObject) {
            return *this;
        }
        // Sets values
        title = rightObject.title;
        director = rightObject.director;
        year = rightObject.year;
        genre = rightObject.genre;
        starring = rightObject.starring;
        return *this;
    }

    Movie::~Movie() {
    }

    string Movie::getTitle() const{
        return title;
    }
    string Movie::getDirector() const{
        return director;
    }
    string Movie::getYear() const{
        return year;
    }
    string Movie::getGenre() const{
        return genre;
    }
    string Movie::getStarring() const{
        return starring;
    }
    void Movie::setTitle(string title) {
        this->title = title;
    }
    void Movie::setDirector(string director) {
        this->director = director;
    }
    void Movie::setYear(string year) {
        this->year = year;
    }
    void Movie::setGenre(string genre) {
        this->genre = genre;
    }
    void Movie::setStarring(string starring) {
        this->starring = starring;
    }
    string Movie::fileOutput() const{
        return "\"" + title + "\" \"" + director + "\" \"" + year + "\" \"" + genre + "\" \"" + starring + "\"";
    }
    int Movie::fieldCount() {
        return MOVIEFIELDSIZE;
    }
    // Compare the two objects and return
    bool Movie::compareByTitle(const Movie& obj1, const Movie& obj2) {
        return obj1.getTitle() < obj2.getTitle();
    }
    bool Movie::compareByDirector(const Movie& obj1, const Movie& obj2) {
        return obj1.getDirector() < obj2.getDirector();
    }
    bool Movie::compareByYear(const Movie& obj1, const Movie& obj2) {
        return obj1.getYear() < obj2.getYear();
    }
    bool Movie::compareByGenre(const Movie& obj1, const Movie& obj2) {
        return obj1.getGenre() < obj2.getGenre();
    }
    bool Movie::compareByStarring(const Movie& obj1, const Movie& obj2) {
        return obj1.getStarring() < obj2.getStarring();
    }
    ostream& operator <<(ostream &outputStream, const Movie& other) {
        outputStream << "\"" << other.title << "\" \"" << other.director << "\" \"" << other.year << "\" \"" << other.genre << "\"";
        return outputStream;
    }
}