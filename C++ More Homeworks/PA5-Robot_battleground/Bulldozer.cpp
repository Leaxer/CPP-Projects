#include "Bulldozer.h"

Bulldozer::Bulldozer() : Robot(4,50,200,"defaultbulldozer") {

}
Bulldozer::Bulldozer(World* wrld, int x,int y,string name) : Robot(wrld,x,y,4,50,200,name) {

}
Bulldozer::~Bulldozer() {
    
}
string Bulldozer::getType() {
    return name;
}
int Bulldozer::getIntType() {
    return BULLDOZER;
}
int Bulldozer::getDamage() {
    return Robot::getDamage(); // Get basic damage from Robot class and return it
}

int Bulldozer::move(int& a,int& b) {
    int dir; // Initiliaze a number to hold direction
    int lastMove = -1; // Initiliaze a number to hold previous move, if user moved to left the number will hold 1(which means it can't move to right)
    int fightResult = -1; // Initiliaze a number to hold who won the fight
    while(fightResult == -1) {
        dir = rand() % 4; // Get a number between 0-4
        if(dir == 0 && lastMove != 0) { // If direction is zero and lastMove is not zero
            if(y>0) { // If (y-1) is inside the grid borders
                if(world->getAt(x,y-1) == NULL) { // If this coordinates' cell is null
                    world->setAt(x,y-1,world->getAt(x,y)); // Place this robot to new cell
                    world->setAt(x,y,NULL); // Set current cell to null
                    y--; // Decrease y, which means it holds new y coordinate
                }else { // If this robot found another robot
                    fightResult = fight(world->getAt(x,y-1)); // Call fight function and get result
                    if(fightResult == 2) { // If second robot dies,it will stay it's current place
                        delete (world->grid[x][y-1]); // Delete second robot
                        world->setAt(x,y-1,world->getAt(x,y)); // Place this robot to new cell
                        world->setAt(x,y,NULL); // Set current cell to null
                        y--; // Decrease y, which means it holds new y coordinate
                    }else { // If first robot dies
                        a = x; // Get current robot's x coordinate
                        b = y; // Get current robot's y coordinate
                    }
                }
                lastMove = 1; // Set lastMove to 1, which means can't go right
            }
        }
        else if(dir == 1 && lastMove != 1) { // If direction is one and lastMove is not one
            if(y<WORLDSIZE-1) { // If (y+1) is inside the grid borders
                if(world->getAt(x,y+1) == NULL) { // If this coordinates' cell is null
                    world->setAt(x,y+1,world->getAt(x,y)); // Place this robot to new cell
                    world->setAt(x,y,NULL); // Set current cell to null
                    y++; // Increase y, which means it holds new y coordinate
                }else { // If this robot found another robot
                    fightResult = fight(world->getAt(x,y+1)); // Call fight function and get result
                    if(fightResult == 2) { // If second robot dies,it will stay it's current place
                        delete (world->grid[x][y+1]); // Delete second robot
                        world->setAt(x,y+1,world->getAt(x,y)); // Place this robot to new cell
                        world->setAt(x,y,NULL); // Set current cell to null
                        y++; // Increase y, which means it holds new y coordinate
                    }else { // If first robot dies
                        a = x; // Get current robot's x coordinate
                        b = y; // Get current robot's y coordinate
                    }
                }
                lastMove = 0; // Set lastMove to 0, which means can't go left
            }
        }
        else if(dir == 2 && lastMove != 2) { // If direction is two and lastMove is not two
            if(x>0) { // If (x-1) is inside the grid borders
                if(world->getAt(x-1,y) == NULL) { // If this coordinates' cell is null
                    world->setAt(x-1,y,world->getAt(x,y)); // Place this robot to new cell
                    world->setAt(x,y,NULL); // Set current cell to null
                    x--; // Decrease x, which means it holds new x coordinate
                }else { // If this robot found another robot
                    fightResult = fight(world->getAt(x-1,y)); // Call fight function and get result
                    if(fightResult == 2) { // If second robot dies,it will stay it's current place
                        delete (world->grid[x-1][y]); // Delete second robot
                        world->setAt(x-1,y,world->getAt(x,y)); // Place this robot to new cell
                        world->setAt(x,y,NULL); // Set current cell to null
                        x--; // Decrease x, which means it holds new x coordinate
                    }else { // If first robot dies
                        a = x; // Get current robot's x coordinate
                        b = y; // Get current robot's y coordinate
                    }
                }
                lastMove = 3; // Set lastMove to 3, which means can't go down
            }
        }
        else if(dir == 3 && lastMove != 3){ // If direction is three and lastMove is not three
            if(x<WORLDSIZE-1) { // If (x+1) is inside the grid borders
                if(world->getAt(x+1,y) == NULL) { // If this coordinates' cell is null
                    world->setAt(x+1,y,world->getAt(x,y)); // Place this robot to new cell
                    world->setAt(x,y,NULL); // Set current cell to null
                    x++; // Increase x, which means it holds new x coordinate
                }else { // If this robot found another robot
                    fightResult = fight(world->getAt(x+1,y)); // Call fight function and get result
                    if(fightResult == 2) { // If second robot dies,it will stay it's current place
                        delete (world->grid[x+1][y]); // Delete second robot
                        world->setAt(x+1,y,world->getAt(x,y)); // Place this robot to new cell
                        world->setAt(x,y,NULL); // Set current cell to null
                        x++; // Increase x, which means it holds new x coordinate
                    }else { // If first robot dies
                        a = x; // Get current robot's x coordinate
                        b = y; // Get current robot's y coordinate
                    }
                }
                lastMove = 2; // Set lastMove to 2, which means can't go up
            }
        }
    }
    return fightResult;
}