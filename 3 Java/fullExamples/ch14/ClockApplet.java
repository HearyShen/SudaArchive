package ch14;

import javax.swing.*;
import java.awt.*;

public class ClockApplet extends JApplet implements Runnable{
	private static final long serialVersionUID = 1L;
	private Thread thread=null;
	private boolean suspended=false;
	private Clock pl;
	
	public void init(){		
		super.init();
		pl=new Clock(Color.WHITE);
		getContentPane().add(pl,BorderLayout.CENTER);
		thread=new Thread(this);
		thread.start();
	}
	
	
	public void run() {
		while (true){
			pl.repaint();
			try{
				Thread.sleep(1000);
				waitForNotificationToResume();
			}catch(InterruptedException e){
				
			}
		}
	}
	
	private synchronized void waitForNotificationToResume() throws InterruptedException{
		while (suspended)
			wait();
	}
	
	public void stop(){
		suspend();
	}

	private synchronized void suspend() {
		suspended=true;		
	}
	
	public void start(){
		resume();
	}

	private synchronized void resume() {
		if (suspended){
			suspended=false;
			notify();
		}		
	}
	
	public void destory(){
		thread=null;
	}

}
