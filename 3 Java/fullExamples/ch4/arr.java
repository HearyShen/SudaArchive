package ch4;

public class arr {
	public static void PTest(int[] a){
		a=new int[4];
		for (int i=0;i<a.length;i++)
			a[i]+=10;
	}
	
	public static void main(String[] arg){
		int[] a={1,2,3,4};
		arr.PTest(a);
		for (int i=0;i<a.length;i++)
			System.out.print(a[i]+",");
		String a1,b1;
		a1="S";
		b1="S";
		System.out.println(a1);
		System.out.println(b1);
	}
}
