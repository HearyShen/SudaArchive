package ch5;
/*�ж��û������Email��ַ�Ƿ�Ϸ�
�����ַ�϶���@�ַ�
����ں������ַ��г���@�ַ�������Ҳ���Ϸ�
��������ַ��@�ĸ�����ֹһ����Ҳ���Ϸ�
���@�ַ���û�С�.���ַ�����.����ֻ��һ���ַ����������ַ���Ϸ�
 */
import javax.swing.*;
public class exam02 {
	private static boolean isValidate(String email){
		int pos=email.indexOf("@");
		if (pos<0)
			return false;
		if (email.length()-pos<=3)
			return false;
		if (email.substring(pos+1).indexOf("@")>=0)
			return false;
		String tmpS=email.substring(pos+1);
		pos=tmpS.indexOf(".");
		if (pos<0)
			return false;
		if (tmpS.length()-pos<=2)
			return false;
		return true;
	}
	public static void main(String[] args){
		String tmp=JOptionPane.showInputDialog("����������Email��");
		if (exam02.isValidate(tmp))
			JOptionPane.showMessageDialog(null,"Email�Ϸ���");
		else
			JOptionPane.showMessageDialog(null,"Email�Ƿ���");
	}
}
