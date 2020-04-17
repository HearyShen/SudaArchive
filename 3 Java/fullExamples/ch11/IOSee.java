package ch11;

import java.io.*;
/**利用随机函数生成200个数量个50~100之间的整数，输出到文件scores.dat中*/
public class IOSee {
	public static void main(String[] args) throws IOException{
		PrintStream o=new PrintStream(new BufferedOutputStream(new FileOutputStream("g:\\scores.dat")));
		int x=(int)(Math.random()*50+50);
		int i=0;
		while (x>50){	//生成恰好50时停止
			o.printf("%3d",x);
			i++;
			if (i%4==0)
				o.println();
			x=(int)(Math.random()*50+50);
		}
		o.close();
	}
}
