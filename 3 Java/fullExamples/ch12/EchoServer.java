package ch12;

import java.net.*;
import java.io.*;

public class EchoServer {

	public static void main(String[] args) {
		try{
			ServerSocket s=new ServerSocket(7800);
			Socket incoming=s.accept();
			BufferedReader in=new BufferedReader(
					new InputStreamReader(incoming.getInputStream()));
			PrintWriter out=new PrintWriter(incoming.getOutputStream(),true);
			out.println("Hello! Enter EXIT to exit.");
			boolean done=false;
			while (!done)
			{
				String line=in.readLine();
				if (line==null)
					done=true;
				else
				{
					out.println("Echo:"+line);
					if (line.trim().equalsIgnoreCase("EXIT"))
						done=true;
				}
			}
			incoming.close();
		}catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
