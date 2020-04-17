package ch5;

public class TestObj implements Cloneable{
	int x;
	double y;
	
	public TestObj(int tx,double ty){
		x=tx;
		y=ty;
	}
	public Object Clone(){
		TestObj o=new TestObj(x,y);
		return o;		
	}	
	public boolean equals(Object o){
		if (o==this)
			return true;
		if (!(o instanceof TestObj))
			return false;
		TestObj tmp=(TestObj)o;
		return (tmp.x==this.x&&tmp.y==this.y);
	}	
	public void modiX(int tx){
		x=tx;
	}	
	public String toString(){
		String str="x="+x+",y="+y;
		return str;
	}
	public static void main(String[] args){
		TestObj o=new TestObj(200,300);
		TestObj obk=(TestObj)o.Clone();
		System.out.println(o==obk);		
		System.out.println(o.equals(obk));
		obk.modiX(20);
		System.out.println(o.equals(obk));
		System.out.println("******************");
		obk=o;
		System.out.println(o==obk);		
		System.out.println(o.equals(obk));
		obk.modiX(2000);
		System.out.println(o.equals(obk));
		System.out.println("******************");
		System.out.println(obk);
		//System.out.println(obk.toString());
	}
}
