package ch3;

public class Draws {
	//标准
	int r1,r2,r3;
	int b;
	
	//用户投注信息
	int ur1,ur2,ur3;
	int ub;
	
	static final int REDMAX=16;
	static final int BLUEMAX=22;
	
	//初始化
	public Draws(){
		r1=r2=r3=b=-1;
		ur1=ur2=ur3=ub=-1;
	}
	
	//判断生成的数字是否已经在已生成列表中
	boolean existsRed(boolean flag,int x){
		if (flag)
			return (r1==x||r2==x||r3==x);
		return (ur1==x||ur2==x||ur3==x);
	}
	
	//计算匹配的红球数量
	int compareRed(){
		int count=0;
		if (existsRed(true,ur1))
			count++;
		if (existsRed(true,ur2))
			count++;
		if (existsRed(true,ur3))
			count++;
		return count;
	}
	
	//生成红球。flag-true表示生成的是中奖号，false表示用户投注号
	int generateRedDigit(boolean flag){
		int x;
		do{
			x=(int)(Math.random()*REDMAX)+1;
		}while (existsRed(flag,x));
		return x;
	}
	
	void setUsrRed(){
		ur1=generateRedDigit(false);
		ur2=generateRedDigit(false);
		ur3=generateRedDigit(false);
	}

	void setRed(){
		r1=generateRedDigit(true);
		r2=generateRedDigit(true);
		r3=generateRedDigit(true);
	}
	
	void setUsrBlue(){
		ub=(int)(Math.random()*BLUEMAX)+1;
	}
	
	void setBlue(){
		b=(int)(Math.random()*BLUEMAX)+1;
	}
	
	//判断绿球是否匹配
	boolean compareBlue(){
		return (ub==b);
	}
	
	//获得用户输入的红球信息
	int inputUsrRed(int i){
		String tmp;
		int x;
		do{
			tmp=javax.swing.JOptionPane.showInputDialog("红球"+i+"号(1-16)：");
			x=Integer.parseInt(tmp);
		}while (existsRed(false,x));
		return x;
	}
	
	void setInputUsrRed(){
		ur1=inputUsrRed(1);
		ur2=inputUsrRed(2);
		ur3=inputUsrRed(3);
	}
	
	//打印输出
	void printInfo(){
		System.out.println("本期中奖信息：红球："+r1+","+r2+","+r3+"\t绿球："+b);
		System.out.println("您的投注信息：红球："+ur1+","+ur2+","+ur3+"\t绿球："+ub);
	}
	
	public static void main(String[] args) {
		Draws d=new Draws();
		d.setRed();
		d.setBlue();
		
		String ch=javax.swing.JOptionPane.showInputDialog("选择投注方式：0－自动生成，1－自己输入！");
		int choice=Integer.parseInt(ch);
		if (choice==0)
			d.setUsrRed();
		else
			d.setInputUsrRed();
		d.setUsrBlue();
		d.printInfo();
		if (d.compareBlue()==true&&d.compareRed()>=2)
			System.out.println("恭喜，您中奖了！");
		else 
			System.out.println("抱歉，未能中奖！");
	}

}
