package ch4;

import java.util.Arrays;

public class ArraysTester {
	public static void testStringArray(){
		String[] s1={"Tom1","Jack","Mike","Mary","Tom2"};
		String[] s2={"Tom1","Jack","Mike","Mary","Tom2"};
		System.out.println(s1.equals(s2));
		System.out.println("s1是否与s2相等："+Arrays.equals(s1,s2));
		Arrays.sort(s1);
		System.out.println("s1排序后，s1和s2是否相等："+Arrays.equals(s1,s2));
		System.out.println("Jack在s1数组中的位置："+Arrays.binarySearch(s1,"Jack"));
		System.out.println("Jack在s2数组中的位置："+Arrays.binarySearch(s2,"Jack"));
		System.out.println("s1:"+Arrays.toString(s1));
		System.out.println("S1:"+s1.toString());
		System.out.println("s2:"+Arrays.toString(s2));
	}
	
	public static void testIntArray(){
		int[] s1=new int[5],s2=new int[5],s3={4,5,6,3,9,4};
		Arrays.fill(s1,100);
		System.arraycopy(s1,0,s2,0,s1.length);
		System.out.println("s1是否与s2相等："+Arrays.equals(s1,s2));
		Arrays.sort(s3);
		System.out.println("5在s3中的位置："+Arrays.binarySearch(s3,5));
		System.out.println("s1:"+Arrays.toString(s1));
		System.out.println("s2:"+Arrays.toString(s2));
		System.out.println("s3:"+Arrays.toString(s3));
	}
	
	public static void main(String[] args) {
		ArraysTester.testStringArray();
		System.out.println("***********************************************");
		//ArraysTester.testIntArray();
	}
}
