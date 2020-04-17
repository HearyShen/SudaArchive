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
		 	name_label = new JLabel("��Ʒ����ѯ");
			scrolltable = new ScrollTablePane();
			queryAction = new QueryAction();
			refresh = new JButton("ˢ��");
			refresh.addActionListener(queryAction);
			killAction = new KillAction();
			kill = new JButton("ɱ��");
			kill.addActionListener(killAction);
			updateAction = new UpdateAction();
			stockin = new JButton("���");
			stockin.addActionListener(updateAction);
			stockout = new JButton("����");
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
			
//			stockin = new JButton("���");
//			this.add(stockin);
//			
//			stockout = new JButton("����");
//			this.add(stockout);
			
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
					if( scrolltable.getScrollTablePanefromQuery("SELECT PigID AS ���, Type AS Ʒ��, Weight AS ���� FROM Pig") == null)		// �����Զ����getScrollTablePanefromQuery������������SQL��ѯ���ScrollTablePane
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
					current_weight += select_weight;			// �����ۼӺ����weight
					ConnectDB.excuteUpdate("UPDATE Meat Set Weight = "+current_weight+"WHERE TYPE = "+"'"+select_type+"'");		// �޸�Meat���ۼ�Weight��
					ConnectDB.excuteUpdate("DELETE FROM Pig WHERE PigID = "+"'"+select_ID+"'");	// �޸�Pig��ɾ����ɱ��
					scrolltable.getScrollTablePanefromQuery("SELECT * FROM Pig");		// ˢ���б�
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
			if(act.equals("���"))
			{
				String str_in = JOptionPane.showInputDialog("���������������Ϣ�����/����/��������\n������P001/������/100��");
				if(str_in == null || str_in.isEmpty()==true)		// ��ɸ�Ƿ�ֵ
				{
					return;
				}
				String str_part[] = str_in.split("/");
				String PID = str_part[0];
				String PType = str_part[1];
				int PWeight = Integer.parseInt( str_part[2] );
				try {
					ConnectDB.excuteUpdate("INSERT INTO Pig VALUES("+"'"+PID+"'"+","+"'"+PType+"'"+","+PWeight+")");
					scrolltable.getScrollTablePanefromQuery("SELECT PigID AS ���, Type AS Ʒ��, Weight AS ���� FROM Pig");		// ˢ���б�
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "ʧ�ܣ��������������磺����ظ�����", "����ʧ��", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			else if(act.equals("����"))
			{
				int select_row = scrolltable.getTable().getSelectedRow();
				String select_ID = scrolltable.getTable().getValueAt(select_row, 0).toString();
				try {
					ConnectDB.excuteUpdate("DELETE FROM Pig WHERE PigID = "+"'"+select_ID+"'");		// �޸�Pig��ɾ��������
					scrolltable.getScrollTablePanefromQuery("SELECT PigID AS ���, Type AS Ʒ��, Weight AS ���� FROM Pig");		// ˢ���б�
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
