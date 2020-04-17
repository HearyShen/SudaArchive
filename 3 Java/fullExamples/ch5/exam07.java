package ch5;

import javax.swing.*;
class AgeException extends Exception{
	private static final long serialVersionUID = 1L;
	private String message;
	public AgeException(String mess){
		message=mess;
	}
	public String toString(){
		return (message);
	}
}

public class exam07 {
	public static void main(String[] arg){
		try {
			(new exam07()).inpuOk();
		} catch (AgeException e) {
			System.err.println(e.toString());
		}
	}

	public boolean inpuOk() throws AgeException{
		boolean ok = false;
		String tmp = JOptionPane.showInputDialog("请输入年龄：");
		//try {
			try {
				int age = Integer.parseInt(tmp.trim()) + 20;
				if (age < 0 || age > 200)
					throw (new AgeException("年龄错误！"));
				// System.out.println(age);
				ok = true;
			} catch (NullPointerException e) {
				// System.out.println("年龄未输入，请输入！");
				ok = false;
			} catch (NumberFormatException e) {
				// System.out.println("年龄格式错误，请重输！");
				ok = false;
			} finally {
				System.out.println(ok);
			}
//		} catch (Exception e) {
//			System.out.println("twice");
//		}
		return ok;
	}

}
