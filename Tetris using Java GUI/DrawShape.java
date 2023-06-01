import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
* @author Akif Safa Angi
* @version 1.0.0
*/
/**
 *Class of DrawShape
 *GUI and gui props are here
*/
public class DrawShape extends JPanel{
	private int[][] current_pos;
	private Color shapeColor;
	private Color[][] boardColor = null;
	
	private JFrame jf;
	private JPanel boardPanel;
	private JPanel nextShapePanel;
	
	private JButton[][] buttons;
	private JButton[][] nextShapeButtons = new JButton[4][4];
	KeyboardHandles bl;
	/**
     *Constructor of DrawShape
     *@param game GameBoard object
    */
	public DrawShape(GameBoard game) {
		this.current_pos = new int[4][2];
		this.current_pos = game.getCurrent_pos();
		this.boardColor = game.getBoardColor();
		jf = new JFrame("Tetris");
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//Board Panel
		boardPanel = new JPanel(new GridLayout(20,10));
		boardPanel.setBounds(4,4,320,640);
		boardPanel.setBackground(Color.BLACK);
		buttons = new JButton[20][10];
		for(int i = 0;i < 20;++i) {
			for(int j = 0;j < 10;++j) {
				buttons[i][j] = new JButton();
				buttons[i][j].setBackground(Color.gray);
				buttons[i][j].setEnabled(false);
				boardPanel.add(buttons[i][j]);
			}
		}
		jf.add(boardPanel);
		//nextShapePanel
		nextShapePanel = new JPanel(new GridLayout(4,4));
		nextShapePanel.setBounds(350, 4, 128,128);
		for(int i = 0;i < 4;++i) {
			for(int j = 0;j < 4;++j) {
				nextShapeButtons[i][j] = new JButton();
				nextShapeButtons[i][j].setBackground(Color.gray);
				nextShapeButtons[i][j].setEnabled(false);
				nextShapePanel.add(nextShapeButtons[i][j]);
			}
		}
		jf.add(nextShapePanel);
		//KeyboadHandles
		bl = new KeyboardHandles(game,this);
		bl.setFocusable(true);
		jf.add(bl);
		//Frame
		jf.setSize(495, 690);
		jf.setLayout(null);
		jf.setVisible(true);
		jf.setResizable(false);
		boardPanel.validate();
		boardPanel.repaint();
	}
	/**
     *Redraw board
    */
	public void redrawBoard() {
		//color all buttons to gray
		for(int i = 0;i < 10;++i) {
			for(int j = 0;j < 20;++j) {
				buttons[j][i].setBackground(Color.gray);
			}
		}
		//color current positions to current shape's color
		for(int i = 0;i < 4;++i) {
			buttons[current_pos[i][0]][current_pos[i][1]].setBackground(shapeColor);
		}
		//color old shape's positions to their color
		for(int i = 0;i < 10;++i) {
			for(int j = 0;j < 20;++j) {
				if(boardColor[j][i] != null) {
					buttons[j][i].setBackground(boardColor[j][i]);
				}
			}
		}
	}
	/**
     *Set shapeColor value to param's color
     *@param shapeColor color of shape
    */
	public void setShapeColor(Color shapeColor) {
		this.shapeColor = shapeColor;
	}
	/**
     *Return frame jf
	 *@return jf
    */
	public JFrame getJf() {
		return jf;
	}
	/**
     *Add key listener to button listener bl
    */
	public void start() {
		bl.addKeyListener(bl);
	}
	/**
     *Remove key listener from button listener bl
    */
	public void end() {
		bl.removeKeyListener(bl);
	}
	/**
     *Method for drawing next shape to next shape panel
	 *@param type type of shape
    */
	public void drawNextShape(char type) {
		Color tempC;
		//color nextShapePanel buttons to see what is next shape
		for(int i = 0;i < 4;++i) {
			for(int j = 0;j < 4;++j) {
				nextShapeButtons[i][j].setBackground(Color.gray);
			}
		}
		if(type == 'I') {
			tempC = Color.pink;
			nextShapeButtons[2][0].setBackground(tempC);
			nextShapeButtons[2][1].setBackground(tempC);
			nextShapeButtons[2][2].setBackground(tempC);
			nextShapeButtons[2][3].setBackground(tempC);
        }
        else if(type == 'O') {
        	tempC = Color.orange;
        	nextShapeButtons[1][1].setBackground(tempC);
        	nextShapeButtons[1][2].setBackground(tempC);
        	nextShapeButtons[2][1].setBackground(tempC);
            nextShapeButtons[2][2].setBackground(tempC);
        }
        else if(type == 'T') {
        	tempC = Color.magenta;
        	nextShapeButtons[1][0].setBackground(tempC);
        	nextShapeButtons[1][1].setBackground(tempC);
        	nextShapeButtons[1][2].setBackground(tempC);
        	nextShapeButtons[2][1].setBackground(tempC);
        }
        else if(type == 'J') {
        	tempC = Color.green;
        	nextShapeButtons[1][2].setBackground(tempC);
        	nextShapeButtons[2][2].setBackground(tempC);
        	nextShapeButtons[3][1].setBackground(tempC);
        	nextShapeButtons[3][2].setBackground(tempC);
        }
        else if(type == 'L') {
        	tempC = Color.white;
        	nextShapeButtons[1][1].setBackground(tempC);
        	nextShapeButtons[2][1].setBackground(tempC);
        	nextShapeButtons[3][1].setBackground(tempC);
        	nextShapeButtons[3][2].setBackground(tempC);
        }
        else if(type == 'S') {
        	tempC = Color.yellow;
        	nextShapeButtons[1][2].setBackground(tempC);
        	nextShapeButtons[1][3].setBackground(tempC);
        	nextShapeButtons[2][1].setBackground(tempC);
        	nextShapeButtons[2][2].setBackground(tempC);
        }
        else if(type == 'Z') {
        	tempC = Color.red;
        	nextShapeButtons[1][1].setBackground(tempC);;
        	nextShapeButtons[1][2].setBackground(tempC);
        	nextShapeButtons[2][2].setBackground(tempC);
        	nextShapeButtons[2][3].setBackground(tempC);
        }
	}
}
