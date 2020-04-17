package tmp;
import java.io.*;
public class RandomF {
	public static void main(String[] args) throws IOException{
		File fd=new File("g:\\scores.dat");
		if (fd.exists())
			fd.delete();
		RandomAccessFile rf=new RandomAccessFile(fd,"rw");
		int x;
		int i=0;
		double sum1=0;
		do{
			x=(int)(Math.random()*50)+50;
			rf.writeInt(x);
			rf.writeChar(' ');
			i++;
			if (i%4==0)
				rf.writeChar('\n');
			sum1+=x;
			System.out.print(x+" ");
		}while (x!=50);
		
		System.out.println("*****************"+i+","+(sum1/i));
		double sum=0;
		rf.seek(0);
		long len=rf.length();
		i=0;	//已经读的数据序号
		boolean flag=false;	//当前行的换行符是否未读取
		long rlen=0;	//目前已经读取的字节数量
		while (rlen<len){
			if (i%4==0&&flag){
				rf.readChar();
				rlen+=2;
				flag=false;
			}
			else{
				sum+=rf.readInt();
				rf.readChar();
				rlen+=6;
				i++;
				flag=true;
			}
		}
		rf.close();
		System.out.println(i);
		System.out.println(sum/i);
	}
}
