#include <iostream>
#include <vector>
#include "tetromino.h"
#include "tetris.h"

using namespace std;

int main()
{
   Tetromino tetromin(tetrominos::O);
   Tetris tetrisGame(20,20);
   tetrisGame.Add(tetromin.GetShape(),0,tetromin.GetShapePos());
   tetrisGame.Animate(0,tetromin.GetShapePos(),tetromin.GetShape());
   return 0;
}