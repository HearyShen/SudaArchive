package adminDBMS;

import java.awt.event.*;
import java.io.*;
import java.sql.*;
import java.util.*;
import javax.swing.*;

import adminDBMS.TodoPanel.UpdateAction;

public class DonePanel extends JPanel{
	JLabel name_label;
	ScrollTablePane scrolltable;
	JButton refresh;
	QueryAction queryAction;
	JButton orderin;
	JButton orderout;
	UpdateAction updateAction;
	
	 Vector<String> vec_attributes;
	 Vector<Vector<String>> vec_rows;
	
	 DonePanel()
	{
		name_label = new JLabel("�Ѵ�������ѯ");
		scrolltable = new ScrollTablePane();
		queryAction = new QueryAction();
		refresh = new JButton("ˢ��");
		refresh.addActionListener(queryAction);
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
        orderin.setBounds(10+refresh.getPreferredSize().width+20, 50, 
        		orderin.getPreferredSize().width, orderin.getPreferredSize().height);
        this.add(orderin);
        orderout.setBounds(10+refresh.getPreferredSize().width+20+orderin.getPreferredSize().width+20, 50, 
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
					if( scrolltable.getScrollTablePanefromQuery("SELECT * FROM Orders WHERE OrderStatus = '����ɹ�'") == null)		// �����Զ����getScrollTablePanefromQuery������������SQL��ѯ���ScrollTablePane
					{
						JOptionPane.showMessageDialog(null, "ʧ�ܣ�δ�������ݿ⣡", "ˢ��ʧ��", JOptionPane.ERROR_MESSAGE);
					}
				} catch (SQLException | IOException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "ʧ�ܣ����ݿ����޶�Ӧ���ݣ�", "����", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				}
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
