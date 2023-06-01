#ifndef TETRIS_H
#define TETRIS_H

#include <iostream>
#include <vector>
#include "tetromino.h"

using namespace std;

class Tetris{
    private:
        int width,height,controlFirstDraw = 0,numOfRow;
        vector<vector<char>> board;
        vector<int> currentPosOne{-1,-1};
        vector<vector<int>> currentPoses;
    public:
    //Constructor to take the rectangular size of the Tetris board
    Tetris(const int &width,const int &height);
    bool Add(const vector<vector<char>> &shape,const int &isFirst,const vector<vector<int>> &positions);//to add a Tetromino to the board.The new Tetromino will be added at the top row in the middle.
    void Fit(const vector<vector<int>> &pos,const vector<vector<char>> &shape);//to rotate and move the added Tetromino so that when it is dropped to the bottom it will produce the best fit.
    void Draw(int &isFirst);//to draw the Tetris board.It will optionally start the drawing from the top
    void LowerLevel();//lower one level the tetromino shape
    void Animate(int isFirst,const vector<vector<int>> &pos,const vector<vector<char>> &shape);//to animate the added tetromino dropping to the bottom of the board.
    /*The animation will be repetition of four steps:
    1. Draw the board with Tetromino at the top
    2. Rotate and move the Tetromino to its optimal position at the top
    3. Draw the board again
    4. Sleep 50 milliseconds
    5. Lower the Tetromino one level and go to step 3 until it hits the bottom.*/
};

#endif