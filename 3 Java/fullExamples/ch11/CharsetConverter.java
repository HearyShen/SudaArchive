package ch11;
import java.io.*;
import java.nio.*;
import java.nio.charset.*;

public class CharsetConverter {
	public static void main(String[] args) throws UnsupportedEncodingException{
		
		ByteBuffer bb=ByteBuffer.wrap("你好".getBytes());
		CharBuffer cb=bb.asCharBuffer();
		System.out.println(cb);
		
		bb=ByteBuffer.wrap("你好".getBytes("UTF-16BE"));
		cb=bb.asCharBuffer();
		System.out.println(cb);
		
		bb=ByteBuffer.wrap("你好".getBytes("UTF-8"));
		Charset cs=Charset.forName("UTF-8");
		cb=cs.decode(bb);
		//cb=bb.asCharBuffer();
		System.out.println(cb);
		
		cs=Charset.forName("GBK");
		bb=cs.encode("你好");
		cb=cs.decode(bb);
		for (int i=0;i<cb.limit();i++)
			System.out.println(cb.get());
		
	}
}
