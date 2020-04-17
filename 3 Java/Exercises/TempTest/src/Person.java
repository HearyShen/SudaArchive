public class Person{
	
	public String name=null, id=null;
	
	void Person(String i, String n){
		id=i;
		name=n;
	}
	
	void show()
	{
		System.out.println("Id:"+id);
		System.out.println("Name:"+name);
	}
	
	public static void main(String args[])
	{
		Person myPerson;
		myPerson = new Person("01", "test");
		myPerson.show();
	}
}
