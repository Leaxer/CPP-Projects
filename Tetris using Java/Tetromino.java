/**
* @author Akif Safa Angi
* @version 1.0.0
*/
/**
 *Class of tetromino shape
*/
public class Tetromino {
    private char[][] shape = new char[4][4];
    private int[][] shapePos = new int[4][2];

    public enum tetrominos {I,O,T,J,L,S,Z} //Create strong enum
    /**
     *Constructor of class
     *@param letter type of tetromino shape
     *Create new shape and store position of shape to shapePos
    */
    public Tetromino(tetrominos letter) {
        for(int i = 0;i < 4;++i) {
            for(int j = 0;j < 4;++j) {
                shape[i][j] = ' ';
            }
        }
        if(letter == tetrominos.I) {
            shape[3][0] = 'I';
            shape[3][1] = 'I';
            shape[3][2] = 'I';
            shape[3][3] = 'I';
        }
        else if(letter == tetrominos.O) {
            shape[2][0] = 'O';
            shape[2][1] = 'O';
            shape[3][0] = 'O';
            shape[3][1] = 'O';
        }
        else if(letter == tetrominos.T) {
            shape[2][0] = 'T';
            shape[2][1] = 'T';
            shape[2][2] = 'T';
            shape[3][1] = 'T';
        }
        else if(letter == tetrominos.J) {
            shape[1][1] = 'J';
            shape[2][1] = 'J';
            shape[3][0] = 'J';
            shape[3][1] = 'J';
        }
        else if(letter == tetrominos.L) {
            shape[1][0] = 'L';
            shape[2][0] = 'L';
            shape[3][0] = 'L';
            shape[3][1] = 'L';
        }
        else if(letter == tetrominos.S) {
            shape[2][1] = 'S';
            shape[2][2] = 'S';
            shape[3][0] = 'S';
            shape[3][1] = 'S';
        }
        else if(letter == tetrominos.Z) {
            shape[2][0] = 'Z';
            shape[2][1] = 'Z';
            shape[3][1] = 'Z';
            shape[3][2] = 'Z';
        }
        int temp = 0;
        for(int i = 0;i < 4;++i){//Get positions' of shape
            for(int j = 0;j < 4;++j){
                if(shape[i][j] != ' ') {
                    shapePos[temp][0] = i;
                    shapePos[temp][1] = j;
                    ++temp;
                }
            }
        }
    }
    /**
     *Rotate the shape with swap tactic
     *@param rotation direction
    */
    public void Rotate() {
        for(int i=0;i<4;i++) {
            for(int j=i;j<4;j++) {
                char temp = shape[i][j];
                shape[i][j] = shape[j][i];
                shape[j][i] = temp;
                }
        }

        for(int i=0;i<4;i++) {  
            int low = 0, high = 3;
            while(low < high) {
                char temp = shape[i][low];
                shape[i][low] = shape[i][high];
                shape[i][high] = temp;
                ++low;
                --high;
            }
        }
        fixShape();
    }
    /**
     *Set shape to left corner
    */
    private void fixShape() {
        while(shape[3][0] == ' ' && shape[3][1] == ' ' && shape[3][2] == ' ' && shape[3][3] == ' '){
            char[] temp = new char[4];//put the shape to left corner after rotate
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
            char[] temp = new char[4];
            temp[0] = shape[0][0];//store first collumn of the shape
            temp[1] = shape[1][0];
            temp[2] = shape[2][0];
            temp[3] = shape[3][0];
            for(int i = 0;i < 3;++i){
                for(int j = 0;j < 4;++j){
                    shape[j][i] = shape[j][i + 1];
                }
            }
                
            shape[0][3] = temp[0];//put first collumn to last collumn
            shape[1][3] = temp[1];
            shape[2][3] = temp[2];
            shape[3][3] = temp[3];
        }
        int temp = 0;
        for(int i = 0;i < 4;++i){//Get positions' of shape
            for(int j = 0;j < 4;++j){
                if(shape[i][j] != ' ') {
                    shapePos[temp][0] = i;
                    shapePos[temp][1] = j;
                    ++temp;
                }
            }
        }
    }
    /**
     *Return shape
     *@return shape
    */
    public char[][] GetShape(){
        return shape;
    }
    /**
     *Return position of shape shapePos
     *@return shapePos
    */
    public int[][] GetShapePos(){
        return shapePos;
    }
}