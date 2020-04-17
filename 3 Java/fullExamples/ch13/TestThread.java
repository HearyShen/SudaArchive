package ch13;

class PrintChar extends Thread{
	private char charToPrint;
	private int times;
	
	public PrintChar(char c,int i){
		charToPrint=c;
		times=i;
	}
	
	public void run(){
		for (int i=0;i<times;i++)
			System.out.print(charToPrint);
	}
}

class PrintNum extends Thread{
	private int firstNum,lastNum;
	public PrintNum(int f,int l){
		firstNum=f;
		lastNum=l;
	}
	public void run(){
		for (int i=firstNum;i<=lastNum;i++)
			System.out.print(i+" ");
	}
}

public class TestThread {
	public static void main(String[] args){
		PrintChar pA=new PrintChar('a',100);
		PrintChar pB=new PrintChar('b',100);
		PrintNum pN=new PrintNum(1,500);
		pN.start();
		pA.start();
		pB.start();		
	}
}
