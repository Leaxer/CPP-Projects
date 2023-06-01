#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>
#include "World.h"

using namespace std;

const int OPTIMUS = 1;
const int ROBOCOP = 2;
const int ROOMBA = 3;
const int BULLDOZER = 4;

class World;
class Robot {
    friend class World;
    public:
        /*Default Constructor
         *Sets all values to zero or null
         */
        Robot();
        /*                          Constructor
         *                          Gets values from paramater and set members
         */
        Robot(int newType, int newStrength, int newHit, string name);
        /*                          Constructor
         *                          Gets values from paramater and set members
         */
        Robot(World *wrld,int x,int y,int newType, int newStrength, int newHit, string name);
        /*                          Destructor
         */
        virtual ~Robot();
        /*                          Gets coordinates from parameter and put robot to world according to coordinates
         */
        void putRobotToWorld(int x,int y);
        /*                          Set type with new value
         *@param newType            New value of type
         */
        void setType(int newType);
        /*                          Set strength with new value
         *@param newStrength        New value of strength
         */
        void setStrength(int newStrength);
        /*                          Set hitpoints with new value
         *@param newHit             New value of hitpoints
         */
        void setHitpoints(int newHit);
        /*@return strength          Strength of robot
         */
        int getStrength() const;
        /*@return hitpoints         Health of robot
         */
        int getHitpoints() const;
        /*@return x                 Coordinate x value
         */
        int getX() const;
        /*@return y                 Coordinate y value
         */
        int getY() const;
        /*                          Fight two robots and return int according to who lose
         *@param sec                The second robot to fight
         *@return int               Who lose the fight
         */
        int fight(Robot* sec);
        /*                          Pure virtual function of getIntType
         *@return                   Int type value of robot
         */
        virtual int getIntType() = 0;
        /*                          Pure virtual function of getType
         *@return                   Name of robot
         */
        virtual string getType() = 0;
        /*                          Virtual function of getDamage
         *                          Calculate basic damage of robot and return the damage
         *@return damage            damage value
         */
        virtual int getDamage();
        /*                          Pure virtual function
         *@param &a                 X coordinate
         *@param &b                 Y coordinate
         *@return int               Returns an int according to the winning robot
         */
        virtual int move(int& a,int& b) = 0;
        /*                          Takes the damage point from the parameter and subtracts it from the hitpoints.
         */
        void takeDamage(int damage);
    protected:
        string name; // Name of robot
        int type; // Type of robot
        int strength; // Strength points of robot
        int hitpoints; // Health of robot
        int x,y; // Coordinates of robot on grid
        World *world; // World pointer to be used in the game
        bool moved; // Boolean value depending on whether the robot moved
};

#endif // ROBOT_H