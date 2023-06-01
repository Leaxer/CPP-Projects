#ifndef ROBOCOP_H
#define ROBOCOP_H

#include "Humanic.h"

class Robocop : public Humanic{
    public:
        /*Default Constructor
         *Calls Humanic constructor and send necessary values according to robot
         */
        Robocop();
        /*                          Gets world pointer address, name and coordinates
         *                          Calls Robot constructo and send values as parameter
         */
        Robocop(World* wrld, int x,int y,string name);
        /*                          Destructor
         */
        ~Robocop();
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

#endif // ROBOCOP_H