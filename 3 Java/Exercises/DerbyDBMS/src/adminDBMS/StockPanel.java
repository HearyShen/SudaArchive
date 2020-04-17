package adminDBMS;

import java.awt.event.*;
import java.io.*;
import java.sql.*;
import java.util.*;
import javax.swing.*;

import adminDBMS.TodoPanel.ExcuteAction;

public class StockPanel extends JPanel{
	JLabel name_label;
	ScrollTablePane scrolltable;
	JButton refresh;
	QueryAction queryAction;
	JButton kill;
	KillAction killAction;
	UpdateAction updateAction;
	JButton stockin;
	JButton stockout;
	
	 Vector<String> vec_attributes;
	 Vector<Vector<String>> vec_rows;
	
	 StockPanel()
	 {
		 	name_label = new JLabel("商品库存查询");
			scrolltable = new ScrollTablePane();
			queryAction = new QueryAction();
			refresh = new JButton("刷新");
			refresh.addActionListener(queryAction);
			killAction = new KillAction();
			kill = new JButton("杀猪");
			kill.addActionListener(killAction);
			updateAction = new UpdateAction();
			stockin = new JButton("入库");
			stockin.addActionListener(updateAction);
			stockout = new JButton("出库");
			stockout.addActionListener(updateAction);
			
			
			this.setLayout(null);
			name_label.setBounds(10, 10, name_label.getPreferredSize().width, name_label.getPreferredSize().height);
	        this.add(name_label);
	        refresh.setBounds(10, 50, refresh.getPreferredSize().width, refresh.getPreferredSize().height);
	        this.add(refresh);
	        kill.setBounds(10+refresh.getPreferredSize().width+20, 50, kill.getPreferredSize().width, kill.getPreferredSize().height);
	        this.add(kill);
	        stockin.setBounds(10+refresh.getPreferredSize().width+20+kill.getPreferredSize().width+20, 50, stockin.getPreferredSize().width, stockin.getPreferredSize().height);
	        this.add(stockin);
	        stockout.setBounds(10+refresh.getPreferredSize().width+20+kill.getPreferredSize().width+20+stockin.getPreferredSize().width+20, 50, stockout.getPreferredSize().width, stockout.getPreferredSize().height);
	        this.add(stockout);
	        scrolltable.setBounds(10, 100, 770, 510);
			this.add(scrolltable);
			
//			stockin = new JButton("入库");
//			this.add(stockin);
//			
//			stockout = new JButton("出库");
//			this.add(stockout);
			
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
					if( scrolltable.getScrollTablePanefromQuery("SELECT PigID AS 编号, Type AS 品种, Weight AS 重量 FROM Pig") == null)		// 调用自定义的getScrollTablePanefromQuery函数，快速由SQL查询获得ScrollTablePane
					{
						JOptionPane.showMessageDialog(null, "失败：未连接数据库！", "刷新失败", JOptionPane.ERROR_MESSAGE);
					}
				} catch (SQLException | IOException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "失败：数据库中无对应数据！", "错误", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				}
			}
		}
	}
	
	class KillAction implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			int select_row = scrolltable.getTable().getSelectedRow();
			String select_ID = scrolltable.getTable().getValueAt(select_row, 0).toString();
			String select_type = scrolltable.getTable().getValueAt(select_row, 1).toString();
			int select_weight = Integer.parseInt( scrolltable.getTable().getValueAt(select_row, 2).toString() );
			try {
				ConnectDB.excuteQuery("SELECT Weight FROM Meat WHERE TYPE = "+"'"+select_type+"'");
				if(ConnectDB.getResultSet().next())
				{
					int current_weight = ConnectDB.getResultSet().getInt(1);
					current_weight += select_weight;			// 计算累加后的新weight
					ConnectDB.excuteUpdate("UPDATE Meat Set Weight = "+current_weight+"WHERE TYPE = "+"'"+select_type+"'");		// 修改Meat表（累加Weight）
					ConnectDB.excuteUpdate("DELETE FROM Pig WHERE PigID = "+"'"+select_ID+"'");	// 修改Pig表（删除已杀猪）
					scrolltable.getScrollTablePanefromQuery("SELECT * FROM Pig");		// 刷新列表
				}
			} catch (SQLException | IOException e1) {
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
			if(act.equals("入库"))
			{
				String str_in = JOptionPane.showInputDialog("请输入入库生猪信息（编号/类型/重量）：\n（例：P001/华南型/100）");
				if(str_in == null || str_in.isEmpty()==true)		// 初筛非法值
				{
					return;
				}
				String str_part[] = str_in.split("/");
				String PID = str_part[0];
				String PType = str_part[1];
				int PWeight = Integer.parseInt( str_part[2] );
				try {
					ConnectDB.excuteUpdate("INSERT INTO Pig VALUES("+"'"+PID+"'"+","+"'"+PType+"'"+","+PWeight+")");
					scrolltable.getScrollTablePanefromQuery("SELECT PigID AS 编号, Type AS 品种, Weight AS 重量 FROM Pig");		// 刷新列表
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "失败：插入数据有误（如：编号重复）！", "插入失败", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			else if(act.equals("出库"))
			{
				int select_row = scrolltable.getTable().getSelectedRow();
				String select_ID = scrolltable.getTable().getValueAt(select_row, 0).toString();
				try {
					ConnectDB.excuteUpdate("DELETE FROM Pig WHERE PigID = "+"'"+select_ID+"'");		// 修改Pig表（删除出库猪）
					scrolltable.getScrollTablePanefromQuery("SELECT PigID AS 编号, Type AS 品种, Weight AS 重量 FROM Pig");		// 刷新列表
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
