#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class CGoods
{
	string	m_name;					//��Ʒ����
	double	m_price;				//��Ʒ�۸�
public:
	CGoods(string name,double price)		//���캯��
	{
		m_name=name;
		m_price=price;
	}
	string getName() const				//��ȡ��Ʒ����
	{
		return m_name;
	}
	double getPrice() const				//��ȡ��Ʒ�۸�
	{
		return m_price;
	}
	void setPrice(double price)			//������Ʒ�۸�
	{
		m_price=price;
	}
};

class CBook : public CGoods
{
private:
	string	m_writer;
	int		m_pages;
public:
	CBook(const string& Name, double Price, string Writer, int Pages);
	friend CBook& operator--(CBook &A);
	friend CBook operator--(CBook &A, int);
	friend ostream& operator<<(ostream& out, const CBook &A);
	int GetPages()const;
};

CBook::CBook(const string& Name, double Price, string Writer, int Pages):CGoods(Name,Price),m_writer(Writer)
{
	m_pages = Pages;
}

CBook& operator--(CBook &A)
{
	if(A.getPrice() >= 10)
	{
		A.setPrice(A.getPrice()-1);
	}
	return A;
}

CBook operator--(CBook &A, int)
{
	CBook T(A);

	if(A.getPrice() >= 10)
	{
		A.setPrice(A.getPrice()-1);
	}
	return T;
}

ostream& operator<<(ostream& out, const CBook &A)
{
	out<<"������"<<A.getName()<<endl;
	out<<"�۸�"<<A.getPrice()<<endl;
	out<<"���ߣ�"<<A.m_writer<<endl;
	out<<"ҳ����"<<A.m_pages<<endl;
	out<<"============================";

	return out;
}

int CBook::GetPages()const
{
	return m_pages;
}

void readData(const string &FName,vector<CBook> &Vect);		//���ļ��ж�ȡ���ݵ�����
void showData(const vector<CBook> &Vect);					//��ʾ��ȡ��������
void processData(vector<CBook> &newVect, vector<CBook> &Vect);	//��ҳ�����200ҳ���鼮ִ��ǰ��--
void outputData(vector<CBook> &newVect);				//���myVectNew�����м۸����10Ԫ���鼮���ƣ�һ��һ��

void main()
{
	vector<CBook> myVect;				//��������
	readData("d:\\books.txt",myVect);		//���ļ��ж�ȡ���ݵ�����
	showData(myVect);					//��ʾ��ȡ��������
	vector<CBook> myVectNew;			//��������
	processData(myVectNew,myVect);	//��ҳ�����200ҳ���鼮ִ��ǰ��--��
										//ͬʱ�Ѹö�����뵽myVectNew��
										//�����鼮ִ�к���--��
										//ͬʱ�Ѹö�����뵽myVectNew��
	showData(myVectNew);
	outputData(myVectNew);				//���myVectNew�����м۸����10Ԫ
										//���鼮���ƣ�һ��һ��
}

void readData(const string &FName,vector<CBook> &Vect)		//���ļ��ж�ȡ���ݵ�����
{
	ifstream fin(FName);
	if(fin == NULL)
	{
		cout<<"�ļ���ʧ�ܣ�"<<endl;
		exit(0);
	}

	string t_name;
	double t_price;
	string t_writer;
	int t_pages;

	while(fin.eof() != true)
	{
		fin>>t_name>>t_price>>t_writer>>t_pages;
		if(fin != NULL)
		{
			Vect.push_back(CBook(t_name,t_price,t_writer,t_pages));
		}
	}
	fin.close();
}

void showData(const vector<CBook> &Vect)					//��ʾ��ȡ��������
{
	for(int i=0;i<Vect.size();i++)
	{
		cout<<Vect[i]<<endl;
	}
	cout<<endl<<endl;
}

void processData(vector<CBook> &newVect, vector<CBook> &Vect)	//��ҳ�����200ҳ���鼮ִ��ǰ��--
{
	for(int i=0;i<Vect.size();i++)
	{
		if(Vect[i].GetPages() > 200)
		{
			newVect.push_back(--Vect[i]);
		}
		else
		{
			newVect.push_back(Vect[i]--);
		}
	}
}

void outputData(vector<CBook> &newVect)				//���myVectNew�����м۸����10Ԫ���鼮���ƣ�һ��һ��
{
	for(int i=0;i<newVect.size();i++)
	{
		if(newVect[i].getPrice() < 10)
		{
			cout<<newVect[i]<<endl;
		}
	}
}