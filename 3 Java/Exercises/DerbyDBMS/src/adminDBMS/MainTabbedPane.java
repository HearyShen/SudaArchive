/***********************************************************************
 * 
 * MainTabbedPane.java  
 * version: beta 1.1  (2016/6/1)
 * author: 沈家赟
 * 		主界面的Tab整合容器。
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
		this.addTab("开始页", null, welcome_panel, "显示开始欢迎页");
		
		to_do_panel = new TodoPanel();
		this.addTab("待办订单", null, to_do_panel, "显示当前待办订单");
		
		goods_panel = new GoodsPanel();
		this.addTab("猪肉现货", null, goods_panel, "显示猪肉现货情况");
		
		stock_panel = new StockPanel();
		this.addTab("生猪存栏", null, stock_panel, "显示生猪存栏清单");
		
		account_panel = new AccountPanel();
		this.addTab("客户管理", null, account_panel, "显示已注册的客户列表");
		
		done_panel = new DonePanel();
		this.addTab("历史订单", null, done_panel, "显示当前已办订单");
		
		function_panel = new MultiFunctionPanel();
		this.addTab("更多", null, function_panel, "显示更多功能");
		
		
		this.setVisible(true);
	}
}
