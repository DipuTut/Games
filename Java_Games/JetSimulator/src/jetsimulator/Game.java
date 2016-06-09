/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jetsimulator;

import java.awt.Graphics;
import java.awt.image.BufferedImage;

import java.awt.Image;
import java.awt.Rectangle;
import javax.swing.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Random;




public class Game extends JPanel implements ActionListener {
    
        Image backGround;
        Timer timer;
        Player player;
        private Graphics g;
        EnemyShip enemyShip1;
   
        ArrayList<Fireball> fireball_array;
        ArrayList<EnemyShip> enemyShip_array;
        ArrayList<EnemyBullet> enemyBullet_array;
        Fireball fireBall, fireLaser;
        private boolean fire;
        Image enemy1, enemy2, enemy3, enemy4;
        Image enemyBullet1, enemyBullet2, enemyBullet3;
    
	
        Image destroyed = new ImageIcon(this.getClass().getClassLoader().getResource("images/Explosion.gif")).getImage();
        
       
        public void setFire(boolean fire){
        this.fire = fire;
        } 
        
        
        public Game(){
        
        
         BufferedImage test1, test2;
         SpriteSheet sheet1, sheet2;
        // EnemyShip enemyShip1, enemyShip2;
         
         
        test1 = ImageLoader.loadImage("/images/SprSheet1.png");
        sheet1 = new SpriteSheet(test1);
        enemy1 = sheet1.crop(290, 210, 165, 145);    
        enemy2 = sheet1.crop(0, 200, 260, 145); 
        enemy3 = sheet1.crop(305, 385, 130, 108);
        enemy4 = sheet1.crop(0, 530, 100, 65); 
        test2 = ImageLoader.loadImage("/images/SpriteBullet.png");
        sheet2 = new SpriteSheet(test2);
        enemyBullet1 = sheet2.crop(70,495,43,75);
        enemyBullet2 = sheet2.crop(70,798,25,30);
        enemyBullet3 = sheet2.crop(0,270,48,240);
        
      
        
        addKeyListener(new Action());    
        ImageIcon ii = new ImageIcon(this.getClass().getResource("/images/SpaceArt_big.png"));
        fireball_array = new ArrayList<Fireball>();
        enemyShip_array = new ArrayList<EnemyShip>();
        enemyBullet_array = new ArrayList<EnemyBullet>();
        
        player = new Player();
        setFocusable(true);
        backGround = ii.getImage();
      
        timer = new Timer(20,this);
        timer.start();
        
        
        Thread startEnemy = new Thread(new Runnable(){
           public void run(){
               while (true)
                   try {
                       enemyShips();
                       Thread.sleep(1000 * 2);   
                   }
               catch (InterruptedException e) {
                   e.printStackTrace();
               }
                   
           }   
            
        }); 
        startEnemy.start(); 
        
        
        
          Thread startFire = new Thread (new Runnable(){
           public void run(){
               while (true)
                   try {
                        if (fire == true){
                          fire();
                        } 
                        
                       Thread.sleep(100);
                   } 
                   catch (InterruptedException e) {
			  e.printStackTrace();
		        }
           }       
        });
       startFire.start();
        
       
        Thread movePlayer = new Thread (new Runnable(){
          @Override
          public void run(){
              while (true)
                  try {
                        if(player.getLeft() == true) {
			   player.left();
			}
			if (player.getRight() == true) {
			    player.right();
			}
                        if(player.getUp() == true) {
			   player.up();
			}
			if (player.getDown() == true) {
			    player.down();
			}
                        
			Thread.sleep(3);
                    }  
                  catch (InterruptedException e) {
                         e.printStackTrace();    
                  }
          }
      }); 
     movePlayer.start();
      
     Thread startBullet = new Thread(new Runnable(){
           public void run(){
               while (true)
                   try {
                       enemyBullets();
                       Thread.sleep(1000 * 2);   
                   }
               catch (InterruptedException e) {
                   e.printStackTrace();
               }
                   
           }   
            
        }); 
        startBullet.start(); 
     
     
    }
        
 
   @Override
   public void actionPerformed(ActionEvent arg0){
     
       for(int k = 0; k < fireball_array.size(); k++){
        fireball_array.get(k).move();
        if(fireball_array.get(k).getY() < 1) {
           fireball_array.remove(k);
        }
    }  
     
     for(int j = 0; j < enemyShip_array.size(); j++){
        enemyShip_array.get(j).move();
        if(enemyShip_array.get(j).getY() > 1300){
            enemyShip_array.remove(j);
        }
    }
   
    for(int j = 0; j < enemyBullet_array.size(); j++){
        enemyBullet_array.get(j).move();
        if(enemyBullet_array.get(j).getY() > 1300){
            enemyBullet_array.remove(j);
        }
    } 
     
     
    Thread collide = new Thread(() -> {
        collision();
        //g.drawImage(getEnemyImg(), 30, 30, null);
       });
    collide.start();     
    
    repaint(); 
   }
     
  /* 
    public void draw(Graphics g) {
    g.drawImage(getEnemyImg(), 30, 30, null);
} */

    public Image getEnemyImg() {
    
    return destroyed;
    }
       
   
   
   
          
        
        @Override
       public void paintComponent(Graphics g){
       g.drawImage(backGround, 0, 0, null);
       g.drawImage(player.getImage(), player.getX(), player.getY(), null);
       g.drawImage(getEnemyImg(), 30, 30, null);
       
       
       if (!enemyShip_array.isEmpty()) {
			for (int i = 0; i < enemyShip_array.size(); i++) {
				g.drawImage(enemyShip_array.get(i).getImage(), enemyShip_array.get(i)
						.getX(), enemyShip_array.get(i).getY(), null);
                            
                            //     g.drawImage(destroyed, enemyShip_array.get(i).getX(), enemyShip_array.get(i).getY(), null);
			}
		}
             
       
       if (!fireball_array.isEmpty()) {
			for (int k = 0; k < fireball_array.size(); k++) {
				g.drawImage(fireball_array.get(k).getImage(), fireball_array
						.get(k).getX(), fireball_array.get(k).getY(), null);
			}
                }
       
        if (!enemyBullet_array.isEmpty()) {
			for (int i = 0; i < enemyBullet_array.size(); i++) {
				g.drawImage(enemyBullet_array.get(i).getImage(), enemyBullet_array.get(i)
						.getX(), enemyBullet_array.get(i).getY(), null);
			}
		}
       
       
       }
   
  
        Random rn = new Random();
        int ran = rn.nextInt(500);
        int y = 1;
       
    public void enemyShips(){
      //  Random rn = new Random();
       // int ran = rn.nextInt(500);
        EnemyShip ship1 = new EnemyShip(ran,y,enemy1);
        EnemyShip ship2 = new EnemyShip(ran+1200,y,enemy2);
        EnemyShip ship3 = new EnemyShip(ran+800,y,enemy3);
        EnemyShip ship4 = new EnemyShip(ran+300,y,enemy4);
        enemyShip_array.add(ship1);
        enemyShip_array.add(ship2);
        enemyShip_array.add(ship3);
        enemyShip_array.add(ship4);
        
    }
      
    public void enemyBullets(){
     //   Random rn = new Random();
     //   int ran = rn.nextInt(2400);
        EnemyBullet bullet1 = new EnemyBullet(ran+70,y+130,enemyBullet1);
        EnemyBullet bullet2 = new EnemyBullet(ran+830,y+70,enemyBullet2);
        enemyBullet_array.add(bullet1);  
        enemyBullet_array.add(bullet2); 
        
        EnemyBullet bullet3 = new EnemyBullet(ran+1300,y+60,enemyBullet3);
        enemyBullet_array.add(bullet3);  
       
        
    }
      
    
    
       
        public void fire(){
        fireBall = new Fireball(player.getX(), player.getY());
        fireLaser = new Fireball(player.getX()+210, player.getY());
        fireball_array.add(fireBall); 
        fireball_array.add(fireLaser);
        } 
        
       
        
   public void collision(){
       for(int k = 0; k < fireball_array.size(); k++){
           for (int j = 0; j < enemyShip_array.size(); j++){
               Rectangle r1;
               if(!fireball_array.isEmpty()){
                   r1 = fireball_array.get(k).getBounds();
                   
                   Rectangle r2 = enemyShip_array.get(j).getBounds();
                   if(r1.intersects(r2)){ 
                       fireball_array.remove(k);
                       enemyShip_array.remove(j);             
                       Music.SHOT.play();
                      // g.drawImage(destroyed, enemyShip_array.get(j).getX(), enemyShip_array.get(j).getY(), null);
                       
                    }
                   
               }
           }
       }
   }
        
     
   public void enemy() {
    g.drawImage(destroyed, 200, 200, null);
}
   
   
   

        private class Action extends KeyAdapter {
                @Override
		public void keyPressed(KeyEvent e) {

			//paddle.volcano_Pressed();
			int keyCode = e.getKeyCode();
			if (keyCode == KeyEvent.VK_SPACE) {
				fire = true;
			} 

			if (keyCode == KeyEvent.VK_LEFT) {
				player.setLeft(true);
			}

			if (keyCode == KeyEvent.VK_RIGHT) {
				player.setRight(true);
			}

                        if (keyCode == KeyEvent.VK_UP) {
				player.setUp(true);
			}

			if (keyCode == KeyEvent.VK_DOWN) {
				player.setDown(true);
			}
		}

                @Override
		public void keyReleased(KeyEvent e) {

			//paddle.volcano_Released();

			 if (e.getKeyCode() == KeyEvent.VK_SPACE) {
				fire = false;
			} 

			if (e.getKeyCode() == KeyEvent.VK_LEFT) {
				player.setLeft(false);    
			}

			if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
				player.setRight(false);                     
			}
                        
                        if (e.getKeyCode() == KeyEvent.VK_UP) {
				player.setUp(false);
			}

			if (e.getKeyCode() == KeyEvent.VK_DOWN) {
				player.setDown(false);
			}
		}
	}  
        
    
        
}