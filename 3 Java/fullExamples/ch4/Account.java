package ch4;
import javax.swing.*;
public class Account {
	private String id;	//卡号
	private double balance; //余额
	private String password;//密码
	
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
		String oldPass=JOptionPane.showInputDialog("请输入当前密码：");
		if (!oldPass.equals(password))
		{
			//告诉密码错误，结束！
			JOptionPane.showMessageDialog(null,"密码错误，请检查！");
			return false;
		}
		return true;
	}
	
	//修改密码
	public boolean modiPass(){
		if (checkPass()==false)
			return false;
		String oldPass=JOptionPane.showInputDialog("请输入新密码：");
		String rePass=JOptionPane.showInputDialog("请再次输入新密码：");
		if (!oldPass.equals(rePass))
		{
			//告诉密码错误，结束！
			JOptionPane.showMessageDialog(null,"两次密码不匹配，请检查！");
			return false;
		}
		password=rePass;
		return true;
	}
	
	//存钱
	public boolean saveMoney(double m){
		if (m<=0)
		{
			JOptionPane.showMessageDialog(null,"金额出错！");
			return false;
		}
		balance+=m;
		return true;
	}
	 
	//取款
	public boolean withDraw(){
		if (checkPass()==false)
			return false;
		String tmp=JOptionPane.showInputDialog("请输入取款金额：");
		double tmpBal = Double.parseDouble(tmp);
		if (tmpBal<=0||tmpBal>balance)
		{
			JOptionPane.showMessageDialog(null,"取款金额出错！");
			return false;
		}
		balance-=tmpBal;
		return true;
	}
	
	//查询
	public boolean browseAcc(){
		if (checkPass()==false)
			return false;
		System.out.println("ID="+id);
		JOptionPane.showMessageDialog(null,"当前余额为："+balance);
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
