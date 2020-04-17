/***********************************************************************
 * 
 * ScrollTablePane.java  
 * version: beta 1.2  (2016/6/9)
 * author: 沈家赟
 * 		主要设计自定义的getScrollTablePanefromQuery函数，
 * 输入SQL查询语句，输出表格显示容器(ScrollTablePane)
 * 
 ***********************************************************************/

package adminDBMS;

import javax.swing.*;
import java.awt.*;
import java.io.IOException;
import java.sql.SQLException;
import java.util.Vector;

public class ScrollTablePane extends JScrollPane{
	JTable current_table;
	 Vector<String> vec_attributes;
	 Vector<Vector<String>> vec_rows;
	
	 public JTable getTable()
	 {
		 return current_table;
	 }
	 
	 /* API: 输入SQL查询语句，返回一个包含结果表(table)的ScrollTablePane */
	public ScrollTablePane getScrollTablePanefromQuery(String sql_query) throws SQLException, IOException
	{
		UIManager.put("Table.font", AdminFrame.table_font);
		
		/* JTable 处理部分*/
		if(ConnectDB.getConnection() == null || ConnectDB.getConnection().isClosed() == true)
		{
			return null;
		}
		
		ConnectDB.excuteQuery(sql_query);		// 查询
		
		vec_rows = new Vector<Vector<String>>( ConnectDB.getResultSetRowsVector() );		// 取值
		vec_attributes = new Vector<String>( ConnectDB.getResultSetAttributesVector() );		//取值
		
		
		if(current_table != null)
		{
			current_table.removeAll();	// 初始化清空
		}
		current_table = new JTable(vec_rows, vec_attributes){		//制表
            public boolean isCellEditable(int row, int column)
            {
                return false;
            }
        }; 
        current_table.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
        current_table.setAutoCreateRowSorter(true);
        //scrollpanel.removeAll();
        //scrollpanel = new JScrollPane(current_table);
		this.setViewportView(current_table);
        
		return this;
	}
}
