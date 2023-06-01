#include <time.h>
#include "World.h"
#include "Robocop.h"
#include "Optimusprime.h"
#include "Bulldozer.h"
#include "Roomba.h"

const int INITIAL = 5;

int main() {
    srand(time(NULL));
    World w;
    int count = 0;
    string name;
    while(count < INITIAL) {
        name = "roomba_";
        name += to_string(count); // Add robot's number to end of the name
        int x = rand() % WORLDSIZE; // Get random number for x coordinate
        int y = rand() % WORLDSIZE; // Get random number for y coordinate
        if(w.getAt(x,y)== NULL) { // If grid is empty
            count++; // Increase count
            Roomba *d1 = new Roomba(&w,x,y,name); // Allocate memory for one roomba class and place it to w(world class)
            w.increaseTotalOne(); // Increase total robot number
        }
    }
    count = 0;
    while(count < INITIAL) {
        name = "robocop_";
        name += to_string(count); // Add robot's number to end of the name
        int x = rand() % WORLDSIZE; // Get random number for x coordinate
        int y = rand() % WORLDSIZE; // Get random number for y coordinate
        if(w.getAt(x,y)== NULL) { // If grid is empty
            count++; // Increase count
            Robocop *r1 = new Robocop(&w,x,y,name); // Allocate memory for one roomba class and place it to w(world class)
            w.increaseTotalOne(); // Increase total robot number
        }
    }
    count = 0;
    while(count < INITIAL) {
        name = "optimusprime_";
        name += to_string(count); // Add robot's number to end of the name
        int x = rand() % WORLDSIZE; // Get random number for x coordinate
        int y = rand() % WORLDSIZE; // Get random number for y coordinate
        if(w.getAt(x,y)== NULL) { // If grid is empty
            count++; // Increase count
            Optimusprime *d1 = new Optimusprime(&w,x,y,name); // Allocate memory for one roomba class and place it to w(world class)
            w.increaseTotalOne(); // Increase total robot number
        }
    }
    count = 0;
    while(count < INITIAL) {
        name = "bulldozer_";
        name += to_string(count); // Add robot's number to end of the name
        int x = rand() % WORLDSIZE; // Get random number for x coordinate
        int y = rand() % WORLDSIZE; // Get random number for y coordinate
        if(w.getAt(x,y)== NULL) { // If grid is empty
            count++; // Increase count
            Bulldozer *d1 = new Bulldozer(&w,x,y,name); // Allocate memory for one roomba class and place it to w(world class)
            w.increaseTotalOne(); // Increase total robot number
        }
    }
    while(w.getTotalRobots() > 1) { // Loop until one robot left
        w.SimulateOneStep();
    }
}