/*
 * ʵ��һ
 * GuessNum.java
 * 1427405017
 * ����S
 */
import javax.swing.*;
//import java.Math.*;

public class GuessNum {
	public static int target_num = 0;
	public static void main(String[] args) {
		target_num = (int)(Math.random()*100);
		while(true)
		{
			String str = JOptionPane.showInputDialog("������һ�����֣�");
			int input_num = Integer.parseInt(str);
			if(input_num < target_num)
			{
				JOptionPane.showMessageDialog(null, "С��Ŀ��ֵ��");
			}
			else if(input_num == target_num)
			{
				JOptionPane.showMessageDialog(null, "�¶��ˣ�");
				target_num = (int)(Math.random()*100);
			}
			if(input_num > target_num)
			{
				JOptionPane.showMessageDialog(null, "����Ŀ��ֵ��");
			}
		}
	}
}
