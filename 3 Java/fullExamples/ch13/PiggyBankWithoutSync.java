package ch13;

class PiggyBank{
	private int balance=0;
	
	public int getBalance(){
		return balance;
	}
	
	public void setBalance(int bal){
		balance=bal;
	}
}

public class PiggyBankWithoutSync {	
	private PiggyBank bank=new PiggyBank();
	private Thread[] thread=new Thread[100];
	
	class AddPennyThread extends Thread{
		public void run(){
			int newBal=bank.getBalance()+1;
			try{
				Thread.sleep(5);
			}catch(InterruptedException e){
				System.out.println(e.getMessage());
			}
			bank.setBalance(newBal);
		}
	}
	
	public PiggyBankWithoutSync(){
		ThreadGroup g=new ThreadGroup("group");
		boolean done=false;
		//Create thread
		for (int i=0;i<thread.length;i++){
			thread[i]=new Thread(g,new AddPennyThread());
			thread[i].start();
		}
		
		//check if all threads are finished
		while (!done)
			done=(g.activeCount()==0);
	}
	
	public static void main(String[] args){
		PiggyBankWithoutSync test=new PiggyBankWithoutSync();
		System.out.println(" What is balance? "+
				test.bank.getBalance());
	}
}
