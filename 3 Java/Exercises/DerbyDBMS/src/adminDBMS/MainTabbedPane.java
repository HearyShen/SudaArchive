/***********************************************************************
 * 
 * MainTabbedPane.java  
 * version: beta 1.1  (2016/6/1)
 * author: ����S
 * 		�������Tab����������
 * 
 ***********************************************************************/

package adminDBMS;

import java.awt.BorderLayout;
import java.awt.event.*;
import java.io.IOException;
import java.sql.*;
import java.util.*;
import javax.swing.*;

public class MainTabbedPane extends JTabbedPane{
	WelcomePanel welcome_panel;
	TodoPanel to_do_panel;
	GoodsPanel goods_panel;
	StockPanel stock_panel;
	AccountPanel account_panel;
	DonePanel done_panel;
	MultiFunctionPanel function_panel;
	
	MainTabbedPane()
	{
		
		UIManager.put("Button.font", AdminFrame.std_font);
		UIManager.put("Label.font", AdminFrame.std_font);
		this.setTabPlacement(JTabbedPane.LEFT);
		
		welcome_panel = new WelcomePanel();
		this.addTab("��ʼҳ", null, welcome_panel, "��ʾ��ʼ��ӭҳ");
		
		to_do_panel = new TodoPanel();
		this.addTab("���충��", null, to_do_panel, "��ʾ��ǰ���충��");
		
		goods_panel = new GoodsPanel();
		this.addTab("�����ֻ�", null, goods_panel, "��ʾ�����ֻ����");
		
		stock_panel = new StockPanel();
		this.addTab("�������", null, stock_panel, "��ʾ��������嵥");
		
		account_panel = new AccountPanel();
		this.addTab("�ͻ�����", null, account_panel, "��ʾ��ע��Ŀͻ��б�");
		
		done_panel = new DonePanel();
		this.addTab("��ʷ����", null, done_panel, "��ʾ��ǰ�Ѱ충��");
		
		function_panel = new MultiFunctionPanel();
		this.addTab("����", null, function_panel, "��ʾ���๦��");
		
		
		this.setVisible(true);
	}
}
