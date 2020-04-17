#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

void read_data(const string &Filename,vector<string> &A);
void print(vector<string> &A);
void print(vector<int> &A);
void trans_str_to_int(const vector<string> &A,vector<int> &B);
void find_max_min_avg(vector<int> &A,int& max,int& min,double& avg);
void select_by_num(const vector<int> &A,vector<int> &B, int sel_value=9);

int main()
{
	vector<string> vec_str_A;  
	vector<int> vec_int_A;
	vector<int> vec_sel;
	int max, min;
	double avg;
	string str;

	string filename = "D:\\data.txt";
	// ���ļ��ж�ȡ��������
	read_data(filename, vec_str_A);
	cout<<"�ļ��е��ַ���Ϊ��\n";
	print(vec_str_A);     
	// ���ַ���ת��������
	trans_str_to_int(vec_str_A,vec_int_A);
	cout<<"\n�����ַ���ת�ɵ�����Ϊ:\n";
	print(vec_int_A);	 
	// �ҳ������е����ֵ����Сֵ�Լ���������������ƽ��ֵ
	find_max_min_avg(vec_int_A, max, min, avg);
	cout<<"\n���������е����ֵ����Сֵ��ƽ��ֵΪ:\n";
	cout<<"���ֵΪ:  "<<max<<"\n";
	cout<<"��СֵΪ:  "<<min<<"\n";
	cout<<"ƽ��ֵΪ:  "<<avg<<"\n";
	// ѡ���ܱ�9����������
	select_by_num(vec_int_A, vec_sel);
	cout<<"\nѡ�������Ϊ:\n";
	print(vec_sel);

	return 0;
}

void read_data(const string &Filename,vector<string> &A)
{
	ifstream fin(Filename);
	if(fin == NULL)
	{
		cout<<"�ļ���ʧ�ܣ�"<<endl;
		exit(0);
	}

	string temp;

	while(fin.eof() == 0)
	{
		fin>>temp;
		if(fin != NULL)
		{
			A.push_back(temp);
		}
	}
	fin.close();
}

void print(vector<string> &A)
{
	int i;

	for(i=0;i<A.size();i++)
	{
		cout<<A[i]<<endl;
	}
	cout<<endl;
}

void trans_str_to_int(const vector<string> &A,vector<int> &B)
{
	int i,j,sum;

	B.clear();

	for(i=0;i<A.size();i++)
	{
		sum=0;
		for(j=0;j<A[i].size();j++)
		{
			sum = sum + (int)A[i][j];
		}
		B.push_back(sum);
	}
}

void print(vector<int> &A)
{
	int i;

	for(i=0;i<A.size();i++)
	{
		cout<<setw(8)<<A[i];
		if((i+1)%5 == 0)
		{
			cout<<endl;
		}
	}
	cout<<endl;
}

void find_max_min_avg(vector<int> &A,int& max,int& min,double& avg)
{
	int i,sum;

	max = A[0];
	min = A[0];
	sum = 0;
	for(i=0;i<A.size();i++)
	{
		if(A[i]>max)
		{
			max = A[i];
		}
		if(A[i]<min)
		{
			min = A[i];
		}
		sum = sum + A[i];
	}
	avg = (double)sum/i;
}

void select_by_num(const vector<int> &A,vector<int> &B, int sel_value)
{
	B.clear();

	int i;

	for(i=0;i<A.size();i++)
	{
		if(A[i]%sel_value == 0)
		{
			B.push_back(A[i]);
		}
	}
}