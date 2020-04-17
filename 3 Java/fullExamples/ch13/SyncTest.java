package ch13;

import java.util.Vector;

class SyncStack{
	private Vector buffer=new Vector(400,200);
	
	public synchronized char pop(){
		char c;
		while (buffer.size()==0){
			try{
				this.wait();
			}catch(InterruptedException e){
				System.out.println(e.getMessage());
			}
		}
		c=((Character)buffer.remove(buffer.size()-1)).charValue();
		return c;
	}
	
	public synchronized void push(char c)
	{		
		Character charObj=new Character(c);
		buffer.addElement(charObj);
		this.notify();
	}
}

class Producer implements Runnable{
	private SyncStack theStack;
	private int num;
	private static int counter=1;
	
	public Producer(SyncStack s)
	{
		theStack=s;
		num=counter++;
	}
	
	public void run()
	{
		char c;
		for (int i=0;i<20;i++){
			c=(char)(Math.random()*26+'A');
			theStack.push(c);
			System.out.println("Producer "+num+":"+c);
			try{
				Thread.sleep((int)(Math.random()*300));
			}catch(InterruptedException e){
				System.out.println(e.getMessage());
			}
		}
	}
}

class Consumer implements Runnable{
	private SyncStack theStack;		
	private int num;
	private static int counter=1;
	
	public Consumer(SyncStack s)
	{
		theStack=s;
		num=counter++;
	}
	
	public void run()
	{
		char c;
		for (int i=0;i<20;i++){
			c=theStack.pop();
			System.out.println("Consumer "+num+":"+c);
			try{
				Thread.sleep((int)(Math.random()*300));
			}catch(InterruptedException e)
			{
				System.out.println(e.getMessage());
			}
		}
	}
}

public class SyncTest {

	public static void main(String[] args) {
		SyncStack stack=new SyncStack();
		Producer p1=new Producer(stack);
		Thread prodT1=new Thread(p1);
		prodT1.start();
		
		Producer p2=new Producer(stack);
		Thread prodT2=new Thread(p2);
		prodT2.start();
		
		Consumer c1=new Consumer(stack);
		Thread consT1=new Thread(c1);
		consT1.start();
		
		Consumer c2=new Consumer(stack);
		Thread consT2=new Thread(c2);
		consT2.start();
	}
}
