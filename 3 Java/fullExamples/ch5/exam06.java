package ch5;

/*编程完成下列功能：
1)从命令行接收两个数据，将这两个数字相加，并在屏幕上显示相加后的结果
2)利用输入语句从键盘上输入一个字符（＋ - * /），根据输入的运算符分别进行不同的运算。*/
public class exam06 {
	public static void main(String[] arg){
		if (arg.length!=2)	System.out.println("参数错误！");
		else
		{	int x=Integer.parseInt(arg[0]);
			int y=Integer.parseInt(arg[1]);
			System.out.println("x+y="+(x+y));
			String tmp=javax.swing.JOptionPane.showInputDialog("请输入运算符:");
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
			else	System.out.println("运算错误！");
		}
	}
}
