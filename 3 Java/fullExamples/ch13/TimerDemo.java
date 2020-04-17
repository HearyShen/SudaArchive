package ch13;

import java.awt.*;
import javax.swing.*;
import java.util.Timer;
import java.util.TimerTask;

class Digit extends JPanel{
	private static final long serialVersionUID = 1L;
	private int dig;
	private int MDig;
	
	public Digit(int d){
		MDig=dig=d;
	}
	
	public void modiDigit(){
		if (dig==0)
			dig=MDig-1;
		else
			dig--;
	}
	
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		g.setColor(Color.BLACK);
		Font ft=new Font("宋体",Font.BOLD,20);
		g.setFont(ft);
		g.drawString(String.valueOf(dig),15,15);
	}
	
	public Dimension getPreferredSize(){
		return new Dimension(40, 40);
	}
}

class Light extends JPanel {
	private static final long serialVersionUID = 1L;
	private boolean red;
	private boolean yellow;
	private boolean green;

	public Light() {
		red = false;
		yellow = false;
		green = false;
	}

	public void turnOnRed() {
		red = true;
		yellow = false;
		green = false;
		repaint();
	}

	public void turnOnYellow() {
		red = false;
		yellow = true;
		green = false;
		repaint();
	}

	public void turnOnGreen() {
		red = false;
		yellow = false;
		green = true;
		repaint();
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		if (red) {
			g.setColor(Color.RED);
			g.fillOval(10, 10, 20, 20);
			g.setColor(Color.BLACK);
			g.drawOval(10, 35, 20, 20);
			g.drawOval(10, 60, 20, 20);
			g.drawRect(5, 5, 30, 80);
		} else if (yellow) {
			g.setColor(Color.YELLOW);
			g.fillOval(10, 35, 20, 20);
			g.setColor(Color.BLACK);
			g.drawOval(10, 10, 20, 20);
			g.drawOval(10, 60, 20, 20);
			g.drawRect(5, 5, 30, 80);
		} else if (green) {
			g.setColor(Color.GREEN);
			g.fillOval(10, 60, 20, 20);
			g.setColor(Color.BLACK);
			g.drawOval(10, 35, 20, 20);
			g.drawOval(10, 10, 20, 20);
			g.drawRect(5, 5, 30, 80);
		} else {
			g.setColor(Color.BLACK);
			g.drawOval(10, 10, 20, 20);
			g.drawOval(10, 35, 20, 20);
			g.drawOval(10, 60, 20, 20);
			g.drawRect(5, 5, 30, 80);
		}
	}

	public Dimension getPreferredSize() {
		return new Dimension(40, 90);
	}
}

public class TimerDemo extends JFrame {
	private static final long serialVersionUID = 1L;
	private Light light;	
	private int flag=0;
	private Digit d;
	
	public TimerDemo() {
		super("交通路灯");
		JPanel p1 = new JPanel();
		light = new Light();
		p1.add(light);
		this.getContentPane().add(p1, BorderLayout.CENTER);
		d=new Digit(5);
		p1=new JPanel();
		p1.add(d);
		this.getContentPane().add(p1, BorderLayout.SOUTH);
		
		Timer timer=new Timer(true);
		TimerTask task=new TimerTask(){
			public void run() {
				flag++;
				if (flag%3==0)
					light.turnOnRed();
				else if (flag%3==1)
					light.turnOnYellow();
				else
					light.turnOnGreen();
			}
		};
		timer.schedule(task,10,5000);
		
		Timer t2=new Timer(true);
		TimerTask t=new TimerTask(){
			public void run(){
				d.modiDigit();
				d.repaint();
			}
		};
		t2.schedule(t,10,1000);
		
		this.setSize(250, 180);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	public static void main(String[] arg) {
		new TimerDemo();
	}
}
