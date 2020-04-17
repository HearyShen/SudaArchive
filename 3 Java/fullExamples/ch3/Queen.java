package ch3;

public class Queen {
	private int size;//棋盘大小
	private int[] location;	//皇后在棋盘的每行上的列位置
	private int[] colsOccupied;	//皇后棋盘上占据的列
	private int[] cross1occupied;	//皇后在棋盘上占据的正对角线
	private int[] cross2occupied;	//皇后在棋盘上占据的反对角线
	private static int count=0;		//解决方案的个数
	
	private static final int STATUS_OCCUPIED=1;	//占领状态
	private static final int STATUS_NOTOCCUPIED=0;	//未占领状态
	
	public Queen(int sz){	//初始化
		size=sz;
		location=new int[size];
		colsOccupied=new int[size];
		cross1occupied=new int[size*2];
		cross2occupied=new int[size*2];
	}
	
	public void printLocation(){
		System.out.println("以下是皇后在棋盘上的第"+count+"种摆放位置");
		for (int i=0;i<size;i++)
			System.out.println("行："+i+",列："+location[i]);
	}
	
	//判断位置(i,j)是否被占领
	private boolean isOccupied(int i,int j){
		return (colsOccupied[j]==STATUS_OCCUPIED)||
			(cross1occupied[i-j+size-1]==STATUS_OCCUPIED)||
			(cross2occupied[i+j]==STATUS_OCCUPIED);
	}
	
	//设置(i,j)的状态
	private void setStatus(int i,int j,int flag){
		colsOccupied[j]=flag;
		cross1occupied[i-j+size-1]=flag;
		cross2occupied[i+j]=flag;
	}
	
	//从第i行开始摆放皇后
	public void place(int i){
		for (int j=0;j<size;j++)
			if (!isOccupied(i,j)){
				location[i]=j;//摆放
				setStatus(i,j,STATUS_OCCUPIED);
				//-----第i行处理完毕
				
				if (i<size-1)
					place(i+1);	//摆放第i+1行－递归方法
				else{
					count++;
					printLocation();//打印输出一种完整解决方案
				}
				
				setStatus(i,j,STATUS_NOTOCCUPIED);
			}
	}
	
	public static void main(String[] args){
		Queen q=new Queen(8);
		q.place(0);
	}
	
}
