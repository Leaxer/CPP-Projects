#include <ctime>
#include "TetrisVector.hpp"
#include "TetrisArray1D.hpp"
#include "TetrisAdapter.hpp"

using namespace TetrisSpace;

int main()
{
   std::cout << "\033[0H\033[2J";
   int height,width,i = 0,randNum;
   char type,whichMode,typeWriteMode;
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
   
   std::cout << "Please enter V for vector, 1 for array1D and A for Adapter" << std::endl;
   std::cin >> whichMode;
   while(whichMode != 'V' && whichMode != '1' && whichMode != 'A')
   {
      std::cout << "Please enter valid character:" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin >> whichMode;
   }
   if(whichMode == 'V') {
      TetrisVector tetrisGame(width,height);
      std::cout << "Enter the tetromino type: " << std::endl;
      std::cin >> type;
      std::cout << "\033[0H\033[2J";
      while(type != 'Q' && tetrisGame.finish == false)
      {
         AbstractTetris::Tetromino *tetromin;
         while(type != 'I' && type != 'O' && type != 'T' && type != 'J' && type != 'L' && type != 'S' && type != 'Z' && type != 'Q' && type != 'R')
         {
            std::cout << "Please enter valid characters" << std::endl;
            std::cin >> type;
         }
         if(type == 'Q') break;
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
         tetrisGame += tetromin;
         if(tetrisGame.finish == false) 
         {
            std::cout << "\033[" << height + 1 << "A\033[0G\033[2K";
            tetrisGame.Animate(i, tetromin);
            std::cout << "\033[J";
            std::cout << "Enter the tetromino type: " << std::endl;
            std::cin >> type;
            delete tetromin;
         }
      }
      std::cout << "0 for save current game image, 1 for reading old game from folder, any type for quit" << std::endl;
      std::cin >> typeWriteMode;
      if(typeWriteMode == '0') {
         std::cout << "Enter file name to save" << std::endl;
         std::cin >> fileName;
         tetrisGame.writeToFile(fileName);
      }else if(typeWriteMode == '1') {
         std::cout << "Enter file name to read" << std::endl;
         std::cin >> fileName;
         tetrisGame.readFromFile(fileName);
      }
   }else if(whichMode == '1') {
      TetrisArray1D tetrisGame(width,height);
      std::cout << "Enter the tetromino type: " << std::endl;
      std::cin >> type;
      std::cout << "\033[0H\033[2J";
      while(type != 'Q' && tetrisGame.finish == false)
      {
         AbstractTetris::Tetromino *tetromin;
         while(type != 'I' && type != 'O' && type != 'T' && type != 'J' && type != 'L' && type != 'S' && type != 'Z' && type != 'Q' && type != 'R')
         {
            std::cout << "Please enter valid characters" << std::endl;
            std::cin >> type;
         }
         if(type == 'Q') break;
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
         tetrisGame += tetromin;
         if(tetrisGame.finish == false) 
         {
            std::cout << "\033[" << height + 1 << "A\033[0G\033[2K";
            tetrisGame.Animate(i, tetromin);
            std::cout << "\033[J";
            std::cout << "Enter the tetromino type: " << std::endl;
            std::cin >> type;
            delete tetromin;
         }
      }
      std::cout << "0 for save current game image, 1 for reading old game from folder, any type for quit" << std::endl;
      std::cin >> typeWriteMode;
      if(typeWriteMode == '0') {
         std::cout << "Enter file name to save" << std::endl;
         std::cin >> fileName;
         tetrisGame.writeToFile(fileName);
      }else if(typeWriteMode == '1') {
         std::cout << "Enter file name to read" << std::endl;
         std::cin >> fileName;
         tetrisGame.readFromFile(fileName);
      }
   }else if(whichMode == 'A') {
      TetrisAdapter<std::deque> tetrisGame(width,height);
      std::cout << "Enter the tetromino type: " << std::endl;
      std::cin >> type;
      std::cout << "\033[0H\033[2J";
      while(type != 'Q' && tetrisGame.finish == false)
      {
         AbstractTetris::Tetromino *tetromin;
         while(type != 'I' && type != 'O' && type != 'T' && type != 'J' && type != 'L' && type != 'S' && type != 'Z' && type != 'Q' && type != 'R')
         {
            std::cout << "Please enter valid characters" << std::endl;
            std::cin >> type;
         }
         if(type == 'Q') break;
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
         tetrisGame += tetromin;
         if(tetrisGame.finish == false) 
         {
            std::cout << "\033[" << height + 1 << "A\033[0G\033[2K";
            tetrisGame.Animate(i, tetromin);
            std::cout << "\033[J";
            std::cout << "Enter the tetromino type: " << std::endl;
            std::cin >> type;
            delete tetromin;
         }
      }
      std::cout << "0 for save current game image, 1 for reading old game from folder, any type for quit" << std::endl;
      std::cin >> typeWriteMode;
      if(typeWriteMode == '0') {
         std::cout << "Enter file name to save" << std::endl;
         std::cin >> fileName;
         tetrisGame.writeToFile(fileName);
      }else if(typeWriteMode == '1') {
         std::cout << "Enter file name to read" << std::endl;
         std::cin >> fileName;
         tetrisGame.readFromFile(fileName);
      }
   }
   std::cout << "Game Over";
   return 0;
}