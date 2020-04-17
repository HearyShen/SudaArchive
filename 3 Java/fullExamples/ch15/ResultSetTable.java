package ch15;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.sql.*;

import javax.swing.*;
import javax.swing.table.*;

class ResultSetTableModel extends AbstractTableModel{
	private static final long serialVersionUID = 1L;
	
	private ResultSet rs;
	private ResultSetMetaData rsmd;
	
	public ResultSetTableModel(ResultSet mrs){
		rs=mrs;
		try {
			rsmd=rs.getMetaData();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public int getColumnCount() {
		int c=0;
		try {
			c=rsmd.getColumnCount();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return c;
	}

	public int getRowCount() {
		int c=0;
		try {
			rs.last();
			c=rs.getRow();
		} catch (SQLException e) {
			e.printStackTrace();
		}		
		return c;
	}

	public Object getValueAt(int rowIndex, int columnIndex) {
		Object o=null;
		try {
			rs.absolute(rowIndex+1);
			o=rs.getObject(columnIndex+1);
		} catch (SQLException e) {
			e.printStackTrace();
		}		
		return o;
	}
	
	public String getColumnName(int col){
		String n="";
		try {
			n=rsmd.getColumnName(col+1);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return n;
	}
	
}

class ResultSetFrame extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private JScrollPane scrollPane;
	private ResultSetTableModel model;
	private JComboBox tableNames;
	private ResultSet rs;
	private Connection conn;
	private Statement stat;
	private boolean scrolling;
	
	public ResultSetFrame(){
		this.setTitle("ResultSetTable");
		this.setSize(600,300);
		tableNames=new JComboBox();
		tableNames.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent arg0) {
				try{
					if (scrollPane!=null)
						remove(scrollPane);
					String tname=(String)tableNames.getSelectedItem();
					if (rs!=null)
						rs.close();
					String query="select * from "+tname;
					rs=stat.executeQuery(query);
					model=new ResultSetTableModel(rs);
					JTable table=new JTable(model);
					scrollPane=new JScrollPane(table);
					getContentPane().add(scrollPane,BorderLayout.CENTER);
					validate();
				}catch(SQLException e){
					System.err.println(e.getMessage());
				}
			}			
		});
		JPanel p=new JPanel();
		p.add(tableNames);
		this.getContentPane().add(p,BorderLayout.NORTH);
		
		try {
			conn=ViewDB.getConnection();
			DatabaseMetaData meta=conn.getMetaData();
			if (meta.supportsResultSetType(ResultSet.TYPE_SCROLL_INSENSITIVE))
				stat=conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,
						ResultSet.CONCUR_READ_ONLY);
			else
				stat=conn.createStatement();
			ResultSet trs=meta.getTables(null,null,null,new String[]{"TABLE"});
			while (trs.next())
				tableNames.addItem(trs.getString(3));
			trs.close();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent evt){
				try{
					if (conn!=null)
						conn.close();
				}catch(SQLException e){
					System.err.println(e.getMessage());
				}
			}
		});
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
}

public class ResultSetTable {
	public static void main(String[] args){
		new ResultSetFrame();
	}
}
