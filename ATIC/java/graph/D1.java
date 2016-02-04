import javax.swing.*;
import java.awt.*;

public class D1 extends JPanel{
    public void paintComponent(Graphics g){
	super.paintComponent(g);
	g.fillRect(0,0,getWidth(),getHeight());
	int rouge = (int)(Math.random()*255);
	int vert = (int)(Math.random()*255);
	int bleu = (int)(Math.random()*255);
	Color randCol = new Color(rouge,vert,bleu);
	g.setColor(randCol);
	g.fillOval(70,70,100,100);
    }

    public static void main(String[] args){
	JFrame cadre = new JFrame();
	JPanel dessin = new D1();
	dessin.setPreferredSize(new Dimension(250,250));
	cadre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	cadre.getContentPane().add(BorderLayout.CENTER, dessin);
	cadre.pack();
	cadre.setVisible(true);
    }
}