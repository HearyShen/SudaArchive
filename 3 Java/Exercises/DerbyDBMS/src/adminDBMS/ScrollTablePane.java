/***********************************************************************
 * 
 * ScrollTablePane.java  
 * version: beta 1.2  (2016/6/9)
 * author: ����S
 * 		��Ҫ����Զ����getScrollTablePanefromQuery������
 * ����SQL��ѯ��䣬��������ʾ����(ScrollTablePane)
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
	 
	 /* API: ����SQL��ѯ��䣬����һ�����������(table)��ScrollTablePane */
	public ScrollTablePane getScrollTablePanefromQuery(String sql_query) throws SQLException, IOException
	{
		UIManager.put("Table.font", AdminFrame.table_font);
		
		/* JTable ������*/
		if(ConnectDB.getConnection() == null || ConnectDB.getConnection().isClosed() == true)
		{
			return null;
		}
		
		ConnectDB.excuteQuery(sql_query);		// ��ѯ
		
		vec_rows = new Vector<Vector<String>>( ConnectDB.getResultSetRowsVector() );		// ȡֵ
		vec_attributes = new Vector<String>( ConnectDB.getResultSetAttributesVector() );		//ȡֵ
		
		
		if(current_table != null)
		{
			current_table.removeAll();	// ��ʼ�����
		}
		current_table = new JTable(vec_rows, vec_attributes){		//�Ʊ�
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
