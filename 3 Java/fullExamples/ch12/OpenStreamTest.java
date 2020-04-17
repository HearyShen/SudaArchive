package ch12;

import java.net.*;
import java.io.*;
import java.util.*;

public class OpenStreamTest {

	public static void main(String[] args) {
		try{
			URL sunUrl=new URL("http://localhost/");			
			InputStream dis=sunUrl.openStream();
			Scanner sc=new Scanner(dis);
			String inputLine;
			while (sc.hasNext())
			{
				inputLine=sc.nextLine();
				System.out.println(inputLine);
			}
			dis.close();
		}catch(MalformedURLException e)
		{
			e.printStackTrace();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
}
