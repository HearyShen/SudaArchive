package ch12;
import java.net.*;
public class TestInetAddress {
	public static void main(String[] args){
		String host="localhost";
		if (args.length>0)
			host=args[0];
		try{
			InetAddress myAddr=InetAddress.getByName(host);
			System.out.println("Canonical Host Name: "+myAddr.getCanonicalHostName());
			System.out.println("������ַΪ��"+myAddr.getHostAddress());
			System.out.println("������Ϊ��"+myAddr.getHostName());
			System.out.println("�Ƿ�loopback��ַ��"+myAddr.isLoopbackAddress());
			System.out.println("�Ƿ�ͨ�䣺"+myAddr.isAnyLocalAddress());
		}catch(UnknownHostException e){
			System.err.println(e.getMessage());
		}
	}
}
