package ch12;
import javax.swing.*;
import javax.swing.event.HyperlinkEvent;
import javax.swing.event.HyperlinkListener;

import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;


public class WebBrowser extends JFrame implements ActionListener,HyperlinkListener{
	private static final long serialVersionUID = 1L;
	private JEditorPane jep;
	private JTextField jtfUrl;
	
	public WebBrowser(){
		setSize(600,600);
		setTitle("ä¯ÀÀÆ÷");
		jep=new JEditorPane();
		jep.setEditable(false);
		jtfUrl=new JTextField();
		
		Box jp=Box.createVerticalBox();
		jp.add(Box.createVerticalStrut(10));		
		Box tjp=Box.createHorizontalBox();
		tjp.add(Box.createHorizontalStrut(30));
		tjp.add(new JLabel("URL:"));
		tjp.add(Box.createHorizontalStrut(10));
		tjp.add(jtfUrl);
		tjp.add(Box.createHorizontalStrut(30));
		jp.add(tjp);
		jp.add(Box.createVerticalStrut(10));
		
		JScrollPane jspViewer=new JScrollPane(jep);
		
		this.getContentPane().add(jspViewer,BorderLayout.CENTER);
		this.getContentPane().add(jp,BorderLayout.NORTH);
		
		jep.addHyperlinkListener(this);
		jtfUrl.addActionListener(this);
		
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	public void actionPerformed(ActionEvent arg0) {
		try{
			URL url=new URL(jtfUrl.getText().trim());
			jep.setPage(url);
		}catch(IOException e){
			System.err.println(e.getMessage());
		}		
	}

	public void hyperlinkUpdate(HyperlinkEvent arg0) {
		try{
			jtfUrl.setText(arg0.getURL().toString());
			jep.setPage(arg0.getURL());
		}catch(IOException e){
			System.err.println(e.getMessage());
		}
	}
	
	public static void main(String[] args){
		new WebBrowser();
	}
}
