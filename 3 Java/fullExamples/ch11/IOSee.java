package ch11;

import java.io.*;
/**���������������200��������50~100֮���������������ļ�scores.dat��*/
public class IOSee {
	public static void main(String[] args) throws IOException{
		PrintStream o=new PrintStream(new BufferedOutputStream(new FileOutputStream("g:\\scores.dat")));
		int x=(int)(Math.random()*50+50);
		int i=0;
		while (x>50){	//����ǡ��50ʱֹͣ
			o.printf("%3d",x);
			i++;
			if (i%4==0)
				o.println();
			x=(int)(Math.random()*50+50);
		}
		o.close();
	}
}
