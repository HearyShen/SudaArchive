/*
 * 实验三
 * Course_List.java
 * 1427405017
 * 沈家赟
 */
/*
学生选课

1. 学生及其选课信息借助数组存储（后续考虑IO或Database接口）
2. 具有以下功能：
	1）增加、删除、修改某个学生
	2）增加、删除、修改某门课程
	3）学生选课、退选、查看已选课程
	4）根据指定课程，查看目前的选课情况
3. 要求：
	根据上述描述进行相关类的定义
	主函数部分，目前使用标准输入输出进行上述功能的测试（后续添加对应的GUI部分）
	对自己完成的内容，以文字的方式进行解释说明。
*/
package stu_course;

public class Course_List {
	private Course[] course_list;
	private int count = 0;
	
	public Course_List()
	{
		course_list = new Course[50];
	}
	public Course_List(int size)
	{
		course_list = new Course[size];
	}
	public void insert(String new_name)
	{
		course_list[count] = new Course(new_name);
		count++;
	}
	
	public boolean insert(String new_name, String new_id)
	{
		if( retrieve(new_id) != null )
		{
			System.out.println("课程表中已有该课程号ID，插入失败！");
			return false;
		}
		course_list[count] = new Course(new_name,new_id);
		count++;
		return true;
	}
	
	public boolean delete(String del_id)
	{
		int pos = 0;
		Course cou = retrieve(del_id, pos);
		if( cou == null )
		{
			System.out.println("当前课程表中无此课程号记录，删除无效！错误课程ID："
					+ del_id);
			return false;
		}
		for(int i=pos; i+1<count; i++)
		{
			course_list[i] = course_list[i+1];	//指向course_list[pos]的引用丢失，该对象会被虚拟机回收
		}
		course_list[count-1] = null;	//原尾项引用丢弃
		count--;
		return true;
	}
	
	public Course retrieve(String seek_id)
	{
		for(int i=0;i<count;i++)
		{
			if(course_list[i].get_id().equals(seek_id))
			{
				return course_list[i];
			}
		}
		return null;
	}
	
	public Course retrieve(String seek_id, int pos)
	{
		for(int i=0;i<count;i++)
		{
			if(course_list[i].get_id().equals(seek_id))
			{
				pos = i;
				return course_list[i];
			}
		}
		return null;
	}
	
	public void display_all()
	{
		for(int i=0;i<count;i++)
		{
			System.out.println(course_list[i].toString());
		}
	}
	
}
