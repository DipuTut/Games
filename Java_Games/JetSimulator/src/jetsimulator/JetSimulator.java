/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jetsimulator;


import javax.swing.JFrame;



public class JetSimulator {

	public static void main(String[] args){
		//Game game = new Game("Space Adventure", 1920,1080);
	      //game.start();
               
                
        Game c = new Game();
        JFrame frame = new JFrame("Space Adventure");
        frame.add(c);
        frame.setSize(2550,1304);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Music.BACK.loop();
                
	} 
    
    
	
}
