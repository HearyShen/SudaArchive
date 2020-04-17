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

		/* Menu: ���ݿ⼰��˵��� */
		db = new DBAction();
		m_start = new JMenu("��ʼ");
		mi_connect = initMenuItem(m_start, "����", db);
		mi_disconnect = initMenuItem(m_start, "�Ͽ�����", db);
		mi_revise = initMenuItem(m_start, "�༭����", db);
		mi_dbhelp = initMenuItem(m_start, "����", db);
		mi_disconnect.setVisible(false);
		this.add(m_start);
		
		m_start.setVisible(true);
		
		
		/* Menu: ���ݿ�߼���������˵��� */
		ad = new AdvanceAction();
		m_advance = new JMenu("�߼�");
		mi_initDB = initMenuItem(m_advance, "��ʼ��", ad);
		mi_dropall = initMenuItem(m_advance, "���", ad);
		mi_adhelp = initMenuItem(m_advance, "����", ad);
		this.add(m_advance);
		
		m_start.setVisible(true);
		
		
		/* Menu: ���ڼ���˵��� */
		info = new InfoAction();
		m_about = new JMenu("����");
		mi_author = initMenuItem(m_about, "����", info);
		mi_version = initMenuItem(m_about, "�汾", info);
		this.add(m_about);
		
		m_about.setVisible(true);
		
	}
	
	
	/* API: initMenuItem  ����JMenuItemʵ�������أ�����¼���������������JMenu */
	private JMenuItem initMenuItem(JMenu menu, String name, ActionListener listener)	
	{
		JMenuItem mitem = new JMenuItem(name);
		mitem.addActionListener(listener);
		menu.add(mitem);
		
		return mitem;
	}
	
	/* DBAction: ���ݿ�˵��Ĳ˵�����¼����� */
	protected class DBAction implements ActionListener
	{
		String act;
		public void actionPerformed(ActionEvent e)
		{
			act = e.getActionCommand();
			if(act.equals("����"))
			{
				try{
					ConnectDB.conn= ConnectDB.openConnection();
					mi_disconnect.setVisible(true);
					mi_connect.setVisible(false);
				}
				catch(SQLException sql_ex){
					JOptionPane.showMessageDialog(null, "�쳣�����ݿ�����쳣������Server�Ƿ��Ѿ�������", 
							"����ʧ��", JOptionPane.ERROR_MESSAGE);
					//System.exit(0);
				}
				catch(IOException io_ex){
					JOptionPane.showMessageDialog(null, "�쳣�����ݿ�IO�쳣��", 
							"����ʧ��", JOptionPane.ERROR_MESSAGE);
				}
				
				try {
					JOptionPane.showMessageDialog(null, "���ݿ������ӣ��û�����"
				 + ConnectDB.conn.getMetaData().getUserName(), "����", JOptionPane.INFORMATION_MESSAGE);
				} catch (HeadlessException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				
			}
			else if(act.equals("�Ͽ�����"))
			{
				if( ConnectDB.closeConnection())
				{
					JOptionPane.showMessageDialog(null, "�ɹ������ݿ��ѶϿ�����", "�Ͽ�����", JOptionPane.INFORMATION_MESSAGE);
					mi_connect.setVisible(true);
					mi_disconnect.setVisible(false);
				}
				else
				{
					JOptionPane.showMessageDialog(null, "ʧ�ܣ����ݿ��޷��Ͽ�����", "�Ͽ�����", JOptionPane.ERROR_MESSAGE);
				}

			}
			else if(act.equals("�༭����"))
			{
				JFrame dframe = new JFrame("�༭���ݿ�����");
				
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
				
				JButton save = new JButton("����");
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
			else if(act.equals("����"))
			{
				JOptionPane.showMessageDialog(null, "�������Ӻ�ʹ�ã�\n�����ݿ����ϵͳ����Apache Derby Database( v10.11 )", "���ݿ����", 
						JOptionPane.INFORMATION_MESSAGE);
			}
			
		}
	}
	
	
	/* AdvanceAction: ���ڲ˵��Ĳ˵�����¼����� */	
	class AdvanceAction implements ActionListener
	{
		String act;
		public void actionPerformed(ActionEvent e)
		{
			act = e.getActionCommand();
			if(act.equals("��ʼ��"))
			{
				int op = JOptionPane.showConfirmDialog(null, "ȷ��Ҫ��ʼ�����ݿ⣿", "��ʼ��", JOptionPane.OK_CANCEL_OPTION, JOptionPane.WARNING_MESSAGE);
				if(op == JOptionPane.OK_OPTION)
				{
					try {
						ConnectDB.initDB();
					} catch ( IOException e1) {
						e1.printStackTrace();
						JOptionPane.showMessageDialog(null, "ʧ�ܣ�����������ݿ⣡", "����", JOptionPane.ERROR_MESSAGE);
					} catch(NullPointerException e2){
						JOptionPane.showMessageDialog(null, "ʧ�ܣ����ݿ�δ���ӣ�", "����", JOptionPane.ERROR_MESSAGE);
					}
				}
			}
			else if(act.equals("���"))
			{
				int op = JOptionPane.showConfirmDialog(null, "ȷ��Ҫ������ݿ⣿", "���", JOptionPane.OK_CANCEL_OPTION, JOptionPane.WARNING_MESSAGE);
				if(op == JOptionPane.OK_OPTION)
				{
					try {
						ConnectDB.deleteDB();
					} /*catch (SQLException e1) {
						JOptionPane.showMessageDialog(null, "ʧ�ܣ����ݿ�����գ�", "����", JOptionPane.ERROR_MESSAGE);
						e1.printStackTrace();
					} */catch(NullPointerException e2){
						JOptionPane.showMessageDialog(null, "ʧ�ܣ����ݿ�δ���ӣ�", "����", JOptionPane.ERROR_MESSAGE);
					}
				}
			}
			else if(act.equals("����"))
			{
				JOptionPane.showMessageDialog(null, "���ݿ�߼�����������ռ���ʼ����\nע�⣺��ʼ��������պ�ִ�У�", "����", JOptionPane.INFORMATION_MESSAGE);
			}
		}
	}
	
	
	/* InfoAction: ���ڲ˵��Ĳ˵�����¼����� */
	class InfoAction implements ActionListener
	{
		String act;
		public void actionPerformed(ActionEvent e)
		{
			act = e.getActionCommand();
			if(act.equals("����"))
				JOptionPane.showMessageDialog(null, "���ߣ�����S", "����", 1);
			else if(act.equals("�汾"))
				JOptionPane.showMessageDialog(null, "�����������ݿ����ϵͳ - �����( alpha v0.1 )", "�汾", 1);
		}
	}
}
