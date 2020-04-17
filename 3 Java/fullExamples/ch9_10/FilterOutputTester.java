package ch9_10;
import java.io.*;

import common.CommVars;
public class FilterOutputTester{
	public static void main(String[] args) throws IOException{
		String fname=CommVars.DTP_PROJECT+"out/out1.txt";
		FileOutputStream out1=new FileOutputStream(fname);
		BufferedOutputStream out2=new BufferedOutputStream(out1,256);
		DataOutputStream out=new DataOutputStream(out2);
		out.writeUTF("ÄãºÃ°¡");
		out.close();
		
		InputStream in1=new FileInputStream(fname);
		BufferedInputStream in2=new BufferedInputStream(in1);
		DataInputStream in=new DataInputStream(in2);
		System.out.println(in.readUTF());
		in.close();
	}
}     

