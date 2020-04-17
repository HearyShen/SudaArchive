package ch11;

import java.io.*;

import common.CommVars;

public class Redirecter {
	/**
	 * Ϊ��׼I/o�ض���
	 */
	public static void redirect(InputStream in,PrintStream out,PrintStream err){
		System.setIn(in);
		System.setOut(out);
		System.setErr(err);
	}
	/**
	 * �ѱ�׼������������д����׼������ͱ�׼���������
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
		/**�ض���ǰ������ԭʼ����*/
		InputStream stdIn=System.in;
		PrintStream stdOut=System.out;
		PrintStream stdErr=System.err;
		/**�ض����ļ�*/
		BufferedInputStream in=new BufferedInputStream(new FileInputStream(CommVars.DTP_PROJECT+"\\out\\results.txt"));
		PrintStream out=new PrintStream(new BufferedOutputStream(new FileOutputStream(CommVars.DTP_PROJECT+"out\\rout.txt")));
		PrintStream err=new PrintStream(new BufferedOutputStream(new FileOutputStream(CommVars.DTP_PROJECT+"out\\rerr.txt")));
		Redirecter.redirect(in, out, err);		
		copy();
		
		/**�ر��û���������*/
		in.close();
		out.close();
		err.close();
		
		/**��ԭ��ԭ��׼���������*/
		Redirecter.redirect(stdIn,stdOut,stdErr);
		//copy();
	}
}
