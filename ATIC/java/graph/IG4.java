import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class IG4{
    private JFrame cadre;
    private JLabel etiquette;

    class boutonColListener implements ActionListener{
	public void actionPerformed(ActionEvent e){
	    cadre.repaint();
	}
    }

    class boutonTexteListener implements ActionListener{
	public void actionPerformed(ActionEvent e){
	    etiquette.setText("change etiquette");
	}
    }

   public void go(){
       cadre = new JFrame();
       etiquette = new JLabel("truc");
	cadre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
	JButton bouton = new JButton("changer");
	bouton.addActionListener(new boutonColListener());
	JButton bouton2 = new JButton();
	bouton2.addActionListener(this.new boutonTexteListener());
	etiquette = new JLabel("le texte");
	JPanel dessin = new D1();
	cadre.getContentPane().add(BorderLayout.SOUTH,bouton);
	cadre.getContentPane().add(BorderLayout.EAST,bouton2);
	cadre.getContentPane().add(BorderLayout.WEST,etiquette);
	cadre.getContentPane().add(BorderLayout.CENTER,dessin);
	cadre.setSize(300,300);
	cadre.setVisible(true);
    }

    public static void main(String[] args){
	IG4 ig = new IG4();
	ig.go();
    }
}
