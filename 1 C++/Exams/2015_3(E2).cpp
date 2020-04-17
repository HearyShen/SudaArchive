#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class CGoods
{
	string	m_name;					//商品名称
	double	m_price;				//商品价格
public:
	CGoods(string name,double price)		//构造函数
	{
		m_name=name;
		m_price=price;
	}
	string getName() const				//获取商品名称
	{
		return m_name;
	}
	double getPrice() const				//获取商品价格
	{
		return m_price;
	}
	void setPrice(double price)			//设置商品价格
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
	out<<"书名："<<A.getName()<<endl;
	out<<"价格："<<A.getPrice()<<endl;
	out<<"作者："<<A.m_writer<<endl;
	out<<"页数："<<A.m_pages<<endl;
	out<<"============================";

	return out;
}

int CBook::GetPages()const
{
	return m_pages;
}

void readData(const string &FName,vector<CBook> &Vect);		//从文件中读取数据到向量
void showData(const vector<CBook> &Vect);					//显示读取到的数据
void processData(vector<CBook> &newVect, vector<CBook> &Vect);	//对页码大于200页的书籍执行前置--
void outputData(vector<CBook> &newVect);				//输出myVectNew中所有价格低于10元的书籍名称，一行一个

void main()
{
	vector<CBook> myVect;				//创建向量
	readData("d:\\books.txt",myVect);		//从文件中读取数据到向量
	showData(myVect);					//显示读取到的数据
	vector<CBook> myVectNew;			//创建向量
	processData(myVectNew,myVect);	//对页码大于200页的书籍执行前置--，
										//同时把该对象插入到myVectNew中
										//其余书籍执行后置--，
										//同时把该对象插入到myVectNew中
	showData(myVectNew);
	outputData(myVectNew);				//输出myVectNew中所有价格低于10元
										//的书籍名称，一行一个
}

void readData(const string &FName,vector<CBook> &Vect)		//从文件中读取数据到向量
{
	ifstream fin(FName);
	if(fin == NULL)
	{
		cout<<"文件打开失败！"<<endl;
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

void showData(const vector<CBook> &Vect)					//显示读取到的数据
{
	for(int i=0;i<Vect.size();i++)
	{
		cout<<Vect[i]<<endl;
	}
	cout<<endl<<endl;
}

void processData(vector<CBook> &newVect, vector<CBook> &Vect)	//对页码大于200页的书籍执行前置--
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

void outputData(vector<CBook> &newVect)				//输出myVectNew中所有价格低于10元的书籍名称，一行一个
{
	for(int i=0;i<newVect.size();i++)
	{
		if(newVect[i].getPrice() < 10)
		{
			cout<<newVect[i]<<endl;
		}
	}
}