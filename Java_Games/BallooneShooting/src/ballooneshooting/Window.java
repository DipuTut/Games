package ballooneshooting;

import javax.swing.JFrame;

public class Window {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Combine c = new Combine();
		JFrame f = new JFrame("Cloud Shooting");
		f.add(c);
		f.setResizable(false);
		f.setSize(800,700);
                f.setLocationRelativeTo(null);
		f.setVisible(true);
                Sound.BACK.loop();
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	}

}
