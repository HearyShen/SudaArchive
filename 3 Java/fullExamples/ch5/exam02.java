package ch5;
/*判断用户输入的Email地址是否合法
邮箱地址肯定有@字符
如果在后三个字符中出现@字符，输入也不合法
如果邮箱地址中@的个数不止一个，也不合法
如果@字符后没有“.”字符，或“.”后只有一个字符，则邮箱地址不合法
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
		String tmp=JOptionPane.showInputDialog("请输入您的Email：");
		if (exam02.isValidate(tmp))
			JOptionPane.showMessageDialog(null,"Email合法！");
		else
			JOptionPane.showMessageDialog(null,"Email非法！");
	}
}
