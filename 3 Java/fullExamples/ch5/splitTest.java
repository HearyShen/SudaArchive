package ch5;

public class splitTest {
	public static void main(String[] args){
		String str="Hello£»world£»ttt£»aaa£»kkk";
		String[] tmp=str.split("£»");
		if (tmp!=null)
			for (int i=0;i<tmp.length;i++)
				System.out.println(tmp[i]);
		System.out.println("PI="+String.valueOf(Math.PI));
	}
}
