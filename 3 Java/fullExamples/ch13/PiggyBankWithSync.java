package ch13;

public class PiggyBankWithSync {
	private PiggyBank bank=new PiggyBank();
	private Thread[] thread=new Thread[100];
	
	public PiggyBankWithSync(){
		ThreadGroup g1=new ThreadGroup("group");
		boolean done=false;
		for (int i=0;i<thread.length;i++){
			thread[i]=new Thread(g1,new AddPennyThread());
			thread[i].start();
		}
		while (!done)
			done=(g1.activeCount()==0);
	}
	
	private static synchronized void addAPenny(PiggyBank bank){
		int newBal=bank.getBalance()+1;
		try{
			Thread.sleep(5);
		}catch(InterruptedException e){
			System.out.println(e.getMessage());
		}
		bank.setBalance(newBal);
	}
	
	class AddPennyThread extends Thread{
		public void run(){
			addAPenny(bank);
		}
	}
	
	public static void main(String[] args){
		PiggyBankWithSync test=new PiggyBankWithSync();
		System.out.println(" What is balance? "+
				test.bank.getBalance());
	}
}
