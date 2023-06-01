#include "Catalog.h"

namespace Catalg{
    template <class T>
    Catalog<T>::Catalog() {
        // Sets size to zero
        size = 0;
    }
    template <class T>
    Catalog<T>::Catalog(const Catalog<T>& rightObject) {
        // Sets member values
        size = rightObject.size;
        items.assign(rightObject.items.begin(),rightObject.items.end());
    }
    template <class T>
    Catalog<T>& Catalog<T>::operator =(const Catalog<T>& rightObject) {
        // If it has the same address with parameter
        if(this == &rightObject) {
            return *this;
        }
        // Sets member values
        size = rightObject.size;
        items.assign(rightObject.items.begin(),rightObject.items.end());
        return *this;
    }
    template <class T>
    void Catalog<T>::add(const T& temp) {
        // Adds parameter item to items
        items.push_back(temp);
    }
    template <class T>
    int Catalog<T>::getSize() {
        return size;
    }

    template <class T>
    list<T> Catalog<T>::getList()  {
        return items;
    }
    template <class T>
    vector<string> Catalog<T>::ReadData(ofstream& outputFile,string line) {
            istringstream iss(line); // Getline
            vector<string> data;
            string item;
            bool isFirst = true;
            while (getline(iss, item, '"')) { // Get line's string as item, get string until hits to delimiter
                if (item != " " && isFirst != true && (int)item.back() != 13) {
                    data.push_back(item); // Add string to data
                }
                isFirst = false;
            }
            try {
                int count = 0;
                for(auto i = data.begin(); i != data.end();++i) // Loop for data vector
                    if(*i != "") count++; // If data is not empty
                if(count != T::fieldCount()) { // If at least one data is empty throw exception
                    throw MissingFieldException("Exception: missing field");
                }
            } catch(MissingFieldException e) {
                outputFile << e.getMessage() << endl;
                outputFile << line << endl;
                vector<string> fail; // Create temp vector to return
                fail.push_back("failed");
                return fail;
            }
            try {
                for(auto it = items.begin();it != items.end();++it) { // Loop for data vector
                    if(data[0] == it->title) {// If title equals to one of items's title throw exception
                        throw DuplicateEntryException("Exception: duplicate entry");                
                    }
                }
            } catch(DuplicateEntryException e) {
                outputFile << e.getMessage() << endl;
                outputFile << line << endl;
                vector<string> fail; // Create temp vector to return
                fail.push_back("failed");
                return fail;
            }
            size++; // Increase size
            return data;
    }
    template <class T>
    void Catalog<T>::Command(ofstream& outputFile) {
        ifstream commandFile("commands.txt");
        string line;
        string information;
        while(getline(commandFile, line)) { // Loop until finish the commands
            
            istringstream iss(line); // Get line
            vector<string> data; // Create data vector
            string item;
            while(getline(iss, item, '"')) { // Loop until end of the line
                if((int)item.back() != 13)
                    data.push_back(item); // Add item to data
            }
            data[0].erase(data[0].size() - 1); // Delete space from the end
            try {
                if(data[0] != "search" && data[0] != "sort") { // If commmand is not correct throw exception
                    throw WrongCommandException("Exception: command is wrong");                
                }
            } catch(WrongCommandException e) {
                outputFile << e.getMessage() << endl;
                continue;
            }
            try {
                if(data.size() == 2) { // If data size equals to 2, means sort command
                    if(data[1] != "title" && data[1] != "authors" && data[1] != "year" && data[1] != "tags"
                       && data[1] != "artists" && data[1] != "genre" && data[1] != "director" && data[1] != "starring") { // If not equal to type throw exception
                        throw WrongCommandException("Exception: command is wrong");
                    }
                    if(sort(data[1],items) != 0) { // Send type and items member to sort function 
                        outputFile << line << endl; // Write line to file
                    }else {
                        throw WrongCommandException("Exception: command is wrong");
                    }
                    print(outputFile);
                }else if(data.size() == 4) { // If data size equals to 4, means sort search
                    if(data[3] != "title" && data[3] != "authors" && data[3] != "year" && data[3] != "tags"
                    && data[3] != "artists" && data[3] != "genre" && data[3] != "director" && data[3] != "starring") { // If not equal to type throw exception
                        throw WrongCommandException("Exception: command is wrong");
                    }
                    outputFile << line << endl; // Write line to file
                    search(data[1],data[3],items,outputFile); // Send keyword,type and items member to search function
                }
                // If it has less or more useless words on command throw exception
                else {
                    throw WrongCommandException("Exception: command is wrong");
                }
            } catch(WrongCommandException e) {
                outputFile << e.getMessage() << endl;
                outputFile << line << endl;
            }
        }
        commandFile.close(); // Close the file
    }
    template <class T>
    void Catalog<T>::search(string keyword, string type, const list<Book>& items,ofstream& outputFile) {
            // Calls find function and return information of this item
            if(type == "title") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(it->title.find(keyword) != string::npos) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }
            else if(type == "authors") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(it->authors.find(keyword) != string::npos) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }else if(type == "year") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(keyword == it->year) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }else if(type == "tags") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(it->tags.find(keyword) != string::npos) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }
    }
    template <class T>
    void Catalog<T>::search(string keyword, string type, const list<Music>& items,ofstream& outputFile) {
        // Calls find function and return information of this item
            if(type == "title") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(it->title.find(keyword) != string::npos) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }
            else if(type == "artist") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(it->artists.find(keyword) != string::npos) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }else if(type == "year") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(keyword == it->year) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }else if(type == "genre") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(it->genre.find(keyword) != string::npos) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }
    }
    template <class T>
    void Catalog<T>::search(string keyword, string type, const list<Movie>& items,ofstream& outputFile) {
        // Calls find function and return information of this item
            if(type == "title") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(it->title.find(keyword) != string::npos) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }
            else if(type == "director") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(it->director.find(keyword) != string::npos) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }else if(type == "year") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(keyword == it->year) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }else if(type == "genre") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(it->genre.find(keyword) != string::npos) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }else if(type == "starring") {
                for(auto it = items.begin();it != items.end();++it) {
                    if(it->starring.find(keyword) != string::npos) {
                        outputFile << it->fileOutput() << endl;
                    }
                }
            }
    }
    template<class T>
    int Catalog<T>::sort(string type, const list<Book>& book) {
        // Calls sort function according to type
        if(type == "title") {
                items.sort(Book::compareByTitle);
                return 1;
            }else if(type == "authors") {
                items.sort(Book::compareByAuthors);
                return 1;
            }else if(type == "year") {
                items.sort(Book::compareByYear);
                return 1;
            }else if(type == "tags") {
                items.sort(Book::compareByTags);
                return 1;
            }
        return 0;
    }
    template<class T>
    int Catalog<T>::sort(string type, const list<Music>& music) {
        // Calls sort function according to type
        if(type == "title") {
                items.sort(T::compareByTitle);
                return 1;
            }else if(type == "artists") {
                items.sort(T::compareByArtists);
                return 1;
            }else if(type == "year") {
                items.sort(T::compareByYear);
                return 1;
            }else if(type == "genre") {
                items.sort(T::compareByGenre);
                return 1;
            }
        return 0;
    }
    template<class T>
    int Catalog<T>::sort(string type, const list<Movie>& movie) {
        // Calls sort function according to type
        if(type == "title") {
                items.sort(T::compareByTitle);
                return 1;
            }else if(type == "director") {
                items.sort(T::compareByDirector);
                return 1;
            }else if(type == "year") {
                items.sort(T::compareByYear);
                return 1;
            }else if(type == "genre") {
                items.sort(T::compareByGenre);
                return 1;
            }else if(type == "starring") {
                items.sort(T::compareByStarring);
                return 1;
            }
        return 0;
    }
}