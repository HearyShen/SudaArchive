/*
 * ʵ��һ
 * SalesCount.java
 * 1427405017
 * ����S
 */

import javax.swing.*;

public class SalesCount {
	private static int target_salary = 5000;
	private static int basic_salary = 5000;
	public static void main(String[] args) {
		String str = JOptionPane.showInputDialog("������Ŀ�����룺");
		target_salary = Integer.parseInt(str);
		
		int addition_salary = target_salary - basic_salary;
		double min_sales = 0;
		if(addition_salary < 0)
		{
			JOptionPane.showMessageDialog(null,"����Ŀ�����벻�ɵ��ڻ������룡");
			return;
		}
		else if(addition_salary <= 5000*0.08)
		{
			min_sales = addition_salary/0.08;
		}
		else if(addition_salary <= 5000*0.08 + (10000-5000)*0.1)
		{
			min_sales = 5000 + (addition_salary - 5000*0.08)/0.1;
		}
		else
		{
			min_sales = 10000 + (addition_salary - 5000*0.08 - (10000-5000)*0.1)/0.12;
		}
		
		System.out.println("��С���۶"+min_sales);
		JOptionPane.showMessageDialog(null,"��С���۶"+min_sales);
	}
}
