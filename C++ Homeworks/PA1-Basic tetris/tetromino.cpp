#include "tetromino.h"

// Tetromino constructor
Tetromino::Tetromino(const tetrominos &s)
{
    if(s == tetrominos::I) {//control the enum type and set shape vector's shape
         shape = { {' ',' ',' ',' '},
                   {' ',' ',' ',' '},
                   {' ',' ',' ',' '},
                   {'I','I','I','I'} };
         shapeLetter = 'I';
      }
      else if(s == tetrominos::O) {
         shape = { {' ',' ',' ',' '},
                   {' ',' ',' ',' '},
                   {'O','O',' ',' '},
                   {'O','O',' ',' '} };
         shapeLetter = 'O';
      }
      else if(s == tetrominos::T) {
         shape = { {' ',' ',' ',' '},
                   {' ',' ',' ',' '},
                   {'T','T','T',' '},
                   {' ','T',' ',' '} };
         shapeLetter = 'T';
      }
      else if(s == tetrominos::J) {
         shape = { {' ',' ',' ',' '},
                   {' ','J',' ',' '},
                   {' ','J',' ',' '},
                   {'J','J',' ',' '} };
         shapeLetter = 'J';   
      }
      else if(s == tetrominos::L) {
         shape = { {' ',' ',' ',' '},
                   {'L',' ',' ',' '},
                   {'L',' ',' ',' '},
                   {'L','L',' ',' '} };
         shapeLetter = 'L';
      }
      else if(s == tetrominos::S) {
         shape = { {' ',' ',' ',' '},
                   {' ',' ',' ',' '},
                   {' ','S','S',' '},
                   {'S','S',' ',' '} };
         shapeLetter = 'S';
      }
      else if(s == tetrominos::Z) {
         shape = { {' ',' ',' ',' '},
                   {' ',' ',' ',' '},
                   {'Z','Z',' ',' '},
                   {' ','Z','Z',' '} };
         shapeLetter = 'Z';
      }
      for(int i = 0;i < 4;++i){//Get positions' of shape
         for(int j = 0;j < 4;++j){
            if(shape[i][j] != ' ') {
               onePos.at(0) = i;
               onePos.at(1) = j;
            shapePos.push_back(onePos);
            }
         }
      }
}

void Tetromino::Print() {
    for(int i = 0;i < 4;++i){
        for(int j = 0;j < 4;++j){
        cout<<shape[i][j];
     }
     cout<<endl;
    }
}

void Tetromino::Rotate(const char &rotation){
   if(rotation == 'R'){//Rotate the shape with swap tactic
      for(int i = 0;i < 4;++i){
         for(int j = 0;j < i;++j) {
            swap(shape[i][j],shape[j][i]);
         }
      }
      for(int i = 0;i < 4;i++) {
         swap(shape[i][0],shape[i][3]);
         swap(shape[i][1],shape[i][2]);
      }
   }
   if(rotation == 'L') {
      for(int i = 0;i < 4;++i){
         for(int j = 0;j < i;++j) {
            swap(shape[i][j],shape[j][i]);
         }
      }
      for(int i = 0;i < 4;++i) {
         swap(shape[0][i],shape[3][i]);
         swap(shape[1][i],shape[2][i]);
      }
   }
   fixShape();
}

void Tetromino::fixShape(){
   while(shape[3][0] == ' ' && shape[3][1] == ' ' && shape[3][2] == ' ' && shape[3][3] == ' '){
      vector<char> temp;//put the shape to left corner after rotate
      temp.push_back(shape[3][0]);//store last row of the shape
      temp.push_back(shape[3][1]);
      temp.push_back(shape[3][2]);
      temp.push_back(shape[3][3]);
      for(int i = 3;i > 0;--i){//swap the vector's chars
         for(int j = 0;j < 4;++j){
             shape[i][j] = shape[i - 1][j];
         }
      }
        
      shape[0][0] = temp.at(0);//put last row to first row
      shape[0][1] = temp.at(1);
      shape[0][2] = temp.at(2);
      shape[0][3] = temp.at(3);
   }
   while(shape[1][0] == ' ' && shape[2][0] == ' ' && shape[3][0] == ' ' && shape[0][0] == ' '){//same process but this time fix columns
      vector<char> temp;
      temp.push_back(shape[0][0]);
      temp.push_back(shape[1][0]);
      temp.push_back(shape[2][0]);
      temp.push_back(shape[3][0]);
      for(int i = 0;i < 3;++i){
         for(int j = 0;j < 4;++j){
             shape[j][i] = shape[j][i + 1];
         }
      }
        
      shape[0][3] = temp.at(0);
      shape[1][3] = temp.at(1);
      shape[2][3] = temp.at(2);
      shape[3][3] = temp.at(3);
   }  
}

bool Tetromino::canFit(Tetromino &other,const vector<vector<int>> &pos){
      vector<vector<char>> board(4,vector<char>(8,' '));//temp board
      vector<vector<char>> tempShape;
      tempShape = other.GetShape();
      int check = 1;
      int i = 0;
      int j = 0;
      while(i < shapePos.size()){//Put the first block to temp board
         board[shapePos[i][0]][shapePos[i][1]] = shape[shapePos[i][0]][shapePos[i][1]];
         ++i;
      }
      do{//The loop until the block find empty space
         i = 0;
         check = 1;
         while(i < 4){
            if(board[pos[i][0]][pos[i][1] + j] != ' '){//If the places where we want to put the block are not empty, it checks the column again by shifting it by 1.
               check = 0;
               ++j;
               break;
            }
            ++i;
         }
      }while(check == 0);
      i = 0;
      while(i < 4){//put second block to temp board
         board[pos[i][0]][pos[i][1] + j] = tempShape[pos[i][0]][pos[i][1]];
         ++i;
      }

      for(int i = 0;i < 4;++i){
        for(int j = 0;j < 8;++j){
        cout<<board[i][j];
      }
      cout<<endl;
      }
      for(i = j - 1;i < pos[i][1] + j;++i){ //controls if they fit without holes or not. If they don't returns false
         if(board[3][i] == ' ') return false;
      }
      return true;
}

vector<vector<char>> Tetromino::GetShape(){
   return shape;
}

vector<vector<int>> Tetromino::GetShapePos(){
   return shapePos;
}