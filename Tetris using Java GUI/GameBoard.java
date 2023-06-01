import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
* @author Akif Safa Angi
* @version 1.0.0
*/
/**
 *Class of GameBoard
*/
public class GameBoard {
	private int[][] board;

	private int[][] shape;
	private int[][] shape_pos;
	private int[][] current_pos;
	
	private Color currentColor;
	private Color[][] boardColor;
	/**
     *Constructor of class
	 *set some props and set board to 0
     *@param shape current shape
     *@param currentColor current color of current shape
    */
	public GameBoard(int[][] shape, Color currentColor) {
		//sizes of objects
		board = new int[20][10];
		boardColor = new Color[20][10];
		current_pos = new int[4][2];
		shape_pos = new int[4][2];
		this.shape = shape;
		for(int i = 0;i < 20;++i) {
			for(int j = 0;j < 10;++j) {
				board[i][j] = 0;
			}
		}
		this.currentColor = currentColor;
		setPositions();
		setBoard();
	}
	/**
     *Set shape_pos for current positions
    */
	private void setPositions() {
		//position of shape
		int a = 0;
		for(int i = 0;i < 4;++i) {
			for(int j = 0;j < 4;++j) {
				if(shape[i][j] != 0) {
					shape_pos[a][0] = i;
					shape_pos[a][1] = j;
					++a;
				}
			}
		}
	}
	/**
     *Set current position and control if board are empty or not
	 *If board is no empty return -1 to warn can't add more tetromino to board
	 *@return int
    */
	private int setBoard() {
		//control cells if they are empty or not
		for(int i = 0;i < 4;++i) {
			current_pos[i][0] = shape_pos[i][0] - shape_pos[0][0];
			current_pos[i][1] = shape_pos[i][1] + 3;
		}
		for(int i = 0;i < 4;++i) {
			if(board[current_pos[i][0]][current_pos[i][1]] != 0) {
				return -1;
			}
		}
		return 0;
	}
	/**
	 *At first control if shape can move
	 *If it can move,then increase y axis of shape to go down
     *@return int
    */
	public int increaseCurrentPos() {
		//control if it can move down,and move shape to one level lower
		if(ControlDown()) {
			for(int i = 0;i < 4;++i) {
				++current_pos[i][0];			
			}
			return 1;
		}else{
			freezeShape();
			return 2;
		}
	}
	/**
	 *Moving left or right
     *@param direction direction of shape to move left or right
    */
	public void moveLeftRight(char direction) {
		//move left or right
		if(direction == 'L' && ControlRightLeft('L')) {
			for(int i = 0;i < 4;++i) {
				--current_pos[i][1];			
			}
		}else if(direction == 'R' && ControlRightLeft('R')) {
			for(int i = 0;i < 4;++i) {
				++current_pos[i][1];		
			}
		}
	}
	/**
	 *Return current_pos int[][]
	 *@return current_pos
    */
	public int[][] getCurrent_pos() {
		return current_pos;
	}
	/**
	 *Control method for shape can go down or not
	 *@return true or false
    */
	private boolean ControlDown() {
		if(current_pos[3][0] + 1 <= 19) {
			if(board[current_pos[3][0] + 1][current_pos[3][1]] != 1 && 
			        board[current_pos[2][0] + 1][current_pos[2][1]] != 1
			        && board[current_pos[1][0] + 1][current_pos[1][1]] != 1
			        && board[current_pos[0][0] + 1][current_pos[0][1]] != 1) return true;
		}
		return false;
    }
	/**
	 *Control method for shape can go right or left based on direction
	 *@param direction right'R' of left'L'
	 *@return true or false
    */
	private boolean ControlRightLeft(char direction) {
		int column;
		//controls shape's columns' +1 or -1 depends on direction
		if(direction == 'R') {
			column = -1;
			for(int i = 0;i < 4;++i) {
				if(column < current_pos[i][1]) column = current_pos[i][1];
			}
			if(column + 1 <= 9) {
				if(board[current_pos[3][0]][current_pos[3][1] + 1] != 1 && 
						board[current_pos[2][0]][current_pos[2][1] + 1] != 1
						&& board[current_pos[1][0]][current_pos[1][1] + 1] != 1
						&& board[current_pos[0][0]][current_pos[0][1] + 1] != 1) return true;
			}			
		}else if(direction == 'L') {
			column = 10;
			for(int i = 0;i < 4;++i) {
				if(column > current_pos[i][1]) column = current_pos[i][1];
			}
			if(column - 1 >= 0) {
				if(board[current_pos[3][0]][current_pos[3][1] - 1] != 1 && 
						board[current_pos[2][0]][current_pos[2][1] - 1] != 1
						&& board[current_pos[1][0]][current_pos[1][1] - 1] != 1
						&& board[current_pos[0][0]][current_pos[0][1] - 1] != 1) return true;
			}		
		}
		return false;
	}
	/**
	 *If shape can't go down more,set current position of shape on board to 1
	 *That means there is a shape on that cell
	 *Same for boardColor value
    */
	public void freezeShape() {
		//set board's current position to 1
		for(int i = 0;i < 4;++i) {
			board[current_pos[i][0]][current_pos[i][1]] = 1;
		}
		//color cell to current color
		for(int i = 0;i < 4;++i) {
			boardColor[current_pos[i][0]][current_pos[i][1]] = currentColor;
		}
	}
	/**
	 *Set shape object to param's shape object
	 *call setPosition method
	 *Control if setBoard -1 or not
	 *Set color
	 *@param shape current shape
	 *@param currentColor current color of current shape
	 *@return int
    */
	public int NewShape(int[][] shape, Color currentColor) {
		this.shape = shape;
		setPositions();
		if(setBoard() == -1) {
			return -1;
		}
		this.currentColor = currentColor;
		return 0;
	}
	/**
	 *Return boardColor
	 *@return boardColor
    */
	public Color[][] getBoardColor() {
		return boardColor;
	}
	/**
	 *Control row
    */
	public void rowControl() {
		int count;
		for(int i = 0;i < 20;++i) {
			count = 0;
			for(int j = 0;j < 10;++j) {
				if(board[i][j] == 1) 
					++count;
			}
			if(count == 10) {
				deleteRow(i);
			}
		}
	}
	/**
	 *Delete row
	 *@param whichRow index of which row should be deleted
    */
	private void deleteRow(int whichRow) {
		//move all row to one level lower
		for(int i = whichRow;i > 0;--i) {
			for(int j = 0;j < 10;++j) {
				board[i][j] = board[i - 1][j];
				boardColor[i][j] = boardColor[i - 1][j];
			}
		}
		//board's first row to 0 and color to null
		for(int j = 0;j < 10;++j) {
			board[0][j] = 0;
			boardColor[0][j] = null;
		}
	}
	/**
	 *Rotate Method
    */
	public void rotate() {
		//rotate shape with swap tactic
		int[][] temp_shape_pos = new int[4][2];
		for(int i=0;i<4;i++) {
            for(int j=0;j<2;j++) {
            	temp_shape_pos[i][j] = shape_pos[i][j];
            }
        }
		for(int i=0;i<4;i++) {
            for(int j=i;j<4;j++) {
                int temp = shape[i][j];
                shape[i][j] = shape[j][i];
                shape[j][i] = temp;
            }
        }

        for(int i=0;i<4;i++) {  
            int low = 0, high = 3;
            while(low < high) {
                int temp = shape[i][low];
                shape[i][low] = shape[i][high];
                shape[i][high] = temp;
                ++low;
                --high;
            }
        }
        setPositions();
		for(int i = 0;i < 4;++i) {
			current_pos[i][0] += shape_pos[i][0] - temp_shape_pos[i][0];
			current_pos[i][1] += shape_pos[i][1] - temp_shape_pos[i][1];
		}
	}
	/**
	 *Reset method to reset game
    */
	public void reset() {
		for(int i = 0;i < 20;++i) {
			for(int j = 0;j < 10;++j) {
				board[i][j] = 0;
				boardColor[i][j] = null;
			}
		}
	}
}
