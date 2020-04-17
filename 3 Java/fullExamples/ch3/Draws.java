package ch3;

public class Draws {
	//��׼
	int r1,r2,r3;
	int b;
	
	//�û�Ͷע��Ϣ
	int ur1,ur2,ur3;
	int ub;
	
	static final int REDMAX=16;
	static final int BLUEMAX=22;
	
	//��ʼ��
	public Draws(){
		r1=r2=r3=b=-1;
		ur1=ur2=ur3=ub=-1;
	}
	
	//�ж����ɵ������Ƿ��Ѿ����������б���
	boolean existsRed(boolean flag,int x){
		if (flag)
			return (r1==x||r2==x||r3==x);
		return (ur1==x||ur2==x||ur3==x);
	}
	
	//����ƥ��ĺ�������
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
	
	//���ɺ���flag-true��ʾ���ɵ����н��ţ�false��ʾ�û�Ͷע��
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
	
	//�ж������Ƿ�ƥ��
	boolean compareBlue(){
		return (ub==b);
	}
	
	//����û�����ĺ�����Ϣ
	int inputUsrRed(int i){
		String tmp;
		int x;
		do{
			tmp=javax.swing.JOptionPane.showInputDialog("����"+i+"��(1-16)��");
			x=Integer.parseInt(tmp);
		}while (existsRed(false,x));
		return x;
	}
	
	void setInputUsrRed(){
		ur1=inputUsrRed(1);
		ur2=inputUsrRed(2);
		ur3=inputUsrRed(3);
	}
	
	//��ӡ���
	void printInfo(){
		System.out.println("�����н���Ϣ������"+r1+","+r2+","+r3+"\t����"+b);
		System.out.println("����Ͷע��Ϣ������"+ur1+","+ur2+","+ur3+"\t����"+ub);
	}
	
	public static void main(String[] args) {
		Draws d=new Draws();
		d.setRed();
		d.setBlue();
		
		String ch=javax.swing.JOptionPane.showInputDialog("ѡ��Ͷע��ʽ��0���Զ����ɣ�1���Լ����룡");
		int choice=Integer.parseInt(ch);
		if (choice==0)
			d.setUsrRed();
		else
			d.setInputUsrRed();
		d.setUsrBlue();
		d.printInfo();
		if (d.compareBlue()==true&&d.compareRed()>=2)
			System.out.println("��ϲ�����н��ˣ�");
		else 
			System.out.println("��Ǹ��δ���н���");
	}

}
