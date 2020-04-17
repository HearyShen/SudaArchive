package adminDBMS;

import java.awt.Font;
import java.awt.HeadlessException;
import java.awt.Toolkit;
import java.awt.event.*;
import java.io.*;
import java.sql.*;
import javax.swing.*;

public class TopMenuBar extends JMenuBar{
	JMenu m_start;
	JMenuItem mi_connect;
	JMenuItem mi_disconnect;
	JMenuItem mi_revise;
	JMenuItem mi_dbhelp;
	DBAction db;
	
	JMenu m_advance;
	JMenuItem mi_initDB;
	JMenuItem mi_dropall;
	JMenuItem mi_adhelp;
	AdvanceAction ad;
	
	JMenu m_about;
	JMenuItem mi_author;
	JMenuItem mi_version;
	InfoAction info;
	
	TopMenuBar()
	{
		UIManager.put("Menu.font", AdminFrame.std_font);
		UIManager.put("MenuItem.font", AdminFrame.std_font);
		UIManager.put("OptionPane.font", AdminFrame.std_font);

		/* Menu: 数据库及其菜单项 */
		db = new DBAction();
		m_start = new JMenu("开始");
		mi_connect = initMenuItem(m_start, "连接", db);
		mi_disconnect = initMenuItem(m_start, "断开连接", db);
		mi_revise = initMenuItem(m_start, "编辑连接", db);
		mi_dbhelp = initMenuItem(m_start, "帮助", db);
		mi_disconnect.setVisible(false);
		this.add(m_start);
		
		m_start.setVisible(true);
		
		
		/* Menu: 数据库高级操作及其菜单项 */
		ad = new AdvanceAction();
		m_advance = new JMenu("高级");
		mi_initDB = initMenuItem(m_advance, "初始化", ad);
		mi_dropall = initMenuItem(m_advance, "清空", ad);
		mi_adhelp = initMenuItem(m_advance, "帮助", ad);
		this.add(m_advance);
		
		m_start.setVisible(true);
		
		
		/* Menu: 关于及其菜单项 */
		info = new InfoAction();
		m_about = new JMenu("关于");
		mi_author = initMenuItem(m_about, "作者", info);
		mi_version = initMenuItem(m_about, "版本", info);
		this.add(m_about);
		
		m_about.setVisible(true);
		
	}
	
	
	/* API: initMenuItem  创建JMenuItem实例并返回，添加事件监听器，并加入JMenu */
	private JMenuItem initMenuItem(JMenu menu, String name, ActionListener listener)	
	{
		JMenuItem mitem = new JMenuItem(name);
		mitem.addActionListener(listener);
		menu.add(mitem);
		
		return mitem;
	}
	
	/* DBAction: 数据库菜单的菜单项的事件处理 */
	protected class DBAction implements ActionListener
	{
		String act;
		public void actionPerformed(ActionEvent e)
		{
			act = e.getActionCommand();
			if(act.equals("连接"))
			{
				try{
					ConnectDB.conn= ConnectDB.openConnection();
					mi_disconnect.setVisible(true);
					mi_connect.setVisible(false);
				}
				catch(SQLException sql_ex){
					JOptionPane.showMessageDialog(null, "异常：数据库访问异常！请检查Server是否已经启动。", 
							"连接失败", JOptionPane.ERROR_MESSAGE);
					//System.exit(0);
				}
				catch(IOException io_ex){
					JOptionPane.showMessageDialog(null, "异常：数据库IO异常！", 
							"连接失败", JOptionPane.ERROR_MESSAGE);
				}
				
				try {
					JOptionPane.showMessageDialog(null, "数据库已连接！用户名："
				 + ConnectDB.conn.getMetaData().getUserName(), "连接", JOptionPane.INFORMATION_MESSAGE);
				} catch (HeadlessException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				
			}
			else if(act.equals("断开连接"))
			{
				if( ConnectDB.closeConnection())
				{
					JOptionPane.showMessageDialog(null, "成功：数据库已断开连接", "断开连接", JOptionPane.INFORMATION_MESSAGE);
					mi_connect.setVisible(true);
					mi_disconnect.setVisible(false);
				}
				else
				{
					JOptionPane.showMessageDialog(null, "失败：数据库无法断开连接", "断开连接", JOptionPane.ERROR_MESSAGE);
				}

			}
			else if(act.equals("编辑连接"))
			{
				JFrame dframe = new JFrame("编辑数据库连接");
				
				Toolkit kit = Toolkit.getDefaultToolkit();
				dframe.setSize(500,  400);
				int frame_x = (kit.getScreenSize().width - 500)/2;
				int frame_y = (kit.getScreenSize().height - 400)/2;
				dframe.setLocation(frame_x, frame_y);
				
				JPanel dpanel = new JPanel();
				dpanel.setLayout(null);
				JLabel l_url = new JLabel("url:");
				JTextField url = new JTextField();
				url.setText(ConnectDB.url);
				JLabel l_user = new JLabel("username:");
				JTextField user = new JTextField();
				user.setText(ConnectDB.username);
				JLabel l_password = new JLabel("password:");
				JTextField password = new JTextField();
				password.setText(ConnectDB.password);
				l_url.setBounds(10, 15, l_url.getPreferredSize().width, l_url.getPreferredSize().height);
				url.setBounds(20, 15+l_url.getPreferredSize().height+10, 350, url.getPreferredSize().height);
				l_user.setBounds(10, 15+l_url.getPreferredSize().height+10+url.getPreferredSize().height+10,
						l_user.getPreferredSize().width, l_user.getPreferredSize().height);
				user.setBounds(20, 15+l_url.getPreferredSize().height+10+url.getPreferredSize().height+10+ l_user.getPreferredSize().height+10, 
						100, user.getPreferredSize().height);
				l_password.setBounds(10, 15+l_url.getPreferredSize().height+10+url.getPreferredSize().height+10+ l_user.getPreferredSize().height+10+user.getPreferredSize().height+10,
						l_password.getPreferredSize().width, l_password.getPreferredSize().height);
				password.setBounds(20, 15+l_url.getPreferredSize().height+10+url.getPreferredSize().height+10+ l_user.getPreferredSize().height+10+user.getPreferredSize().height+10+l_password.getPreferredSize().height+10, 
						100, password.getPreferredSize().height);
				dpanel.add(l_url);
				dpanel.add(url);
				dpanel.add(l_user);
				dpanel.add(user);
				dpanel.add(l_password);
				dpanel.add(password);
				dframe.add(dpanel);
				
				JButton save = new JButton("保存");
				save.addActionListener(new ActionListener(){
					public void actionPerformed(ActionEvent e)
					{
						ConnectDB.url = url.getText();
						ConnectDB.username = user.getText();
						ConnectDB.password = password.getText();
					}
				});
				save.setBounds(50, 15+l_url.getPreferredSize().height+10+url.getPreferredSize().height+10+ l_user.getPreferredSize().height+10+user.getPreferredSize().height+10+l_password.getPreferredSize().height+10+password.getPreferredSize().height+20, 
						save.getPreferredSize().width, save.getPreferredSize().height);
				dpanel.add(save);
				dframe.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				dframe.setVisible(true);
			}
			else if(act.equals("帮助"))
			{
				JOptionPane.showMessageDialog(null, "请点击连接后使用！\n本数据库管理系统基于Apache Derby Database( v10.11 )", "数据库帮助", 
						JOptionPane.INFORMATION_MESSAGE);
			}
			
		}
	}
	
	
	/* AdvanceAction: 关于菜单的菜单项的事件处理 */	
	class AdvanceAction implements ActionListener
	{
		String act;
		public void actionPerformed(ActionEvent e)
		{
			act = e.getActionCommand();
			if(act.equals("初始化"))
			{
				int op = JOptionPane.showConfirmDialog(null, "确认要初始化数据库？", "初始化", JOptionPane.OK_CANCEL_OPTION, JOptionPane.WARNING_MESSAGE);
				if(op == JOptionPane.OK_OPTION)
				{
					try {
						ConnectDB.initDB();
					} catch ( IOException e1) {
						e1.printStackTrace();
						JOptionPane.showMessageDialog(null, "失败：请先清空数据库！", "错误", JOptionPane.ERROR_MESSAGE);
					} catch(NullPointerException e2){
						JOptionPane.showMessageDialog(null, "失败：数据库未连接！", "错误", JOptionPane.ERROR_MESSAGE);
					}
				}
			}
			else if(act.equals("清空"))
			{
				int op = JOptionPane.showConfirmDialog(null, "确认要清空数据库？", "清空", JOptionPane.OK_CANCEL_OPTION, JOptionPane.WARNING_MESSAGE);
				if(op == JOptionPane.OK_OPTION)
				{
					try {
						ConnectDB.deleteDB();
					} /*catch (SQLException e1) {
						JOptionPane.showMessageDialog(null, "失败：数据库已清空！", "错误", JOptionPane.ERROR_MESSAGE);
						e1.printStackTrace();
					} */catch(NullPointerException e2){
						JOptionPane.showMessageDialog(null, "失败：数据库未连接！", "错误", JOptionPane.ERROR_MESSAGE);
					}
				}
			}
			else if(act.equals("帮助"))
			{
				JOptionPane.showMessageDialog(null, "数据库高级操作用于清空及初始化。\n注意：初始化须在清空后执行！", "帮助", JOptionPane.INFORMATION_MESSAGE);
			}
		}
	}
	
	
	/* InfoAction: 关于菜单的菜单项的事件处理 */
	class InfoAction implements ActionListener
	{
		String act;
		public void actionPerformed(ActionEvent e)
		{
			act = e.getActionCommand();
			if(act.equals("作者"))
				JOptionPane.showMessageDialog(null, "作者：沈家赟", "作者", 1);
			else if(act.equals("版本"))
				JOptionPane.showMessageDialog(null, "智能养猪数据库管理系统 - 管理端( alpha v0.1 )", "版本", 1);
		}
	}
}
