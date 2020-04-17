/***********************************************************************
 * 
 * GoodsPanel.java  
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

import adminDBMS.DonePanel.UpdateAction;

class GoodsPanel extends JPanel{
	JLabel name_label;
	ScrollTablePane scrolltable;
	JButton refresh;
	QueryAction queryAction;
	JButton goodsin;
	JButton goodsout;
	UpdateAction updateAction;
	
	 Vector<String> vec_attributes;
	 Vector<Vector<String>> vec_rows;
	
	GoodsPanel()
	{
		name_label = new JLabel("可售商品查询");
		scrolltable = new ScrollTablePane();
		queryAction = new QueryAction();
		refresh = new JButton("刷新");
		refresh.addActionListener(queryAction);
		updateAction = new UpdateAction();
		goodsin = new JButton("上新");
		goodsin.addActionListener(updateAction);
		goodsout = new JButton("下架");
		goodsout.addActionListener(updateAction);
		
		
		this.setLayout(null);
		name_label.setBounds(10, 10, name_label.getPreferredSize().width, name_label.getPreferredSize().height);
        this.add(name_label);
        refresh.setBounds(10, 50, refresh.getPreferredSize().width, refresh.getPreferredSize().height);
        this.add(refresh);
        goodsin.setBounds(10+refresh.getPreferredSize().width+20, 50, 
        		goodsin.getPreferredSize().width, goodsin.getPreferredSize().height);
        this.add(goodsin);
        goodsout.setBounds(10+refresh.getPreferredSize().width+20+goodsin.getPreferredSize().width+20, 50, 
        		goodsout.getPreferredSize().width, goodsout.getPreferredSize().height);
        this.add(goodsout);
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
					if( scrolltable.getScrollTablePanefromQuery("SELECT Type AS 品种, Weight AS 重量 FROM Meat") == null)		// 调用自定义的getScrollTablePanefromQuery函数，快速由SQL查询获得ScrollTablePane
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
	
	class UpdateAction implements ActionListener
	{
		String act;
		public void actionPerformed(ActionEvent e)
		{
			act = e.getActionCommand();
			if(act.equals("上新"))
			{
				String str_in = JOptionPane.showInputDialog("请输入新增订单信息（品种/重量）：\n（例：华南型/10）");
				if(str_in == null || str_in.isEmpty()==true)		// 初筛非法值
				{
					return;
				}
				String str_part[] = str_in.split("/");
				String Type = str_part[0];
				int Weight = Integer.parseInt( str_part[1] );
				try {
					ConnectDB.excuteUpdate("INSERT INTO Meat VALUES("+"'"+Type+"'"+","+Weight+")");
					scrolltable.getScrollTablePanefromQuery("SELECT Type AS 品种, Weight AS 重量 FROM Meat");		// 刷新列表
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "失败：插入数据有误（如：编号重复）！", "插入失败", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			else if(act.equals("下架"))
			{
				int select_row = scrolltable.getTable().getSelectedRow();
				String select_Type = scrolltable.getTable().getValueAt(select_row, 0).toString();
				try {
					ConnectDB.excuteUpdate("DELETE FROM Meat WHERE Type = "+"'"+select_Type+"'");		// 修改Meat表（删除选中品种）
					scrolltable.getScrollTablePanefromQuery("SELECT Type AS 品种, Weight AS 重量 FROM Meat");		// 刷新列表
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