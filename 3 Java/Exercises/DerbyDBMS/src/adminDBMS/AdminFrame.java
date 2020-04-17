/***********************************************************************
 * 
 * AdminFrame.java  
 * version: beta 1.1  (2016/6/1)
 * author: 沈家赟
 * 		GUI主框架。
 * 
 ***********************************************************************/

package adminDBMS;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.awt.*;
import javax.swing.*;

public class AdminFrame extends JFrame{
	private static final int DEFAULT_WIDTH = 900;
	private static final int DEFAULT_HEIGHT = 700;
	static Font std_font = new Font("微软雅黑" ,Font.PLAIN, 15);
	static Font table_font = new Font("新宋体" ,Font.PLAIN, 12);
	static Font largebutton_font = new Font("微软雅黑" ,Font.BOLD, 16);
	
	TopMenuBar tmbar;
	MainTabbedPane mtabpane;
	
	AdminFrame()
	{
		/*Frame self init*/
		int frame_x, frame_y;
		this.setTitle("智能养猪系统-管理端 (alpha v0.1) Demo");
		Toolkit kit = Toolkit.getDefaultToolkit();
		this.setSize(AdminFrame.DEFAULT_WIDTH, AdminFrame.DEFAULT_HEIGHT);
		frame_x = (kit.getScreenSize().width - AdminFrame.DEFAULT_WIDTH)/2;
		frame_y = (kit.getScreenSize().height - AdminFrame.DEFAULT_HEIGHT)/2;
		this.setLocation(frame_x, frame_y);
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(null);
		this.setIconImage(new ImageIcon("src/Logo.png").getImage());
		
		/*init other components*/
		tmbar = new TopMenuBar();
		tmbar.setLocation(0, 0);
		tmbar.setSize(AdminFrame.DEFAULT_WIDTH, 30);
		this.add(tmbar);
		
		UIManager.put("TabbedPane.font", AdminFrame.largebutton_font);
		mtabpane = new MainTabbedPane();
		mtabpane.setLocation(0, 35);
		mtabpane.setSize(AdminFrame.DEFAULT_WIDTH-20, AdminFrame.DEFAULT_HEIGHT-75);
		this.add(mtabpane);
		
		this.setVisible(true);
	}
	
	public static void main(String args[]) throws IOException
	{
		
		AdminFrame fframe = new AdminFrame();
	      
	}

}
