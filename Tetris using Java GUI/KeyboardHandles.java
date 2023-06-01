import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JPanel;

/**
* @author Akif Safa Angi
* @version 1.0.0
*/
/**
 *Class of KeyboardHandles
*/
public class KeyboardHandles extends JPanel implements KeyListener{
	GameBoard game;
	DrawShape ds;
	/**
     *Constructor of KeyboardHandles
     *@param game DrawShape object
     *@param ds GameBoard object
    */
	public KeyboardHandles(GameBoard game, DrawShape ds) {
		this.game = game;
		this.ds = ds;
	}
	public void keyPressed(KeyEvent e) {
	    if (e.getKeyCode() == KeyEvent.VK_RIGHT ) {
		        //Right arrow key code
			game.moveLeftRight('R');
			ds.redrawBoard();
	    } else if (e.getKeyCode() == KeyEvent.VK_LEFT ) {
	            //Left arrow key code
			game.moveLeftRight('L');
			ds.redrawBoard();
		   }else if(e.getKeyCode() == KeyEvent.VK_DOWN) {
			game.increaseCurrentPos();
			ds.redrawBoard();
	    }else if(e.getKeyCode() == KeyEvent.VK_UP) {
			game.rotate();
			ds.redrawBoard();
		   }
		}
	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
}
