#include "Music.h"

namespace Catalg{ 
    Music::Music() {
        // Sets values
        title = "";
        artists = "";
        year = "";
        genre = "";
    }
    Music::Music(string title, string artists, string year, string genre) {
        // Sets values
        this->title = title;
        this->artists = artists;
        this->year = year;
        this->genre = genre;
    }
    Music::Music(const Music& rightObject) {
        // Sets values
        title = rightObject.title;
        artists = rightObject.artists;
        year = rightObject.year;
        genre = rightObject.genre;
    }
    Music& Music::operator =(const Music& rightObject) {
        // If it has the same address with parameter
        if(this == &rightObject) {
            return *this;
        }
        // Sets values
        title = rightObject.title;
        artists = rightObject.artists;
        year = rightObject.year;
        genre = rightObject.genre;
        return *this;
    }

    Music::~Music() {
    }

    string Music::getTitle() const{
        return title;
    }
    string Music::getArtists() const{
        return artists;
    }
    string Music::getYear() const{
        return year;
    }
    string Music::getGenre() const{
        return genre;
    }
    void Music::setTitle(string title) {
        this->title = title;
    }
    void Music::setArtists(string artists) {
        this->artists = artists;
    }
    void Music::setYear(string year) {
        this->year = year;
    }
    void Music::setGenre(string genre) {
        this->genre = genre;
    }
    string Music::fileOutput() const{
        return "\"" + title + "\" \"" + artists + "\" \"" + year + "\" \"" + genre + "\"";
    }
    int Music::fieldCount() {
        return MUSICFIELDSIZE;
    }
    // Compare the two objects and return
    bool Music::compareByTitle(const Music& obj1, const Music& obj2) {
        return obj1.getTitle() < obj2.getTitle();
    }
    bool Music::compareByArtists(const Music& obj1, const Music& obj2) {
        return obj1.getArtists() < obj2.getArtists();
    }
    bool Music::compareByYear(const Music& obj1, const Music& obj2) {
        return obj1.getYear() < obj2.getYear();
    }
    bool Music::compareByGenre(const Music& obj1, const Music& obj2) {
        return obj1.getGenre() < obj2.getGenre();
    }
    ostream& operator <<(ostream &outputStream, const Music& other) {
        outputStream << "\"" << other.title << "\" \"" << other.artists << "\" \"" << other.year << "\" \"" << other.genre << "\"";
        return outputStream;
    }
}