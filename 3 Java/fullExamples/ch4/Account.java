package ch4;
import javax.swing.*;
public class Account {
	private String id;	//����
	private double balance; //���
	private String password;//����
	
	Account(String pass){
		id="1341341341"+(int)(Math.random()*100);
		balance=0;
		password=pass;
	}
	
	Account(){
		this("123456");
		balance+=500;
	}
	
	public double getBalance(){
		return balance;
	}
	
	public void setBalance(double b){
		balance=b;
	}
	
	protected boolean checkPass(){
		String oldPass=JOptionPane.showInputDialog("�����뵱ǰ���룺");
		if (!oldPass.equals(password))
		{
			//����������󣬽�����
			JOptionPane.showMessageDialog(null,"����������飡");
			return false;
		}
		return true;
	}
	
	//�޸�����
	public boolean modiPass(){
		if (checkPass()==false)
			return false;
		String oldPass=JOptionPane.showInputDialog("�����������룺");
		String rePass=JOptionPane.showInputDialog("���ٴ����������룺");
		if (!oldPass.equals(rePass))
		{
			//����������󣬽�����
			JOptionPane.showMessageDialog(null,"�������벻ƥ�䣬���飡");
			return false;
		}
		password=rePass;
		return true;
	}
	
	//��Ǯ
	public boolean saveMoney(double m){
		if (m<=0)
		{
			JOptionPane.showMessageDialog(null,"������");
			return false;
		}
		balance+=m;
		return true;
	}
	 
	//ȡ��
	public boolean withDraw(){
		if (checkPass()==false)
			return false;
		String tmp=JOptionPane.showInputDialog("������ȡ���");
		double tmpBal = Double.parseDouble(tmp);
		if (tmpBal<=0||tmpBal>balance)
		{
			JOptionPane.showMessageDialog(null,"ȡ�������");
			return false;
		}
		balance-=tmpBal;
		return true;
	}
	
	//��ѯ
	public boolean browseAcc(){
		if (checkPass()==false)
			return false;
		System.out.println("ID="+id);
		JOptionPane.showMessageDialog(null,"��ǰ���Ϊ��"+balance);
		return true;
	}
	
	public static void main(String[] args) {
		Account acc1=new Account();
		//Account acc2=new Account("0000");
		acc1.browseAcc();
		acc1.modiPass();
		acc1.saveMoney(1000);
		acc1.browseAcc();
		//acc2.withDraw();	
		System.exit(0);
	}

}
