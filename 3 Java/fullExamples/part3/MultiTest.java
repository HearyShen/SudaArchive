package part3;

class Person{
	String pid;
	String name;
	public Person(String id,String nm)
	{
		pid=id;
		name=nm;
	}
	public void print()
	{
		System.out.println("身份证："+pid);
		System.out.println("姓名："+name);
	}
}

class Student extends Person{
	String sid;
	int grade;
	
	public Student(String pid,String nm,String id, int g)
	{
		super(pid,nm);
		sid=id;
		grade=g;
	}
	public void print()
	{
		super.print();
		System.out.println("学号："+sid);
		System.out.println("年级："+grade);
	}
	public void changeGrade(int g)
	{
		grade=g;
	}
}

public class MultiTest {
	public static void test(Person p){
		p.print();
	}
	public static void main(String[] args){
		Person p=new Person("001","张三");
		p.print();
		System.out.println("=================================");
		p=new Student("002","李四","123",2);
		p.print();
	}
}
