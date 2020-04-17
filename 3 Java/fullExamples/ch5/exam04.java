package ch5;

/* 编程完成下列功能：
1) 要求生成一个随机整数x，其取值范围为1800~2004之间，表示一个年份；
2) 判断x是否是闰年，如果是，则向屏幕显示闰年的信息，否则显示不是闰年的信息 */
public class exam04 {
	static final int HIGH = 2004;
	static final int LOW = 1800;

	public static void main(String[] args) {
		for (int i = 0; i < 100; i++) {
			int x = (int) ((HIGH - LOW + 1) * Math.random());
			x += LOW;
			if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
				System.out.println(x + "是闰年！");
			else
				System.out.println(x + "不是闰年！");
		}
	}
}
