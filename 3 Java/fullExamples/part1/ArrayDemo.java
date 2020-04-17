package part1;

import java.util.Scanner;


public class ArrayDemo {
	
	public static void main(String[] args)
	{
		String[] names;
		String courses[][];
		Scanner scn=new Scanner(System.in);
		
		int x;
		System.out.println("请输入人数：");
		x=scn.nextInt();
		scn.nextLine();
		names=new String[x];
		System.out.println("输入姓名，每个一行");
		for (int i=0;i<names.length;i++)
			names[i]=scn.nextLine();
		courses=new String[x][];
		for (int i=0;i<names.length;i++)
		{
			System.out.println("请输入"+names[i]+"选课信息，课程之间逗号间隔，每人一行");
			courses[i]=scn.nextLine().split(",");
		}
		System.out.println("***************************************************");
		System.out.println("请输入要查找选课者的姓名：");
		String tmpName=scn.nextLine();
		int idx=-1;
		for (int i=0;i<names.length;i++)
			if (names[i].equals(tmpName))
			{
				idx=i;
				break;
			}
		if (idx==-1)
			System.out.println("查无此人！");
		else
		{
			System.out.println("选课情况为：");
			for (int i=0;i<courses[idx].length;i++)
				System.out.println(courses[idx][i]);
		}
		
		System.out.println("请输入要查找的课程：");
		tmpName=scn.nextLine();
		for (idx=0;idx<courses.length;idx++)
		{
			for (int i=0;i<courses[idx].length;i++)
				if (courses[idx][i].equals(tmpName))
				{
					System.out.println(names[idx]);
					break;
				}
		}
		
		scn.close();
	}

}
