package ch5;


public class Pro{
	String context;
	
	public Pro(String str){
		context=str;
	}
	public boolean equals(Object o){
		if (this==o)
			return true;
		if (!(o instanceof Pro))
			return false;
		String tmp=((Pro)o).context.toLowerCase();
		return (this.context.toLowerCase().equals(tmp));
	}	
	public static void main(String[] arg){
		Pro o=new Pro("Hello");
		Pro obk=new Pro("HELLO!");
		System.out.println(o.equals(obk));
	}
}
