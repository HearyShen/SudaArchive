/**
 * �ļ�������
 * @author ����S
 * 1427405017
 * 2016/6/17
 */

import javax.swing.*;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.Vector;
import java.awt.event.ActionEvent;
import java.awt.Color;
import java.awt.Font;
import java.awt.Toolkit;


public class FileFilterFrame extends JFrame{
	private static final int DEFAULT_WIDTH = 600;
	private static final int DEFAULT_HEIGHT = 500;
	private JTextField textField_path;
	private JTextField textField_target;
	private JScrollPane scrollPaneForFile;
	private JList list_file;
	private JScrollPane scrollPaneForDir;
	private JList list_dir;
	
	// file info  
    private static Vector<String> fileInfo;  
    // dir info  
    private static Vector<String> dirInfo;  
    // child file info  
    private static File[] fm;  
    
    
	public FileFilterFrame() {
		this.setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
		Toolkit kit = Toolkit.getDefaultToolkit();
		this.setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
		int frame_x = (kit.getScreenSize().width - DEFAULT_WIDTH)/2;
		int frame_y = (kit.getScreenSize().height - DEFAULT_HEIGHT)/2;
		this.setLocation(frame_x, frame_y);
		setResizable(false);
		setTitle("�ļ�������");
		getContentPane().setLayout(null);
		
		JPanel searchpanel = new JPanel();
		searchpanel.setBounds(10, 16, 569, 135);
		getContentPane().add(searchpanel);
		searchpanel.setLayout(null);
		
		JLabel label_target = new JLabel("������Ϣ");
		label_target.setBounds(15, 26, 84, 20);
		searchpanel.add(label_target);
		
		textField_target = new JTextField();
		textField_target.setBounds(95, 24, 294, 27);
		searchpanel.add(textField_target);
		textField_target.setColumns(10);
		
		JLabel label_path = new JLabel("����·��");
		label_path.setBounds(15, 69, 84, 20);
		searchpanel.add(label_path);
		
		textField_path = new JTextField();
		textField_path.setBounds(95, 67, 459, 27);
		searchpanel.add(textField_path);
		textField_path.setColumns(10);
		
		JButton button_search = new JButton("����");
		button_search.addActionListener(new ActionListener() {
			/**
			 * JButton-���� �� �¼�����
			 * ������ָ���ļ�·���е�ָ���ؼ��֣���ˢ��File��Directory����JList��
			 */
			public void actionPerformed(ActionEvent arg0) {
				  // ����Ŀ¼  
		        File dir = new File(textField_path.getText());  
		        // Ҫ���ҵĹؼ���  
		        String key = textField_target.getText();  
		        // ��ӡ�ļ�����Ϣ  
		        fileInfo = new Vector<String>();  
		        dirInfo = new Vector<String>();  
		        fm = dir.listFiles();  
		        for (File file : fm) {  
		        	if(file.getName().indexOf(key) >= 0)
		        	{
			            if (file.isFile()) 
			            {  
			                fileInfo.addElement(file.getName()+"  [file]");  
			            } 
			            else if (file.isDirectory()) 
			            {  
			                dirInfo.addElement(file.getName() +"  [dir]");  
			            }  
		        	}
		        }  
		        /**
		         * ������Ϣ��
		         * Console���������ϸ��Ϣ
		         */
		        System.out.println(dir.getAbsolutePath());
		        System.out.println("contains : ");  
		        System.out.println("file -> " + fileInfo);  
		        System.out.println("dir  -> " + dirInfo);  
		        
		        if(list_file != null)
		        {
		        	list_file.removeAll();
		        }
		        list_file = new JList<String>(fileInfo);
		        scrollPaneForFile.setViewportView(list_file);
		        if(list_dir != null)
		        {
		        	list_dir.removeAll();
		        }
		        list_dir = new JList<String>(dirInfo);
		        scrollPaneForDir.setViewportView(list_dir);
		        //list.setVisible(true);
			}
		});
		button_search.setBounds(435, 22, 119, 29);
		searchpanel.add(button_search);
		
		scrollPaneForFile = new JScrollPane();
		scrollPaneForFile.setBounds(10, 167, 280, 288);
		getContentPane().add(scrollPaneForFile);
		
		list_file = new JList();
		scrollPaneForFile.setViewportView(list_file);
		
		scrollPaneForDir = new JScrollPane();
		scrollPaneForDir.setBounds(300, 167, 279, 288);
		getContentPane().add(scrollPaneForDir);
		
		list_dir = new JList();
		scrollPaneForDir.setViewportView(list_dir);
		
		JLabel lblFile = new JLabel("File");
		lblFile.setBounds(10, 152, 54, 15);
		getContentPane().add(lblFile);
		
		JLabel lblDirectory = new JLabel("Directory");
		lblDirectory.setBounds(300, 152, 54, 15);
		getContentPane().add(lblDirectory);
		
		JLabel lblAuthor = new JLabel("Author: ����S(1427405017)");
		lblAuthor.setBounds(429, 455, 164, 15);
		getContentPane().add(lblAuthor);
		lblAuthor.setFont(UIManager.getFont("Label.font"));
		lblAuthor.setForeground(Color.GRAY);
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
    /** 
     * main ����
     * �����ʼ��FileFilterFrame���ṩ��GUI����ʵ������
     */  
	public static void main(String args[])
	{
		FileFilterFrame ffframe = new FileFilterFrame(); 
		ffframe.setVisible(true);
	}
	
}  
