/***********************************************************************
 * 
 * MultiFunctionPanel.java  
 * version: beta 1.1  (2016/6/1)
 * author: 沈家赟
 * 		Tab页，拓展功能页面。
 * 
 ***********************************************************************/

package adminDBMS;

import java.awt.event.*;
import javax.swing.*;

class MultiFunctionPanel extends JPanel{
	JButton button1;
	JButton button2;
	JButton button3;
	FunctionAction fncs;
	MultiFunctionPanel()
	{

		this.setLayout(null);
		fncs = new FunctionAction();
		
		button1 = new JButton("反黄牛系统");
		button1.addActionListener(fncs);
		button1.setSize(120, 100);
		button1.setLocation(10, 10);
		this.add(button1);
		
		button2 = new JButton("检验检疫");
		button2.addActionListener(fncs);
		button2.setSize(120, 100);
		button2.setLocation(10+120+10, 10);
		this.add(button2);
		
		button3 = new JButton("软件更新");
		button3.addActionListener(fncs);
		button3.setSize(120, 100);
		button3.setLocation(10+(120+10)*2, 10);
		this.add(button3);
		
		this.setVisible(true);
	}
	
	class FunctionAction implements ActionListener
	{
		String act;
		public void actionPerformed(ActionEvent e)
		{
			act = e.getActionCommand();
			if(act.equals("反黄牛系统"))
			{
				JOptionPane.showMessageDialog(null, "建设中", "反黄牛系统", JOptionPane.WARNING_MESSAGE);
			}
			if(act.equals("检验检疫"))
			{
				JOptionPane.showMessageDialog(null, "建设中", "检验检疫", JOptionPane.WARNING_MESSAGE);
			}
			if(act.equals("软件更新"))
			{
				JOptionPane.showMessageDialog(null, "建设中", "软件更新", JOptionPane.WARNING_MESSAGE);
			}
		}
	}
}
