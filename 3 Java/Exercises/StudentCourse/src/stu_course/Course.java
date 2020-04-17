/*
 * ʵ����
 * Course.java
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

public class Course {
	static int count = 0;
	private String name;
	private String id;
	
	public Course(String new_name)					//��ָ��id��ʹ��ϵͳĬ�Ϸ����id
	{
		count++;
		name = new_name;
		id = Integer.toString(count);
	}
	public Course(String new_name, String new_id)	//ָ��id
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
