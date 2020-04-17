package ch5;
/*已知以分号；间隔若干姓名
将输入姓名中包含“Wang”的替换成“Zhang”
将输入姓名按倒序输出
*/
import javax.swing.*;
public class exam03 {
	public static void main(String[] args){
		String tmp=JOptionPane.showInputDialog("请输入分号间隔的若干姓名:");
		tmp=tmp.replaceAll("Wang","Zhang");
		String[] names=tmp.split(";");
		if (names!=null)
			for (int i=names.length-1;i>=0;i--)
				System.out.println(names[i]);
	}
}
