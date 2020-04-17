package GUI;
import java.awt.*;

import javax.swing.*;

import java.awt.event.*;

public class EventDemo  extends JFrame implements ActionListener{
	JPanel jpl;
	JButton jbtRed,jbtYellow,jbtGreen;
	
	//=========构造函数
	public EventDemo()
	{
		jpl=new JPanel();
		jbtRed=new JButton("红色");
		jbtYellow=new JButton("黄色");
		jbtGreen=new JButton("绿色");
		JPanel tmp=new JPanel();
		Container c=this.getContentPane();
		jpl.setBackground(Color.BLACK);
		c.add(jpl,BorderLayout.CENTER);
		c.add(tmp,BorderLayout.SOUTH);
		tmp.add(jbtRed);
		tmp.add(jbtGreen);
		tmp.add(jbtYellow);
		this.setSize(300,200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
		
		jbtRed.addActionListener(this);
		jbtYellow.addActionListener(this);
		jbtGreen.addActionListener(this);
		
	}
	
	//=================数据处理函数
	public static void main(String[] args){
		new EventDemo();
	}
	
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		String cmd=e.getActionCommand();
		if (cmd.equals("红色"))
			jpl.setBackground(Color.RED);
		else if (cmd.equals("黄色"))
			jpl.setBackground(Color.YELLOW);
		else if (cmd.equals("绿色"))
			jpl.setBackground(Color.GREEN);
	}
}




