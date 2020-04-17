package ch8;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class Calculator extends JFrame implements ActionListener{
	static String[] lbl={"7","8","9","+",
					"4","5","6","-",
					"1","2","3","*",
					"0",".","=","/"};
	JTextField jfl;
	
	double op1,op2;
	char op;
	
	
	public Calculator(){
		setSize(200,200);
		Dimension dm=Toolkit.getDefaultToolkit().getScreenSize();
		int x,y;
		x=(dm.width-getWidth())/2;
		y=(dm.height-getHeight())/2;
		setLocation(x,y);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		jfl=new JTextField();
		JPanel jpl=new JPanel();
		Container con=getContentPane();
		con.add(jfl,BorderLayout.NORTH);
		con.add(jpl,BorderLayout.CENTER);
		
		//--≤ºæ÷√Ê∞Â
		GridLayout gl=new GridLayout(4,4);
		jpl.setLayout(gl);
		JButton btn;
		for (int i=0;i<lbl.length;i++)
		{
			btn=new JButton(lbl[i]);
			jpl.add(btn,i);
			btn.addActionListener(this);
		}
		setVisible(true);
		
		op='#';
		
	}
	
	public static void main(String[] args){
		new Calculator();
	}
	
	public double operation()
	{
		double tmp=0;
		switch(op)
		{
		case '+': tmp=op1+op2; break;
		case '-': tmp=op1-op2; break;
		case '*': tmp=op1*op2; break;
		case '/': tmp=op1/op2;
		}
		return tmp;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		String tmp=e.getActionCommand();
		if (Character.isDigit(tmp.charAt(0)) || tmp.equals("."))
			jfl.setText(jfl.getText()+tmp);
		else if (tmp.equals("=")==false)
		{
			if (op=='#')
				op1=Double.parseDouble(jfl.getText());
			else
			{
				op2=Double.parseDouble(jfl.getText());
				op1=operation();
			}
			op=tmp.charAt(0);
			jfl.setText("");
		}
		else
		{
			op2=Double.parseDouble(jfl.getText());
			jfl.setText(operation()+"");
			op='#';
		}
	}
}
