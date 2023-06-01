#ifndef TETROMINO_H
#define TETROMINO_H

#include <iostream>
#include <vector>

using namespace std;

enum class tetrominos {I,O,T,J,L,S,Z}; //Create strong enum

class Tetromino {
   private:
      char shapeLetter;
      vector<int> onePos{-1,-1};
      vector<vector<char>> shape;
      vector<vector<int>> shapePos;
   public:
   Tetromino(const tetrominos &s);//Constructor
   void Print();//Print the shape
   void Rotate(const char &rotation);//rotate the shape
   void fixShape();//set shape to left corner
   bool canFit(Tetromino &other,const vector<vector<int>> &pos);//check if the blocks fit each other
   vector<vector<char>> GetShape();
   vector<vector<int>> GetShapePos();
};

#endif