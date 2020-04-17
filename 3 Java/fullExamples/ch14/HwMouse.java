package ch14;
import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class HwMouse extends Applet implements MouseListener{
	private static final long serialVersionUID = 1L;
	int mouseX=25;
	int mouseY=25;
	
	public void init()
	{
		addMouseListener(this);
	}
	
	public void paint(Graphics g)
	{
		g.drawString("Hello World",mouseX,mouseY);
	}
	
	public void mousePressed(MouseEvent evt)
	{
		if (evt.isShiftDown()){
			mouseX=evt.getX();
			mouseY=evt.getY();
			repaint();
		}
	}
	
	public void mouseClicked(MouseEvent evt){}
	public void mouseEntered(MouseEvent evt){}
	public void mouseExited(MouseEvent evt){}
	public void mouseReleased(MouseEvent evt){}

}
