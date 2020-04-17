/*
 * ʵ����
 * SC_Relation_List.java
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
		System.out.println("ѧ������Ϣ���£�ѧ�� ��������");
		s_list.display_all();
		
		System.out.println("����ѧ����delete���ܣ�ɾ�����ڵ�1 �����ڵ�4����");
		s_list.delete("1");
		s_list.delete("4");
		System.out.println("ѧ������Ϣ���£�ѧ�� ��������");
		s_list.display_all();
		s_list.insert("stuA","1");
		
		System.out.println("�γ̱���Ϣ���£��γ̺� �γ�������");
		c_list.insert("couA");
		c_list.insert("couB");
		c_list.insert("couC");
		c_list.display_all();
		
		scr_list.insert("1", s_list, "3", c_list);
		scr_list.insert("2", s_list, "2", c_list);
		scr_list.insert("3", s_list, "5", c_list);
		System.out.println("ѧ��ѡ�α�洢��Ϣ���£�");
		scr_list.display_all();
		System.out.println("ѧ��ѡ�α������Ϣ���£�");
		scr_list.display_all_info(s_list, c_list);
		
		System.out.println("����delete���ܣ�����ɾ�����ڵ�1 3�������ڵ�1 2����");
		scr_list.delete("1", "3");
		scr_list.delete("1", "2");
		System.out.println("ѧ��ѡ�α�洢��Ϣ���£�");
		scr_list.display_all();
		System.out.println("ѧ��ѡ�α������Ϣ���£�");
		scr_list.display_all_info(s_list, c_list);
		
		System.out.println("����insert���ܣ����Բ�����ڵ�2 2�������ڵ�1 3����");
		scr_list.insert("2", s_list, "2", c_list);
		scr_list.insert("1", s_list, "3", c_list);
		System.out.println("ѧ��ѡ�α�洢��Ϣ���£�");
		scr_list.display_all();
		System.out.println("ѧ��ѡ�α������Ϣ���£�");
		scr_list.display_all_info(s_list, c_list);
		
		System.out.println("1��ѧ��ѡ����Ϣ���£�");
		scr_list.get_student_courses("1", s_list, c_list);
		
		System.out.println("2�ſγ���ѡѧ����Ϣ���£�");
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
			System.out.println("ѧ��ѡ�α������и���ѧ��ѡ�ι�ϵ��¼������ʧ�ܣ�����ѧ��ID �γ�ID��"
					+ s_id + " " + c_id);
			return false;
		}
		if(s_list.retrieve(s_id) == null)
		{
			System.out.println("ѧ�������޴�ѧ��������ʧ�ܣ�����ѧ��ID��" + s_id);
			return false;
		}
		if(c_list.retrieve(c_id) == null)
		{
			System.out.println("�γ̱����޴˿γ̣�����ʧ�ܣ�����γ�ID��" + c_id);
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
			System.out.println("��ǰѧ��ѡ�α����޴���ѧ��ѡ�ι�ϵ��¼��ɾ����Ч������ѧ��ID �γ�ID��"
					+ s_id + " "+ c_id);
			return false;
		}
		for(int i=pos; i+1<count; i++)
		{
			sc_list[i] = sc_list[i+1];	//ָ��sc_list[pos]�����ö�ʧ���ö���ᱻ���������
		}
		sc_list[count-1] = null;	//ԭβ�����ö���
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
	
	public void display_all_info(Student_List s_list, Course_List c_list)	//display_all_info��ʾѧ��ѡ�α�����Ӧ����Ϣ
	{
		for(int i=0; i<count; i++)
		{
			System.out.println( s_list.retrieve(sc_list[i].get_student_id()).get_name() + " "
					+ c_list.retrieve(sc_list[i].get_course_id()).get_name());
		}
	}
	
	public void get_student_courses(String s_id, Student_List s_list, Course_List c_list)	//get_student_courses��ʾ�ض�ѧ����ѡ�γ�
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
	
	public void get_course_students(String c_id, Student_List s_list, Course_List c_list)	//get_courses_student��ʾ�ض��γ���ѡѧ��
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