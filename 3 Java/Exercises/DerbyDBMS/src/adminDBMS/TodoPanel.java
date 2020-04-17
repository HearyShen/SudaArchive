/***********************************************************************
 * 
 * TodoPanel.java  
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
		name_label = new JLabel("����������ѯ");
		scrolltable = new ScrollTablePane();
		queryAction = new QueryAction();
		refresh = new JButton("ˢ��");
		refresh.addActionListener(queryAction);
		excuteAction = new ExcuteAction();
		excute = new JButton("һ������");
		excute.addActionListener(excuteAction);
		updateAction = new UpdateAction();
		orderin = new JButton("����");
		orderin.addActionListener(updateAction);
		orderout = new JButton("ɾ��");
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
			if(act.equals("ˢ��"))
			{
				try {
					if( scrolltable.getScrollTablePanefromQuery("SELECT * FROM Orders WHERE OrderStatus = 'Ԥ��������'") == null)		// �����Զ����getScrollTablePanefromQuery������������SQL��ѯ���ScrollTablePane
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
	
	class ExcuteAction implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			//ResultSet orders_todo;
			int i=0, excute_count = 0;
			String[][] orders_list = new String[50][3];		// ��java���ԣ��ݶ�50��
			try {
				ConnectDB.excuteQuery("SELECT OrderID, Type, Weight FROM Orders WHERE OrderStatus = 'Ԥ��������'");
				i = 0;
				while( ConnectDB.getResultSet().next() )
				{
					orders_list[i][0] = new String( ConnectDB.getResultSet().getString(1) );			// ȡOrders������У�OrderID�е���ֵ
					orders_list[i][1] =  new String( ConnectDB.getResultSet().getString(2) );		// ȡOrders������У�Type�е���ֵ
					orders_list[i][2] =  new String( ConnectDB.getResultSet().getString(3) );		// ȡOrders������У�Weight�е���ֵ
					i++;
				}
				
				//int j=0;
				for( int j=0; j < i; j++)
				{
					ConnectDB.excuteQuery("SELECT Weight FROM Meat WHERE Type="+"'"+orders_list[j][1]+"'");	// ȡMeat���У���ǰType��Ӧ��Weight
					//ConnectDB.excuteQuery("SELECT Weight FROM Meat WHERE Type = '������'");	// ȡMeat���У���ǰType��Ӧ��Weight
					if( ConnectDB.getResultSet().next())
					{
						int goods_weight = ConnectDB.getResultSet().getInt(1);		// ȡMeat������У���ǰType��Ӧ��Weight�е���ֵ
						if( goods_weight >= Integer.parseInt(orders_list[j][2]) );
						{
							int new_weight = goods_weight - Integer.parseInt(orders_list[j][2]);
							ConnectDB.excuteUpdate("UPDATE Meat SET Weight = "+new_weight+"WHERE Type = "+"'"+orders_list[j][1]+"'");
							ConnectDB.excuteUpdate("UPDATE Orders SET OrderStatus = '����ɹ�' WHERE OrderID = "+"'"+orders_list[j][0]+"'");
							excute_count++;
						}
					}
				}
				
				scrolltable.getScrollTablePanefromQuery("SELECT * FROM Orders WHERE OrderStatus = 'Ԥ��������'");
				if(i > excute_count)
				{
					JOptionPane.showMessageDialog(null, "�Ѵ���"+excute_count+"���\nʣ��"+(i-excute_count)+"���ȱ�ٿ�棬�޷�����", 
							"������", JOptionPane.INFORMATION_MESSAGE);
				}
				else if(i == excute_count)
				{
					JOptionPane.showMessageDialog(null, "�Ѵ���ȫ����"+excute_count+"���", 
							"������", JOptionPane.INFORMATION_MESSAGE);
				}
				
			}  catch (SQLException e1) {
				// TODO Auto-generated catch block
				JOptionPane.showMessageDialog(null, "����SQL������", 
						"������", JOptionPane.ERROR_MESSAGE);
				e1.printStackTrace();
			} catch (NullPointerException e2) {
				// TODO Auto-generated catch block
				JOptionPane.showMessageDialog(null, "�������ݿ�δ���ӣ�", 
						"������", JOptionPane.ERROR_MESSAGE);
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
			if(act.equals("����"))
			{
				String str_in = JOptionPane.showInputDialog("����������������Ϣ���������/��������/����״̬/�˻����/����Ʒ��/������������\n������O001/2016-6-1/Ԥ��������/A001/������/10��");
				if(str_in == null || str_in.isEmpty()==true)		// ��ɸ�Ƿ�ֵ
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
					scrolltable.getScrollTablePanefromQuery("SELECT * FROM Orders WHERE OrderStatus = 'Ԥ��������'");		// ˢ���б�
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "ʧ�ܣ��������������磺����ظ�����", "����ʧ��", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			else if(act.equals("ɾ��"))
			{
				int select_row = scrolltable.getTable().getSelectedRow();
				String select_ID = scrolltable.getTable().getValueAt(select_row, 0).toString();
				try {
					ConnectDB.excuteUpdate("DELETE FROM Orders WHERE OrderID = "+"'"+select_ID+"'");		// �޸�Orders��ɾ��ѡ�ж�����
					scrolltable.getScrollTablePanefromQuery("SELECT * FROM Orders WHERE OrderStatus = 'Ԥ��������'");		// ˢ���б�
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