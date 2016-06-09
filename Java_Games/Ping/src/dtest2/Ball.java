/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dtest2;

import java.awt.Graphics2D;
import java.awt.Rectangle;

public class Ball {
	private static final int DIAMETER = 30;
        int x = 0;
	int y = 0;
	int xa = 1;
	int ya = 1;
	private Dtest2 game;

	public Ball(Dtest2 game) {
		this.game= game;
	}

	void move() {
                boolean changeDirection = true;
		if (x + xa < 0)
			xa = game.speed;
                else if (x + xa > game.getWidth() - DIAMETER)
			xa = -game.speed;
                else if (y + ya < 0)
			ya = game.speed;
                else if (y + ya > game.getHeight() - DIAMETER)
			game.gameOver();
                
                else if (collision()){
			ya = -game.speed;
			y = game.racquet.getTopY() - DIAMETER;
                        game.speed++;
		}
                else changeDirection = false;
                
                if (changeDirection)
                    Sound.BALL.play();

		x = x + xa;
		y = y + ya;
	}

        private boolean collision() {
		return game.racquet.getBounds().intersects(getBounds());
	}
        
	public void paint(Graphics2D g) {
		g.fillOval(x, y, DIAMETER, DIAMETER);
	}
        
        public Rectangle getBounds() {
		return new Rectangle(x, y, DIAMETER, DIAMETER);
	}
        
        
}