package tmp;

import java.io.*;

public class ByteTest {
	public static void main(String[] args) throws IOException{
		ByteArrayOutputStream out=new ByteArrayOutputStream();
		out.write(259);
		byte[] buff=out.toByteArray();
		out.close();
		System.out.println(buff.length);
		ByteArrayInputStream in=new ByteArrayInputStream(buff);
		int data;
		while ((data=in.read())!=-1)
			System.out.println(data);
		in.close();
	}

}
