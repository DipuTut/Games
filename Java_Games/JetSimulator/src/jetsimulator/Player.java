/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jetsimulator;

import java.awt.Image;
import javax.swing.ImageIcon;

import java.awt.Graphics;
import java.awt.image.BufferedImage;

public class Player {
    private int x, y;
    private boolean left = false, right = false, up = false, down = false;
    
    Image player;
    private Graphics g;
    private BufferedImage test3;
    private SpriteSheet sheet3;
    //ImageIcon smallVol = new ImageIcon(this.getClass().getResource(obj1));
    
   
    
    
    public Player(){
        
        test3 = ImageLoader.loadImage("/images/PlayerShip.png");
        sheet3 = new SpriteSheet(test3);
      //  g.drawImage(sheet3.crop(0, 0, 528, 358), 600, 550, null);
        player = sheet3.crop(0, 0, 228, 154);
        x = 950;
        y = 740;
    }
    
    public void setLeft(boolean left){
        this.left = left;
    }
    
    public void setRight(boolean right){
        this.right = right;
    }
    
     public void setUp(boolean up){
        this.up = up;
    }
    
    public void setDown(boolean down){
        this.down = down;
    }
    
    
    public boolean getLeft(){
      return left;
    }
 
    public boolean getRight(){
      return right;
    }
  
    public boolean getUp(){
      return up;
    }
 
    public boolean getDown(){
      return down;
    }
    
    
    public int getX(){
        return x;
    }
  
     public int getY(){
        return y;
    }
     
    public Image getImage(){
        return player;
    } 
    
    public void left(){
        x -= 2;
        if(x <= 0)
            x = 0;
    }
    
    public void right(){
        x += 2;
        if(x >= 2330)
            x = 2330;        
    }
   
    public void up(){
        y -= 2;
        if(y <= 0)
            y = 0;
    }
    
    public void down(){
        y += 2;
        if(y >= 1120)
            y = 1120;        
    }
     
    
}
