package ch13;

class ControlledThread extends Thread{
	public static final int SUSP=1;
	public static final int STOP=2;
	public static final int RUN=0;
	
	private int stat=RUN;
	
	public synchronized void setState(int state){
		stat=state;
		if (stat==RUN)
			notify();
	}
	
	public synchronized boolean checkState(){
		while (stat==RUN){
			try{
				System.out.println(Thread.currentThread().getName()+":wait");
				wait();
			}catch(InterruptedException e){
				System.err.print(e.getMessage());
			}
		}
		if (stat==STOP)
			return false;
		return true;
	}
}

public class Machine extends ControlledThread{
	private int count;
	
	public void run(){
		while (true){
			synchronized(this){
				count++;
				System.out.println(Thread.currentThread().getName()+":run "+count+" times");
			}
			if (!checkState()){
				System.out.println(Thread.currentThread().getName()+":stop");
				break;
			}
		}
	}
	
	public synchronized int getCount(){
		return count;
	}
	
	public synchronized void reset(){
		count=0;
		System.out.println(Thread.currentThread().getName()+":reset");
	}
	
	public static void main(String[] args){
		Machine mc=new Machine();
		mc.start();
		for (int i=0;i<200;i++){
			if (mc.getCount()>5){
				mc.setState(ControlledThread.SUSP);	//ÔÝÍ£
				yield();
				mc.reset();
				mc.setState(ControlledThread.RUN);
			}
			yield();
		}
		mc.setState(ControlledThread.STOP);
	}
}
