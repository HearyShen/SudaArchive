package ch11;

import java.io.*;

import common.CommVars;

public class Redirecter {
	/**
	 * 为标准I/o重定向
	 */
	public static void redirect(InputStream in,PrintStream out,PrintStream err){
		System.setIn(in);
		System.setOut(out);
		System.setErr(err);
	}
	/**
	 * 把标准输入流的数据写到标准输出流和标准错误输出流
	 */
	public static void copy() throws IOException{
		InputStreamReader reader=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(reader);
		String data=br.readLine();
		while (data!=null&&data.length()>0){
			System.out.println(data);
			System.err.println(data);
			data=br.readLine();
		}
	}
	
	public static void main(String[] args) throws IOException{
		/**重定向前，保留原始副本*/
		InputStream stdIn=System.in;
		PrintStream stdOut=System.out;
		PrintStream stdErr=System.err;
		/**重定向到文件*/
		BufferedInputStream in=new BufferedInputStream(new FileInputStream(CommVars.DTP_PROJECT+"\\out\\results.txt"));
		PrintStream out=new PrintStream(new BufferedOutputStream(new FileOutputStream(CommVars.DTP_PROJECT+"out\\rout.txt")));
		PrintStream err=new PrintStream(new BufferedOutputStream(new FileOutputStream(CommVars.DTP_PROJECT+"out\\rerr.txt")));
		Redirecter.redirect(in, out, err);		
		copy();
		
		/**关闭用户创建的流*/
		in.close();
		out.close();
		err.close();
		
		/**还原到原标准输入输出流*/
		Redirecter.redirect(stdIn,stdOut,stdErr);
		//copy();
	}
}
