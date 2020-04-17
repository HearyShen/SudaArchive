package ch11;

import java.io.*;
import java.nio.channels.*;
import java.nio.*;
import java.nio.charset.*;

public class FileChannelTester {
	public static void main(String[] args) throws IOException{
		//final int BSIZE=1024;
		
		//���ļ���д
		FileChannel fc=new FileOutputStream("f:\\d.txt").getChannel();
		fc.write(ByteBuffer.wrap("���".getBytes()));
		fc.close();
		
		//���ļ�β�����
		fc=new RandomAccessFile("f:\\d.txt","rw").getChannel();
		fc.position(fc.size());
		fc.write(ByteBuffer.wrap("���ѣ�".getBytes()));
		fc.position(0);
		ByteBuffer buff=ByteBuffer.allocate((int)fc.size());
		fc.read(buff);
		//fc.close();
		
		//��ȡ����
		/*fc=new FileInputStream("f:\\d.txt").getChannel();
		buff=ByteBuffer.allocate(BSIZE);
		fc.read(buff);*/
		buff.flip();
		Charset cs=Charset.defaultCharset();
		System.out.println(cs.decode(buff));
		//System.out.println(buff);
		fc.close();
	}
}
