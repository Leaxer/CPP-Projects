#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <fstream>
#include "Catalog.h"
#include "Catalog.cpp"
#include <string>
#include "Book.h"
#include "Music.h"
#include "Movie.h"
using namespace std;
using namespace Catalg;

class Program {
    public:
        /*                          Menu for program
         */
        void Menu();
};

#endif