/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jetsimulator;

import java.awt.Image;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;



public class EnemyBullet {
    
    private int x, y, width, height;
    private Image enemyBullet;
    
   // private BufferedImage test1;
   // private SpriteSheet sheet1;
    
    public EnemyBullet(int x, int y, Image enemyBullet){
        
       // test1 = ImageLoader.loadImage("/images/MagicBullet2.gif");
       // sheet1 = new SpriteSheet(test1);
      
        
        this.enemyBullet = enemyBullet;
        this.x = x;
        this.y = y; 
        width = enemyBullet.getWidth(null);
        height = enemyBullet.getHeight(null);        
    }
    
    public int getX(){
        return x;
    }
    
    public int getY(){
        return y;
    }
    
    public void move(){
        y+= 10 ;
        x+= 5;
    }
    public Image getImage(){
        return enemyBullet;
    }
    
    public Rectangle getBounds(){
        return new Rectangle(x, y, width, height);
    }
    
   
}


/*
public class EnemyBullet {

    int x, y, vx, vy;
    float speed;
    float direction;
    
    public EnemyBullet(int x, int y, int vx, int vy){
        this.x = x;
        this.y = y;
        this.vx = vx;
        this.vy = vy;
        
        
    }
    
}
*/