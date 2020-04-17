/*****************************
 *		实验四
 *		Fan GUI Demo
 *		沈家赟
 *		1427405017
 *		2016/5/26
 *****************************/
package fanGUI;

import java.awt.*;
import java.util.Timer;
import java.util.TimerTask;
import javax.swing.*;

@SuppressWarnings("serial")
public class FanGraphicPanel extends JPanel{
	int init_angle = 30;
	int repaint_period = 0;
	
	static FanGraphicPanel fgpanel;
	static Timer timer;
	
	FanGraphicPanel()
	{
		this.setVisible(true);
	}
	 
	public void paint(Graphics p) {   
		super.paint(p);  
		int x_1 = getWidth() / 2;    
		int y_1 = getHeight() / 2;    
		int a = (int) (Math.min(getWidth(), getHeight() * 0.4));   
		int x = x_1 - a;   
		int y = y_1 - a;
		
		p.setColor(Color.darkGray);    
		p.fillArc(x, y, 2 * a, 2 * a, init_angle, 60);   
		p.setColor(Color.gray);    
		p.fillArc(x, y, 2 * a, 2 * a, init_angle + 120, 60);   
		p.setColor(Color.lightGray);    
		p.fillArc(x, y, 2 * a, 2 * a, init_angle + 240, 60);
	}
	
	public void set_repaint_period(int new_period)			//通过调整刷新率来实现风扇转速快慢，相比于调整角度控制转速，不易引起视觉卡顿感
	{
		if(timer  != null)
		{
			timer.cancel();
		}
		if(new_period == 0)
		{
			return;
		}
		this.repaint_period = new_period;
		timer = new Timer();
		timer.schedule(new RepaintTask(), 0, repaint_period);
	}
	
	class RepaintTask extends TimerTask
	{
		public void run()
		{
			init_angle -= 2;    
			repaint();
		}
	}
	
}
