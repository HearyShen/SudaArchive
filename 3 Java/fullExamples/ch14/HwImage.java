package ch14;

import java.applet.*;
import java.awt.*;

public class HwImage extends Applet {
	private static final long serialVersionUID = 1L;
	Image duck;
	AudioClip sound;
	
	public void init()
	{
		System.out.println(this.getCodeBase());
		duck=getImage(getDocumentBase(),"hhw.gif");
		sound=getAudioClip(getDocumentBase(),"spacemusic.au");
	}
	public void paint(Graphics g)
	{
		g.drawImage(duck,10,10,this);
	}
	public void start()
	{
		sound.loop();
	}
	public void stop()
	{
		sound.stop();
	}
}