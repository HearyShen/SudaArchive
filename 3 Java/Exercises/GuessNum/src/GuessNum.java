/*
 * 实验一
 * GuessNum.java
 * 1427405017
 * 沈家赟
 */
import javax.swing.*;
//import java.Math.*;

public class GuessNum {
	public static int target_num = 0;
	public static void main(String[] args) {
		target_num = (int)(Math.random()*100);
		while(true)
		{
			String str = JOptionPane.showInputDialog("请输入一个数字：");
			int input_num = Integer.parseInt(str);
			if(input_num < target_num)
			{
				JOptionPane.showMessageDialog(null, "小于目标值！");
			}
			else if(input_num == target_num)
			{
				JOptionPane.showMessageDialog(null, "猜对了！");
				target_num = (int)(Math.random()*100);
			}
			if(input_num > target_num)
			{
				JOptionPane.showMessageDialog(null, "大于目标值！");
			}
		}
	}
}
