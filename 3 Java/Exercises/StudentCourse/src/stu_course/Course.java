/*
 * 实验三
 * Course.java
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

public class Course {
	static int count = 0;
	private String name;
	private String id;
	
	public Course(String new_name)					//不指定id，使用系统默认分配的id
	{
		count++;
		name = new_name;
		id = Integer.toString(count);
	}
	public Course(String new_name, String new_id)	//指定id
	{
		count++;
		name = new_name;
		id = new_id;
	}
	public void update_name(String new_name)
	{
		name = new_name;
	}
	public void update_id(String new_id)
	{
		id = new_id;
	}
	public String get_name()
	{
		return name;
	}
	public String get_id()
	{
		return id;
	}
	public String toString()
	{
		return get_id()+ " " + get_name();
	}
}
