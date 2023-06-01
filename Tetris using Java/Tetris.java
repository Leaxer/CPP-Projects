import java.util.*;
import java.lang.Thread;
import java.io.*;

/**
* @author Akif Safa Angi
* @version 1.0.0
*/
/**
 *Class of Tetris
*/
public class Tetris {
    private int height,width,numOfRow;
    private char[][] board;
    private int[][] currentPoses;
    /**
     *Constructor of class
     *@param input_width width of board
     *@param input_height height of board
    */
    public Tetris(int input_width, int input_height) {
        height = input_height;
        width = input_width;
        board = new char[height + 1][width + 2];
        currentPoses = new int[4][2];

        for(int i = 0; i < height;++i) {
            for(int j = 0; j < width + 2;++j) {
                if(j == 0 || j == width + 1) {
                    board[i][j] = '#';
                }else {
                    board[i][j] = ' ';
                }
            }
        }
        for(int i = 0;i <= width + 1;++i)
            board[height][i] = '#';
    }
    /**
     *Add method to add tetromino to board
     *@param shape shape of tetromino from tetromino class
     *@param positions position of shape of tetromino from tetromino class
    */
    public boolean Add(char[][] shape, int[][] positions){
        numOfRow = 0;
        for(int i = 0;i < 4;++i) {//Find how many row spaces does shape have
            if(shape[i][0] == ' ' && shape[i][1] == ' ' && shape[i][2] == ' ' && shape[i][3] == ' ') ++numOfRow;
        }
        for(int i = 0;i < 4;++i) {//If first block are not empty return false
            if(board[positions[i][0] - numOfRow][positions[i][1] + (width/2 - 1)] != ' ') return false;
        }
        for(int i = 0;i < 4;++i) {//Set the shape to board
            board[positions[i][0] - numOfRow][positions[i][1] + (width/2 - 1)] = shape[positions[i][0]][positions[i][1]];
        }
        int temp = 0;
        for(int i = 0;i < 4;++i) {//update currentPoses
            for(int j = 0;j < 4;++j) {
                if(shape[i][j] != ' ') {
                    currentPoses[temp][0] = i - numOfRow;
                    currentPoses[temp][1] = j + (width/2 - 1);
                    ++temp;
                }
            }
        }
        return true;
    }
    /**
     *Increase row index and lower the tetromino
    */
    private void LowerLevel(){//Get char of shape as temp. Set current positions to ' ' and set new positions to temp character.
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
    /**
     *Print the board
    */
    private void Draw() {
        System.out.print("\033[0H");
        System.out.print("\033[J");
        for(int i = 0;i <= height;++i)//Print the board
        {
            for(int j = 0;j <= width + 1;++j)
            {
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
    }
    /**
     *Animate board
     *@param shapeObj Tetromino class
    */
    public void Animate(Tetromino shapeObj){
        int random,check;
        boolean addCheck = true;
        Random rand = new Random();
        Draw();
        for(int i = 0;i < 4;++i) {
            board[currentPoses[i][0]][currentPoses[i][1]] = ' ';
        }
        while(addCheck) {
            random = rand.nextInt(4);
            for(int i = 0;i < random;++i) {
                //rotate
                shapeObj.Rotate();
            }
            addCheck = Add(shapeObj.GetShape(),shapeObj.GetShapePos());
        }
        random = rand.nextInt(2);
        if(random == 0) {
            random = rand.nextInt(width/2) + 1;
            check = controlMovement('R',random);
            while(check < 0 && check != -2) {
                random = rand.nextInt(width/2) + 1;
                check = controlMovement('R',random);
            }
            moveTetromino('R',random);
        }else if(random == 1) {
            random = rand.nextInt(width/2) + 1;
            check = controlMovement('L',random);
            while(check < 0 && check != -2) {
                random = rand.nextInt(width/2) + 1;
                check = controlMovement('L',random);
            }
            moveTetromino('L',random);
        }
        // Loop until the hit the bottom
        while(board[currentPoses[3][0] + 1][currentPoses[3][1]] == ' ' &&
            (board[currentPoses[2][0] + 1][currentPoses[2][1]] == ' ' || currentPoses[2][1] == currentPoses[3][1])
            && (board[currentPoses[1][0] + 1][currentPoses[1][1]] == ' ' || currentPoses[1][1] == currentPoses[2][1] || currentPoses[1][1] == currentPoses[3][1])
            && (board[currentPoses[0][0] + 1][currentPoses[0][1]] == ' ' || currentPoses[0][1] == currentPoses[2][1] || currentPoses[0][1] == currentPoses[3][1] || currentPoses[0][1] == currentPoses[1][1])){
            LowerLevel();
            Draw();
            try {
                //call sleep method of thread
                Thread.sleep(50);
            }catch(InterruptedException e){System.out.println(e);}
        }
    }
    /**
     *Move left or right
     *@param direction direction,left or right
     *@param count count of how many times will tetromino move
    */
    private void moveTetromino(char direction, int count) {
        char temp;
        int moveTimeCount = 0;
        //Move right or left and set empty old position of shape
        if(direction == 'R')
        {
            temp = board[currentPoses[0][0]][currentPoses[0][1]];
            for(int j = 0;j < count;++j) {
                for(int i = 0;i < 4;++i)
                    board[currentPoses[i][0]][currentPoses[i][1] + moveTimeCount] = ' ';
                for(int i = 0;i < 4;++i)
                    board[currentPoses[i][0]][currentPoses[i][1] + moveTimeCount + 1] = temp;
                Draw();
                ++moveTimeCount;
                try {
                    //call sleep method of thread
                    Thread.sleep(50);
                }catch(InterruptedException e){System.out.println(e);}
            }
            for(int i = 0;i < 4;++i)
                currentPoses[i][1] += moveTimeCount;
        }else if(direction == 'L')
        {
            temp = board[currentPoses[0][0]][currentPoses[0][1]];
            for(int j = 0;j < count;++j) {
                for(int i = 0;i < 4;++i)
                    board[currentPoses[i][0]][currentPoses[i][1] - moveTimeCount] = ' ';
                for(int i = 0;i < 4;++i)
                    board[currentPoses[i][0]][currentPoses[i][1] - moveTimeCount - 1] = temp;
                Draw();
                ++moveTimeCount;
                try {
                    //call sleep method of thread
                    Thread.sleep(50);
                }catch(InterruptedException e){System.out.println(e);}
            }
            for(int i = 0;i < 4;++i)
                currentPoses[i][1] -= moveTimeCount;
        }
    }
    /**
     *Control if tetromino can move left or right
     *@param direction direction,left or right
     *@param count count of how many times will tetromino move
    */
    private int controlMovement(char direction, int count) {
        if(count == 0) return -2;//If it's zero return -2 and do nothing
            int maxColumn = 0;
            for(int i = 0;i < 4;++i) {
                if(maxColumn < currentPoses[i][1]) {
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
        return 1;
    }
}