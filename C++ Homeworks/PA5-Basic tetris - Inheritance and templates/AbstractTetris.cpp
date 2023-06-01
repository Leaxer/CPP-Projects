#include "AbstractTetris.hpp"

namespace TetrisSpace
{
    AbstractTetris::AbstractTetris(const int &width,const int &height) : width(width), height(height){//Take board size and set the board

    }
    void AbstractTetris::readFromFile(const std::string &fileName) {//get filename and add .txt to find game folder
        std::string fileFormat = fileName + ".txt";
        std::string line;
        std::ifstream readFile;
        readFile.open(fileFormat);
        if(!readFile.is_open()) {
            std::cout << "File couldn't open" << std::endl;
        }else {
            while(getline(readFile, line))
            {
                std::cout << line;
                std::cout << std::endl;
            }
            readFile.close();
        }
    }
    std::string AbstractTetris::getFileName(const std::string& inputFileName) {
      fileName = inputFileName + ".txt";
      return fileName;
    }
    std::pair<int,std::string> AbstractTetris::lastMove(const int &moves,const char &direction) {
      std::string s_direction;
      try//control the direction
      {
         if(direction == 'R') {
             s_direction = "right";
         }else if(direction == 'L') {
             s_direction = "left";
         }else if(direction == 'D') {
             s_direction = "down";
         }else {
             throw;
         }
      }
      catch (std::exception ex)
      {
         std::cout << "There is no last move";
      }
      std::cout << "Last move is " << moves << " steps" << " to the " << s_direction << std::endl;
      return std::make_pair(moves,s_direction);
    }
    AbstractTetris::~AbstractTetris()
    {
    }

    // Tetromino constructor
   AbstractTetris::Tetromino::Tetromino(const tetrominos &s)
   {
        try
        {
            shapePos = new int*[4];
        }
        catch (std::bad_alloc)
        {
            std::cout << "Ran out of memory!";
            exit(1);
        }
         for(int i = 0;i < 4;++i)
            shapePos[i] = new int[2];
         try
        {
            shape = new char*[4];
        }
        catch (std::bad_alloc)
        {
            std::cout << "Ran out of memory!";
            exit(1);
        }
         for(int i = 0;i < 4;++i)
            shape[i] = new char[4];

         for(int i = 0;i < 4;++i)
               for(int j = 0;j < 4;++j)
                  shape[i][j] = ' ';
         if(s == tetrominos::I) {//control the enum type and set shape vector's shape
            for(int i = 0;i < 4;++i)
               shape[3][i] = 'I';
            shapeLetter = 'I';
         }
         else if(s == tetrominos::O) {
            for(int i = 2;i < 4;++i)
               for(int j = 0;j < 2;++j)
                  shape[i][j] = 'O';
            shapeLetter = 'O';
         }
         else if(s == tetrominos::T) {
            shape[2][0] = 'T';
            shape[2][1] = 'T';
            shape[2][2] = 'T';
            shape[3][1] = 'T';
            shapeLetter = 'T';
         }
         else if(s == tetrominos::J) {
            shape[1][1] = 'J';
            shape[2][1] = 'J';
            shape[3][1] = 'J';
            shape[3][0] = 'J';
            shapeLetter = 'J';   
         }
         else if(s == tetrominos::L) {
            shape[1][0] = 'L';
            shape[2][0] = 'L';
            shape[3][0] = 'L';
            shape[3][1] = 'L';
            shapeLetter = 'L';
         }
         else if(s == tetrominos::S) {
            shape[2][1] = 'S';
            shape[2][2] = 'S';
            shape[3][0] = 'S';
            shape[3][1] = 'S';
            shapeLetter = 'S';
         }
         else if(s == tetrominos::Z) {
            shape[2][0] = 'Z';
            shape[2][1] = 'Z';
            shape[3][1] = 'Z';
            shape[3][2] = 'Z';
            shapeLetter = 'Z';
         }
         int *temp = new int;
         *temp = 0;
         for(int i = 0;i < 4;++i){//Get positions' of shape
            for(int j = 0;j < 4;++j){
               if(shape[i][j] != ' ') {
                  shapePos[*temp][0] = i;
                  shapePos[*temp][1] = j;
                  ++(*temp);
               }
            }
         }
         delete temp;
   }

   void AbstractTetris::Tetromino::Print() {
      for(int i = 0;i < 4;++i){
         for(int j = 0;j < 4;++j){
         std::cout << shape[i][j];
      }
      std::cout << std::endl;
      }
   }

   void AbstractTetris::Tetromino::Rotate(const char &rotation){
      if(rotation == 'R'){//Rotate the shape with swap tactic
         for(int i = 0;i < 4;++i){
            for(int j = 0;j < i;++j) {
               std::swap(shape[i][j],shape[j][i]);
            }
         }
         for(int i = 0;i < 4;i++) {
            std::swap(shape[i][0],shape[i][3]);
            std::swap(shape[i][1],shape[i][2]);
         }
      }
      if(rotation == 'L') {
         for(int i = 0;i < 4;++i){
            for(int j = 0;j < i;++j) {
               std::swap(shape[i][j],shape[j][i]);
            }
         }
         for(int i = 0;i < 4;++i) {
            std::swap(shape[0][i],shape[3][i]);
            std::swap(shape[1][i],shape[2][i]);
         }
      }
      fixShape();
   }

   void AbstractTetris::Tetromino::fixShape(){
         auto *temp = new char[4];//put the shape to left corner after rotate
      while(shape[3][0] == ' ' && shape[3][1] == ' ' && shape[3][2] == ' ' && shape[3][3] == ' '){
         temp[0] = shape[3][0];//store last row of the shape
         temp[1] = shape[3][1];
         temp[2] = shape[3][2];
         temp[3] = shape[3][3];
         for(int i = 3;i > 0;--i){//swap the vector's chars
            for(int j = 0;j < 4;++j){
               shape[i][j] = shape[i - 1][j];
            }
         }
         
         shape[0][0] = temp[0];//put last row to first row
         shape[0][1] = temp[1];
         shape[0][2] = temp[2];
         shape[0][3] = temp[3];
      }
      while(shape[1][0] == ' ' && shape[2][0] == ' ' && shape[3][0] == ' ' && shape[0][0] == ' '){//same process but this time fix columns
         temp[0] = shape[0][0];
         temp[1] = shape[1][0];
         temp[2] = shape[2][0];
         temp[3] = shape[3][0];
         for(int i = 0;i < 3;++i){
            for(int j = 0;j < 4;++j){
               shape[j][i] = shape[j][i + 1];
            }
         }
         
         shape[0][3] = temp[0];
         shape[1][3] = temp[1];
         shape[2][3] = temp[2];
         shape[3][3] = temp[3];
      }
      int a = 0;
      for(int i = 0;i < 4;++i){//Get positions' of shape
         for(int j = 0;j < 4;++j){
            if(shape[i][j] != ' ') {
               shapePos[a][0] = i;
               shapePos[a][1] = j;
               ++a;
            }
         }
      }
      delete[] temp;
   }


   char** AbstractTetris::Tetromino::GetShape(){
      return shape;
   }

   int** AbstractTetris::Tetromino::GetShapePos(){
      return shapePos;
   }

   AbstractTetris::Tetromino::~Tetromino(){
      for(int i = 0;i < 4;++i)
      {
         delete[] shape[i];
         delete[] shapePos[i];
      }
      delete[] shape;
      delete[] shapePos;
   }
   bool checkValid(const int& num){
      if(!std::cin.good()) {
         std::cout << "Please enter valid number" << std::endl;
         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         return false;
      }else { return true;}
   }
}