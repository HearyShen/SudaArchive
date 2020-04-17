package ch12;

import java.io.IOException;
import java.net.*;

public class ParseURL {

	public static void main(String[] args) throws IOException {
		URL aURL=null;
		try{
			aURL=new URL("http://java.sun.com:80/tutorial/intro.html#DOWNLOADING");
			System.out.println("Protocol="+aURL.getProtocol());
			System.out.println("Host="+aURL.getHost());
			System.out.println("FileName="+aURL.getFile());
			System.out.println("Port="+aURL.getPort());
			System.out.println("Ref="+aURL.getRef());
		}catch(MalformedURLException e)
		{
			e.printStackTrace();
		}
	}
}
