/*****************************
 *		实验四
 *		Fan GUI Demo
 *		沈家赟
 *		1427405017
 *		2016/5/26
 *****************************/
package fanGUI;

import java.awt.*;
import java.awt.event.*;
import java.util.Timer;
import java.util.TimerTask;
import javax.swing.*;

@SuppressWarnings("serial")
public class FanTimerPanel extends JPanel{
	static Timer timer_stop;
	FanGraphicPanel fgpanel;
	JLabel timer_label;
	JSlider timer_bar;
	JButton timer_start = new JButton("Start");
	int count_down;
	
	FanTimerPanel(FanGraphicPanel ref_fgpanel)
	{
		fgpanel = ref_fgpanel;
		timer_label = new JLabel("Timer(s)");
		timer_bar = new JSlider(JSlider.VERTICAL, 0, 120, 0);
		timer_bar.setMajorTickSpacing(20);
		timer_bar.setMinorTickSpacing(5);
		timer_bar.setPaintTicks(true);
		timer_bar.setSnapToTicks(true);
		timer_bar.setPaintLabels(true);
		//timer_bar.addChangeListener(new TimerStopAction());
		timer_start.addActionListener(new TimerStopAction());
		this.setLayout(new BorderLayout());
		this.add(BorderLayout.NORTH, timer_label);
		this.add(BorderLayout.WEST, timer_bar);
		this.add(BorderLayout.SOUTH, timer_start);
		
		this.setVisible(true);
	}
	
	class TimerStopAction implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent e) {
			count_down = timer_bar.getValue() * 1000;
			if(timer_stop != null)
			{
				timer_stop.cancel();
			}
			timer_stop = new Timer();
			timer_stop.schedule(new TimerStopTask(), count_down);
			JOptionPane.showMessageDialog(null, "The fan will stop after "+count_down/1000+"sec", "Timer", 1);
			//System.out.println("The fan will stop after "+count_down/1000+"sec");
		}
	}
	
	class TimerStopTask extends TimerTask{
		public void run()
		{
			fgpanel.set_repaint_period(0);
		}
	}

}
