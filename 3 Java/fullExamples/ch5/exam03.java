package ch5;
/*��֪�Էֺţ������������
�����������а�����Wang�����滻�ɡ�Zhang��
�������������������
*/
import javax.swing.*;
public class exam03 {
	public static void main(String[] args){
		String tmp=JOptionPane.showInputDialog("������ֺż������������:");
		tmp=tmp.replaceAll("Wang","Zhang");
		String[] names=tmp.split(";");
		if (names!=null)
			for (int i=names.length-1;i>=0;i--)
				System.out.println(names[i]);
	}
}
