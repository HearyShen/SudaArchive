/*
 * 实验二
 * Account
 * 1427405017
 * 沈家赟
 * 2016/3/17
 */

public class Account {
	private int id;
	private double balance;
	private double annualInterestRate;
	
	public Account(int new_id, double new_balance, double new_annualInterestRate)
	{
		setId(new_id);
		setBalance(new_balance);
		setAnnualInterestRate(new_annualInterestRate);
	}
	public int getId()
	{
		return id;
	}
	public double getBalance()
	{
		return balance;
	}
	public double getAnnualInterestRate()
	{
		return annualInterestRate;
	}
	public void setId(int new_id)
	{
		id = new_id;
	}
	public void setBalance(double new_balance)
	{
		balance = new_balance;
	}
	public void setAnnualInterestRate(double new_rate)
	{
		annualInterestRate = new_rate;
	}
	public double getMonthlyInterest()
	{
		return (annualInterestRate*balance)/12;
	}
	public void withdraw(double amount)
	{
		balance -= amount;
	}
	public void deposit(double amount)
	{
		balance += amount;
	}
	public String toString()
	{
		String info;
		
		info = "ID:" + id + " ";
		info += "Balance:" + balance + " ";
		info += "AnnualInterestRate:" + annualInterestRate + " ";
		
		return info;
	}
	public static void main(String[] args) {
		Account a = new Account(1122, 20000, 4.5/100);
		System.out.println(a.toString());
		a.withdraw(2500);
		System.out.println(a.toString());
		a.deposit(3000);
		System.out.println(a.toString() + "MonthlyInterestRate:" + a.getMonthlyInterest()/a.getBalance());
	}

}
