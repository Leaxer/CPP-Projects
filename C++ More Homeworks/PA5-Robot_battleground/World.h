#ifndef WORLD_H
#define WORLD_H

#include "Robot.h"

using namespace std;

const int WORLDSIZE = 10;

class Robot;
class World {
    // Declarate the classes as friend
    friend class Robot;
    friend class Roomba;
    friend class Bulldozer;
    friend class Humanic;
    friend class Robocop;
    friend class Optimusprime;
    public:
        /*Default Constructor
         *Set each grid to NULL
         */
        World( );
        /*                          Destructor
         *                          If grid is not null, delete the grid
         */
        ~World();
        /*@return grid[x][y]       Returns the robot in the coordinates
         */
        Robot* getAt(int x, int y);
        /*                          Place robot to grid acoording to x,y coordinates
         *@param x,y                Coordinates
         *@param rbt                Robot which will be placed to grid
         */
        void setAt(int x,int y,Robot *rbt);
        /*                          Print the game map
         */
        void Display();
        /*                          Controls the each grid, if grid is not null set robot's moved to false
         *                          Controls the each grid, if grid is not null and robot hasn't moved yet move the robot until find another robot
         */
        void SimulateOneStep();
        /*                          Set hitpoints with new value
         *@param newNum             New value of totalRobots
         */
        void setTotalRobots(int newNum);
        /*@return totalRobots       totalRobots value
         */
        int getTotalRobots();
        /*                          Increase totalRobots one time
         */
        void increaseTotalOne();
    private:
        Robot* grid[WORLDSIZE][WORLDSIZE]; // Game map where robots will be placed
        int totalRobots; // Number of total robots
};

#endif // WORLD_H