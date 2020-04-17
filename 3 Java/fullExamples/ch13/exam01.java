package ch13;

//编写程序，启动100个线程，每个线程给初始值为0的变量sum加1。
//需要通过引用传递将sum传递给每一个线程。为了能够引用传递，
//需要为sum定义一个包装类对象Integer。分别使用同步、不同步来运行程序，看看其影响
class Number {
	private Integer sum;

	public Number() {
		sum = new Integer(0);
	}

	public Integer getSum() {
		return sum;
	}

	public void setSum(Integer s) {
		sum = s;
	}
}

class AddNumber extends Thread {
	Number addS;

	public AddNumber(Number s) {
		addS = s;
	}
	
	public void run() {
		exam01.addAct(addS);
	}
}

public class exam01 {
	Thread[] td = new Thread[100];
	Number addObj = new Number();
	boolean done = false;

	public static synchronized void addAct(Number addS){
		int i = addS.getSum().intValue() + 1;
		try {
			Thread.sleep(5);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		addS.setSum(new Integer(i));
	}
	
	public exam01() {
		ThreadGroup gp = new ThreadGroup("group");
		for (int i = 0; i < td.length; i++) {
			td[i] = new Thread(gp, new AddNumber(addObj));
			td[i].start();
		}

		do {
			done = (gp.activeCount() == 0);
		} while (!done);
	}

	public static void main(String[] args) {
		exam01 o = new exam01();
		System.out.println(o.addObj.getSum().toString());
	}
}
