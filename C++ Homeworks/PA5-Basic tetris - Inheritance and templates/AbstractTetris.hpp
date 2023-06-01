#ifndef ABSTRACTTETRIS_H
#define ABSTRACTTETRIS_H

#include <iostream>
#include <unistd.h>
#include <limits>
#include <fstream>
#include <utility>

namespace TetrisSpace
{
    enum class tetrominos {I,O,T,J,L,S,Z}; //Create strong enum

    class AbstractTetris{
        public:
        class Tetromino {
            private:
                char shapeLetter;
                char **shape = NULL;
                int **shapePos = NULL;
            public:
                Tetromino(const tetrominos &s);//Constructor
                ~Tetromino();
                void Print();//Print the shape
                void Rotate(const char &rotation);//rotate the shape
                void fixShape();//set shape to left corner
                char** GetShape();
                int** GetShapePos();
                friend class TetrisVector;
                friend class TetrisArray1D;
                template <template <typename...>class T> friend class TetrisAdapter;
        };
        //Constructor to take the rectangular size of the Tetris board
        AbstractTetris(const int &width = 20,const int &height = 20);
        ~AbstractTetris();
        virtual void Draw() const = 0;//to draw the Tetris board.It will optionally start the drawing from the top
        virtual void LowerLevel() = 0;//lower one level the tetromino shape
        virtual void Animate(int isFirst, Tetromino *obj) = 0;//to animate the added tetromino dropping to the bottom of the board.
        AbstractTetris &operator +=(Tetromino *tetrisShape);//to add a Tetromino to the board.The new Tetromino will be added at the top row in the middle.
        virtual int moveTetromino(const char &direction, const int &count, int &moveTimeCount) = 0;//move tetromino to left or right
        /* The animation will be repetition of four steps:
        1. Draw the board with Tetromino at the top
        2. Ask the user rotation direction and rotation count
        3. Ask the user move direction and count
        4. Rotate and move the Tetromino
        5. Draw the board
        6. Sleep 50 miliseconds
        7. Lower the Tetromino one level and go to step 5 until it hits the bottom.*/
        virtual void SetCurrentPosesEmpty() = 0;
        virtual bool ControlAnimateFinish() const = 0;
        virtual void writeToFile(const std::string &fileName) = 0;
        void readFromFile(const std::string &fileName);
        std::pair<int,std::string> lastMove(const int &moves,const char &direction);
        int numberOfMoves() const{ return numOfMoves;}
        std::string getFileName(const std::string& inputFileName);
        bool finish = false;
        int downMovesSteps = 0;
        private:
        protected:
            int width,height,controlFirstDraw = 0,numOfRow,numOfMoves = 0;
            std::string fileName;
    };
    bool checkValid(const int& num);
}

#endif