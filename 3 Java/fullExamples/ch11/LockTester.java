package ch11;
import java.io.*;
import java.nio.channels.*;

public class LockTester {
	public static void main(String[] args) throws IOException, InterruptedException{
		FileOutputStream fos=new FileOutputStream("f:\\d.txt");
		FileLock f1=fos.getChannel().tryLock();
		if (f1!=null){
			System.out.println("Locked File");
			System.out.println(f1.isShared());
			Thread.sleep(30000);
			f1.release();
			System.out.println("Realease Lock");
		}
	}
}
