package ch5;

/* ���������й��ܣ�
1) Ҫ������һ���������x����ȡֵ��ΧΪ1800~2004֮�䣬��ʾһ����ݣ�
2) �ж�x�Ƿ������꣬����ǣ�������Ļ��ʾ�������Ϣ��������ʾ�����������Ϣ */
public class exam04 {
	static final int HIGH = 2004;
	static final int LOW = 1800;

	public static void main(String[] args) {
		for (int i = 0; i < 100; i++) {
			int x = (int) ((HIGH - LOW + 1) * Math.random());
			x += LOW;
			if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
				System.out.println(x + "�����꣡");
			else
				System.out.println(x + "�������꣡");
		}
	}
}
