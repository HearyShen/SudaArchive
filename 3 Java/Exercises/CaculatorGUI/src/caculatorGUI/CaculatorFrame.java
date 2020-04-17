/*****************************
 *		实验四
 *		Caculator GUI Demo
 *		沈家赟
 *		1427405017
 *		2016/5/27
 *****************************/
package caculatorGUI;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CaculatorFrame extends JFrame{
	private static final long serialVersionUID = 1L;
	private static final int DEFAULT_WIDTH = 400;
	private static final int DEFAULT_HEIGHT = 500;
	
	private InfoMenu info_menu;
	private Display display;
	private CaculatorButtonPanel cbpanel;
	static String last_cmd;
	private double result_num;
	private String str_help = "Press the buttons to caculate.\neg. N√x, x^N";
	private String str_about = "This is a Caculator GUI Demo by Jiayun Shen.\n(stuID: 1427405017)";
	static Font std_font = new Font("微软雅黑" ,Font.BOLD, 25);
	
	
	public CaculatorFrame()
	{
		int frame_x, frame_y;
		this.setTitle("Caculator GUI Demo");
		Toolkit kit = Toolkit.getDefaultToolkit();
		this.setSize(CaculatorFrame.DEFAULT_WIDTH, CaculatorFrame.DEFAULT_HEIGHT);
		frame_x = (kit.getScreenSize().width - CaculatorFrame.DEFAULT_WIDTH)/2;
		frame_y = (kit.getScreenSize().height - CaculatorFrame.DEFAULT_HEIGHT)/2;
		this.setLocation(frame_x, frame_y);
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		info_menu = new InfoMenu();
		display = new Display();
		cbpanel = new CaculatorButtonPanel();
		
		this.setLayout(null);
		info_menu.setLocation(0, 0);
		display.setLocation(0, 30);
		cbpanel.setLocation(0, 150);
		this.add( info_menu);
		this.add(display);
		this.add(cbpanel);
		
		this.setVisible(true);
	}
	
	@SuppressWarnings("serial")
	class InfoMenu extends JMenuBar{
		JMenuItem help;
		JMenuItem about;
		InfoMenu()
		{
			this.setSize(DEFAULT_WIDTH, 30);
			help = new JMenuItem("Help");
			help.addActionListener(new ActionListener()
					{
						public void actionPerformed(ActionEvent event)
						{
							JOptionPane.showMessageDialog(null, str_help, "Help", 1);
						}
					});
			about = new JMenuItem("About");
			about.addActionListener(new ActionListener()
					{
						public void actionPerformed(ActionEvent event)
						{
							JOptionPane.showMessageDialog(null, str_about, "About", 1);
						}
					});
			
			this.add(help);
			this.add(about);
			this.setVisible(true);
		}
	}
	
	@SuppressWarnings("serial")
	class Display extends JTextArea{
		//Font std_font = new Font("微软雅黑" ,Font.BOLD, 35);
		Display()
		{
			this.setSize(DEFAULT_WIDTH, 120);
			this.setLineWrap(true);
		    this.setWrapStyleWord(true);
			this.setFont(std_font);
			this.setVisible(true);
		}
	}
	
	@SuppressWarnings("serial")
	class CaculatorButtonPanel extends JPanel{
		//Font std_font = new Font("微软雅黑" ,Font.BOLD, 24);
		CaculatorButtonPanel()
		{
			ActionListener num = new NumActionListener();
			ActionListener cmd = new CmdActionListener();
			
			this.setSize(DEFAULT_WIDTH, DEFAULT_WIDTH-80);
			this.setLayout(new GridLayout(5, 4));
			
			this.initButton("C", std_font, cmd);
			this.initButton("<-", std_font, cmd);
			this.initButton("^", std_font, cmd);
			this.initButton("√", std_font, cmd);
			
			this.initButton("7", std_font, num);
			this.initButton( "8", std_font, num);
			this.initButton("9", std_font, num);
			this.initButton( "+", std_font, cmd);
			
			this.initButton("4", std_font, num);
			this.initButton("5", std_font, num);
			this.initButton("6", std_font, num);
			this.initButton("-", std_font, cmd);
			
			this.initButton("1", std_font, num);
			this.initButton("2", std_font, num);
			this.initButton("3", std_font, num);
			this.initButton("×", std_font, cmd);
			
			this.initButton("0", std_font, num);
			this.initButton(".", std_font, num);
			this.initButton("=", std_font, cmd);
			this.initButton("÷", std_font, cmd);
			
			this.setVisible(true);
		}
		
		private void initButton(String name, Font ref_font, ActionListener listener)	// 创建JButton，添加事件监听器，并加入面板
		{
			JButton button = new JButton(name);
			button.setFont(ref_font);
			button.addActionListener(listener);
			this.add(button);
		}
		
		
		
		class NumActionListener implements ActionListener		// 此监听器处理数字符
		{
			public void actionPerformed(ActionEvent event)
			{
				if(last_cmd != null && last_cmd.equals("="))
				{
					display.setText(null);
					last_cmd = null;
				}
				
				if(display.getText() == null)
				{
					display.setText(event.getActionCommand());
				}
				else
				{
					display.setText(display.getText()+event.getActionCommand());
				}
			}
		}
		
		class CmdActionListener implements ActionListener		// 此监听器处理运算符
		{
			public void actionPerformed(ActionEvent event)
			{
				
				if(last_cmd != null && last_cmd.equals("="))
				{
					display.setText(Double.toString(result_num));
				}
				
				if(event.getActionCommand().equals("="))
				{
					String text = display.getText();
					System.out.println("1. 获取计算式："+text);
					System.out.println("2. 抽取运算符："+last_cmd);
					String[] part = text.split("\\" + last_cmd);
					System.out.println("3. 分解：");
					for(String i : part) 
					{
						System.out.println(i);
					}
					
					double left_num = Double.parseDouble(part[0]);
					double right_num = Double.parseDouble(part[1]);
					if(last_cmd.equals("+"))
					{
						result_num = left_num + right_num;
					}
					else if(last_cmd.equals("-"))
					{
						result_num = left_num - right_num;
					}
					else if(last_cmd.equals("×"))
					{
						result_num = left_num * right_num;
					}
					else if(last_cmd.equals("÷"))
					{
						result_num = left_num / right_num;
					}
					else if(last_cmd.equals("^"))		// N次方幂（x^N）
					{
						result_num = Math.pow(left_num, right_num);
					}
					else if(last_cmd.equals("√"))		// N次方根（N√x）
					{
						result_num = Math.pow(right_num, 1/left_num);
					}
					System.out.println("4. 运算结果："+result_num);
					display.setText(display.getText()+" \n "+event.getActionCommand()+Double.toString(result_num));
				}
				else if(event.getActionCommand().equals("Help"))
				{
					JOptionPane.showMessageDialog(null, str_help, "About", 1);
				}
				else if(event.getActionCommand().equals("C"))
				{
					display.setText(null);
				}
				else if(event.getActionCommand().equals("<-"))
				{
					display.setText(display.getText().substring(0, display.getText().length()-1));
				}
				else
				{
					display.setText(display.getText()+event.getActionCommand());
				}
				last_cmd = event.getActionCommand();
			}
		}
	}
	public static void main(String[] args) {
		CaculatorFrame cframe = new CaculatorFrame();

	}

}
