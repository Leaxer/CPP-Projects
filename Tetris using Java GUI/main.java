import java.lang.Thread;

/**
* @author Akif Safa Angi
* @version 1.0.0
*/
/**
 *Class of main
 *Create GUI object
 *Call createBoard and start methods
*/
public class main {
	public static void main(String[] args) {
		GUI g = new GUI();
		g.createBoard();
		while(true) {
			while(g.gameState() == 0) {
				try {//call sleep method of thread
					Thread.sleep(500);
				}catch(InterruptedException e){System.out.println(e);}
			}
			g.start();
		}
	}
}