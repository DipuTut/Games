/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jetsimulator;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;
import javax.swing.ImageIcon;

/**
 *
 * @author Dipu
 */
public class Fireball {
    
        private int x, y;
	private Image fireball;
	boolean visible;
	private int width, height;
	private int dy;
        
        private Graphics g;
        private BufferedImage test2;
        private SpriteSheet sheet2;
        

      public Fireball(int x, int y){
        dy = 20;
        
        // ImageIcon ii = new ImageIcon(this.getClass().getResource("/images/Laser.png"));
       //  fireball = ii.getImage();
        test2 = ImageLoader.loadImage("/images/playermissile1.png");
        sheet2 = new SpriteSheet(test2);
        fireball = sheet2.crop(0, 0, 17, 95);
  
        //visible = true;
        width = fireball.getWidth(null);
        height = fireball.getHeight(null);
        
        this.x = x; 
        this.y = y; 
        
      }
    
      public Image getImage(){
        return fireball;
      }
      
      public int getX(){
          return x;
      }

      public int getY(){
          return y;
      }

      public Rectangle getBounds() {
		return new Rectangle(x, y, width, height);
	}
      
      public void move(){
          y = y - dy;     
      }
      
}

