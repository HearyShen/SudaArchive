/***********************************************************************
 * 
 * GoodsPanel.java  
 * version: beta 1.1  (2016/6/1)
 * author: ����S
 * 		Tabҳ����������ҳ�档
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
		name_label = new JLabel("������Ʒ��ѯ");
		scrolltable = new ScrollTablePane();
		queryAction = new QueryAction();
		refresh = new JButton("ˢ��");
		refresh.addActionListener(queryAction);
		updateAction = new UpdateAction();
		goodsin = new JButton("����");
		goodsin.addActionListener(updateAction);
		goodsout = new JButton("�¼�");
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
			if(act.equals("ˢ��"))
			{
				try {
					if( scrolltable.getScrollTablePanefromQuery("SELECT Type AS Ʒ��, Weight AS ���� FROM Meat") == null)		// �����Զ����getScrollTablePanefromQuery������������SQL��ѯ���ScrollTablePane
					{
						JOptionPane.showMessageDialog(null, "ʧ�ܣ�δ�������ݿ⣡", "ˢ��ʧ��", JOptionPane.ERROR_MESSAGE);
					}
				} catch (SQLException | IOException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "ʧ�ܣ����ݿ����޶�Ӧ���ݣ�", "����", JOptionPane.ERROR_MESSAGE);
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
			if(act.equals("����"))
			{
				String str_in = JOptionPane.showInputDialog("����������������Ϣ��Ʒ��/��������\n������������/10��");
				if(str_in == null || str_in.isEmpty()==true)		// ��ɸ�Ƿ�ֵ
				{
					return;
				}
				String str_part[] = str_in.split("/");
				String Type = str_part[0];
				int Weight = Integer.parseInt( str_part[1] );
				try {
					ConnectDB.excuteUpdate("INSERT INTO Meat VALUES("+"'"+Type+"'"+","+Weight+")");
					scrolltable.getScrollTablePanefromQuery("SELECT Type AS Ʒ��, Weight AS ���� FROM Meat");		// ˢ���б�
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "ʧ�ܣ��������������磺����ظ�����", "����ʧ��", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			else if(act.equals("�¼�"))
			{
				int select_row = scrolltable.getTable().getSelectedRow();
				String select_Type = scrolltable.getTable().getValueAt(select_row, 0).toString();
				try {
					ConnectDB.excuteUpdate("DELETE FROM Meat WHERE Type = "+"'"+select_Type+"'");		// �޸�Meat��ɾ��ѡ��Ʒ�֣�
					scrolltable.getScrollTablePanefromQuery("SELECT Type AS Ʒ��, Weight AS ���� FROM Meat");		// ˢ���б�
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