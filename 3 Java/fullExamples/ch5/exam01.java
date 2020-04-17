package ch5;
/*创建一个String类的对象str，其内容为“you Are a GOOD boy”；
在屏幕上显示str的内容；
将字符串的首字符改为大写，其余均变成小写，并将修改后的内容显示在屏幕上；
在屏幕上显示字符串str的长度、第四个字符；
在屏幕上显示字符串str的最后一个单词boy*/

public class exam01 {
	public static void main(String[] args){
		String str=new String("you Are a GOOD boy!");
		System.out.println(str);
		String tmp=str.substring(0,1).toUpperCase()+str.substring(1).toLowerCase();
		System.out.println(tmp);
		System.out.println(str.length());
		System.out.println(str.charAt(3));
		str=str.trim();
		if (!Character.isLetter(str.charAt(str.length()-1)))
				str=str.substring(0,str.length()-1);		
		int pos=str.lastIndexOf(" ");
		if (pos>=0)
			System.out.println(str.substring(pos+1));
		else
			System.out.println(str);
	}
}
