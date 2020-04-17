/*
 * ʵ����
 * SC_Relation.java
 * 1427405017
 * ����S
 */
/*
ѧ��ѡ��

1. ѧ������ѡ����Ϣ��������洢����������IO��Database�ӿڣ�
2. �������¹��ܣ�
	1�����ӡ�ɾ�����޸�ĳ��ѧ��
	2�����ӡ�ɾ�����޸�ĳ�ſγ�
	3��ѧ��ѡ�Ρ���ѡ���鿴��ѡ�γ�
	4������ָ���γ̣��鿴Ŀǰ��ѡ�����
3. Ҫ��
	���������������������Ķ���
	���������֣�Ŀǰʹ�ñ�׼������������������ܵĲ��ԣ�������Ӷ�Ӧ��GUI���֣�
	���Լ���ɵ����ݣ������ֵķ�ʽ���н���˵����
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
