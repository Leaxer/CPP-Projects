import java.util.Random;
import java.util.Scanner;

public class driver2 {
    public static void main(String[] args) {
        Tetris tetrisGame;
        Tetromino tetromin;
        Scanner obj = new Scanner(System.in);  // Create a Scanner object
        Random rand = new Random();
        int height = 0,width = 0,i = 0,randNum;
        char type;
        boolean flag,finish = true;
        System.out.println("Please enter the size of board");
        System.out.println("Height:");
        do{
            try
            {
                height = obj.nextInt();
                flag=false;
            }
            catch(Exception e)
            {
                // accept integer only.
                obj.nextLine();
                System.out.println("Please enter valid number");
                flag=true;
            }
        }while(flag || height <= 3);
        System.out.println("Width:");
        do{
            try
            {
                width = obj.nextInt();
                flag=false;
            }
            catch(Exception e)
            {
                // accept integer only.
                obj.nextLine();
                System.out.println("Please enter valid number");
                flag=true;
            }
        }while(flag || width <= 3);
        tetrisGame = new Tetris(width,height);
        System.out.print("\033[0H\033[2J");
        while(finish) {
            System.out.print("Enter the tetromino type: ");
            type = obj.next().charAt(0);
            while(type != 'I' && type != 'O' && type != 'T' && type != 'J' && type != 'L' && type != 'S' && type != 'Z' && type != 'Q' && type != 'R')
            {
                obj.nextLine();
                System.out.println("Please enter valid characters");
                type = obj.next().charAt(0);
            }
            if(type == 'Q') break;
            if(type == 'R')
            {
                randNum = rand.nextInt(7);
                if(randNum == 0) type = 'I';
                else if(randNum == 1) type = 'O';
                else if(randNum == 2) type = 'T';
                else if(randNum == 3) type = 'J';
                else if(randNum == 4) type = 'L';
                else if(randNum == 5) type = 'S';
                else if(randNum == 6) type = 'Z';
            }
            if(type == 'I') tetromin = new Tetromino(Tetromino.tetrominos.I);
            else if(type == 'O') tetromin = new Tetromino(Tetromino.tetrominos.O);
            else if(type == 'T') tetromin = new Tetromino(Tetromino.tetrominos.T);
            else if(type == 'J') tetromin = new Tetromino(Tetromino.tetrominos.J);
            else if(type == 'L') tetromin = new Tetromino(Tetromino.tetrominos.L);
            else if(type == 'S') tetromin = new Tetromino(Tetromino.tetrominos.S);
            else tetromin = new Tetromino(Tetromino.tetrominos.Z);
            finish = tetrisGame.Add(tetromin.GetShape(),tetromin.GetShapePos());
            if(finish == false) {
                System.out.println("Game Over");
            }else {
                tetrisGame.Animate(tetromin);
            }
        }
    }
}