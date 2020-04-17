package ch11;

import java.io.*;
import java.nio.channels.*;
import java.nio.*;
import java.nio.charset.*;

public class FileChannelTester {
	public static void main(String[] args) throws IOException{
		//final int BSIZE=1024;
		
		//向文件中写
		FileChannel fc=new FileOutputStream("f:\\d.txt").getChannel();
		fc.write(ByteBuffer.wrap("你好".getBytes()));
		fc.close();
		
		//向文件尾部添加
		fc=new RandomAccessFile("f:\\d.txt","rw").getChannel();
		fc.position(fc.size());
		fc.write(ByteBuffer.wrap("朋友！".getBytes()));
		fc.position(0);
		ByteBuffer buff=ByteBuffer.allocate((int)fc.size());
		fc.read(buff);
		//fc.close();
		
		//读取数据
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
