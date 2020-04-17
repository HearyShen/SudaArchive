/***********************************************************************
 * 
 * TodoPanel.java  
 * version: beta 1.1  (2016/6/1)
 * author: 沈家赟
 * 		Tab页，待办事项页面。
 * 
 ***********************************************************************/

package adminDBMS;

import java.awt.event.*;
import java.io.*;
import java.sql.*;
import java.util.*;
import javax.swing.*;

class TodoPanel extends JPanel{
	JLabel name_label;
	ScrollTablePane scrolltable;
	JButton refresh;
	QueryAction queryAction;
	JButton excute;
	ExcuteAction excuteAction;
	JButton orderin;
	JButton orderout;
	UpdateAction updateAction;
	
	 Vector<String> vec_attributes;
	 Vector<Vector<String>> vec_rows;
	
	TodoPanel()
	{
		name_label = new JLabel("待处理订单查询");
		scrolltable = new ScrollTablePane();
		queryAction = new QueryAction();
		refresh = new JButton("刷新");
		refresh.addActionListener(queryAction);
		excuteAction = new ExcuteAction();
		excute = new JButton("一键处理");
		excute.addActionListener(excuteAction);
		updateAction = new UpdateAction();
		orderin = new JButton("新增");
		orderin.addActionListener(updateAction);
		orderout = new JButton("删除");
		orderout.addActionListener(updateAction);
		
		
		this.setLayout(null);
		name_label.setBounds(10, 10, name_label.getPreferredSize().width, name_label.getPreferredSize().height);
        this.add(name_label);
        refresh.setBounds(10, 50, refresh.getPreferredSize().width, refresh.getPreferredSize().height);
        this.add(refresh);
        excute.setBounds(10+refresh.getPreferredSize().width+20, 50, excute.getPreferredSize().width, excute.getPreferredSize().height);
        this.add(excute);
        orderin.setBounds(10+refresh.getPreferredSize().width+20+excute.getPreferredSize().width+20, 50, 
        		orderin.getPreferredSize().width, orderin.getPreferredSize().height);
        this.add(orderin);
        orderout.setBounds(10+refresh.getPreferredSize().width+20+excute.getPreferredSize().width+20+orderin.getPreferredSize().width+20, 50, 
        		orderout.getPreferredSize().width, orderout.getPreferredSize().height);
        this.add(orderout);
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
					if( scrolltable.getScrollTablePanefromQuery("SELECT * FROM Orders WHERE OrderStatus = '预订待处理'") == null)		// 调用自定义的getScrollTablePanefromQuery函数，快速由SQL查询获得ScrollTablePane
					{
						JOptionPane.showMessageDialog(null, "失败：未连接数据库！", "刷新失败", JOptionPane.ERROR_MESSAGE);
					}
				} catch (SQLException | IOException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "失败：数据库中无对应数据！", "错误", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				}
				
				//scrolltable.invalidate();
			}
		}
	}
	
	class ExcuteAction implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			//ResultSet orders_todo;
			int i=0, excute_count = 0;
			String[][] orders_list = new String[50][3];		// 因java特性，暂定50行
			try {
				ConnectDB.excuteQuery("SELECT OrderID, Type, Weight FROM Orders WHERE OrderStatus = '预订待处理'");
				i = 0;
				while( ConnectDB.getResultSet().next() )
				{
					orders_list[i][0] = new String( ConnectDB.getResultSet().getString(1) );			// 取Orders结果表中，OrderID列的数值
					orders_list[i][1] =  new String( ConnectDB.getResultSet().getString(2) );		// 取Orders结果表中，Type列的数值
					orders_list[i][2] =  new String( ConnectDB.getResultSet().getString(3) );		// 取Orders结果表中，Weight列的数值
					i++;
				}
				
				//int j=0;
				for( int j=0; j < i; j++)
				{
					ConnectDB.excuteQuery("SELECT Weight FROM Meat WHERE Type="+"'"+orders_list[j][1]+"'");	// 取Meat表中，当前Type对应的Weight
					//ConnectDB.excuteQuery("SELECT Weight FROM Meat WHERE Type = '华中型'");	// 取Meat表中，当前Type对应的Weight
					if( ConnectDB.getResultSet().next())
					{
						int goods_weight = ConnectDB.getResultSet().getInt(1);		// 取Meat结果表中，当前Type对应的Weight列的数值
						if( goods_weight >= Integer.parseInt(orders_list[j][2]) );
						{
							int new_weight = goods_weight - Integer.parseInt(orders_list[j][2]);
							ConnectDB.excuteUpdate("UPDATE Meat SET Weight = "+new_weight+"WHERE Type = "+"'"+orders_list[j][1]+"'");
							ConnectDB.excuteUpdate("UPDATE Orders SET OrderStatus = '购买成功' WHERE OrderID = "+"'"+orders_list[j][0]+"'");
							excute_count++;
						}
					}
				}
				
				scrolltable.getScrollTablePanefromQuery("SELECT * FROM Orders WHERE OrderStatus = '预订待处理'");
				if(i > excute_count)
				{
					JOptionPane.showMessageDialog(null, "已处理"+excute_count+"项订单\n剩余"+(i-excute_count)+"项订单缺少库存，无法处理", 
							"处理订单", JOptionPane.INFORMATION_MESSAGE);
				}
				else if(i == excute_count)
				{
					JOptionPane.showMessageDialog(null, "已处理全部的"+excute_count+"项订单", 
							"处理订单", JOptionPane.INFORMATION_MESSAGE);
				}
				
			}  catch (SQLException e1) {
				// TODO Auto-generated catch block
				JOptionPane.showMessageDialog(null, "错误：SQL语句错误！", 
						"处理订单", JOptionPane.ERROR_MESSAGE);
				e1.printStackTrace();
			} catch (NullPointerException e2) {
				// TODO Auto-generated catch block
				JOptionPane.showMessageDialog(null, "错误：数据库未连接！", 
						"处理订单", JOptionPane.ERROR_MESSAGE);
				e2.printStackTrace();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			
		}
	}
	
	class UpdateAction implements ActionListener
	{
		String act;
		public void actionPerformed(ActionEvent e)
		{
			act = e.getActionCommand();
			if(act.equals("新增"))
			{
				String str_in = JOptionPane.showInputDialog("请输入新增订单信息（订单编号/订单日期/订单状态/账户编号/购买品种/购买重量）：\n（例：O001/2016-6-1/预订待处理/A001/华南型/10）");
				if(str_in == null || str_in.isEmpty()==true)		// 初筛非法值
				{
					return;
				}
				String str_part[] = str_in.split("/");
				String OID = str_part[0];
				String ODate = str_part[1];
				String OStatus = str_part[2];
				String AID = str_part[3];
				String Type = str_part[4];
				int Weight = Integer.parseInt( str_part[5] );
				try {
					ConnectDB.excuteUpdate("INSERT INTO Orders VALUES("+"'"+OID+"'"+","+"'"+ODate+"'"+","+"'"+OStatus+"'"+","+"'"+AID+"'"+","+"'"+Type+"'"+","+Weight+")");
					scrolltable.getScrollTablePanefromQuery("SELECT * FROM Orders WHERE OrderStatus = '预订待处理'");		// 刷新列表
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "失败：插入数据有误（如：编号重复）！", "插入失败", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			else if(act.equals("删除"))
			{
				int select_row = scrolltable.getTable().getSelectedRow();
				String select_ID = scrolltable.getTable().getValueAt(select_row, 0).toString();
				try {
					ConnectDB.excuteUpdate("DELETE FROM Orders WHERE OrderID = "+"'"+select_ID+"'");		// 修改Orders表（删除选中订单）
					scrolltable.getScrollTablePanefromQuery("SELECT * FROM Orders WHERE OrderStatus = '预订待处理'");		// 刷新列表
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