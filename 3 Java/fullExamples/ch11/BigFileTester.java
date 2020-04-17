package ch11;
import java.io.*;
import java.nio.*;
import java.nio.channels.*;
//import java.nio.charset.*;

public class BigFileTester {
	public static void main(String[] args) throws IOException{
		int capacity=0x2000000;	//32MB
		FileChannel fc=new RandomAccessFile("f:\\d.txt","rw").getChannel();
		MappedByteBuffer mb=fc.map(FileChannel.MapMode.READ_WRITE,0,capacity);
		mb.put("你好啊".getBytes("GBK"));  //向文件中写入信息
		mb.flip();
		//System.out.println(Charset.forName("GBK").decode(mb));
	}
}
