package ch4;

class MyDate{
	int year,month,day;
	public MyDate(int y,int m,int d){
		year=y;
		month=m;
		day=d;
	}	
	public boolean equals(Object o){
		if (o==this)
			return true;
		if (o instanceof MyDate)
		{
			MyDate dt=(MyDate)o;
			return (dt.year==this.year&&dt.month==this.month&&dt.day==this.day);
		}
		return false;
	}	
}
public class MainTest {
	public static void main(String[] arg)
	{
		String s1,s2;
		s1=new String("hello");
		s2=s1;
		System.out.println(s1==s2);	//s1和s2是否引向同一个实例
		System.out.println(s1.equals(s2));	//引向的实例内容是否相等
		
		MyDate dt1=new MyDate(2007,4,11);
		MyDate dt2=new MyDate(2007,4,11);
		System.out.println(dt1==dt2);
		System.out.println(dt1.equals(dt2));
	}
}
