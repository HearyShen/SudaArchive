package GUI;

abstract class Employee{
	String pid;
	String name;
	String address;
	
	public Employee(String id,String nm,String add)
	{
		this.pid=id;
		this.name=nm;
		this.address=add;
	}
	
	public void print()
	{
		System.out.println("身份号："+pid);
		System.out.println("姓名："+name);
		System.out.println("联系方式："+address);
	}
	
	abstract public void changeAct(String at);
}

class Manger extends Employee{
	String act;		//承担的职务
	
	public Manger(String id,String nm,String add,String at)
	{
		super(id,nm,add);
		this.act=at;
	}
	
	public Manger(Employee e,String at)
	{
		super(e.pid,e.name,e.address);
		this.act=at;
	}
	
	public void print()
	{
		super.print();
		System.out.println("职务："+this.act);
	}
	
	public void changeAct(String at)
	{
		this.act=at;
	}
}


public class MainTest {
	
	public static void test(Employee e)
	{
		e.print();
		System.out.println("=========================");
	}
	
	public static void main(String[] args)
	{
		//Employee x=new Employee("001","张三","12344555");
		Employee y=new Manger("002","李四","4445546546546","CEO");
		//Employee z=new Manger(x,"部门主管");
		
		/*
		x.print();
		System.out.println("=========================");
		y.print();
		System.out.println("=========================");
		z.print();
		//*/
		
		
		
		//*
		//MainTest.test(x);
		MainTest.test(y);
		//MainTest.test(z);
		//*/
	}

}
