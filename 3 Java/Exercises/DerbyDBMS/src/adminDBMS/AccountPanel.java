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
		 	name_label = new JLabel("�ͻ�����");
			scrolltable = new ScrollTablePane();
			queryAction = new QueryAction();
			refresh = new JButton("ˢ��");
			refresh.addActionListener(queryAction);
			detail = new JButton("����");
			detail.addActionListener(queryAction);
			
			updateAction = new UpdateAction();
			accountin = new JButton("ע��");
			accountin.addActionListener(updateAction);
			accountout = new JButton("ע��");
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
			if(act.equals("ˢ��"))
			{
				try {
					if( scrolltable.getScrollTablePanefromQuery("SELECT Account.AccountID AS �û����, Name AS �û���, COUNT(*) AS ������� FROM Account, Orders WHERE Account.AccountID = Orders.AccountID GROUP BY Account.AccountID, Name") == null)		// �����Զ����getScrollTablePanefromQuery������������SQL��ѯ���ScrollTablePane
					{
						JOptionPane.showMessageDialog(null, "ʧ�ܣ�δ�������ݿ⣡", "ˢ��ʧ��", JOptionPane.ERROR_MESSAGE);
					}
				} catch (SQLException | IOException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "ʧ�ܣ����ݿ����޶�Ӧ���ݣ�", "����", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				}
			}
			else if(act.equals("����"))
			{
				int select_row = scrolltable.getTable().getSelectedRow();
				String select_ID = scrolltable.getTable().getValueAt(select_row, 0).toString();
				
				
				JFrame dframe = new JFrame("����");
				
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
			if(act.equals("ע��"))
			{
				String str_in = JOptionPane.showInputDialog("��������ע���û���Ϣ���˺�/����/���룩��\n������A001/��һ/���룩");
				if(str_in == null || str_in.isEmpty()==true)		// ��ɸ�Ƿ�ֵ
				{
					return;
				}
				String str_part[] = str_in.split("/");
				String AID = str_part[0];
				String AName = str_part[1];
				String APassword = str_part[2];
				try {
					ConnectDB.excuteUpdate("INSERT INTO Account VALUES("+"'"+AID+"'"+","+"'"+AName+"'"+","+"'"+APassword+"'"+")");
					scrolltable.getScrollTablePanefromQuery("SELECT Account.AccountID AS �û��˺�, Name AS �û���, COUNT(*) AS �������"
							+ " FROM Account, Orders WHERE Account.AccountID = Orders.AccountID GROUP BY Account.AccountID, Name");		// ˢ���б�
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "ʧ�ܣ��������������磺�˺��ظ�����", "����ʧ��", JOptionPane.ERROR_MESSAGE);
					e1.printStackTrace();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
			else if(act.equals("ע��"))
			{
				int select_row = scrolltable.getTable().getSelectedRow();
				String select_ID = scrolltable.getTable().getValueAt(select_row, 0).toString();
				try {
					ConnectDB.excuteUpdate("DELETE FROM Account WHERE AccountID = "+"'"+select_ID+"'");		// �޸�Account��ע���û���
					scrolltable.getScrollTablePanefromQuery("SELECT Account.AccountID AS �û����, Name AS �û���, COUNT(*) AS ������� "
							+ "FROM Account, Orders WHERE Account.AccountID = Orders.AccountID GROUP BY Account.AccountID, Name");		// ˢ���б�
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
