package ch12;

import java.net.*;

public class UdpDaytimeClient {

	public static void main(String[] args) {
		String host;
		InetAddress hostAddress;
		byte[] inBuffer=new byte[512];
		byte[] outBuffer=new byte[1];
		DatagramPacket request;
		DatagramPacket reply;
		DatagramSocket timeSocket;
		if (args.length<1)
			System.out.println("Usage: UdpDaytime host");
		else
		{
			try{
				host=args[0];
				hostAddress=InetAddress.getByName(host);
				timeSocket=new DatagramSocket();
				//创建请求和响应
				request=new DatagramPacket(outBuffer,outBuffer.length,
						hostAddress,13);
				reply=new DatagramPacket(inBuffer,inBuffer.length);
				try{
					//将超时设为5秒
					timeSocket.setSoTimeout(5000);
					timeSocket.send(request);
					timeSocket.receive(reply);
					System.out.println("Reply received:"
							+new String(inBuffer,0,reply.getLength()));
				}catch(Exception e)
				{
					e.printStackTrace();
				}
				finally
				{
					timeSocket.close();
				}
			}catch(Exception e)
			{
				e.printStackTrace();
			}
			System.exit(0);
		}
	}
}
