package ch5;

/*���������й��ܣ�
1)�������н����������ݣ���������������ӣ�������Ļ����ʾ��Ӻ�Ľ��
2)�����������Ӽ���������һ���ַ����� - * /�������������������ֱ���в�ͬ�����㡣*/
public class exam06 {
	public static void main(String[] arg){
		if (arg.length!=2)	System.out.println("��������");
		else
		{	int x=Integer.parseInt(arg[0]);
			int y=Integer.parseInt(arg[1]);
			System.out.println("x+y="+(x+y));
			String tmp=javax.swing.JOptionPane.showInputDialog("�����������:");
			tmp=tmp.trim();
			int result=0;
			boolean flag=false;
			if (tmp.equals("+")){
				result=x+y;
				flag=true;
			}
			else if (tmp.equals("-")){
				result=x-y;
				flag=true;
			}
			else if (tmp.equals("*")){
				result=x*y;
				flag=true;
			}
			else if (tmp.equals("/")){
				if (y!=0){
					result=x/y;
					flag=true;
				}
			}
			if (flag)	System.out.println("x"+tmp+"y="+result);
			else	System.out.println("�������");
		}
	}
}
