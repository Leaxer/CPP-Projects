#include <iostream>
#include <vector>
#include "tetromino.h"

using namespace std;

int main()
{
   vector<vector<char>> board(4,vector<char>(20,' '));//initialize board
   int num,currentColumn = 0;
   char type;
   vector<vector<int>> tempShapePos;
   cout<<"How many tetrominos"<<endl;
   do{
   cin>>num;
   if(num <= 0) cout<<"Please enter valid number"<<endl;
   }while(num <= 0);
   vector<Tetromino> tetromin;
   cout<<"What are the types?"<<endl;
   for(int i = 0;i < num;++i) {//Get tetro type and send enum as parameter
      do{
      cin>>type;
      if(type != 'I' && type != 'O' && type != 'T' && type != 'J' && type != 'L' && type != 'S' && type != 'Z') cout<<"Please enter valid characters"<<endl;
      }while(type != 'I' && type != 'O' && type != 'T' && type != 'J' && type != 'L' && type != 'S' && type != 'Z');
      if(type == 'I') tetromin.push_back(Tetromino(tetrominos::I));
      else if(type == 'O') tetromin.push_back(Tetromino(tetrominos::O));
      else if(type == 'T') tetromin.push_back(Tetromino(tetrominos::T));
      else if(type == 'J') tetromin.push_back(Tetromino(tetrominos::J));
      else if(type == 'L') tetromin.push_back(Tetromino(tetrominos::L));
      else if(type == 'S') tetromin.push_back(Tetromino(tetrominos::S));
      else if(type == 'Z') tetromin.push_back(Tetromino(tetrominos::Z));
   }
   for(int i = 0;i < num;++i){
      tetromin[i].Print();
   }

   //Trying canFit function for first two block
   cout<<"Controlling first two blocks at their first positions"<<endl;
   tempShapePos = tetromin[1].GetShapePos();
   if(!tetromin[0].canFit(tetromin.at(1),tempShapePos)) cout<<"They didn't fit without any holes";
   else cout<<"They fit"<<endl;
   cout<<endl;

   //Trying rotate function
   cout<<"Rotating second shape to try rotate function"<<endl;
   tetromin[1].Rotate('R');
   tetromin[1].Print();
   return 0;
}