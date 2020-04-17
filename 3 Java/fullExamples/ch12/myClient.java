package ch12;
import java.io.*;
import java.net.*;

public class myClient {
	public static void main(String[] args){
		String serName="localhost";
		int servPort=8000;
		try{
			Socket conToServer=new Socket(serName,servPort);
			DataInputStream isFromServer=new DataInputStream(conToServer.getInputStream());
			DataOutputStream osToServer=new DataOutputStream(conToServer.getOutputStream());
			DataInputStream myInput=new DataInputStream(System.in);
			
			while (true){
				System.out.print("Please enter a radius:");
				double radius=myInput.readDouble();
				osToServer.writeDouble(radius);
				osToServer.flush();
				if (radius==-1)
					break;
				double area=isFromServer.readDouble();
				System.out.println("Area received from the server is: "+area);				
			}
			
			conToServer.close();
		}catch(IOException e){
			System.err.println(e.getMessage());
		}
	}
}
