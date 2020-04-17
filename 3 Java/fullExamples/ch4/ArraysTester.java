package ch4;

import java.util.Arrays;

public class ArraysTester {
	public static void testStringArray(){
		String[] s1={"Tom1","Jack","Mike","Mary","Tom2"};
		String[] s2={"Tom1","Jack","Mike","Mary","Tom2"};
		System.out.println(s1.equals(s2));
		System.out.println("s1�Ƿ���s2��ȣ�"+Arrays.equals(s1,s2));
		Arrays.sort(s1);
		System.out.println("s1�����s1��s2�Ƿ���ȣ�"+Arrays.equals(s1,s2));
		System.out.println("Jack��s1�����е�λ�ã�"+Arrays.binarySearch(s1,"Jack"));
		System.out.println("Jack��s2�����е�λ�ã�"+Arrays.binarySearch(s2,"Jack"));
		System.out.println("s1:"+Arrays.toString(s1));
		System.out.println("S1:"+s1.toString());
		System.out.println("s2:"+Arrays.toString(s2));
	}
	
	public static void testIntArray(){
		int[] s1=new int[5],s2=new int[5],s3={4,5,6,3,9,4};
		Arrays.fill(s1,100);
		System.arraycopy(s1,0,s2,0,s1.length);
		System.out.println("s1�Ƿ���s2��ȣ�"+Arrays.equals(s1,s2));
		Arrays.sort(s3);
		System.out.println("5��s3�е�λ�ã�"+Arrays.binarySearch(s3,5));
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
