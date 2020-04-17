package ch4;

class Person{
	Person()
	{
		
	}
}

public class MAccount {
	String id;
	Person owner;
	double crid;
	double balance;
	String address;
	String password;
	static double rate;
	static double lateFeerate;
	static{
		rate=3.5;
		lateFeerate=2.8;
	}
	
	static void modiRate(double stp)
	{
		String[] x=new String[100];
		for (int i=0;i<x.length;i++)
			x[i]=new String("xyz");
		
		for (String s:x)
			System.out.println(s);
		
		MAccount.rate+=stp;
	}
	private void generateId()
	{
		this.id="00000000";
	}
	private void generateCrid()
	{
		this.crid=5000;
	}
	public MAccount(Person o,double d,String add,String pass)
	{
		this.owner=o;
		this.balance=d;
		this.address=add;
		this.generateId();
		this.generateCrid();
		this.password=pass;
	}
	public MAccount()
	{
		this.generateId();
		this.owner=null;
		this.crid=0;
		this.balance=0;
		this.address=null;
		this.password="0000";
	}
	
	private boolean isValidate(String pass)
	{
		return (this.password.equals(pass));
	}
	
	public boolean save(String pass, double bal)
	{
		boolean vad=isValidate(pass);
		if (!vad)
		{
			System.out.println("ÃÜÂë´íÎó£¡");
			return false;
		}
		if (bal<=0)
		{
			System.out.println("½ð¶î´íÎó£¡");
			return false;
		}
		this.balance+=bal;
		return true;
	}
	
	public static void main(String[] args)
	{
		MAccount acc=new MAccount();
		acc.save("0000", 2000);
	}
}
