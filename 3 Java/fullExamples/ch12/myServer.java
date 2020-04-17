package ch12;
import java.io.*;
import java.net.*;

public class myServer {
	public static void main(String[] args){
		try{
			ServerSocket serverS=new ServerSocket(8000);
			Socket conClient=serverS.accept();
			DataInputStream isFromClient=new DataInputStream(conClient.getInputStream());
			DataOutputStream osToClient=new DataOutputStream(conClient.getOutputStream());
			
			while (true){
				double radius=isFromClient.readDouble();
				if (radius==-1)
					break;
				System.out.println("Radius received from client: "+radius);
				double area=Math.PI*radius*radius;
				osToClient.writeDouble(area);
				osToClient.flush();
				System.out.println("Area found: "+area);
			}	
			
			conClient.close();
		}catch(IOException e){
			System.err.println(e.getMessage());
		}
	}
}
