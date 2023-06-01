#include "Humanic.h"
Humanic::Humanic() : Robot(0,0,0,NULL) {

}
Humanic::Humanic(int newType, int newStrength, int newHit, string name) : Robot(newType,newStrength,newHit,name) {
    
}
Humanic::Humanic(World *wrld,int x,int y,int newType, int newStrength, int newHit, string name) : Robot(wrld,x,y,4,50,200,name) {

}
Humanic::~Humanic() {

}
int Humanic::getDamage() {
    int damage;
    damage = Robot::getDamage(); // Get basic damage from Robot class
    int random = rand() % 100; // Random number between 0-100
    if(random < 10) { // If number is less than 10, means %10 chance
        damage += 50; // Add 50 points to current damage points
        cout << getType() << " damage increased with %10 chance." << "New damage is " << damage << " points!" << endl;
    }
    return damage;
}