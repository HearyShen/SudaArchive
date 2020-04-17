package ch14;

import java.applet.Applet;
import java.awt.event.*;
import java.awt.*;

public class MouseMotionTest extends Applet implements MouseMotionListener,
	MouseListener{
	private Point start;
	private Point endPoint;
	
	public void init(){
		start=new Point(0,0);
		endPoint=new Point(0,0);
		this.addMouseListener(this);
		this.addMouseMotionListener(this);		
	}
	
	public void draw(){
		Graphics g=this.getGraphics();
		g.drawLine(start.x,start.y,endPoint.x,endPoint.y);
	}
		
	public void mouseDragged(MouseEvent arg0) {
		// TODO Auto-generated method stub
	}

	public void mouseMoved(MouseEvent arg0) {
		// TODO Auto-generated method stub		
	}

	public void mouseClicked(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	public void mouseEntered(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	public void mouseExited(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	public void mousePressed(MouseEvent arg0) {
		// TODO Auto-generated method stub
		endPoint=arg0.getPoint();
		draw();
	}

	public void mouseReleased(MouseEvent arg0) {
		// TODO Auto-generated method stub
		start=arg0.getPoint();
	}

}
