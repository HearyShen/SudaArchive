package adminDBMS;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.sql.*;
import java.util.*;
import javax.swing.*;

public class WelcomePanel extends JPanel{
	JLabel wlcm_label;
	JTextArea intro_conn_text;
	JTextArea intro_adv_text;
	
	WelcomePanel()
	{
		this.setLayout(null);
		
		wlcm_label = new JLabel("»¶Ó­£¡");
		wlcm_label.setFont( new Font("Î¢ÈíÑÅºÚ" ,Font.BOLD | Font.ITALIC, 20) );
		wlcm_label.setLocation(10, 10);
		wlcm_label.setSize(wlcm_label.getPreferredSize().width, wlcm_label.getPreferredSize().height);
		this.add(wlcm_label);
		
		intro_conn_text = new JTextArea("¿ªÊ¼£ºÇëÏÈÁ¬½ÓÊý¾Ý¿â¡£");
		intro_conn_text.setFont( new Font("Î¢ÈíÑÅºÚ" ,Font.PLAIN, 15) );
		intro_conn_text.setLocation(10, 10+wlcm_label.getPreferredSize().height+20);
		intro_conn_text.setSize(intro_conn_text.getPreferredSize().width, intro_conn_text.getPreferredSize().height);
		intro_conn_text.setEditable(false);
		intro_conn_text.setBackground(this.getBackground());
		this.add(intro_conn_text);
		
		intro_adv_text = new JTextArea("¸ß¼¶¹¦ÄÜ£ºÇå¿Õ -> ³õÊ¼»¯");
		intro_adv_text.setFont( new Font("Î¢ÈíÑÅºÚ" ,Font.PLAIN, 15) );
		intro_adv_text.setLocation(10, 10+wlcm_label.getPreferredSize().height+20+intro_conn_text.getPreferredSize().height+20);
		intro_adv_text.setSize(intro_adv_text.getPreferredSize().width, intro_adv_text.getPreferredSize().height);
		intro_adv_text.setEditable(false);
		intro_adv_text.setBackground(this.getBackground());
		this.add(intro_adv_text);
	}
	
}
