package ch3;
import java.util.*;

public class ComputeMortgage {
	public static void main(String[] args){
		double annualInterestRate;
		int numOfYears;
		double loanAmount;
		
		System.out.println("�����������ʣ����磺8.25��");
		Scanner sc=new Scanner(System.in);
		annualInterestRate=sc.nextDouble();
		double monthlyInterestRate=annualInterestRate/1200;
		
		System.out.println("������������������磺5��");
		numOfYears=sc.nextInt();
		
		System.out.println("������������������磺12000.95��");
		loanAmount=sc.nextDouble();
		
		sc.close();
		
		double monthlyPayment=loanAmount*monthlyInterestRate/
			(1-1/Math.pow(1+monthlyInterestRate,numOfYears*12));
		double totalPayment=monthlyPayment*12;
		
		System.out.println("�³�����"+monthlyPayment);
		System.out.println("�ܳ�����"+totalPayment);
	}
}
