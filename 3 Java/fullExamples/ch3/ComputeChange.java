package ch3;

import java.util.*;

public class ComputeChange {
	public static void main(String[] args) {
		double amount;// 总金额
		System.out.println("请输入总数，例如：11.56：");
		Scanner sc = new Scanner(System.in);
		amount = sc.nextDouble();
		sc.close();
		
		int remainingAmount = (int) (amount * 100);
		int numOfFive = remainingAmount / 500;
		remainingAmount = remainingAmount - numOfFive * 500;

		int numOfOne = remainingAmount / 100;
		remainingAmount -= numOfOne * 100;

		int numOfOneS = remainingAmount / 10;
		remainingAmount -= numOfOneS * 10;

		int numOfFiveS = remainingAmount / 5;
		remainingAmount -= numOfFiveS * 5;

		int numOfOneSS = remainingAmount;

		// 结果
		System.out.println("5元数量：" + numOfFive);
		System.out.println("1元数量：" + numOfOne);
		System.out.println("1角数量：" + numOfOneS);
		System.out.println("5分数量：" + numOfFiveS);
		System.out.println("1分数量：" + numOfOneSS);
	}
}
