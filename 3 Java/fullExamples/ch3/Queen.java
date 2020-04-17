package ch3;

public class Queen {
	private int size;//���̴�С
	private int[] location;	//�ʺ������̵�ÿ���ϵ���λ��
	private int[] colsOccupied;	//�ʺ�������ռ�ݵ���
	private int[] cross1occupied;	//�ʺ���������ռ�ݵ����Խ���
	private int[] cross2occupied;	//�ʺ���������ռ�ݵķ��Խ���
	private static int count=0;		//��������ĸ���
	
	private static final int STATUS_OCCUPIED=1;	//ռ��״̬
	private static final int STATUS_NOTOCCUPIED=0;	//δռ��״̬
	
	public Queen(int sz){	//��ʼ��
		size=sz;
		location=new int[size];
		colsOccupied=new int[size];
		cross1occupied=new int[size*2];
		cross2occupied=new int[size*2];
	}
	
	public void printLocation(){
		System.out.println("�����ǻʺ��������ϵĵ�"+count+"�ְڷ�λ��");
		for (int i=0;i<size;i++)
			System.out.println("�У�"+i+",�У�"+location[i]);
	}
	
	//�ж�λ��(i,j)�Ƿ�ռ��
	private boolean isOccupied(int i,int j){
		return (colsOccupied[j]==STATUS_OCCUPIED)||
			(cross1occupied[i-j+size-1]==STATUS_OCCUPIED)||
			(cross2occupied[i+j]==STATUS_OCCUPIED);
	}
	
	//����(i,j)��״̬
	private void setStatus(int i,int j,int flag){
		colsOccupied[j]=flag;
		cross1occupied[i-j+size-1]=flag;
		cross2occupied[i+j]=flag;
	}
	
	//�ӵ�i�п�ʼ�ڷŻʺ�
	public void place(int i){
		for (int j=0;j<size;j++)
			if (!isOccupied(i,j)){
				location[i]=j;//�ڷ�
				setStatus(i,j,STATUS_OCCUPIED);
				//-----��i�д������
				
				if (i<size-1)
					place(i+1);	//�ڷŵ�i+1�У��ݹ鷽��
				else{
					count++;
					printLocation();//��ӡ���һ�������������
				}
				
				setStatus(i,j,STATUS_NOTOCCUPIED);
			}
	}
	
	public static void main(String[] args){
		Queen q=new Queen(8);
		q.place(0);
	}
	
}
