package ch5;

public class BufferTest {

	public static void main(String[] args) {
		String tmp=javax.swing.JOptionPane.showInputDialog("���������⴮��");
		StringBuffer str=new StringBuffer(tmp);
		str.reverse();
		if (str.toString().equals(tmp))
			javax.swing.JOptionPane.showMessageDialog(null,"�ǻ��ģ�");
		else
			javax.swing.JOptionPane.showMessageDialog(null,"���ǻ��ģ�");
	}

}
