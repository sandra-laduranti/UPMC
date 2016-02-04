import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class IG3 implements ActionListener{
    private JFrame cadre;

    public void actionPerformed(ActionEvent e){
	cadre.repaint();
    }

    public void go(){
	cadre = new JFrame();
	cadre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	JButton bouton = new JButton("changer");
	bouton.addActionListener(this);
	JPanel dessin = new D1();
	cadre.getContentPane().add(BorderLayout.SOUTH,bouton);
	cadre.getContentPane().add(BorderLayout.CENTER,dessin);
	cadre.setSize(300,300);
	cadre.setVisible(true);
    }

    public static void main(String[] args){
	IG3 ig = new IG3();
	ig.go();
    }
}