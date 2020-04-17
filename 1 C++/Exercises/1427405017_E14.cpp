/*******************
	E14
	1427405017
	����S
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
	CString();					//���캯��1������Ϊ���ַ���
	CString(char *src);		//���캯��2���ڿ�����src�ĳ����Ƿ�Ϸ����ʼ����ǰ����
	CString(char ch);			//���캯��3��0��Ԫ�ظ�ֵΪch
	char& operator[](int n);
	int setString(char *src);//�����ַ������ٿ�����src�ĳ����Ƿ�Ϸ������õ�ǰ����	
	friend ostream& operator<<(ostream& Out, const CString& S);		//����ַ���
};

CString::CString()		//�����Ա����CString()
{
	m_buff[0] = '\0';	//Ĭ��ʱ����Ԫ��Ϊ\0
}

CString::CString(char *src)	//���س�Ա����CString(char *src)
{
	int n_src;

	n_src = strlen(src);			//ѭ��ͳ������ԴC-���ַ���

	if(n_src+1 > MAXLENGTH)
	{
		cout<<"����Դ���ȹ��������캯������ʧ�ܣ�"<<endl;
		return;
	}
	else
	{
		strcpy(m_buff,src);
	}
}

CString::CString(char ch)		//���س�Ա����CString(char ch)
{
	m_buff[0] = ch;
	m_buff[1]='\0';
}

char& CString::operator[](int n)
{
	char &tmp = m_buff[n];

	return tmp;
}

int CString::setString(char *src)	//�����Ա����setString(char *src)
{
	int n_src,i;

	n_src=0;
	while(src[n_src] != NULL)		//ѭ��ͳ������ԴC-���ַ���
	{
		n_src++;
	}

	if(n_src > MAXLENGTH)
	{
		cout<<"src���鳤�ȹ��������캯������ʧ�ܣ�"<<endl;
		return 0;
	}
	else
	{
		for(i=0;i<n_src;i++)		//ѭ��д��
		{
			m_buff[i] = src[i];
		}
		m_buff[i]='\0';			//�ַ������β������\0
		return n_src;
	}
}

ostream& operator<<(ostream& Out, const CString& S)		//�������������<<
{
	int i;

	i=0;
	while(S.m_buff[i] != NULL)	//ѭ����ʾ�ַ�
	{
		Out<<S.m_buff[i];
		i++;
	}
	cout<<endl;			//��β���У�����

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

