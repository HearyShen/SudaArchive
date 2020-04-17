package ch5;

public class BufferTest {

	public static void main(String[] args) {
		String tmp=javax.swing.JOptionPane.showInputDialog("请输入任意串：");
		StringBuffer str=new StringBuffer(tmp);
		str.reverse();
		if (str.toString().equals(tmp))
			javax.swing.JOptionPane.showMessageDialog(null,"是回文！");
		else
			javax.swing.JOptionPane.showMessageDialog(null,"不是回文！");
	}

}
