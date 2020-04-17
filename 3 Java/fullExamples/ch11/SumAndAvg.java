package ch11;
import java.io.*;
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class SumAndAvg extends JFrame{
	private static final long serialVersionUID = 1L;
	private JTextField sum;
	private JTextField avg;
	
	public SumAndAvg(){
		JMenuBar b=new JMenuBar();
		JMenu f=new JMenu("File");
		JMenuItem o=new JMenuItem("Open");
		o.addActionListener(new Cal());
		JMenuItem e=new JMenuItem("Exit");
		e.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				System.exit(0);
			}
		});
		f.add(o);
		f.add(e);
		b.add(f);
		this.setJMenuBar(b);
		
		Box bx=Box.createVerticalBox();
		bx.add(Box.createVerticalStrut(35));
		
		Box b1=Box.createHorizontalBox();
		b1.add(Box.createHorizontalStrut(30));
		b1.add(new JLabel("总成绩为："));
		sum=new JTextField();
		b1.add(Box.createHorizontalStrut(20));
		b1.add(sum);
		b1.add(Box.createHorizontalStrut(30));
		
		bx.add(b1);
		bx.add(Box.createVerticalStrut(30));
		
		b1=Box.createHorizontalBox();
		b1.add(Box.createHorizontalStrut(30));
		b1.add(new JLabel("平均成绩："));
		avg=new JTextField();
		b1.add(Box.createHorizontalStrut(20));
		b1.add(avg);
		b1.add(Box.createHorizontalStrut(30));
		
		bx.add(b1);
		bx.add(Box.createVerticalStrut(35));
		this.getContentPane().add(bx,BorderLayout.CENTER);
		
		this.setSize(354,224);
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	private void caluate(String f) throws IOException{
		StreamTokenizer o=new StreamTokenizer(new FileReader(f));
		o.nextToken();
		int count=0;
		double s=0;
		while (o.ttype!=StreamTokenizer.TT_EOF){
			count++;
			s+=o.nval;
			o.nextToken();
		}
		sum.setText(String.valueOf(s));
		if (count!=0)
			s=s/count;
		avg.setText(String.valueOf(s));
	}
	
	class Cal implements ActionListener{
		public void actionPerformed(ActionEvent e){
			JFileChooser ch=new JFileChooser();
			int answer=ch.showOpenDialog(SumAndAvg.this);
			if (answer==JFileChooser.APPROVE_OPTION){
				//-----从文件读取，并计算
				try {
					String fd=ch.getSelectedFile().getPath();
					caluate(fd);
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		}
	}
	
	public static void main(String[] args){
		new SumAndAvg();
	}
}
