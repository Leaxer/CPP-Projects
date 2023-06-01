#ifndef ROOMBA_H
#define ROOMBA_H

#include "Robot.h"

class Robot;
class Roomba : public Robot {
    public:
        /*Default Constructor
         *Calls Robot constructor and send necessary values according to robot
         */
        Roomba();
        /*                          Gets world pointer address, name and coordinates
         *                          Calls Robot constructo and send values as parameter
         */
        Roomba(World* wrld, int x,int y,string name);
        /*                          Destructor
         */
        ~Roomba();
        /*@return name              name value
         */
        string getType();
        /*@return type              type value
         */
        int getIntType();
        /*                          Calls Robot getDamage() function and set to int value
         *                          Add more damage according to chance factor
         *@return damage             damage value
         */
        int getDamage();
        /*                          Move robot randomly until find other robots and fight
         *@param &a                 X coordinate
         *@param &b                 Y coordinate
         *@return int                Returns an int according to the winning robot
         */
        int move(int& a,int& b);
};

#endif // ROOMBA_H