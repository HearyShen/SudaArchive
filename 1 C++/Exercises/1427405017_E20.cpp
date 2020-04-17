/*****************
	E20
	1427405017
	����S
	2015-5-20 9:47
******************/
#include <iostream>

using namespace std;

class CContry
{
private:
	char *name;		//��������
	char *caption;		//�׶�����
	double area;		//�����������λ��ƽ������
	double person_num;		//�˿���������λ ��
public:
	CContry()		//�޲ι��캯��
	{
		name = new char[100];
		strcpy(name,"�й�");
		caption = new char[100];
		strcpy(caption,"����");
		area = 960;
		person_num = 130000.00;
	}
	CContry(const CContry&);		//�������캯��
	CContry(char* ,char* ,double ,double);	//�������Ĺ��캯��
	CContry& operator=(const CContry&);
	~CContry();		//��������
	void set(char*,char*,double ,double );		//�������Եĳ�Ա����
	void print()const;		//����Ļ�����CContry�������Ϣ
};
CContry::CContry(const CContry& A)		//�������캯��
{
	name = new char[100];
	strcpy(name,A.name);
	caption = new char[100];
	strcpy(caption,A.caption);
	area = A.area;
	person_num = A.person_num;
}
CContry::CContry(char* Name, char* Caption, double Area, double Person_num)	//�������Ĺ��캯��
{
	name = new char[100];
	strcpy(name,Name);
	caption = new char[100];
	strcpy(caption,Caption);
	area = Area;
	person_num = Person_num;
}
CContry& CContry::operator=(const CContry& A)
{
	strcpy(name,A.name);
	strcpy(caption,A.caption);
	area = A.area;
	person_num = A.person_num;

	return *this;
}
CContry::~CContry()		//��������
{
	cout<<name<<"���������ˣ�"<<endl;

	delete [] name;
	delete [] caption;
}
void CContry::set(char* Name,char* Caption,double Area,double Person_num)		//�������Եĳ�Ա����
{
	strcpy(name,Name);
	strcpy(caption,Caption);
	area = Area;
	person_num = Person_num;
}
void CContry::print()const		//����Ļ�����CContry�������Ϣ
{
	cout<<"�������ƣ�"<<name<<endl;
	cout<<"�׶����ƣ�"<<caption<<endl;
	cout<<"�����"<<area<<endl;
	cout<<"�˿�������"<<person_num<<endl;
}

void main()
{
	CContry Ch;
	Ch.print();
	cout<<endl<<endl;

	CContry Jap("�ձ�","����",37.835,12665.9683);
	Jap.print();
	cout<<endl<<endl;
}