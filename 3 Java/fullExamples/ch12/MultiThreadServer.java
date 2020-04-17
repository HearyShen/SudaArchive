package ch12;
import java.io.*;
import java.net.*;

class HandleAClient extends Thread{
	private Socket connectToClient;
	
	public HandleAClient(Socket sk){
		connectToClient=sk;
	}
	
	public void run(){
		try{
			DataInputStream isFromClient=new DataInputStream(
					connectToClient.getInputStream());
			DataOutputStream osToClient=new DataOutputStream(
					connectToClient.getOutputStream());
			while (true){
				double radius=isFromClient.readDouble();
				if (radius==-1)
					break;
				System.out.println("Radius received from client:"+radius);
				double area=radius*radius*Math.PI;
				osToClient.writeDouble(area);
				System.out.println("Area found: "+area);
			}
		}catch(IOException e){
			System.err.println(e.getMessage());
		}
	}
}

public class MultiThreadServer {
	public static void main(String[] args){
		try{
			ServerSocket serverSocket=new ServerSocket(8000);
			int clientNo=1;
			while (true){
				Socket connectToClient=serverSocket.accept();
				System.out.println("Start thread for client "+clientNo);
				
				//Find the client's host name, and ip address
				InetAddress clientInetAddress=connectToClient.getInetAddress();
				System.out.println("Client "+clientNo+" 's host name is "+
						clientInetAddress.getHostName());
				System.out.println("Client "+clientNo+" 's IP address is "+
						clientInetAddress.getHostAddress());
				
				//create a new thread for the connection
				HandleAClient thread=new HandleAClient(connectToClient);
				thread.start();
				clientNo++;
			}
		}catch(IOException e){
			System.err.println(e.getMessage());
		}
	}
}
