#include <ctime>
#include <climits>
#include "TetrisVector.hpp"
#include "TetrisArray1D.hpp"
#include "TetrisAdapter.hpp"

using namespace TetrisSpace;

int main()
{
   int height,width,i = 0,randNum;
   char type;
   std::string fileName;
   srand(time(0));
   std::cout << "Please enter the size of board" << std::endl;
   std::cout << "Height:" << std::endl;
   std::cin >> height;
   while(height <= 3 || !checkValid(height))
   {
      std::cin >> height;
   }
   std::cout << "Width:" << std::endl;
   std::cin >> width;
   while(width <= 3 || !checkValid(width))
   {
      std::cin >> width;
   }

      std::cout << "-------------TETRIS VECTOR-------------" << std::endl;
      std::cout << "Enter the tetromino type: " << std::endl;
      std::cin >> type;
      std::cout << "\033[0H\033[2J";
      if(type != 'Q') {
        TetrisVector tetrisGame1(width,height);
        AbstractTetris::Tetromino *tetromin;
        while(type != 'I' && type != 'O' && type != 'T' && type != 'J' && type != 'L' && type != 'S' && type != 'Z' && type != 'Q' && type != 'R')
        {
            std::cout << "Please enter valid characters" << std::endl;
            std::cin >> type;
        }
        if(type == 'R')
        {
            randNum = rand() % 7;
            if(randNum == 0) type = 'I';
            else if(randNum == 1) type = 'O';
            else if(randNum == 2) type = 'T';
            else if(randNum == 3) type = 'J';
            else if(randNum == 4) type = 'L';
            else if(randNum == 5) type = 'S';
            else if(randNum == 6) type = 'Z';
        }
        if(type == 'I') tetromin = new AbstractTetris::Tetromino(tetrominos::I);
        else if(type == 'O') tetromin = new AbstractTetris::Tetromino(tetrominos::O);
        else if(type == 'T') tetromin = new AbstractTetris::Tetromino(tetrominos::T);
        else if(type == 'J') tetromin = new AbstractTetris::Tetromino(tetrominos::J);
        else if(type == 'L') tetromin = new AbstractTetris::Tetromino(tetrominos::L);
        else if(type == 'S') tetromin = new AbstractTetris::Tetromino(tetrominos::S);
        else if(type == 'Z') tetromin = new AbstractTetris::Tetromino(tetrominos::Z);
        tetrisGame1 += tetromin;
        std::cout << "\033[" << height + 1 << "A\033[0G\033[2K";
        tetrisGame1.Animate(i, tetromin);
        delete tetromin;
        std::cout << "\033[0H\033[2J";
        tetrisGame1.lastMove(tetrisGame1.downMovesSteps,'D');
        std::cout << "Total move: " << tetrisGame1.numberOfMoves() << std::endl;
        std::cout << "Enter file name to save" << std::endl;
        std::cin >> fileName;
        tetrisGame1.writeToFile(fileName);
        std::cout << "Enter file name to read" << std::endl;
        std::cin >> fileName;
        tetrisGame1.readFromFile(fileName);
      }
      std::cout <<  std::endl;
      std::cout << "-------------TETRIS ARRAY 1D-------------" << std::endl;
      std::cout << "Enter the tetromino type: " << std::endl;
      std::cin >> type;
      std::cout << "\033[0H\033[2J";
      if(type != 'Q') {
        TetrisArray1D tetrisGame2(width,height);
        AbstractTetris::Tetromino *tetromin;
        while(type != 'I' && type != 'O' && type != 'T' && type != 'J' && type != 'L' && type != 'S' && type != 'Z' && type != 'Q' && type != 'R')
        {
            std::cout << "Please enter valid characters" << std::endl;
            std::cin >> type;
        }
        if(type == 'R')
        {
            randNum = rand() % 7;
            if(randNum == 0) type = 'I';
            else if(randNum == 1) type = 'O';
            else if(randNum == 2) type = 'T';
            else if(randNum == 3) type = 'J';
            else if(randNum == 4) type = 'L';
            else if(randNum == 5) type = 'S';
            else if(randNum == 6) type = 'Z';
        }
        if(type == 'I') tetromin = new AbstractTetris::Tetromino(tetrominos::I);
        else if(type == 'O') tetromin = new AbstractTetris::Tetromino(tetrominos::O);
        else if(type == 'T') tetromin = new AbstractTetris::Tetromino(tetrominos::T);
        else if(type == 'J') tetromin = new AbstractTetris::Tetromino(tetrominos::J);
        else if(type == 'L') tetromin = new AbstractTetris::Tetromino(tetrominos::L);
        else if(type == 'S') tetromin = new AbstractTetris::Tetromino(tetrominos::S);
        else if(type == 'Z') tetromin = new AbstractTetris::Tetromino(tetrominos::Z);
        tetrisGame2 += tetromin;
        std::cout << "\033[" << height + 1 << "A\033[0G\033[2K";
        tetrisGame2.Animate(i, tetromin);
        delete tetromin;
        std::cout << "\033[0H\033[2J";
        tetrisGame2.lastMove(tetrisGame2.downMovesSteps,'D');
        std::cout << "Total move: " << tetrisGame2.numberOfMoves() << std::endl;
        std::cout << "Enter file name to save" << std::endl;
        std::cin >> fileName;
        tetrisGame2.writeToFile(fileName);
        std::cout << "Enter file name to read" << std::endl;
        std::cin >> fileName;
        tetrisGame2.readFromFile(fileName);
      }
      std::cout <<  std::endl;
      std::cout << "-------------TETRIS ADAPTER-------------" << std::endl;
      std::cout << "Enter the tetromino type: " << std::endl;
      std::cin >> type;
      std::cout << "\033[0H\033[2J";
      if(type != 'Q') {
        TetrisAdapter<std::deque> tetrisGame3(width,height);
        AbstractTetris::Tetromino *tetromin;
        while(type != 'I' && type != 'O' && type != 'T' && type != 'J' && type != 'L' && type != 'S' && type != 'Z' && type != 'Q' && type != 'R')
        {
            std::cout << "Please enter valid characters" << std::endl;
            std::cin >> type;
        }
        if(type == 'R')
        {
            randNum = rand() % 7;
            if(randNum == 0) type = 'I';
            else if(randNum == 1) type = 'O';
            else if(randNum == 2) type = 'T';
            else if(randNum == 3) type = 'J';
            else if(randNum == 4) type = 'L';
            else if(randNum == 5) type = 'S';
            else if(randNum == 6) type = 'Z';
        }
        if(type == 'I') tetromin = new AbstractTetris::Tetromino(tetrominos::I);
        else if(type == 'O') tetromin = new AbstractTetris::Tetromino(tetrominos::O);
        else if(type == 'T') tetromin = new AbstractTetris::Tetromino(tetrominos::T);
        else if(type == 'J') tetromin = new AbstractTetris::Tetromino(tetrominos::J);
        else if(type == 'L') tetromin = new AbstractTetris::Tetromino(tetrominos::L);
        else if(type == 'S') tetromin = new AbstractTetris::Tetromino(tetrominos::S);
        else if(type == 'Z') tetromin = new AbstractTetris::Tetromino(tetrominos::Z);
        tetrisGame3 += tetromin;
        std::cout << "\033[" << height + 1 << "A\033[0G\033[2K";
        tetrisGame3.Animate(i, tetromin);
        delete tetromin;
        std::cout << "\033[0H\033[2J";
        tetrisGame3.lastMove(tetrisGame3.downMovesSteps,'D');
        std::cout << "Total move: " << tetrisGame3.numberOfMoves() << std::endl;
        std::cout << "Enter file name to save" << std::endl;
        std::cin >> fileName;
        tetrisGame3.writeToFile(fileName);
        std::cout << "Enter file name to read" << std::endl;
        std::cin >> fileName;
        tetrisGame3.readFromFile(fileName);
      }
    std::cout << "Game Over";
    std::cout << "Enter any type to continue: ";
    std::cin.clear(); std::cin.ignore(INT_MAX,'\n'); 
    std::cin.ignore();
   return 0;
}