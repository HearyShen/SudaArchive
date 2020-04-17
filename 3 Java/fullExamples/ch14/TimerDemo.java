package ch14;

import java.awt.BorderLayout;
import java.awt.event.*;
import java.awt.*;

import javax.swing.*;
class ArcsPanel extends JPanel{
	private static final long serialVersionUID = 1L;
	
	private int StartAg;
	private int step;
	
	public ArcsPanel(int stp){
		StartAg=0;
		step=stp;
	}
	
	public void modiArcs(){
		StartAg=(StartAg+step)%360;
	}
	
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		int xCenter=this.getSize().width/2;
		int yCenter=this.getSize().height/2;
		int radius=(int)(Math.min(getSize().width,getSize().height)*0.4);
		int x=xCenter-radius;
		int y=yCenter-radius;
		g.setColor(Color.BLACK);
		g.fillArc(x,y,2*radius,2*radius,0+StartAg,45);
		g.fillArc(x,y,2*radius,2*radius,90+StartAg,45);
		g.fillArc(x,y,2*radius,2*radius,180+StartAg,45);
		g.fillArc(x,y,2*radius,2*radius,270+StartAg,45);
	}
}

public class TimerDemo extends JApplet implements ActionListener{

	private static final long serialVersionUID = 1L;
	private Timer timer;
	//private Clock pl;
	private ArcsPanel pl;
	public void init(){
		super.init();
		//pl=new Clock(Color.WHITE);
		pl=new ArcsPanel(15);
		getContentPane().add(pl,BorderLayout.CENTER);
		timer=new Timer(200,this);
		timer.start();
	}
	
	public void start(){
		timer.start();
	}
	
	public void stop(){
		timer.stop();
	}	
	
	public void actionPerformed(ActionEvent arg0) {
		pl.modiArcs();
		pl.repaint();
	}

}
