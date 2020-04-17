/*
 * 实验三
 * SC_Relation_List.java
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

public class SC_Relation_List {
	private SC_Relation[] sc_list;
	private int count = 0;
	
	public static void main(String[] args)
	{
		SC_Relation_List scr_list = new SC_Relation_List(10);
		Student_List s_list = new Student_List(10);
		Course_List c_list = new Course_List(10);
		
		s_list.insert("stuA");
		s_list.insert("stuB");
		s_list.insert("stuC");
		System.out.println("学生表信息如下（学号 姓名）：");
		s_list.display_all();
		
		System.out.println("测试学生表delete功能（删除存在的1 不存在的4）：");
		s_list.delete("1");
		s_list.delete("4");
		System.out.println("学生表信息如下（学号 姓名）：");
		s_list.display_all();
		s_list.insert("stuA","1");
		
		System.out.println("课程表信息如下（课程号 课程名）：");
		c_list.insert("couA");
		c_list.insert("couB");
		c_list.insert("couC");
		c_list.display_all();
		
		scr_list.insert("1", s_list, "3", c_list);
		scr_list.insert("2", s_list, "2", c_list);
		scr_list.insert("3", s_list, "5", c_list);
		System.out.println("学生选课表存储信息如下：");
		scr_list.display_all();
		System.out.println("学生选课表代表信息如下：");
		scr_list.display_all_info(s_list, c_list);
		
		System.out.println("测试delete功能（测试删除存在的1 3，不存在的1 2）：");
		scr_list.delete("1", "3");
		scr_list.delete("1", "2");
		System.out.println("学生选课表存储信息如下：");
		scr_list.display_all();
		System.out.println("学生选课表代表信息如下：");
		scr_list.display_all_info(s_list, c_list);
		
		System.out.println("测试insert功能（测试插入存在的2 2，不存在的1 3）：");
		scr_list.insert("2", s_list, "2", c_list);
		scr_list.insert("1", s_list, "3", c_list);
		System.out.println("学生选课表存储信息如下：");
		scr_list.display_all();
		System.out.println("学生选课表代表信息如下：");
		scr_list.display_all_info(s_list, c_list);
		
		System.out.println("1号学生选课信息如下：");
		scr_list.get_student_courses("1", s_list, c_list);
		
		System.out.println("2号课程已选学生信息如下：");
		scr_list.get_course_students("2", s_list, c_list);
	}
	
	public SC_Relation_List()
	{
		sc_list = new SC_Relation[50];
	}
	
	public SC_Relation_List(int size)
	{
		sc_list = new SC_Relation[size];
	}
	
	public boolean insert(String s_id, Student_List s_list, String c_id, Course_List c_list)
	{
		if( retrieve(s_id, c_id) != null )
		{
			System.out.println("学生选课表中已有该条学生选课关系记录，插入失败！错误学生ID 课程ID："
					+ s_id + " " + c_id);
			return false;
		}
		if(s_list.retrieve(s_id) == null)
		{
			System.out.println("学生表中无此学生，插入失败！错误学生ID：" + s_id);
			return false;
		}
		if(c_list.retrieve(c_id) == null)
		{
			System.out.println("课程表中无此课程，插入失败！错误课程ID：" + c_id);
			return false;
		}
		sc_list[count] = new SC_Relation(s_id, c_id);
		count++;
		return true;
	}
	
	public boolean delete(String s_id, String c_id)
	{
		int pos = 0;
		SC_Relation scr = retrieve(s_id, c_id, pos);
		if( scr == null )
		{
			System.out.println("当前学生选课表中无此条学生选课关系记录，删除无效！错误学生ID 课程ID："
					+ s_id + " "+ c_id);
			return false;
		}
		for(int i=pos; i+1<count; i++)
		{
			sc_list[i] = sc_list[i+1];	//指向sc_list[pos]的引用丢失，该对象会被虚拟机回收
		}
		sc_list[count-1] = null;	//原尾项引用丢弃
		count--;
		return true;
	}
	
	public SC_Relation retrieve(String s_id, String c_id)
	{
		for(int i=0;i<count;i++)
		{
			if(sc_list[i].get_student_id().equals(s_id) && sc_list[i].get_course_id().equals(c_id))
			{
				return sc_list[i];
			}
		}
		return null;
	}
	
	public SC_Relation retrieve(String s_id, String c_id, int pos)
	{
		for(int i=0;i<count;i++)
		{
			if(sc_list[i].get_student_id().equals(s_id) && sc_list[i].get_course_id().equals(c_id))
			{
				pos = i;
				return sc_list[i];
			}
		}
		return null;
	}
	
	public void display_all()
	{
		for(int i=0; i<count; i++)
		{
			System.out.println(sc_list[i].toString());
		}
	}
	
	public void display_all_info(Student_List s_list, Course_List c_list)	//display_all_info显示学生选课表具体对应的信息
	{
		for(int i=0; i<count; i++)
		{
			System.out.println( s_list.retrieve(sc_list[i].get_student_id()).get_name() + " "
					+ c_list.retrieve(sc_list[i].get_course_id()).get_name());
		}
	}
	
	public void get_student_courses(String s_id, Student_List s_list, Course_List c_list)	//get_student_courses显示特定学生所选课程
	{
		for(int i=0; i<count; i++)
		{
			if(sc_list[i].get_student_id().equals(s_id))
			{
				System.out.println( s_list.retrieve(s_id).get_name() + " "
			 + c_list.retrieve(sc_list[i].get_course_id()).get_name());
			}
		}
	}
	
	public void get_course_students(String c_id, Student_List s_list, Course_List c_list)	//get_courses_student显示特定课程已选学生
	{
		for(int i=0; i<count; i++)
		{
			if(sc_list[i].get_course_id().equals(c_id))
			{
				System.out.println( c_list.retrieve(c_id).get_name() + " "
			 + s_list.retrieve(sc_list[i].get_student_id()).get_name());
			}
		}
	}
	
}