#include <iostream>
#include <vector>
#include <ctime>
#include "tetromino.h"
#include "tetris.h"

using namespace std;

int main()
{
   int height,width,i = 0,randNum;
   bool finish = true;
   char type;
   vector<Tetromino> tetromin;
   vector<vector<int>> tempShapePos;
   vector<char> letters {'I','O','T','J','L','S','Z'};
   srand(time(0));
   cout<<"Please enter the size of board"<<endl;
   cout<<"Height:"<<endl;
   do{
      cin>>height;
      if(height <= 3) cout<<"Please enter valid number"<<endl;
   }while(height <= 3);
   cout<<"Width:"<<endl;
   do{
      cin>>width;
      if(width <= 3) cout<<"Please enter valid number"<<endl;
   }while(width <= 3);

   Tetris tetrisGame(width,height);
   cout<<"Enter the tetromino type: "<<endl;
      cin>>type;
   while(type != 'Q' && finish == true){ 
      while(type != 'I' && type != 'O' && type != 'T' && type != 'J' && type != 'L' && type != 'S' && type != 'Z' && type != 'Q' && type != 'R') {
         cout<<"Please enter valid characters"<<endl;
         cin>>type;
      }
      if(type == 'R') {
         randNum = rand() % 7;
         if(randNum == 0) type = 'I';
         else if(randNum == 1) type = 'O';
         else if(randNum == 2) type = 'T';
         else if(randNum == 3) type = 'J';
         else if(randNum == 4) type = 'L';
         else if(randNum == 5) type = 'S';
         else if(randNum == 6) type = 'Z';
      } 
      if(type == 'I') tetromin.push_back(Tetromino(tetrominos::I));
      else if(type == 'O') tetromin.push_back(Tetromino(tetrominos::O));
      else if(type == 'T') tetromin.push_back(Tetromino(tetrominos::T));
      else if(type == 'J') tetromin.push_back(Tetromino(tetrominos::J));
      else if(type == 'L') tetromin.push_back(Tetromino(tetrominos::L));
      else if(type == 'S') tetromin.push_back(Tetromino(tetrominos::S));
      else if(type == 'Z') tetromin.push_back(Tetromino(tetrominos::Z));
      finish = tetrisGame.Add(tetromin[i].GetShape(),i,tetromin[i].GetShapePos());
      if(finish == true){
         tetrisGame.Animate(i,tetromin[i].GetShapePos(),tetromin[i].GetShape());
         ++i;
         cin>>type;
      }
   }
   cout<<"Game Over";
   return 0;
}