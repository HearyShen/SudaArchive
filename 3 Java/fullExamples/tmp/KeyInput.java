package tmp;
import java.io.*;

public class KeyInput {
	public static void main(String[] arg) throws IOException{
		ByteArrayOutputStream out=new ByteArrayOutputStream();
		out.write(259);
		byte[] buff=out.toByteArray();
		out.close();
		System.out.println(buff.length);
		ByteArrayInputStream in=new ByteArrayInputStream(buff);
		int x;
		while ((x=in.read())!=-1)
			System.out.println(x);
		in.close();
	}
}
