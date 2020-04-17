/*
 * ʵ����
 * Student_List.java
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

public class Student_List {
	private Student[] student_list;
	private int count = 0;
	
	public Student_List()
	{
		student_list = new Student[50];
	}
	public Student_List(int size)
	{
		student_list = new Student[size];
	}
	public void insert(String new_name)
	{
		student_list[count] = new Student(new_name);
		count++;
	}
	
	public boolean insert(String new_name, String new_id)
	{
		if( retrieve(new_id) != null )
		{
			System.out.println("ѧ���������и�ѧ��ID������ʧ�ܣ�");
			return false;
		}
		student_list[count] = new Student(new_name,new_id);
		count++;
		return true;
	}
	
	public boolean delete(String del_id)
	{
		int pos = 0;
		Student stu = retrieve(del_id, pos);
		if( stu == null )
		{
			System.out.println("��ǰѧ�������޴�ѧ�ż�¼��ɾ����Ч������ѧ��ID��"
		+ del_id);
			return false;
		}
		for(int i=pos; i+1<count; i++)
		{
			student_list[i] = student_list[i+1];		//ָ��student_list[pos]�����ö�ʧ���ö���ᱻ���������
		}
		student_list[count-1] = null;	//ԭβ�����ö���
		count--;
		return true;
	}
	
	public Student retrieve(String seek_id)
	{
		for(int i=0;i<count;i++)
		{
			if(student_list[i].get_id().equals(seek_id))
			{
				return student_list[i];
			}
		}
		return null;
	}
	
	public Student retrieve(String seek_id, int pos)
	{
		for(int i=0;i<count;i++)
		{
			if(student_list[i].get_id().equals(seek_id))
			{
				pos = i;
				return student_list[i];
			}
		}
		return null;
	}
	
	public void display_all()
	{
		for(int i=0;i<count;i++)
		{
			System.out.println(student_list[i].toString());
		}
	}
	
}
