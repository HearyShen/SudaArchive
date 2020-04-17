/******************
	E04
	1427405017
	����S
	2015-3-20 18:47
*******************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Student			//a)����ṹ������Student
{
	int ID;				//ѧ��
	string name;		//����
	float score[3];		//���ſγ̳ɼ�
};

vector<Student> In_A(vector<Student> &A,const int &Num);			//����In_A����������ֵΪ����������
void Sort_ID(vector<Student> &A,const int &Num);					//����Sort_ID����������IDΪ��������
void Display(vector<Student> &A,const int &Num);					//����Display��������ʾ�ṹ��������������Ϣ
int Delete(vector<Student> &A,string S,int &Num);					//����Delete������ɾ��ָ��������Ԫ��
int Write(vector<Student> &A,const int &Num,string FileName);		//�����������Write_dat

void main()
{
	int num=5;								//ѧ����������ʼ��Ϊ5
	vector<Student> A;

	In_A(A,num);							//b)��������A
	Sort_ID(A,num);							//c)������A����ѧ��ID��������
	Display(A,num);							//��ʾ������ѧ����Ϣ
	if(Delete(A,"TOM",num) != 0)			//ɾ��ָ����TOMԪ��
	{
		cout<<"���ҵ���ɾ������"<<endl;
	}
	else
	{
		cout<<"δ�ҵ�������"<<endl;
	}

	if(Write(A,num,"D:\\res.dat") != 0)	//д�����ļ�
	{
		cout<<"��������ɹ�"<<endl;
	}
	else
	{
		cout<<"�������ʧ��"<<endl;
	}
}

vector<Student> In_A(vector<Student> &A,const int &Num)		//����������������In_A
{
	struct Student tmp;
	for(int i=0;i<Num;i++)
	{
		cout<<"ѧ�ţ�";
		cin>>tmp.ID;
		cout<<"������";
		cin>>tmp.name;
		cout<<"���ſγ̳ɼ���";
		cin>>tmp.score[0]>>tmp.score[1]>>tmp.score[2];
		A.push_back(tmp);
	}
	return A;								//����ֵΪ�����õ�����A
}

void Sort_ID(vector<Student> &A,const int &Num)		//��������������Sort_ID����ID����
{
	int i,j,min_inx;

	for(i=0;i<Num-1;i++)					//ѡ������
	{
		min_inx=i;
		for(j=i+1;j<Num;j++)
		{
			if(A[j].ID < A[min_inx].ID)
			{
				min_inx=j;
			}
		}
		if(min_inx != i)
		{
			swap(A[i],A[min_inx]);			//ʹ��swap����ʵ�����ݽ���
		}
	}
}

void Display(vector<Student> &A,const int &Num)		//����������Ϣ��ʾ����
{
	int i;

	for(i=0;i<Num;i++)						//ѭ����ʾȫ����Ϣ
	{
		cout<<setw(10)<<A[i].ID;
		cout<<setw(10)<<A[i].name;
		cout<<showpoint<<"	"<<setprecision(3)<<A[i].score[0]<<"	"<<setprecision(3)<<A[i].score[1]<<"	"<<setprecision(3)<<A[i].score[2]<<endl;
	}
}

int Delete(vector<Student> &A,string S,int &Num)		//��������Ԫ��ɾ������Delete
{
	int i,j,flag;

	flag=0;
	for(i=0;i<Num;i++)
	{
		if(A[i].name == S)						//�ҵ���Ӧ��Ԫ��
		{
			for(j=i;(j+1)<Num;j++)
			{
				swap(A[j],A[j+1]);				//����ŵ����һ��
			}
			A.pop_back();						//ɾ�����һ�����������ҳ��Ķ�Ӧ����
			flag++;
			Num--;
		}
	}
	return flag;								//����ֵΪ�ҵ��Ķ�Ӧ����Ԫ�صĸ���
}

int Write(vector<Student> &A,const int &Num,string FileName)	//�����ļ��������Write_dat
{
	int i;

	ofstream out(FileName);					//���������
	if(out != NULL)							//�ж��������������
	{
		for(i=0;i<Num;i++)					//ѭ�����
		{
			out<<setw(10)<<A[i].ID;
			out<<setw(10)<<A[i].name;
			out<<showpoint<<"	"<<setprecision(3)<<A[i].score[0]<<"	"<<setprecision(3)<<A[i].score[1]<<"	"<<setprecision(3)<<A[i].score[2]<<endl;
		}
		out.close();						//��ʱ�ر��ļ�
		return 1;							//����ֵ1��ʾ�ɹ�
	}
	else
	{
		return 0;							//һ��ʧ�ܣ�����ֵ0
	}
}