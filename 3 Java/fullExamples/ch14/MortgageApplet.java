package ch14;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.border.*;

public class MortgageApplet extends JApplet 
	implements ActionListener{
	
	private static final long serialVersionUID = 1L;
	private JTextField jtfAnnualInterestRate=new JTextField();
	private JTextField jtfNumOfYears=new JTextField();
	private JTextField jtfLoanAmount=new JTextField();
	private JTextField jtfMonthlyPayment=new JTextField();
	private JTextField jtfTotalPayment=new JTextField();
	private JButton jbtComputeMortgage=new JButton("Compute Mortgage");
	
	public void init(){
		jtfMonthlyPayment.setEnabled(false);
		jtfTotalPayment.setEnabled(false);
		
		//right align textfield
		jtfAnnualInterestRate.setHorizontalAlignment(JTextField.RIGHT);
		jtfNumOfYears.setHorizontalAlignment(JTextField.RIGHT);
		jtfLoanAmount.setHorizontalAlignment(JTextField.RIGHT);
		jtfMonthlyPayment.setHorizontalAlignment(JTextField.RIGHT);
		jtfTotalPayment.setHorizontalAlignment(JTextField.RIGHT);
		
		JPanel pl=new JPanel();
		pl.setLayout(new GridLayout(5,2));
		pl.add(new JLabel("AnnualInterestRate:"));
		pl.add(jtfAnnualInterestRate);
		pl.add(new JLabel("Num of Years:"));
		pl.add(jtfNumOfYears);
		pl.add(new JLabel("Loan Amount:"));
		pl.add(jtfLoanAmount);
		pl.add(new JLabel("Monthly Payment:"));
		pl.add(jtfMonthlyPayment);
		pl.add(new JLabel("Total Payment:"));
		pl.add(jtfTotalPayment);
		pl.setBorder(new TitledBorder("Enter Information"));
		
		JPanel p2=new JPanel();
		p2.add(jbtComputeMortgage);
		
		Container con=this.getContentPane();
		con.add(pl,BorderLayout.CENTER);
		con.add(p2,BorderLayout.SOUTH);
		
		jbtComputeMortgage.addActionListener(this);
		this.setSize(300,200);
	}
	
	public void start(){
		jtfAnnualInterestRate.setText("");
		jtfLoanAmount.setText("");
		jtfNumOfYears.setText("");
		jtfMonthlyPayment.setText("");
		jtfTotalPayment.setText("");
	}
	
	public void actionPerformed(ActionEvent arg0) {
		double annualInterestRate=Double.parseDouble(jtfAnnualInterestRate.getText());
		double monthlyInterestRate=annualInterestRate/1200;
		double loanAmount=Double.parseDouble(jtfLoanAmount.getText());
		int numOfYears=Integer.parseInt(jtfNumOfYears.getText());
		double monthlyPayment=loanAmount*monthlyInterestRate/(1-1/Math.pow(1+monthlyInterestRate,numOfYears*12));
		double totalPayment=monthlyPayment*12;
		jtfMonthlyPayment.setText(String.valueOf(monthlyPayment));
		jtfTotalPayment.setText(String.valueOf(totalPayment));
	}

}
