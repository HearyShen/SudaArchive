/*****************************
 *		实验四
 *		Fan GUI Demo
 *		沈家赟
 *		1427405017
 *		2016/5/26
 *****************************/
package fanGUI;

import java.awt.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class FanFrame extends JFrame{
	private static final int DEFAULT_WIDTH = 900;
	private static final int DEFAULT_HEIGHT = 700;
	
	private FanGraphicPanel fgpanel;
	private FanControlPanel fcpanel;
	private FanTimerPanel ftpanel;
	
	FanFrame()
	{
		int frame_x, frame_y;
		this.setTitle("Fan GUI Demo");
		Toolkit kit = Toolkit.getDefaultToolkit();
		this.setSize(FanFrame.DEFAULT_WIDTH, FanFrame.DEFAULT_HEIGHT);
		frame_x = (kit.getScreenSize().width - FanFrame.DEFAULT_WIDTH)/2;
		frame_y = (kit.getScreenSize().height - FanFrame.DEFAULT_HEIGHT)/2;
		this.setLocation(frame_x, frame_y);
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		this.setLayout(new BorderLayout());
		fgpanel = new FanGraphicPanel();
		fcpanel = new FanControlPanel(fgpanel);
		ftpanel = new FanTimerPanel(fgpanel);
		this.add(BorderLayout.CENTER, fgpanel);
		this.add(BorderLayout.SOUTH, fcpanel);
		this.add(BorderLayout.EAST, ftpanel);
		
		this.setVisible(true);
	}
	
	public static void main(String[] args){
		FanFrame fframe = new FanFrame();
	}
}
