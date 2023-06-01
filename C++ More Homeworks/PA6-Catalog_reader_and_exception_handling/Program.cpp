#include "Program.h"

void Program::Menu() {
    ifstream dataFile("data.txt");
    ofstream outputFile("output.txt");
    string line;
    getline(dataFile, line); // Get first line
    outputFile << "Catalog Read: " << line << endl;
    vector<string> data;
    line.erase(line.size() - 1); // Delete space from the end
    if(line == "book") {
        Catalog<Book> cat; // Initialize catalog for book
        while (getline(dataFile, line)) { // Loop until finish file
            data = cat.ReadData(outputFile,line); // Calls catalog's readData function
            if(data[0] != "failed") { // If it doesn't throw exception
                Book temp(data[0], data[1], data[2], data[3]); //  temp book
                cat.add(temp); // Adds book to catalog
            }
        }
        outputFile << cat.getSize() << " unique entries" << endl;
        cat.Command(outputFile); // Calls command function
    }else if(line == "music") {
        Catalog<Music> cat; // Initialize catalog for music
        while (getline(dataFile, line)) { // Loop until finish file
            data = cat.ReadData(outputFile,line); // Calls catalog's readData function
            if(data[0] != "failed") { // If it doesn't throw exception
                Music temp(data[0], data[1], data[2], data[3]); //  temp music
                cat.add(temp); // Adds music to catalog
            }
        }
        outputFile << cat.getSize() << " unique entries" << endl;
        cat.Command(outputFile); // Calls command function
    }else if(line == "movie") {
        Catalog<Movie> cat; // Initialize catalog for movie
        while (getline(dataFile, line)) { // Loop until finish file
            data = cat.ReadData(outputFile,line); // Calls catalog's readData function
            if(data[0] != "failed") { // If it doesn't throw exception
                Movie temp(data[0], data[1], data[2], data[3], data[4]); //  temp movie
                cat.add(temp); // Adds movie to catalog
            }
        }
        outputFile << cat.getSize() << " unique entries" << endl;
        cat.Command(outputFile); // Calls command function
    }
    dataFile.close();
}