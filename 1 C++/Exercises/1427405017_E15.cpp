/*******************
	E15
	1427405017
	����S
	2015-5-10  10:33
*******************/
#include <iostream>

using namespace std;

class CString
{
private:
	char * m_pbuff;			//ָ���ַ�����ָ��
	int m_length;			//��ʾ��ǰ�ַ�������������ȣ�Ҳ�����ַ�����ĳ���
public:
	CString();				//���캯��1������Ϊ���ַ�����m_length=100
	CString(char *src);		//���캯��2���ڿ�����src�ĳ��Ⱥ��ʼ����ǰ����m_length>=src�ĳ���+1
	CString(char ch);		//���캯��3��0��Ԫ�ظ�ֵΪch, m_length=100
	CString(const CString &A);	//�������캯��
	~CString();				//�漰����ʵ�壬������������
	char& operator[](int n);
	int setString(char *src);	//�����ַ������ڿ�����src�ĳ��Ⱥ����õ�ǰ����,m_length>=src�ĳ���+1
	friend ostream& operator<<(ostream& Out, const CString& S);	 //����ַ���
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
	m_length = n_src+1;		//��\0Ԥ��һ���ֽ�
	m_pbuff = new char[m_length];
	strcpy(m_pbuff,src);
}

CString::CString(char ch)		//���س�Ա����CString(char ch)
{
	m_length = 100;
	m_pbuff = new char[m_length];
	m_pbuff[0] = ch;
	m_pbuff[1]='\0';
}

CString::CString(const CString &A)		//���ؿ������캯��
{
	m_pbuff = new char[A.m_length];		//������ʵ��
	if(A.m_pbuff != NULL)
	{
		strcpy(m_pbuff,A.m_pbuff);		//����������ʵ��
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
	while(src[n_src] != NULL)		//ѭ��ͳ������ԴC-���ַ���
	{
		n_src++;
	}

	m_length = n_src+1;		//��\0Ԥ��һ���ֽ�
	m_pbuff = new char[m_length];
	for(i=0;i<n_src;i++)	//ѭ��д��
	{
		m_pbuff[i] = src[i];
	}
	m_pbuff[i]='\0';			//�ַ������β������\0

	return n_src;
}

ostream& operator<<(ostream& Out, const CString& S)		//�������������<<
{
	int i;

	i=0;
	while(S.m_pbuff[i] != NULL)	//ѭ����ʾ�ַ�
	{
		Out<<S.m_pbuff[i];
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