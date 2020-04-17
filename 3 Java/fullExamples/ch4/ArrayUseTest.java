package ch4;

/**
 * 数组对象使用示例
 * @author Administrator
 */
public class ArrayUseTest {
	public static void main(String[] args)
	{
		int[] a={3,4,5,6};
		int[] b={3,4,5,6};
		int[] c=a;
		int[][] d=new int[2][];
		
		d[0]=new int[4];
		d[0][0]=3;
		d[0][1]=4;
		d[0][2]=5;
		d[0][3]=6;
		System.out.println(a instanceof Object);
		System.out.println(c instanceof int[]);
		System.out.println(d instanceof int[][]);
		System.out.println(d[1] instanceof Object);
		System.out.println("************************************");
		System.out.println(a==d[0]);
		System.out.println(a.equals(d[0]));
		System.out.println(a==c);
		System.out.println(a.equals(c));
		System.out.println(a.equals(b));
	}
}
