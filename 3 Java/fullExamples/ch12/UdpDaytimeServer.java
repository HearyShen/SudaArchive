package ch12;

import java.net.*;
import java.util.*;

public class UdpDaytimeServer {

	public static void main(String[] args) {
		DatagramSocket timeSocket;
		Date currDate;
		byte[] inBuffer;
		byte[] outBuffer;
		DatagramPacket request;
		DatagramPacket reply;
		InetAddress clientAddress;
		int clientPort;
		try{
			timeSocket=new DatagramSocket(13);
			try{
				inBuffer=new byte[1];
				request=new DatagramPacket(inBuffer,inBuffer.length);
				timeSocket.receive(request);
				clientAddress=request.getAddress();
				clientPort=request.getPort();
				//创建响应数据报
				currDate=new Date();
				outBuffer=currDate.toString().getBytes();
				reply=new DatagramPacket(outBuffer,outBuffer.length,
						clientAddress,clientPort);
				timeSocket.send(reply);
			}
			finally{
				timeSocket.close();
			}
		}catch(Exception e)
		{
			e.printStackTrace();
		}
		System.exit(0);
	}
}
