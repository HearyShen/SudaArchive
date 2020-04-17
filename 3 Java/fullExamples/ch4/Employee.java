package ch4;

import java.sql.Date;

abstract class Employ {
	String name;
	double salary;
	
	public Employ(String n)
	{
		this.name=n;
		this.salary=2000;
	}
	
	public void print()
	{
		System.out.println("Name:"+name);
		System.out.println("Salary:"+salary);
	}
	
	abstract public void upBoune(double b);
}

class Manager extends Employ{
	double boune;
	public Manager(String n)
	{
		super(n);
		this.boune=1000;
	}
	public void upBoune(double b)
	{
		System.out.println("Manager");
		this.boune+=b;
	}
}

class TeamLeader extends Employ implements Comparable<TeamLeader>{
	double boune;
	double effect;
	Date dt;
	public TeamLeader(String n){
		super(n);
	}
	public void upBoune(double b){
		System.out.println("TeamLeader");
		boune+=b/12.0;
	}
	@Override
	public int compareTo(TeamLeader arg0) {
		// TODO Auto-generated method stub
		if (this.effect>=arg0.effect)
			return 1;
		return 0;
	}
}

public class Employee{
	public static void test(Employ e)
	{
		e.upBoune(1000);
	}
	
	public static void main(String[] args){
		test(new Manager("Zhang"));
		test(new TeamLeader("Wang"));
	}
}

