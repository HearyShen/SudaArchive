package ch3;

public class FindSalesAmount {
	
	public static void main(String[] args){
		final double COMMISSION_SOUGHT=30000-5000;
		double commission=0;
		double salesAmount=1;
		while (commission<COMMISSION_SOUGHT){
			if (salesAmount>=10001)
				commission=5000*0.08+5000*0.1+(salesAmount-10000)*0.12;
			else if (salesAmount>5001)
				commission=5000*0.08+(salesAmount-5000)*0.1;
			else
				commission=salesAmount*0.08;
			salesAmount++;
		}
		
		System.out.println("最小销售数量："+salesAmount);
	}
}
