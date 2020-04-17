/*******************
	E21
	1427405017
	����S
	2015-6-6  14:38
********************/
#include <iostream>
#include <string>

using namespace std;

class CPerson
{
private:
	string m_name;	// ����
	int m_age;		// ����
	char m_sex;		// �Ա� ��M����ʾ���� ��F����ʾŮ��
public:
	CPerson(string& name, int age, char sex)
	{
		m_name = name;
		m_age = age;
		m_sex = sex;
	}
	CPerson()
	{
		m_name = "����";
		m_age = 18;
		m_sex = 'M';
	}
	void print()
	{
		cout<<"\n ������"<<m_name<<"\n ���䣺"<<m_age<<"\n";
		if (m_sex == 'M')
			cout<<"�Ա� ��"<<endl;
		else
			cout<<"�Ա� Ů"<<endl;
	}
};

class CStudent : public CPerson		//��CPerson ��Ϊ���ඨ��һ��������CStudent
{
private:
	string m_university;
	int m_grade;

public:
	CStudent();		// ��{����������18 �ꡢ���ԡ������ݴ�ѧ����1 �꼶}ΪĬ��ֵ���޲ι��캯����
	CStudent(string name, int , char, string collageName, int grade); // �������Ĺ��캯��
	void print();	 // ��ʾѧ��������������Ϣ

};

CStudent::CStudent():CPerson(),m_university("���ݴ�ѧ")	// ��{����������18 �ꡢ���ԡ������ݴ�ѧ����1 �꼶}ΪĬ��ֵ���޲ι��캯��
{
	m_grade = 1;
}

CStudent::CStudent(string name, int age, char sex, string collageName, int grade):CPerson(name,age,sex),m_university(collageName)	 // �������Ĺ��캯��
{
	m_grade = grade;
}

void CStudent::print()	 // ��ʾѧ��������������Ϣ
{
	CPerson::print();
	cout<<"ѧУ��"<<m_university<<endl;
	cout<<"�꼶��"<<m_grade<<endl;
}

void main()
{
	CStudent student1;
	student1.print();

	CStudent student2("Liming",21,'M',"���ݴ�ѧ",1);
	student2.print();
}