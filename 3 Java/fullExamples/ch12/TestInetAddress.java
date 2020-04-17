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
			System.out.println("主机地址为："+myAddr.getHostAddress());
			System.out.println("主机名为："+myAddr.getHostName());
			System.out.println("是否loopback地址？"+myAddr.isLoopbackAddress());
			System.out.println("是否通配："+myAddr.isAnyLocalAddress());
		}catch(UnknownHostException e){
			System.err.println(e.getMessage());
		}
	}
}
