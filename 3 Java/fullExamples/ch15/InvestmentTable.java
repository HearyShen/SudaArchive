package ch15;

import javax.swing.*;
import javax.swing.table.*;

class InvestmentTableModel extends AbstractTableModel{
	
	private static final long serialVersionUID = 1L;
	private static double INITIAL_BALANCE=100000.0;
	private int years,minRate,maxRate;
	
	public InvestmentTableModel(int y,int r1,int r2){
		years=y;
		minRate=r1;
		maxRate=r2;
	}
	
	public int getColumnCount() {
		return (maxRate-minRate+1);
	}

	public int getRowCount() {
		return years;
	}

	public Object getValueAt(int r,int c) {
		double rate=(c+minRate)/100.0;
		int nperiods=r;
		double futureBalance=INITIAL_BALANCE*Math.pow(1+rate,nperiods);
		return String.format("%.2f",futureBalance);
	}
	
	public String getColumnName(int c){
		return ((c+minRate)+"%");
	}
}

class InvestmentTableFrame extends JFrame{
	private static final long serialVersionUID = 1L;

	public InvestmentTableFrame(){
		setTitle("InvestmentTable");
		setSize(600,300);
		TableModel model=new InvestmentTableModel(30,5,10);
		JTable table=new JTable(model);
		this.getContentPane().add(new JScrollPane(table));
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
}

public class InvestmentTable {
	public static void main(String[] args){
		new InvestmentTableFrame();
	}
}
