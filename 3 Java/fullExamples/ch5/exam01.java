package ch5;
/*����һ��String��Ķ���str��������Ϊ��you Are a GOOD boy����
����Ļ����ʾstr�����ݣ�
���ַ��������ַ���Ϊ��д����������Сд�������޸ĺ��������ʾ����Ļ�ϣ�
����Ļ����ʾ�ַ���str�ĳ��ȡ����ĸ��ַ���
����Ļ����ʾ�ַ���str�����һ������boy*/

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
