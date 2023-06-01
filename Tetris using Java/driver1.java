public class driver1 {
    public static void main(String[] args) {
        Tetromino tetromin = new Tetromino(Tetromino.tetrominos.L);
        Tetris tetrisGame = new Tetris(20,20);
        tetrisGame.Add(tetromin.GetShape(),tetromin.GetShapePos());
        tetrisGame.Animate(tetromin);
    }
}