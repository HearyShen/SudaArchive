package adminDBMS;

import java.awt.Toolkit;
import java.awt.event.*;
import java.io.*;
import java.sql.*;
import java.util.*;
import javax.swing.*;

public class AccountPanel extends JPanel{
	JLabel name_label;
	ScrollTablePane scrolltable;
	QueryAction queryAction;
	JButton refresh;
	JButton detail;
	UpdateAction updateAction;
	JButton accountin;
	JButton accountout;
	
	 Vector<String> vec_attributes;
	 Vector<Vector<String>> vec_rows;
	
	 AccountPanel()
	 {
		 	name_label = new JLabel("客户管理");
			scrolltable = new ScrollTablePane();
			queryAction = new QueryAction();
			refresh = new JButton("刷新");
			refresh.addActionListener(queryAction);
			detail = new JButton("详情");
			detail.addActionListener(queryAction);
			
			updateAction = new UpdateAction();
			accountin = new JButton("注册");
			accountin.addActionListener(updateAction);
			accountout = new JButton("注销");
			accountout.addActionListener(updateAction);
			
			
			this.setLayout(null);
			name_label.setBounds(10, 10, name_label.getPreferredSize().width, name_label.getPreferredSize().height);
	        this.add(name_label);
	        refresh.setBounds(10, 50, refresh.getPreferredSize().width, refresh.getPreferredSize().height);
	        this.add(refresh);
	        detail.setBounds(10+refresh.getPreferredSize().width+20, 50, detail.getPreferredSize().width, detail.getPreferredSize().height);
	        this.add(detail);
	        accountin.setBounds(10+refresh.getPreferredSize().width+20+detail.getPreferredSize().width+20, 50, 
	        		accountin.getPreferredSize().width, accountin.getPreferredSize().height);
	        this.add(accountin);
	        accountout.setBounds(10+refresh.getPreferredSize().width+20+detail.getPreferredSize().width+20+accountin.getPreferredSize().width+20, 50, 
	        		accountout.getPreferredSize().width, accountout.getPreferredSize().height);
	        this.add(accountout);
	        scrolltable.setBounds(10, 100, 770, 510);
			this.add(scrolltable);
			
			this.setVisible(true);
			
	 }
	
	class QueryAction implements ActionListener
	{
		String act;
		public void actionPerformed(ActionEvent e)
		{
			act = e.getActionCommand();
			if(act.equals("刷新"))
			{
				try {
					if( scrolltable.getScrollTablePanefromQuery("SELECT Account.AccountID AS 用户编号, Name AS 用户名, COUNT(*) AS 购买次数 FROM Account, Orders WHERE Account.AccountID = Orders.AccountID GROUP BY Account.AccountID, Name") == null)		// 调用自定义的getScrollTablePanefromQuery函数，快速由SQL查询获得ScrollTablePane
					{
						JOptionPane.showMessageDialog(null, "失败：未连接数据库！", "刷新失败", JOptionPane.ERROR_MESSAGE);
					}
				} catch (SQLException | IOException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "失败：数据库中无对应数据！", "错误", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				}
			}
			else if(act.equals("详情"))
			{
				int select_row = scrolltable.getTable().getSelectedRow();
				String select_ID = scrolltable.getTable().getValueAt(select_row, 0).toString();
				
				
				JFrame dframe = new JFrame("详情");
				
				Toolkit kit = Toolkit.getDefaultToolkit();
				dframe.setSize(600,  500);
				int frame_x = (kit.getScreenSize().width - 600)/2;
				int frame_y = (kit.getScreenSize().height - 500)/2;
				dframe.setLocation(frame_x, frame_y);
				
				
				
				JPanel dpanel = new JPanel();
				ScrollTablePane detailstpane = new ScrollTablePane();
				try {
					detailstpane.getScrollTablePanefromQuery("SELECT * FROM Orders WHERE AccountID = "+"'"+select_ID+"'");
				} catch (SQLException | IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				dpanel.add(detailstpane);
				dframe.add(dpanel);
				
				dframe.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				dframe.setVisible(true);
			}
		}
	}
	
	class UpdateAction implements ActionListener
	{
		String act;
		public void actionPerformed(ActionEvent e)
		{
			act = e.getActionCommand();
			if(act.equals("注册"))
			{
				String str_in = JOptionPane.showInputDialog("请输入新注册用户信息（账号/姓名/密码）：\n（例：A001/赵一/密码）");
				if(str_in == null || str_in.isEmpty()==true)		// 初筛非法值
				{
					return;
				}
				String str_part[] = str_in.split("/");
				String AID = str_part[0];
				String AName = str_part[1];
				String APassword = str_part[2];
				try {
					ConnectDB.excuteUpdate("INSERT INTO Account VALUES("+"'"+AID+"'"+","+"'"+AName+"'"+","+"'"+APassword+"'"+")");
					scrolltable.getScrollTablePanefromQuery("SELECT Account.AccountID AS 用户账号, Name AS 用户名, COUNT(*) AS 购买次数"
							+ " FROM Account, Orders WHERE Account.AccountID = Orders.AccountID GROUP BY Account.AccountID, Name");		// 刷新列表
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "失败：插入数据有误（如：账号重复）！", "插入失败", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			else if(act.equals("注销"))
			{
				int select_row = scrolltable.getTable().getSelectedRow();
				String select_ID = scrolltable.getTable().getValueAt(select_row, 0).toString();
				try {
					ConnectDB.excuteUpdate("DELETE FROM Account WHERE AccountID = "+"'"+select_ID+"'");		// 修改Account表（注销用户）
					scrolltable.getScrollTablePanefromQuery("SELECT Account.AccountID AS 用户编号, Name AS 用户名, COUNT(*) AS 购买次数 "
							+ "FROM Account, Orders WHERE Account.AccountID = Orders.AccountID GROUP BY Account.AccountID, Name");		// 刷新列表
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		}
		
	}
}
