package ch11;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.io.*;
import java.util.zip.*;

public class ZipTest extends JFrame{

	private static final long serialVersionUID = 1L;
	private final static int DEFAULT_WIDTH=300;
	private final static int DEFAULT_HEIGHT=400;
	private JComboBox fileComb;
	private JTextArea fileText;
	private String zipName;
	
	private class OpenAction implements ActionListener{
		public void actionPerformed(ActionEvent e){
			JFileChooser chooser=new JFileChooser();
			chooser.setCurrentDirectory(new File("."));
			int r=chooser.showOpenDialog(ZipTest.this);
			if (r==JFileChooser.APPROVE_OPTION){
				zipName=chooser.getSelectedFile().getPath();
				scanZipFile();
			}
		}
	}
	
	/**
	 * scans the contents of the zip archive and populates the combo
	 */
	public void scanZipFile(){
		fileComb.removeAllItems();
		try{
			ZipInputStream zin=new ZipInputStream(new FileInputStream(zipName));
			ZipEntry entry=zin.getNextEntry();
			while (entry!=null){
				fileComb.addItem(entry.getName());
				zin.closeEntry();
				entry=zin.getNextEntry();
			}
			zin.close();
		}catch(IOException e){
			System.err.println(e.getMessage());
		}
	}
	
	/**
	 * Loads a file from the zip archive into the text area
	 */
	public void loadZipFile(String name){
		try{
			ZipInputStream zin=new ZipInputStream(new FileInputStream(zipName));
			ZipEntry entry;
			fileText.setText("");
			//find entry matching the name
			while ((entry=zin.getNextEntry())!=null){
				if (entry.getName().equals(name))
				{
					//找到了要加载的文件对应条目
					BufferedReader in=new BufferedReader(new InputStreamReader(zin));
					String line;
					while ((line=in.readLine())!=null){
						fileText.append(line);
						fileText.append("\n");
					}
					zin.closeEntry();
					break;
				}
				zin.closeEntry();
			}
			zin.close();
		}catch(IOException e){
			System.err.println(e.getMessage());
		}
	}
	
	public ZipTest(){
		setTitle("ZipTest");
		setSize(DEFAULT_WIDTH,DEFAULT_HEIGHT);
		//do something about menu
		JMenuBar mbar=new JMenuBar();
		JMenu menu=new JMenu("File");
		JMenuItem openItem=new JMenuItem("Open");
		menu.add(openItem);
		openItem.addActionListener(new OpenAction());
		JMenuItem exitItem=new JMenuItem("Exit");
		menu.add(exitItem);
		exitItem.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				System.exit(0);
			}
		});
		mbar.add(menu);
		setJMenuBar(mbar);
		
		//do something about textArea and combobox
		fileText=new JTextArea();
		fileComb=new JComboBox();
		fileComb.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				loadZipFile((String)fileComb.getSelectedItem());
			}
		});
		add(fileComb,BorderLayout.SOUTH);
		add(new JScrollPane(fileText),BorderLayout.CENTER);
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
	
	public static void main(String[] args){
		new ZipTest();
	}
}
