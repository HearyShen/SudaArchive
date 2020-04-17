/*****************************
 *		实验四
 *		Fan GUI Demo
 *		沈家赟
 *		1427405017
 *		2016/5/26
 *****************************/
package fanGUI;

import java.awt.event.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class FanControlPanel extends JPanel{
	JButton off= new JButton("Off");
	JButton low = new JButton("Low");
	JButton medium = new JButton("Medium");
	JButton high = new JButton("High");
	JButton help = new JButton("Help");
	FanGraphicPanel fgpanel;
	
	FanControlPanel(FanGraphicPanel ref_fgpanel)		//ref_fgpanel传参，实现ControlPanel对GraphicPanel的控制
	{
		this.add(off);
		this.add(low);
		this.add(medium);
		this.add(high);
		this.add(help);
		
		off.addActionListener(new FanControlActionListener("off"));
		low.addActionListener(new FanControlActionListener("low"));
		medium.addActionListener(new FanControlActionListener("medium"));
		high.addActionListener(new FanControlActionListener("high"));
		help.addActionListener(new FanControlActionListener("help"));
		
		this.fgpanel = ref_fgpanel;
		
		this.setVisible(true);
	}
	
	private class FanControlActionListener implements ActionListener{
		String control_cmd;
		String help_msg = "This is a demo GUI application by Jiayun Shen. \nIt simulates a electrical fan.\n(stuID: 1427405017";
		
		public FanControlActionListener(String cmd)
		{
			control_cmd = cmd;
		}
		
		public void actionPerformed(ActionEvent event)
		{
			if(control_cmd == "off")
			{
				fgpanel.set_repaint_period(0);
				//JOptionPane.showMessageDialog(null, control_cmd, "test", 1);
			}
			else if(control_cmd == "low")
			{
				fgpanel.set_repaint_period(9);
				//JOptionPane.showMessageDialog(null, control_cmd, "test", 1);
			}
			else if(control_cmd == "medium")
			{
				fgpanel.set_repaint_period(3);
				//JOptionPane.showMessageDialog(null, control_cmd, "test", 1);
			}
			else if(control_cmd == "high")
			{
				fgpanel.set_repaint_period(1);
				//JOptionPane.showMessageDialog(null, control_cmd, "test", 1);
			}
			else if(control_cmd == "help")
			{
				JOptionPane.showMessageDialog(null, help_msg, "HELP", 1);
			}
		}
	}
}
