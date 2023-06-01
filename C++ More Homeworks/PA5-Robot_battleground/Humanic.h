#ifndef HUMANIC_H
#define HUMANIC_H

#include "Robot.h"

class Humanic : public Robot{
    public:
        /*Default Constructor
         *Calls Robot constructor and send necessary values according to robot
         */
        Humanic();
        /*                          Constructor
         *                          Gets values from paramater and calls Robot constructor
         */
        Humanic(int newType, int newStrength, int newHit, string name);
        /*                          Constructor
         *                          Gets values from paramater and calls Robot constructor
         */
        Humanic(World *wrld,int x,int y,int newType, int newStrength, int newHit, string name);
        /*                          Destructor
         */
        virtual ~Humanic();
        /*                          Pure virtual function of getType
         *@return                   Name of robot
         */
        virtual string getType() = 0;
        /*                          Pure virtual function of getIntType
         *@return                   Int type value of robot
         */
        virtual int getIntType() = 0;
        /*                          Virtual function of getDamage
         *                          Calls Robot::getDamage and get basic damage
         *                          Calculate humanic robot damage and adds to basic damage
         *                          Return the damage
         *@return damage            Damage value
         */
        virtual int getDamage();
        /*                          Pure virtual function
         *@param &a                 X coordinate
         *@param &b                 Y coordinate
         *@return int               Returns an int according to the winning robot
         */
        virtual int move(int& a,int& b) = 0;
};

#endif // HUMANIC_H