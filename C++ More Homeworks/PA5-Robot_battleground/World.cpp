#include "World.h"

World::World() {
    int i,j;
    // Set all grids to null
    for(i = 0; i < WORLDSIZE;i++) {
        for(j = 0;j < WORLDSIZE;j++) {
            grid[i][j] = NULL;
        }
    }
    totalRobots = 0;
}
World::~World() {
    int i,j;
    // Delete unempty grids
    for(i = 0; i < WORLDSIZE;i++) {
        for(j = 0;j < WORLDSIZE;j++) {
            if(grid[i][j] != NULL) delete (grid[i][j]);
        }
    }
}
void World::setTotalRobots(int newNum) {
    totalRobots = newNum;
}
Robot* World::getAt(int x, int y) {
    if((x>=0) && (x<WORLDSIZE) && (y>=0) && (y<WORLDSIZE)) // If x and y are inside the grid borders
        return grid[x][y]; // Return robot from this grid
    return NULL; // If x and y are not inside the grid borders return null
}
void World::setAt(int x,int y,Robot *rbt) {
    if((x>=0) && (x<WORLDSIZE) && (y>=0) && (y<WORLDSIZE)) { // If x and y are inside the grid borders
        grid[x][y] = rbt; // Set rbt to this grid
    }
}
void World::Display() {
    int i,j;
    cout << endl << endl;
    for(i = 0; i < WORLDSIZE;i++) {
        for(j = 0;j < WORLDSIZE;j++) {
            if(grid[i][j] == NULL)
                cout << ".";
            else if(grid[i][j]->getIntType() == OPTIMUS)
                cout << "O";
            else if(grid[i][j]->getIntType() == ROBOCOP)
                cout << "C";
            else if(grid[i][j]->getIntType() == ROOMBA) {
                cout << "R";
            }
            else cout << "B";
        }
        cout << endl;
    }
}

void World::SimulateOneStep() {
    int i,j;
    int whichOne;
    // Check the grids and set all robots' moved value to false
    for(i = 0; i < WORLDSIZE;i++) {
        for(j = 0;j < WORLDSIZE;j++) {
            if(grid[i][j] != NULL) grid[i][j]->moved = false;
        }
    }
    // Loop for all cell inside the grid
    for(i = 0; i < WORLDSIZE;i++) {
        for(j = 0;j < WORLDSIZE;j++) {
            if((grid[i][j] != NULL)) { // If grid is not null, means there is robot in there
                if(grid[i][j]->moved == false) { // If robot has not moved yet
                    grid[i][j]->moved = true; // Set moved value to true, To indicate this robot has moved
                    int x,y;
                    whichOne = grid[i][j]->move(x,y); // Call move function and get result
                    if(whichOne == 1) { // If first robot dies
                        delete (grid[x][y]);  // Delete robot's current cell according to x and y
                        grid[x][y] = NULL; // Set this grid cell to null
                    }
                    totalRobots--; // Decrease number of total robots
                    if(totalRobots == 1) { // If one robot left on the map
                        i = WORLDSIZE; // Set i to world size to finish the loop
                        j = WORLDSIZE; // Set j to world size to finish the loop
                    }
                }
            }
        }
    }
}
int World::getTotalRobots() {
    return totalRobots;
}
void World::increaseTotalOne() {
    ++totalRobots;
}