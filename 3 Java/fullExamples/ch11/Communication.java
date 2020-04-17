package ch11;

import java.io.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import common.CommVars;

import java.util.*;

class Infomation implements Serializable {
	private static final long serialVersionUID = 1L;

	private String[] infos;

	public Infomation(String[] tmp) {
		infos = new String[tmp.length];
		for (int i = 0; i < tmp.length; i++)
			infos[i] = new String(tmp[i]);
	}

	public String getInfo(int i) {
		return infos[i];
	}

	public String getAllInfo() {
		String str = infos[0];
		for (int i = 1; i < infos.length; i++)
			str += "," + infos[i];
		return str;
	}

	public boolean cmp(String o) {
		if (this.getInfo(infos.length - 1).equals(o))
			return true;
		return false;
	}
}

public class Communication extends JFrame {
	private static final long serialVersionUID = 1L;

	private JTextField[] info; // 文本框
	private static String[] lbl = { "姓名：", "邮编：", "地址：", "电话：", "手机：", "Email:" }; // label上的文字
	private JButton[] btns; // 按钮
	private static String[] btnLbl = { "添加", "查找", "清空", "退出" };
	private ArrayList lst = null;
	private final String fName = CommVars.DTP_PROJECT+"out\\tmp.dat";

	private void reset() {
		for (int i = 0; i < info.length; i++)
			info[i].setText("");
	}

	public Communication() throws IOException, ClassNotFoundException {
		// -----------从文件中读取
		JPanel jp;
		readInfo();

		this.setTitle("通信簿");
		this.setSize(400, 400);

		Container cp = this.getContentPane();
		jp = new JPanel();
		jp.add(new JLabel("通信簿"));
		cp.add(jp, BorderLayout.NORTH);

		Box b = Box.createVerticalBox();
		b.add(Box.createVerticalStrut(20));
		info = new JTextField[lbl.length];
		for (int i = 0; i < lbl.length; i++) {
			info[i] = new JTextField();
			Box tmp = Box.createHorizontalBox();
			tmp.add(Box.createHorizontalStrut(20));
			tmp.add(new JLabel(lbl[i]));
			tmp.add(Box.createHorizontalStrut(20));
			tmp.add(info[i]);
			tmp.add(Box.createHorizontalStrut(20));
			b.add(tmp);
			b.add(Box.createVerticalStrut(20));
		}
		
		InfoOperate opt=new InfoOperate();
		btns = new JButton[btnLbl.length];
		jp = new JPanel();
		for (int i = 0; i < btns.length; i++) {
			btns[i] = new JButton(btnLbl[i]);
			// ----------追加事件
			btns[i].addActionListener(opt);
			jp.add(btns[i]);
		}

		Box t = Box.createHorizontalBox();
		t.add(jp);
		b.add(t);
		b.add(Box.createVerticalStrut(20));
		cp.add(b, BorderLayout.CENTER);

		// -------------------------------------------------
		this.setVisible(true);
		this.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent arg0) {
				try {
					writeInfo();
				} catch (IOException e) {
					e.printStackTrace();
				}
				System.exit(0);
			}
		});
	}

	public static void main(String[] args) throws IOException,ClassNotFoundException {
		new Communication();
	}

	private void writeInfo() throws IOException {
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(
				fName));
		out.writeObject(lst);
		out.close();
	}

	private void readInfo() throws IOException, ClassNotFoundException {
		File fd = new File(fName);
		if (!fd.exists()) {
			lst = new ArrayList();
			return;
		}
		ObjectInputStream in = new ObjectInputStream(new FileInputStream(fName));
		lst = (ArrayList) in.readObject();
		in.close();
	}

	class InfoOperate implements ActionListener {
		private Infomation getObject() {
			String[] tmpStr = new String[info.length];
			for (int i = 0; i < info.length; i++)
				tmpStr[i] = info[i].getText();
			Infomation tmpO = new Infomation(tmpStr);
			return tmpO;
		}

		private void AddObject() {
			// ---------合法性检验
			lst.add(getObject());
		}

		private int SearchObject() {
			for (int i = 0; i < lst.size(); i++) {
				Infomation inf = (Infomation) lst.get(i);
				if (inf.cmp(info[info.length - 1].getText()) == true)
					return i;
			}
			return -1;
		}

		public void actionPerformed(ActionEvent arg0) {
			String tmpStr = arg0.getActionCommand();
			if (tmpStr.equals(btnLbl[0])) {
				AddObject();
				reset();
			} else if (tmpStr.equals(btnLbl[1])) {
				int i = SearchObject();
				if (i != -1) {
					Infomation tmpO = ((Infomation) lst.get(i));
					for (int j = 0; j < info.length; j++)
						info[j].setText(tmpO.getInfo(j));
				} else
					javax.swing.JOptionPane.showMessageDialog(
							Communication.this, "未找到！");
			} else if (tmpStr.equals(btnLbl[2]))
				lst.clear();
			else if (tmpStr.equals(btnLbl[3])) {
				try {
					writeInfo();
				} catch (IOException e) {
					e.printStackTrace();
				}
				System.exit(0);
			} 
		}
	}
}
