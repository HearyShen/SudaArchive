/*******************
	E14
	1427405017
	沈家赟
	2015-5-9  16:40
*******************/
#include <iostream>
#include <string>
#include <sstream>

#define MAXLENGTH 1000

using namespace std;

class CString
{
private:
	char m_buff[MAXLENGTH];
public:
	CString();					//构造函数1，设置为空字符串
	CString(char *src);		//构造函数2，在考虑了src的长度是否合法后初始化当前对象
	CString(char ch);			//构造函数3，0号元素赋值为ch
	char& operator[](int n);
	int setString(char *src);//设置字符串，再考虑了src的长度是否合法后设置当前对象	
	friend ostream& operator<<(ostream& Out, const CString& S);		//输出字符串
};

CString::CString()		//定义成员函数CString()
{
	m_buff[0] = '\0';	//默认时，首元素为\0
}

CString::CString(char *src)	//重载成员函数CString(char *src)
{
	int n_src;

	n_src = strlen(src);			//循环统计数据源C-串字符数

	if(n_src+1 > MAXLENGTH)
	{
		cout<<"内容源长度过长，构造函数构造失败！"<<endl;
		return;
	}
	else
	{
		strcpy(m_buff,src);
	}
}

CString::CString(char ch)		//重载成员函数CString(char ch)
{
	m_buff[0] = ch;
	m_buff[1]='\0';
}

char& CString::operator[](int n)
{
	char &tmp = m_buff[n];

	return tmp;
}

int CString::setString(char *src)	//定义成员函数setString(char *src)
{
	int n_src,i;

	n_src=0;
	while(src[n_src] != NULL)		//循环统计数据源C-串字符数
	{
		n_src++;
	}

	if(n_src > MAXLENGTH)
	{
		cout<<"src数组长度过长，构造函数构造失败！"<<endl;
		return 0;
	}
	else
	{
		for(i=0;i<n_src;i++)		//循环写入
		{
			m_buff[i] = src[i];
		}
		m_buff[i]='\0';			//字符数组结尾处补上\0
		return n_src;
	}
}

ostream& operator<<(ostream& Out, const CString& S)		//定义操作符重载<<
{
	int i;

	i=0;
	while(S.m_buff[i] != NULL)	//循环显示字符
	{
		Out<<S.m_buff[i];
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

