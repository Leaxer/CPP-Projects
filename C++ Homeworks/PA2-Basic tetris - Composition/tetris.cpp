#include "tetris.h"
#include "tetromino.h"
#include <unistd.h>

Tetris::Tetris(const int &width,const int &height) : width(width), height(height){//Take board size and set the board
    for(int i = 0;i <= height;++i){
            board.push_back(vector<char>(width + 2,' '));
    }
    for(int i = 0;i < height;++i){
        board[i][0] = '#';
        board[i][width + 1] = '#';
    }
    for(int i = 0;i <= width + 1;++i){
        board[height][i] = '#';
    }
}

bool Tetris::Add(const vector<vector<char>> &shape,const int &isFirst,const vector<vector<int>> &positions){
    controlFirstDraw = 0;
    numOfRow = 0;
    for(int i = 0;i < 4;++i){//Find how many row spaces does shape have
        if(shape[i][0] == ' ' && shape[i][1] == ' ' && shape[i][2] == ' ' && shape[i][3] == ' ') ++numOfRow;
    }
    for(int i = 0;i < 4;++i){//If first block are not empty return false
        if(board[positions[i][0] - numOfRow][positions[i][1] + width/2 - 1] != ' ') return false;
    }
    if(isFirst != 0){//Delete elements of currentposes
        for(int i = 0;i < 4;++i){
            currentPoses.pop_back();
        }
    }
    for(int i = 0;i < 4 - numOfRow;++i){//Set the shape to board
        for(int j = 0;j < 4;++j){
            board[i][j + (width/2 - 1)] = shape[i + numOfRow][j];
        }
    }
    for(int i = 0;i < 4;++i){//update currentPoses
        for(int j = 0;j < 4;++j){
            if(shape[i][j] != ' '){
                currentPosOne[0] = i - numOfRow;
                currentPosOne[1] = j + (width/2 - 1);
                currentPoses.push_back(currentPosOne);
            }
        }
    }
    return true;
}

void Tetris::Fit(const vector<vector<int>> &pos,const vector<vector<char>> &shape){
    int i,j = 1,check = 1,row = 0;
    do{//The loop until the block find empty space
        if(j == width + 1) {
            j = 1;
            ++row;
        }
        i = 0;
        check = 1;
        while(i < 4){
            if(board[height + pos[i][0] - 3 - row][pos[i][1] + j] != ' '){//If the places where we want to put the block are not empty, it checks the column again by shifting it by 1.
                if((height + pos[i][0] - 3 - row) == (pos[i][0] - numOfRow) && (pos[i][1] + j) == (pos[i][1] + (width/2) - 1)) ;//Check if the cells are first cells or not
                else{
                    check = 0;
                    ++j;
                    break;
                }
            }
            ++i;
        }
    }while(check == 0);

    char temp = board[currentPoses[0][0]][currentPoses[0][1]];
    for(int i = 3;i > -1;--i){
        board[currentPoses[i][0]][currentPoses[i][1]] = ' ';
    }
    for(int i = 3;i > -1;--i){
        board[currentPoses[i][0]][pos[i][1] + j] = temp;
    }
    for(int i = 0;i < 4;++i){
        currentPoses[i][1] = pos[i][1] + j;
    }
}

void Tetris::Draw(int &isFirst){
    if(isFirst == 0) {//If it's first shape of my board
        --isFirst;
    }else {//Set cursor on console to redraw the board
        if(isFirst == -1) cout << "\033[" << height + 1 << "F";
        else if(isFirst != -1 && controlFirstDraw != 0) {
            cout << "\033[" << height + 1 << "F";
        }
        else if(isFirst != -1 && controlFirstDraw == 0) {
            cout << "\033[" << height + 2 << "F";
            controlFirstDraw = -1;
        }
    }
    for(int i = 0;i <= height;++i){//Print the board
        for(int j = 0;j <= width + 1;++j){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

void Tetris::LowerLevel(){//Get char of shape as temp. Set current positions to ' ' and set new positions to temp character.
    char temp = board[currentPoses[0][0]][currentPoses[0][1]];
    for(int i = 3;i > -1;--i){
        board[currentPoses[i][0]][currentPoses[i][1]] = ' ';
    }
    for(int i = 3;i > -1;--i){
        board[currentPoses[i][0] + 1][currentPoses[i][1]] = temp;
    }
    for(int i = 0;i < 4;++i){
        ++currentPoses[i][0];//increase one of every positions of shape's X
    }
}

void Tetris::Animate(int isFirst,const vector<vector<int>> &pos,const vector<vector<char>> &shape){
    Draw(isFirst);
    Fit(pos,shape);
    Draw(isFirst);
    //Loop until the hit the bottom
    while(board[currentPoses[3][0] + 1][currentPoses[3][1]] == ' ' && 
        (board[currentPoses[2][0] + 1][currentPoses[2][1]] == ' ' || currentPoses[2][1] == currentPoses[3][1])
        && (board[currentPoses[1][0] + 1][currentPoses[1][1]] == ' ' || currentPoses[1][1] == currentPoses[2][1] || currentPoses[1][1] == currentPoses[3][1])
        && (board[currentPoses[0][0] + 1][currentPoses[0][1]] == ' ' || currentPoses[0][1] == currentPoses[2][1] || currentPoses[0][1] == currentPoses[3][1] || currentPoses[0][1] == currentPoses[1][1])){
        LowerLevel();
        Draw(isFirst);
        usleep(50000);
    }
}