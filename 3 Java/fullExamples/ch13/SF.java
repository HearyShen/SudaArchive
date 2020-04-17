package ch13;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.JFrame;
import javax.swing.JPanel;


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
public class SF extends JFrame{
	private static final long serialVersionUID = 1L;
	private ArcsPanel pl=new ArcsPanel(15);
	public SF()
	{
		setTitle("ShowArcs");
		getContentPane().add(pl);
		Timer tm=new Timer();
		TimerTask task=new TimerTask(){
			public void run(){
				pl.modiArcs();
				pl.repaint();
			}
		};
		tm.schedule(task,10,100);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(200,300);
		setVisible(true);
	}
	public static void main(String[] args)
	{
		new SF();
	}
}
