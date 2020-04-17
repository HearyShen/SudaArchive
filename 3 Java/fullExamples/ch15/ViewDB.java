package ch15;

import java.sql.*;
import java.io.*;
import java.util.*;

public class ViewDB {
	private Connection conn;
	private Statement stat;
	private DatabaseMetaData meta;
	private ResultSet rs;
	private boolean scrolling;
	
	public static Connection getConnection() throws IOException, SQLException{
		Properties props=new Properties();
		FileInputStream in=new FileInputStream("database.properties");
		props.load(in);
		in.close();
		
		String drivers=props.getProperty("jdbc.drivers");
		if (drivers!=null)
			System.setProperty("jdbc.drivers",drivers);
		String url=props.getProperty("jdbc.url");
		String username=props.getProperty("jdbc.username");
		String password=props.getProperty("jdbc.password");
		return (DriverManager.getConnection(url,username,password));
	}
	
	public void createStatement() throws SQLException{
		if (meta.supportsResultSetType(ResultSet.TYPE_SCROLL_INSENSITIVE)){
			stat=conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_READ_ONLY);
			scrolling=true;
		}
		else
		{
			stat=conn.createStatement();
			scrolling=false;
		}
	}
	
	public void getTableNames() throws SQLException{
		rs=meta.getTables(null,null,null,new String[]{"TABLE","VIEW","SYSTEM TABLE"});
		while (rs.next())
			System.out.println(rs.getString(3));
		rs.close();
	}
	
	public ViewDB(){
		try{
			conn=getConnection();
			meta=conn.getMetaData();
			createStatement();
			getTableNames();
			stat.close();
			conn.close();
			System.out.println("*********"+scrolling+"***********");
		}catch(SQLException e){
			System.err.println(e.getMessage());
		}catch(IOException ex){
			System.err.println(ex.getMessage());
		}
	}
	public static void main(String[] args){
		new ViewDB();
	}

}
