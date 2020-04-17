package ch15;

import java.sql.*;

public class DbConn {
	private final static String dbUrl = "jdbc:microsoft:sqlserver://127.0.0.1:1433;databaseName=clsTest";
	private final static String dbUser = "cls";
	private final static String dbPass = "cls";

	public static void main(String[] args) {
		Connection con=null;
		Statement stmt=null;
		try {
			Class.forName("com.microsoft.jdbc.sqlserver.SQLServerDriver");
			con=DriverManager.getConnection(dbUrl, dbUser, dbPass);
			String sql=" delete from employee where id='001' ";
			stmt=con.createStatement();
			stmt.execute(sql);
			stmt.close();
			con.close();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
}
