package ch11;
import java.io.*;
public class User implements Serializable{
	private static final long serialVersionUID = 1L;
	
	private String name;
	private transient String password;
	
	public User(String n,String p){
		name=n;
		password=p;
	}
	
	public String toString(){
		return (name+" "+password);
	}
	
	
	//加密数组，将buff数组中的每个字节的每一位取反
	private byte[] change(byte[] buff){
		for (int i=0;i<buff.length;i++){
			int b=0;
			for (int j=0;j<8;j++){
				int bit=(buff[i]>>j & 1)==0?1:0;
				b+=(1<<j)*bit;
			}
			buff[i]=(byte)b;
		}
		return buff;
	}
	
	private void writeObject(ObjectOutputStream stream) throws IOException{
		stream.defaultWriteObject();	//先按默认方式进行序列化
		stream.writeObject(change(password.getBytes()));
	}
	
	private void readObject(ObjectInputStream stream) throws IOException, ClassNotFoundException{
		stream.defaultReadObject();	//先按默认方式进行反序列化
		byte[] buff=(byte[])stream.readObject();
		password=new String(change(buff));
	}
	
	
	public static void main(String[] args) throws IOException, ClassNotFoundException{
		User user=new User("Tom","123456");
		System.out.println("Before Serialization: "+user);
		ByteArrayOutputStream buff=new ByteArrayOutputStream();		
		ObjectOutputStream o=new ObjectOutputStream(buff);
		o.writeObject(user);
				
		//反序列化对象
		ObjectInputStream in=new ObjectInputStream(new ByteArrayInputStream(buff.toByteArray()));
		user=(User)in.readObject();
		System.out.println("After Serialization: "+user);
		o.close();
		in.close();
	}
}
