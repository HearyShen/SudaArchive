/*
 * ʵ����
 * Course_List.java
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
			System.out.println("�γ̱������иÿγ̺�ID������ʧ�ܣ�");
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
			System.out.println("��ǰ�γ̱����޴˿γ̺ż�¼��ɾ����Ч������γ�ID��"
					+ del_id);
			return false;
		}
		for(int i=pos; i+1<count; i++)
		{
			course_list[i] = course_list[i+1];	//ָ��course_list[pos]�����ö�ʧ���ö���ᱻ���������
		}
		course_list[count-1] = null;	//ԭβ�����ö���
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
