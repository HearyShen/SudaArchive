package ch3;

import java.util.*;

public class ComputeChange {
	public static void main(String[] args) {
		double amount;// �ܽ��
		System.out.println("���������������磺11.56��");
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

		// ���
		System.out.println("5Ԫ������" + numOfFive);
		System.out.println("1Ԫ������" + numOfOne);
		System.out.println("1��������" + numOfOneS);
		System.out.println("5��������" + numOfFiveS);
		System.out.println("1��������" + numOfOneSS);
	}
}
