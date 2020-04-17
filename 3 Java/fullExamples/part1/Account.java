package part1;

import java.util.*;

import javax.swing.JOptionPane;


class Person{
	private String address;
	public void changeAdd()
	{
		
	}
	
}

public class Account {
	private String id;
	private String password;
	private double balance;
	private Date vdt;
	private Person owner;
	
	
	
	public boolean changePass()
	{
		return true;
	}
	
	public boolean saving(double b)
	{
		return true;
	}
	
	public boolean withdraw(double b)
	{
		if (this.isValidate()==false)
			return false;
		if (b<=0 || this.balance<b)
			return false;
		this.balance-=b;
		return true;
	}
	
	public boolean browseBal()
	{
		return true;
	}
	
	public boolean browseVdt()
	{
		return true;
	}
	
	private boolean isValidate()
	{
		String pass=JOptionPane.showInputDialog("请输入当前密码：");
		return (this.password.equals(pass));
	}
	
	//构造函数
	public Account(double bal,String pass,Person p)
	{
		this(p);
		password=pass;
		this.balance=bal;
	}
	
	public Account(Person p)
	{
		id=Account.generateID();
		password="0000";
		this.balance=0;
		this.vdt=Account.generateVDt();
		this.owner=p;
	}
	
	private static Date generateVDt()
	{
		GregorianCalendar dt=new GregorianCalendar();
		dt.add(GregorianCalendar.YEAR, 3);
		return (dt.getTime());
	}
	
	private static String generateID()
	{
		String str="628384885855";
		str+=(int)(Math.random()*(999-100))+100;
		return str;
	}
}
