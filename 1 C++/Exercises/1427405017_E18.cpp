/*******************
	E18
	1427405017
	����S
	2015-5-18 17:20
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

void main()
{
	string n="C++�������", a="����", pub="���ݴ�ѧ������";

	CBook b1;
	cout<<b1<<endl;
	b1.SetName(n);
	b1.print();
	b1.SetName("VB");
	cout<<b1<<endl;

	CBook b2=b1;
	cout<<b2<<endl;

	CBook b3(n,a,35.0,pub);
	cout<<b3<<endl;

	CBook *b4=new CBook("VC++", "���", 45.0, "�廪��ѧ������");
	cout<<*b4<<endl;
	delete b4;
}