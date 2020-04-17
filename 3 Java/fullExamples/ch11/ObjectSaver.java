package ch11;
import java.util.*;
import java.io.*;

class Customer implements Serializable{
	private static final long serialVersionUID = 1L;
	
	private String name;
	private int age;
	public Customer(String n,int a){
		name=n;
		age=a;
	}
	public boolean equals(Object o){
		if (this==o)
			return true;
		if (o instanceof Customer)
		{
			Customer other=(Customer)o;
			if (this.name.equals(other.name)&& this.age==other.age)
				return true;
		}
		return false;
	}
	public String toString(){
		return ("Name:"+name+",Age:"+age);
	}
	public void setAge(int a){
		age=a;
	}
}

public class ObjectSaver {
	public static void main(String[] args) throws IOException, ClassNotFoundException{
		ObjectOutputStream out=new ObjectOutputStream(new FileOutputStream("g:\\obj.dat"));
		String obj1="Hello";
		Date obj2=new Date();
		Customer obj3=new Customer("Tom",20);
		/**序列化对象*/
		out.writeObject(obj1);
		out.writeObject(obj2);
		out.writeObject(obj3);
		out.close();
		
		/**反序列化对象*/
		ObjectInputStream in=new ObjectInputStream(new FileInputStream("g:\\obj.dat"));
		String obj11=(String)in.readObject();
		System.out.println("Obj11? "+obj11);
		System.out.println("Obj11==obj1? "+(obj1==obj11));
		System.out.println("Obj11 equals obj1? "+(obj1.equals(obj11)));
		System.out.println();
		
		Date obj22=(Date)in.readObject();
		System.out.println("Obj22? "+obj22);
		System.out.println("Obj22==obj2? "+(obj2==obj22));
		System.out.println("Obj22 equals obj2? "+(obj2.equals(obj22)));
		System.out.println();
		
		Customer obj33=(Customer)in.readObject();
		System.out.println("Obj33? "+obj33);
		System.out.println("Obj33==obj3? "+(obj3==obj33));
		System.out.println("Obj33 equals obj3? "+(obj3.equals(obj33)));
		in.close();
		obj3.setAge(100);
		System.out.println("Obj3:"+obj3);
		System.out.println("Obj33:"+obj33);
	}
}
