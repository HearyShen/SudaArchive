/*******************
	E15
	1427405017
	沈家赟
	2015-5-10  10:33
*******************/
#include <iostream>

using namespace std;

class CString
{
private:
	char * m_pbuff;			//指向字符串的指针
	int m_length;			//表示当前字符串的最大允许长度，也就是字符数组的长度
public:
	CString();				//构造函数1，设置为空字符串，m_length=100
	CString(char *src);		//构造函数2，在考虑了src的长度后初始化当前对象，m_length>=src的长度+1
	CString(char ch);		//构造函数3，0号元素赋值为ch, m_length=100
	CString(const CString &A);	//拷贝构造函数
	~CString();				//涉及函数实体，构建析构函数
	char& operator[](int n);
	int setString(char *src);	//设置字符串，在考虑了src的长度后设置当前对象,m_length>=src的长度+1
	friend ostream& operator<<(ostream& Out, const CString& S);	 //输出字符串
};

CString::CString()
{
	m_length = 100;
	m_pbuff = new char[m_length];
	m_pbuff[0] = '\0';
}

CString::CString(char *src)
{
	int n_src;

	n_src=strlen(src);
	m_length = n_src+1;		//给\0预留一个字节
	m_pbuff = new char[m_length];
	strcpy(m_pbuff,src);
}

CString::CString(char ch)		//重载成员函数CString(char ch)
{
	m_length = 100;
	m_pbuff = new char[m_length];
	m_pbuff[0] = ch;
	m_pbuff[1]='\0';
}

CString::CString(const CString &A)		//重载拷贝构造函数
{
	m_pbuff = new char[A.m_length];		//创建新实体
	if(A.m_pbuff != NULL)
	{
		strcpy(m_pbuff,A.m_pbuff);		//拷贝构造新实体
	}
}

CString::~CString()
{
	//cout<<"ok"<<endl;
	delete[] m_pbuff;
}

char& CString::operator[](int n)
{
	char &tmp = m_pbuff[n];

	return tmp;
}

int CString::setString(char *src)
{
	int n_src,i;

	n_src=0;
	while(src[n_src] != NULL)		//循环统计数据源C-串字符数
	{
		n_src++;
	}

	m_length = n_src+1;		//给\0预留一个字节
	m_pbuff = new char[m_length];
	for(i=0;i<n_src;i++)	//循环写入
	{
		m_pbuff[i] = src[i];
	}
	m_pbuff[i]='\0';			//字符数组结尾处补上\0

	return n_src;
}

ostream& operator<<(ostream& Out, const CString& S)		//定义操作符重载<<
{
	int i;

	i=0;
	while(S.m_pbuff[i] != NULL)	//循环显示字符
	{
		Out<<S.m_pbuff[i];
		i++;
	}
	cout<<endl;			//结尾换行，美观

	return Out;
}

void main()
{
	CString s1;
	cout<<s1;
	s1.setString("abc1");
	cout<<s1;

	CString s2("abc2");
	cout<<s2;

	CString s3('a');
	cout<<s3;

	CString s4(s2);
	cout<<s4;
}