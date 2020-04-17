package ch3;


public class Test {
	public static void main(String[] args){
		if (args==null || args.length<=0)
			System.out.println("No Parameter!");
		else
			System.out.println("Hello,"+args[0]);
	}
}
