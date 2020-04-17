/***********************************************************************
 * 
 * ConnectDB.java  
 * version: beta 2.0  (2016/6/1)
 * author: 沈家赟
 * 		负责封装对数据库操作的相关功能，实现便捷的连接开闭，增删改查，
 * 	数据结构转换等功能。
 * 
 ***********************************************************************/

package adminDBMS;

import java.nio.file.*;
import java.sql.*;
import java.io.*;
import java.util.*;

public class ConnectDB {
	protected static Connection conn;
	protected static Statement stat;
	protected static ResultSet rsset;
	
	 protected static String drivers = "org.apache.derby.jdbc.ClientDriver";
	 protected static String url = "jdbc:derby://localhost:1527/E:\\DerbyDB;create=true";
	 protected static String username = "admin";
	 protected static String password ="123456";
	 
	 protected static ResultSetMetaData rsmd;
	 protected static int col_count;
	 protected static Vector<String> attributes = new Vector<String>();
	 protected static Vector<Vector<String>> rows = new Vector<Vector<String>>();

//	public static void main(String args[]) throws IOException
//	   {
//	      try
//	      {
//	         runTest();
//	      }
//	      catch (SQLException ex)
//	      {
//	         for (Throwable t : ex)
//	            t.printStackTrace();
//	      }
//	   }
	 
	/*Demo : initDB*/
	public static void initDB() throws  IOException
	{
	    	 //conn = openConnection();
			try {
				stat.executeUpdate("CREATE TABLE Pig "
				 		+ "(PigID VARCHAR(20), "
				 		+ "Type VARCHAR(20), "
				 		+ "Weight INT, "
				 		+ "primary key(PigID) )");
				
				 stat.executeUpdate("INSERT INTO Pig VALUES ( 'P001', '华北型', 100)");
				 stat.executeUpdate("INSERT INTO Pig VALUES ( 'P002', '华中型', 101)");
				 stat.executeUpdate("INSERT INTO Pig VALUES ( 'P003', '华南型', 102)");
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	         
	         
	         try {
				stat.executeUpdate("CREATE TABLE Meat "
				 		+ "(Type VARCHAR(20), "
				 		+ "Weight INT, "
				 		+ "primary key(Type) )");
				
				ConnectDB.stat.executeUpdate("INSERT INTO Meat VALUES ( '华北型', 10)");
				ConnectDB.stat.executeUpdate("INSERT INTO Meat VALUES ( '华中型', 20)");
				ConnectDB.stat.executeUpdate("INSERT INTO Meat VALUES ('华南型', 30)");
				ConnectDB.stat.executeUpdate("INSERT INTO Meat VALUES ('西南型', 40)");
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	         
	         
	         try {
				stat.executeUpdate("CREATE TABLE Account "
				     		+ "(AccountID VARCHAR(20), "
				     		+ "Name VARCHAR(20), "
				     		+ "Password VARCHAR(20), "
				     		+ "primary key(AccountID) )");
				
				 stat.executeUpdate("INSERT INTO Account VALUES ( 'A001', '张三', '123456')");
		         stat.executeUpdate("INSERT INTO Account VALUES ( 'A002', '李四', '234567')");
		         stat.executeUpdate("INSERT INTO Account VALUES ( 'A003', '王五', '345678')");
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	         
	         try {
				stat.executeUpdate("CREATE TABLE Orders "
				 		+ "( OrderID VARCHAR(20), "
				 		+ "OrderDate  DATE, "
				 		+ "OrderStatus VARCHAR(20), "
				 		+ "AccountID VARCHAR(20), "
				 		+ "Type VARCHAR(20), "
				 		+ "Weight INT, "
				 		+ "primary key(OrderID))");
				
				 stat.executeUpdate("INSERT INTO Orders VALUES ( 'O001', '2016-6-1', '购买成功', 'A001', '华北型', 5)");
		         stat.executeUpdate("INSERT INTO Orders VALUES ( 'O002', '2016-6-2', '预订待处理', 'A002', '华中型', 6)");
		         stat.executeUpdate("INSERT INTO Orders VALUES ( 'O003', '2016-6-3', '购买成功', 'A003', '华南型', 7)");
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	         
	         //rsset = stat.executeQuery("SELECT * FROM PigList");
//            while(rsset.next())
//            {
//               System.out.println(rsset.getString(1));
//            }
	        // stat.executeUpdate("DROP TABLE PigList");
	         
	       //stat.executeUpdate("CREATE TABLE Greetings (Message CHAR(20))");
//	       stat.executeUpdate("INSERT INTO Greetings VALUES ('Hello, World!')");
//	       rsset = stat.executeQuery("SELECT * FROM Greetings");
	      // stat.executeUpdate("DROP TABLE Greetings");
	   
	  }
	
	/*Demo : deleteDB*/
	public static void deleteDB()
	{
		try {
			stat.executeUpdate("DROP TABLE Orders");
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			stat.executeUpdate("DROP TABLE Account");
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			stat.executeUpdate("DROP TABLE Meat");
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			stat.executeUpdate("DROP TABLE Pig");
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static String getUsername()
	{
		return username;
	}
	
	/* API : openConnection() */
	public static Connection openConnection() throws SQLException, IOException
	{
	      System.setProperty("jdbc.drivers", drivers);
	      conn = DriverManager.getConnection(url, username, password);
	      stat = conn.createStatement();

	      return conn;
	  
	}
	
	/* API : closeConnection() */
	public static boolean closeConnection()
	{
	      try {
	    	  if(conn != null)
	    		  conn.close();
	    	  if(stat != null)
	    		  stat.close();
	    	  if(rsset != null)
	    		  rsset.close();
			} 
	      catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
			}
	      return true;
	}
	
	/* API : getConnection() */
	public static Connection getConnection()
	{
	     return conn;
	}
	
	/* API : getResultSet() */
	public static ResultSet getResultSet()
	{
	     return rsset;
	}
	
	
	/* API : excuteUpdate(String sql_cmd) */
	public static int excuteUpdate(String sql_cmd) throws SQLException
	{
		return stat.executeUpdate(sql_cmd);
	}
	
	/* API : excuteQuery(String sql_cmd) */
	public static ResultSet excuteQuery(String sql_cmd) throws SQLException
	{
		rsset = stat.executeQuery(sql_cmd);
		rsmd = ConnectDB.getResultSet().getMetaData();
		return rsset;
	}
	
	/* API : getResultSetAttributesVector() */
	public static Vector getResultSetAttributesVector() throws SQLException
	{
		/* convert ResultSet attributes data to Vector, in order to display resultset in JTable*/
		rsmd = ConnectDB.getResultSet().getMetaData();
		col_count = rsmd.getColumnCount();
		if(attributes != null)
		{
			attributes.clear();
		}
		for(int i=1; i<=col_count; i++)
		{
			attributes.addElement(rsmd.getColumnLabel( i ));
		}
		return attributes;
	}
	
	/* API : getResultSetRowsVector() */
	public static Vector getResultSetRowsVector() throws SQLException, IOException
	{
		/* convert ResultSet row data to Vector, in order to display resultset in JTable*/
		rsmd = ConnectDB.getResultSet().getMetaData();
		col_count = rsmd.getColumnCount();
		
		if(rows != null)
		{
			rows.clear();
		}
		while(ConnectDB.getResultSet().next())
		{
			Vector<String> currentRow = new Vector<String>();
			for ( int i = 1; i <= rsmd.getColumnCount(); ++i ) 
			{ 
				currentRow.addElement( ConnectDB.getResultSet().getString( i ) ); 
			} 
			rows.addElement(currentRow); 
		}
			
		return rows;
		
	}
	
}
