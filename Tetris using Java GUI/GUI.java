import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.Thread;
import java.util.Random;

import javax.swing.JButton;
import javax.swing.JPanel;
/**
* @author Akif Safa Angi
* @version 1.0.0
*/
/**
 *Class of GUI
 *This class contains our shape and its methods and Game loop
*/
public class GUI {
	private enum State{end,start,reset};
	
	private char shapeLetter;
	private int[][] shape;
	private int speed = 1000;
	private Color currentColor;
	GameBoard game;
	DrawShape ds;
	Random rand = new Random();
	/**
     *Constructor of class
	 *Set some properties
	 *Set shape's board to zero
	 *Set shape's board,type and color again
    */
	private State currentState;
	public GUI() {
		currentState = State.end;
		shape = new int[4][4];
		//all board to zero value
		for(int i = 0;i < 4;++i) {
			for(int j = 0;j < 4;++j) {
				shape[i][j] = 0;				
			}
		}
		//get random value and define type
		int randNum = rand.nextInt(7);
		if(randNum == 0) {
			shape[2][0] = 2;
            shape[2][1] = 2;
            shape[2][2] = 2;
            shape[2][3] = 2;
			shapeLetter = 'I';
			currentColor = Color.pink;
        }
        else if(randNum == 1) {
        	shape[1][1] = 2;
            shape[1][2] = 2;
            shape[2][1] = 2;
            shape[2][2] = 2;
    		shapeLetter = 'O';
        	currentColor = Color.orange;
        }
        else if(randNum == 2) {
        	shape[1][1] = 2;
            shape[1][2] = 2;
            shape[1][3] = 2;
            shape[2][2] = 2;
    		shapeLetter = 'T';
        	currentColor = Color.magenta;
        }
        else if(randNum == 3) {
        	shape[1][2] = 2;
            shape[2][2] = 2;
            shape[3][1] = 2;
            shape[3][2] = 2;
    		shapeLetter = 'J';
        	currentColor = Color.green;
        }
        else if(randNum == 4) {
        	shape[1][1] = 2;
            shape[2][1] = 2;
            shape[3][1] = 2;
            shape[3][2] = 2;
    		shapeLetter = 'L';
        	currentColor = Color.white;
        }
        else if(randNum == 5) {
        	shape[1][2] = 2;
            shape[1][3] = 2;
            shape[2][1] = 2;
            shape[2][2] = 2;
    		shapeLetter = 'S';
        	currentColor = Color.yellow;
        }
        else if(randNum == 6) {
        	shape[1][1] = 2;
            shape[1][2] = 2;
            shape[2][2] = 2;
            shape[2][3] = 2;
    		shapeLetter = 'Z';
        	currentColor = Color.red;
        }
		
	}
	/**
     *Create board
	 *Call buttonHandles and changeColor
    */
	public void createBoard() {
		game = new GameBoard(shape, currentColor);
		ds = new DrawShape(game);
		buttonHandles();
		changeColor();
	}
	/**
     *Start game
    */
	public void start() {
		int timer = 0;
		//call methods to create new shape and add to board
		setNewShapeType();
		setNewShape();
		setNewShapeType();
		ds.drawNextShape(shapeLetter);
		//loop until game finish
		while(currentState == State.start) {
			ds.redrawBoard();
			try {//call sleep method of thread
				Thread.sleep(speed);
			}catch(InterruptedException e){System.out.println(e);}
			++timer;
			if(timer * (speed/1000) > 30) {
				timer = 0;
				speed = (speed*9/10);
			}
			if(game.increaseCurrentPos() == 2 && currentState == State.start) {
				setNewShape();
				setNewShapeType();
				ds.drawNextShape(shapeLetter);
			}
			game.rowControl();
		}
		ds.end();
	}
	/**
     *Change color based on shapeLetter
    */
	private void changeColor() {
		//change color
		if(shapeLetter == 'I') {
			currentColor = Color.pink;
			ds.setShapeColor(currentColor);
        }
        else if(shapeLetter == 'O') {
        	currentColor = Color.orange;
			ds.setShapeColor(currentColor);
        }
        else if(shapeLetter == 'T') {
        	currentColor = Color.magenta;
			ds.setShapeColor(currentColor);
        }
        else if(shapeLetter == 'J') {
        	currentColor = Color.green;
			ds.setShapeColor(currentColor);
        }
        else if(shapeLetter == 'L') {
        	currentColor = Color.white;
			ds.setShapeColor(currentColor);
        }
        else if(shapeLetter == 'S') {
        	currentColor = Color.yellow;
			ds.setShapeColor(currentColor);
        }
        else if(shapeLetter == 'Z') {
        	currentColor = Color.red;
			ds.setShapeColor(currentColor);
        }
	}
	/**
     *Create new type
    */
	public void setNewShapeType() {
		//same with constructor
		int randNum = rand.nextInt(7);
		if(randNum == 0) {
			shapeLetter = 'I';
			currentColor = Color.pink;
        }
        else if(randNum == 1) {
    		shapeLetter = 'O';
    		currentColor = Color.orange;
        }
        else if(randNum == 2) {
    		shapeLetter = 'T';
    		currentColor = Color.magenta;
        }
        else if(randNum == 3) {
    		shapeLetter = 'J';
    		currentColor = Color.green;
        }
        else if(randNum == 4) {
    		shapeLetter = 'L';
    		currentColor = Color.white;
        }
        else if(randNum == 5) {
    		shapeLetter = 'S';
    		currentColor = Color.yellow;
    		
        }
        else if(randNum == 6) {
    		shapeLetter = 'Z';
    		currentColor = Color.red;
        }
	}
	/**
     *After creating new type set board,color
	 *And call game object's NewShape method to add shape to tetris board
    */
	private void setNewShape() {
		for(int i = 0;i < 4;++i) {
			for(int j = 0;j < 4;++j) {
				shape[i][j] = 0;				
			}
		}
		if(shapeLetter == 'I') {
			shape[2][0] = 2;
            shape[2][1] = 2;
            shape[2][2] = 2;
            shape[2][3] = 2;
        }
        else if(shapeLetter == 'O') {
        	shape[1][1] = 2;
            shape[1][2] = 2;
            shape[2][1] = 2;
            shape[2][2] = 2;
        }
        else if(shapeLetter == 'T') {
        	shape[1][0] = 2;
            shape[1][1] = 2;
            shape[1][2] = 2;
            shape[2][1] = 2;
        }
        else if(shapeLetter == 'J') {
        	shape[1][2] = 2;
            shape[2][2] = 2;
            shape[3][1] = 2;
            shape[3][2] = 2;
        }
        else if(shapeLetter == 'L') {
        	shape[1][1] = 2;
            shape[2][1] = 2;
            shape[3][1] = 2;
            shape[3][2] = 2;
        }
        else if(shapeLetter == 'S') {
        	shape[1][2] = 2;
            shape[1][3] = 2;
            shape[2][1] = 2;
            shape[2][2] = 2;
        }
        else if(shapeLetter == 'Z') {
        	shape[1][1] = 2;
            shape[1][2] = 2;
            shape[2][2] = 2;
            shape[2][3] = 2;
        }
		changeColor();
		if(game.NewShape(shape, currentColor) == -1) {
			currentState = State.end;
		}
	}
	/**
     *Return type of shape
	 *@return shapeLetter
    */
	public char getType() {
		return shapeLetter;
	}
	private JPanel buttonPanel;
	private JButton reset;
	private JButton start;
	private JButton end;
	/**
     *Button Handles Method
    */
	private void buttonHandles() {
		//Button Panel
		buttonPanel = new JPanel();
		buttonPanel.setBounds(374,132,80,100);
		buttonPanel.setBackground(Color.gray);
		reset = new JButton("Reset");
		reset.setFocusable(false);
		reset.setEnabled(false);
		start = new JButton("Start");
		start.setFocusable(false);
		end = new JButton("End");
		end.setEnabled(false);
		end.setFocusable(false);
		buttonPanel.add(reset);
		buttonPanel.add(start);
		buttonPanel.add(end);
		ds.getJf().add(buttonPanel);
		ActionListener buttonListener = new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				if(e.getSource() == start) {
					//start button
					currentState = State.start;
					start.setEnabled(false);
					reset.setEnabled(true);
					end.setEnabled(true);
					ds.start();
				}else if(e.getSource() == end) {
					//end button
					currentState = State.end;
					end.setEnabled(false);
					ds.end();
				}else if(e.getSource() == reset) {
					//reset button
					//call ds.end method and game.reset method
					currentState = State.reset;
					ds.end();
					game.reset();
					end.setEnabled(true);
				}
			}
		};
		//add listener to buttons
		start.addActionListener(buttonListener);
		end.addActionListener(buttonListener);
		reset.addActionListener(buttonListener);
	}
	/**
     *Control currentState and return it's value
	 *@return int
    */
	public int gameState() {
		//control state
		if(currentState == State.reset) {
			currentState = State.start;
			ds.start();
			return 1;
		}
		else if(currentState == State.start) return 1;
		else return 0;
	}
}