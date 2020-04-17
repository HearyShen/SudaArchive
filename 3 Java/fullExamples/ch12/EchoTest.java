package ch12;

import java.net.*;
import java.io.*;

public class EchoTest {
	public static void main(String[] args) {
		Socket echoSocket=null;
		DataOutputStream os=null;
		DataInputStream is=null;
		DataInputStream stdIn=new DataInputStream(System.in);
		byte[] buff=new byte[256];
		try{
			echoSocket=new Socket("127.0.0.1",7800);
			os=new DataOutputStream(echoSocket.getOutputStream());
			is=new DataInputStream(echoSocket.getInputStream());
		}catch(UnknownHostException e)
		{
			System.err.println("Don't know about host: 127.0.0.1");
		}
		catch(IOException e)
		{
			System.err.println("Could't get IO for the connection to: 127.0.0.1");
		}
		int digits;
		if (echoSocket!=null&&os!=null&&is!=null)
		{
			try{				
				while ((digits=stdIn.read(buff))!=-1)
				{
					os.write(digits);
					os.writeByte('\n');
					//System.out.println("echo:"+is.readLine());
				}
				os.close();
				is.close();
				echoSocket.close();
			}catch(IOException e)
			{
				e.printStackTrace();
			}
		}
	}
}
