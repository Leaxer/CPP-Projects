#include "Robot.h"

Robot::Robot() {
    world = NULL;
    x = 0;
    y = 0;
    moved = false;
    name = "unknown";
    type = 0;
    strength = 0;
    hitpoints = 0;
}
Robot::Robot(int newType, int newStrength, int newHit, string name) {
    world = NULL;
    x = 0;
    y = 0;
    moved = false;
    type = newType;
    strength = newStrength;
    hitpoints = newHit;
    this->name = name;
}
Robot::Robot(World *wrld,int x,int y,int newType, int newStrength, int newHit, string name) {
    this->name = name;
    type = newType;
    strength = newStrength;
    hitpoints = newHit;
    this->x = x;
    this->y = y;
    moved = false;
    this->world = wrld;
    wrld->setAt(x,y,this);
}
Robot::~Robot() {
    
}
void Robot::putRobotToWorld(int x,int y) {
    this->x = x;
    this->y = y;
    world->setAt(x,y,this);
}
void Robot::setType(int newType) {
    type = newType;
}
void Robot::setStrength(int newStrength) {
    strength = newStrength;
}
void Robot::setHitpoints(int newHit) {
    hitpoints = newHit;
}
int Robot::getStrength() const {
    return strength;
}
int Robot::getHitpoints() const {
    return hitpoints;
}
int Robot::getX() const {
    return x;
}
int Robot::getY() const {
    return y;
}
int Robot::fight(Robot* sec) {
    int d_r,d_s;
    while(this->hitpoints > 0 && sec->hitpoints > 0) { // Loop until one robot dies
        d_r = this->getDamage(); // Get first robot's damage points
        sec->takeDamage(d_r); // Give damage to second robot
        if(sec->hitpoints > 0) {
            d_s =  sec->getDamage(); // Get second robot's damage points
            this->takeDamage(d_s); // Give damage to first robot
        }
    }
    if(this->hitpoints <= 0) { // If first robot dies
        cout << name << " died" << endl << endl;
        return 1;
    }else if(sec->hitpoints <= 0){ // If second robot dies
        cout << sec->name << " died" << endl << endl;
        return 2;
    }
}
int Robot::getDamage() {
    int damage;
    damage = (rand() % strength) + 1; // Get random number
    cout << getType() << " attacks for " << damage << " points!" << endl;
    return damage;
}
void Robot::takeDamage(int damage) {
    hitpoints -= damage; // Substract the damage points from hitpoints
    cout << "The new hitpoints of " << name << " is " << hitpoints << endl;
}
