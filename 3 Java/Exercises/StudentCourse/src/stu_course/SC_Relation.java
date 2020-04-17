/*
 * 实验三
 * SC_Relation.java
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

public class SC_Relation {
	private String student_id;
	private String course_id;
	
	public SC_Relation(String s_id, String c_id)
	{
		student_id = s_id;
		course_id = c_id;
	}
	public void update_course(String c_id)
	{
		course_id = c_id;
	}
	public void update_student(String s_id)
	{
		student_id = s_id;
	}
	public String get_course_id()
	{
		return course_id;
	}
	public String get_student_id()
	{
		return student_id;
	}
	public String toString()
	{
		return get_student_id() +" "+ get_course_id();
	}
	public boolean equals(SC_Relation new_r)
	{
		if(new_r.get_student_id().equals(student_id) && new_r.get_course_id().equals(course_id))
		{
			return true;
		}
		return false;
	}
}
