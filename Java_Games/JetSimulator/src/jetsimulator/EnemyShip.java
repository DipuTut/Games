/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jetsimulator;

import java.awt.Image;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;


public class EnemyShip {
    
    private int x, y, width, height;
    private Image enemy;
    
   // private BufferedImage test1;
    //private SpriteSheet sheet1;
    
    public EnemyShip(int x, int y, Image enemy){
        
      //  test1 = ImageLoader.loadImage("/images/SprSheet1.png");
      //  sheet1 = new SpriteSheet(test1);
      //  enemy = sheet1.crop(0, 200, 260, 145);
        
        this.enemy = enemy;
        this.x = x;
        this.y = y; 
        width = enemy.getWidth(null);
        height = enemy.getHeight(null);        
    }
    
    public int getX(){
        return x;
    }
    
    public int getY(){
        return y;
    }
    
    public void move(){
        y+= 5 ;
        x+= 2;
    }
    public Image getImage(){
        return enemy;
    }
    
    public Rectangle getBounds(){
        return new Rectangle(x, y, width, height);
    }
    
   
}
