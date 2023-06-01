#include "TetrisVector.hpp"

namespace TetrisSpace
{
   TetrisVector::TetrisVector() : AbstractTetris(){
    }
   TetrisVector::TetrisVector(const int &width,const int &height) : AbstractTetris(){//Take board size and set the board
        this->width = width;
        this->height = height;
        for(int i = 0;i <= height;++i){
            board.push_back(std::vector<char>(width + 2,' '));
        }
        for(int i = 0;i < height;++i){
            board[i][0] = '#';
            board[i][width + 1] = '#';
        }
        for(int i = 0;i <= width + 1;++i){
            board[height][i] = '#';
        }

        for(int i = 0;i < 4;++i)
        {
            currentPoses.push_back(std::vector<int>(2,-1));
        }
    }
    void TetrisVector::Draw() const{
        std::cout << "\033[0H";
        for(int i = 0;i <= height;++i)//Print the board
        {
            for(int j = 0;j <= width + 1;++j)
            {
                std::cout<<board[i][j];
            }
            std::cout<<std::endl;
        }
    }
    void TetrisVector::LowerLevel(){//Get char of shape as temp. Set current positions to ' ' and set new positions to temp character.
        auto temp = board[currentPoses[0][0]][currentPoses[0][1]];
        for(int i = 3;i > -1;--i)
            board[currentPoses[i][0]][currentPoses[i][1]] = ' ';
        for(int i = 3;i > -1;--i)
            board[currentPoses[i][0] + 1][currentPoses[i][1]] = temp;
        for(int i = 0;i < 4;++i)
            ++currentPoses[i][0];//increase one of every positions of shape's X
    }

    void TetrisVector::Animate(int isFirst, AbstractTetris::Tetromino *obj) {
        char direction;
        int count,moveTimeCount = 0,check = 1;
        Draw();
        SetCurrentPosesEmpty();
        std::cout << "Type 'R' to rotate right or 'L' to rotate left:" << std::endl;
        std::cout << "\033[J";
        std::cin >> direction;
        while(direction != 'R' && direction != 'L')
        {
            std::cout << "Please enter 'R' or 'L'" << std::endl;
            std::cin >> direction;
        }
        std::cout << "Enter how many times will tetromino rotate:" << std::endl;
        std::cout << "\033[J";
        std::cin >> count;
        while(count < 0 || !checkValid(count))
        {
            std::cin >> count;
        }
        //Rotate and add to board
        for(int i = 0;i < count;++i)
            obj->Rotate(direction);
        *this += obj;
        numOfMoves += count;
        downMovesSteps -= count;
        Draw();
        std::cout << "\033[J";
        std::cout << "Type 'R' to move right or 'L' to move left:" << std::endl;
        std::cout << "\033[J";
        std::cin >> direction;
        while(direction != 'R' && direction != 'L')
        {
            std::cout << "Please enter 'R' or 'L'" << std::endl;
            std::cin >> direction;
        }
        std::cout << "\033[J";
        std::cout << "Enter how many times will tetromino move:" << std::endl;
        std::cout << "\033[J";
        std::cin >> count;
        while(count < 0 || !checkValid(count))
        {
            std::cin >> count;
        }
        //While until it can move right,left or stay on same positions
        do{
            check = moveTetromino(direction, count, moveTimeCount);
            while(check == -1) {
                std::cout << "You can't move there. Please enter valid number: " << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> count;
                while(count < 0 || !checkValid(count))
                {
                    std::cin >> count;
                }
                check = moveTetromino(direction, count, moveTimeCount);
            }
            Draw();
            usleep(50000);
        }while(check == 1);
        numOfMoves += count;
        downMovesSteps -= count;
        //Loop until the hit the bottom
        while(ControlAnimateFinish())
        {
            LowerLevel();
            Draw();
            ++numOfMoves;
            usleep(50000);
        }
        downMovesSteps += numOfMoves;
    }

    TetrisVector &TetrisVector::operator +=(AbstractTetris::Tetromino *tetrisShape)
    {
        int *temp = new int;
        *temp = 0;
        controlFirstDraw = 0;
        numOfRow = 0;

        for(int i = 0;i < 4;++i)//Find how many row spaces does shape have
        {
            if(tetrisShape->shape[i][0] == ' ' && tetrisShape->shape[i][1] == ' ' && tetrisShape->shape[i][2] == ' ' && tetrisShape->shape[i][3] == ' ') ++numOfRow;
        }
        for(int i = 0;i < 4;++i)//If first block are not empty return false
        {
            if(board[tetrisShape->shapePos[i][0] - numOfRow][tetrisShape->shapePos[i][1] + width/2 - 1] != ' ') {
                finish = true;
                std::cout << "Game Over" << std::endl;
                exit(0);
            }
        }
        for(int i = 0;i < 4 - numOfRow;++i)//Set the shape to board
        {
            for(int j = 0;j < 4;++j)
                if(tetrisShape->shape[i + numOfRow][j] != ' ')
                {
                    board[i][j + (width/2 - 1)] = tetrisShape->shape[i + numOfRow][j];
                }
        }
        for(int i = 0;i < 4;++i)//update currentPoses
        {
            for(int j = 0;j < 4;++j)
            {
                if(tetrisShape->shape[i][j] != ' ')
                {
                    currentPoses[*temp][0] = i - numOfRow;
                    currentPoses[*temp][1] = j + (width/2 - 1);
                    ++(*temp);
                }
            }
        }
        delete temp;
        return *this;
    }

    int TetrisVector::moveTetromino(const char &direction, const int &count, int &moveTimeCount) {
        char temp;
        if(count == 0) return -2;//If it's zero return -2 and do nothing
        if(moveTimeCount == 0) //At first time control if it can move right or left. If it can't move,return -1
        {
            int maxColumn = 0;
            for(int i = 0;i < 4;++i) {
                if(maxColumn < currentPoses[i][1]){
                    maxColumn = currentPoses[i][1];
                }
            }
            maxColumn = maxColumn - (width/2 - 1);
            //Control all way is clear to move
            if(direction == 'R')
            {
                for(int i = 0;i < count;++i)
                {
                    for(int j = 0;j < 4;++j)
                    {
                        if(board[currentPoses[j][0]][currentPoses[j][1] + i + maxColumn] != ' ') 
                        {
                            if(j == 0) 
                            {
                                if(currentPoses[0][0] != currentPoses[1][0] && currentPoses[0][0] != currentPoses[2][0] && 
                                currentPoses[0][0] != currentPoses[3][0]) return -1;
                            }else if(j == 1) {
                                if(currentPoses[1][0] != currentPoses[2][0] && currentPoses[1][0] != currentPoses[3][0]) return -1;
                            }
                            else if(j == 2) {
                                if(currentPoses[2][0] != currentPoses[3][0]) return -1;
                            }
                            else if(j == 3) return -1;
                        }
                    }
                }
            }else if(direction == 'L')
            {
                for(int i = 0;i < count;++i) 
                {
                    for(int j = 0;j < 4;++j)
                    {
                        if(board[currentPoses[j][0]][currentPoses[j][1] - i - maxColumn] != ' ') 
                        {
                            if(j == 0) return -1;
                            else if(j == 1) {
                                if(currentPoses[1][0] != currentPoses[0][0]) return -1;
                            }
                            else if(j == 2) {
                                if(currentPoses[2][0] != currentPoses[0][0] && currentPoses[2][0] != currentPoses[1][0]) return -1;
                            }
                            else if(j == 3) {
                                if(currentPoses[3][0] != currentPoses[0][0] && currentPoses[3][0] != currentPoses[1][0]
                                && currentPoses[3][0] != currentPoses[2][0]) return -1;
                            }
                        }
                    }
                }
            }
        }
        //Move right or left and set empty old position of shape
        if(direction == 'R')
        {
            temp = board[currentPoses[0][0]][currentPoses[0][1] + moveTimeCount];
            for(int i = 0;i < 4;++i)
                board[currentPoses[i][0]][currentPoses[i][1] + moveTimeCount] = ' ';
            for(int j = 0;j < 4;++j)
                board[currentPoses[j][0]][currentPoses[j][1] + moveTimeCount + 1] = temp;
        }else if(direction == 'L')
        {
            temp = board[currentPoses[0][0]][currentPoses[0][1] - moveTimeCount];
            for(int i = 0;i < 4;++i)
                board[currentPoses[i][0]][currentPoses[i][1] - moveTimeCount] = ' ';
            for(int j = 0;j < 4;++j)
                board[currentPoses[j][0]][currentPoses[j][1] - moveTimeCount - 1] = temp;    
        }
        ++moveTimeCount;
        //update current positions
        if(moveTimeCount == count)
        {
            if(direction == 'R')
            {
                for(int i = 0;i < 4;++i)
                    currentPoses[i][1] += moveTimeCount;
            }else if(direction == 'L')
            {
                for(int i = 0;i < 4;++i)
                    currentPoses[i][1] -= moveTimeCount;
            }
            return 0;
        }
        return 1;
    }
    void TetrisVector::SetCurrentPosesEmpty() {
        //Set shape's old positions' to space
        for(int i = 0;i < 4;++i)
            board[currentPoses[i][0]][currentPoses[i][1]] = ' ';
    }
    bool TetrisVector::ControlAnimateFinish() const{//check are next steps empty?
        if(board[currentPoses[3][0] + 1][currentPoses[3][1]] == ' ' && 
        (board[currentPoses[2][0] + 1][currentPoses[2][1]] == ' ' || currentPoses[2][1] == currentPoses[3][1])
        && (board[currentPoses[1][0] + 1][currentPoses[1][1]] == ' ' || currentPoses[1][1] == currentPoses[2][1] || currentPoses[1][1] == currentPoses[3][1])
        && (board[currentPoses[0][0] + 1][currentPoses[0][1]] == ' ' || currentPoses[0][1] == currentPoses[2][1] || currentPoses[0][1] == currentPoses[3][1] || currentPoses[0][1] == currentPoses[1][1])) return true;
        else return false;
    }
    void TetrisVector::writeToFile(const std::string &fileNameInput) {
        std::ofstream writeFile;
        writeFile.open(getFileName(fileNameInput));
        if(!writeFile.is_open()) {
            std::cout << "File couldn't open" << std::endl;
        }else {
            for(auto i = 0;i <= height;++i)
            {
                for(auto j = 0;j <= width + 1;++j)
                {
                    writeFile << board[i][j];
                }
                writeFile << std::endl;
            }
            writeFile.close();
        }
    }
    TetrisVector::~TetrisVector()
    {
    }
}