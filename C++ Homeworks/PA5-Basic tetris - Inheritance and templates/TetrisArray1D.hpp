#ifndef TETRISARRAY1D_HPP
#define TETRISARRAY1D_HPP

#include <limits>
#include <vector>
#include "AbstractTetris.hpp"

namespace TetrisSpace
{
   class TetrisArray1D : public AbstractTetris{
        private:
            char *board;
            std::vector<int> currentPosOne{-1,-1};
            std::vector<std::vector<int>> currentPoses;
        public:
        TetrisArray1D();
        //Constructor to take the rectangular size of the Tetris board
        TetrisArray1D(const int &width = 20,const int &height = 20);
        ~TetrisArray1D();
        void Draw() const;//to draw the Tetris board.It will optionally start the drawing from the top
        void LowerLevel();//lower one level the tetromino shape
        void Animate(int isFirst, AbstractTetris::Tetromino *obj);//to animate the added tetromino dropping to the bottom of the board.
        void SetCurrentPosesEmpty();
        bool ControlAnimateFinish() const;
        /* The animation will be repetition of four steps:
        1. Draw the board with Tetromino at the top
        2. Ask the user rotation direction and rotation count
        3. Ask the user move direction and count
        4. Rotate and move the Tetromino
        5. Draw the board
        6. Sleep 50 miliseconds
        7. Lower the Tetromino one level and go to step 5 until it hits the bottom.*/
        TetrisArray1D &operator +=(AbstractTetris::Tetromino *tetrisShape);//to add a Tetromino to the board.The new Tetromino will be added at the top row in the middle.
        int moveTetromino(const char &direction, const int &count, int &moveTimeCount);//move tetromino to left or right
        void writeToFile(const std::string &fileName);
    };
}
#endif