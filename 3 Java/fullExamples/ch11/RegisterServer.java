package ch11;

import java.io.*;
import java.net.*;

public class RegisterServer {
	public static void main(String[] args) {
		try {
			ServerSocket sk = new ServerSocket(8000);
			Socket skt = sk.accept();
			ObjectInputStream in = new ObjectInputStream(skt.getInputStream());
			PrintWriter out = new PrintWriter(new OutputStreamWriter(skt
					.getOutputStream()));
			Infomation tmpO = (Infomation) in.readObject();
			System.out.println(tmpO.getAllInfo());
			out.println("OK");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
