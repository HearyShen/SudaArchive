/*******************
	E22
	1427405017
	����S
	2015-6-6 14:38
*******************/
#include <iostream>
#include <string>

using namespace std;

class CBook
{
private:
	string name;
	string author;
	double price;
	string publisher;
public:
	CBook(){name = "��"; author="��"; price = 0.0; publisher = "��";}
	CBook(const CBook &); // �������캯��
	CBook(string , string, double, string); // �������Ĺ��캯��
	CBook(char*, char*, double, char*); // �������Ĺ��캯��
	~CBook(); // ��������
	void SetName(char*); // ���������ĳ�Ա����
	void SetName(string&); // ���������ĳ�Ա����
	void print()const; // ����Ļ����ʾ�����Ϣ�ĳ�Ա����
	friend ostream & operator<<(ostream& out, const CBook &); // ��������������غ���
};

CBook::CBook(const CBook &A)	// �������캯��
{
	name = A.name;
	author = A.author;
	price = A.price;
	publisher = A.publisher;
}
CBook::CBook(string Name, string Author, double Price, string Publisher)		// �������Ĺ��캯��
{
	name = Name;
	author = Author;
	price = Price;
	publisher = Publisher;
}
CBook::CBook(char* Name, char* Author, double Price, char* Publisher)	 // �������Ĺ��캯��
{
	name = Name;
	author = Author;
	price = Price;
	publisher = Publisher;
}
CBook::~CBook()		 // ��������
{
	cout<<name<<"���������ˣ�"<<endl;
}
void CBook::SetName(char* Name)		 // ���������ĳ�Ա����
{
	name = Name;
}
void CBook::SetName(string& Name)	 // ���������ĳ�Ա����
{
	name = Name;
}
void CBook::print()const	 // ����Ļ����ʾ�����Ϣ�ĳ�Ա����
{
	cout<<"������"<<name<<endl;
	cout<<"���ߣ�"<<author<<endl;
	cout<<"�۸�"<<price<<endl;
	cout<<"�����磺"<<publisher<<endl;
}
ostream & operator<<(ostream& out, const CBook &A) // ��������������غ���
{
	out<<"������"<<A.name<<endl;
	out<<"���ߣ�"<<A.author<<endl;
	out<<"�۸�"<<A.price<<endl;
	out<<"�����磺"<<A.publisher<<endl;
	
	return out;
}


class CComputerBook:public CBook
{
private:
	string field;
	string type;

public:
	CComputerBook();	//a) �޲ι��캯��
	CComputerBook(string Name, string Author, double Price, string Publisher, string Field, string Type);	//b) �������Ĺ��캯��
	~CComputerBook();	//c) ��������
	friend ostream& operator<<(ostream& out,const CComputerBook A);	//d) ����������غ���

};

CComputerBook::CComputerBook():CBook(),field("��"),type("��")		//a) �޲ι��캯��
{
}

CComputerBook::CComputerBook(string Name, string Author, double Price, string Publisher, string Field, string Type):CBook(Name,Author,Price,Publisher),field(Field),type(Type)	//b) �������Ĺ��캯��
{
}

CComputerBook::~CComputerBook()		//c) ��������
{
	cout<<"CComputerBook �����������!"<<endl;
}

ostream& operator<<(ostream& out,const CComputerBook A)	//d) ����������غ���
{
	out<<(CBook)A<<"����"<<A.field<<"\n���"<<A.type<<endl;

	return out;
}

void main()
{
	CComputerBook *p = new CComputerBook("C������ƽ̳�","����",35.0,"�廪��ѧ������","�������","�̲�");

	cout<<*p<<endl;

	delete p;
}