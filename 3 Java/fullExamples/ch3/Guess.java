package ch3;

import java.util.*;
import javax.swing.*;

public class Guess {
	private static final int MAX=100;
	private static int stdDigit=-1;
	
	public static void setDigit(){
		stdDigit=(int)(Math.random()*MAX);
	}
	
	public static void guess_console(){
		if (stdDigit<0)
			Guess.setDigit();
		Scanner scn=new Scanner(System.in);
		int guess;
		do{
			System.out.println("请输入您猜想的数字（0－"+MAX+"):");
			guess=scn.nextInt();
			if (guess>stdDigit)
				System.out.println("猜想过大！");
			else if (guess<stdDigit)
				System.out.println("猜想过小！");
		}while (guess!=stdDigit);
		System.out.println("恭喜，猜中了！");
		stdDigit=-1;
		scn.close();
	}
	
	public static void guess_win(){
		if (stdDigit<0)
			Guess.setDigit();
		String input;
		int guess;
		do{
			input=JOptionPane.showInputDialog("请输入您猜想的数字（0－"+MAX+"):");
			guess=Integer.parseInt(input);
			if (guess>stdDigit)
				JOptionPane.showMessageDialog(null,"猜想过大！");
			else if (guess<stdDigit)
				JOptionPane.showMessageDialog(null,"猜想过小！");
		}while (guess!=stdDigit);
		JOptionPane.showMessageDialog(null, "恭喜，猜中了！");
		stdDigit=-1;
	}
	
	public static void main(String[] args){
		Guess.guess_win();
	}
}
