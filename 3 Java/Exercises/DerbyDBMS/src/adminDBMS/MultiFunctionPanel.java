/***********************************************************************
 * 
 * MultiFunctionPanel.java  
 * version: beta 1.1  (2016/6/1)
 * author: ����S
 * 		Tabҳ����չ����ҳ�档
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
		
		button1 = new JButton("����ţϵͳ");
		button1.addActionListener(fncs);
		button1.setSize(120, 100);
		button1.setLocation(10, 10);
		this.add(button1);
		
		button2 = new JButton("�������");
		button2.addActionListener(fncs);
		button2.setSize(120, 100);
		button2.setLocation(10+120+10, 10);
		this.add(button2);
		
		button3 = new JButton("�������");
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
			if(act.equals("����ţϵͳ"))
			{
				JOptionPane.showMessageDialog(null, "������", "����ţϵͳ", JOptionPane.WARNING_MESSAGE);
			}
			if(act.equals("�������"))
			{
				JOptionPane.showMessageDialog(null, "������", "�������", JOptionPane.WARNING_MESSAGE);
			}
			if(act.equals("�������"))
			{
				JOptionPane.showMessageDialog(null, "������", "�������", JOptionPane.WARNING_MESSAGE);
			}
		}
	}
}
