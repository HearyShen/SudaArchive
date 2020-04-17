package ch13;

class PrtChar implements Runnable{
	private char prtCh;
	private int times;
	public PrtChar(char ch,int tms){
		prtCh=ch;
		times=tms;
	}
	public void run() {
		for (int i=0;i<times;i++)
			System.out.print(prtCh);
	}	
}

class PrtNum implements Runnable{
	private int first,last;
	public PrtNum(int f,int l){
		first=f;
		last=l;
	}
	public void run() {
		for (int i=first;i<=last;i++)
			System.out.print(i+" ");
	}
}

public class TestRunnable{
	public static void main(String[] args) throws InterruptedException{
		Thread pA=new Thread(new PrtChar('a',100));
		Thread pB=new Thread(new PrtChar('b',100));
		Thread pN=new Thread(new PrtNum(1,500));
		pN.start();
		pA.start();
		pB.start();
		pA.join();
		System.out.println("End of main");
	}
}
