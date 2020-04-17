/******************
	E04
	1427405017
	沈家赟
	2015-3-20 18:47
*******************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Student			//a)定义结构体类型Student
{
	int ID;				//学号
	string name;		//姓名
	float score[3];		//三门课程成绩
};

vector<Student> In_A(vector<Student> &A,const int &Num);			//声明In_A函数，返回值为输入后的向量
void Sort_ID(vector<Student> &A,const int &Num);					//声明Sort_ID函数，根据ID为向量排序
void Display(vector<Student> &A,const int &Num);					//声明Display函数，显示结构体型向量所含信息
int Delete(vector<Student> &A,string S,int &Num);					//声明Delete函数，删除指定的向量元素
int Write(vector<Student> &A,const int &Num,string FileName);		//声明输出函数Write_dat

void main()
{
	int num=5;								//学生个数，初始化为5
	vector<Student> A;

	In_A(A,num);							//b)创建向量A
	Sort_ID(A,num);							//c)将向量A按照学号ID增序排序
	Display(A,num);							//显示排序后的学生信息
	if(Delete(A,"TOM",num) != 0)			//删除指定的TOM元素
	{
		cout<<"已找到并删除向量"<<endl;
	}
	else
	{
		cout<<"未找到该向量"<<endl;
	}

	if(Write(A,num,"D:\\res.dat") != 0)	//写出到文件
	{
		cout<<"内容输出成功"<<endl;
	}
	else
	{
		cout<<"内容输出失败"<<endl;
	}
}

vector<Student> In_A(vector<Student> &A,const int &Num)		//定义向量创建函数In_A
{
	struct Student tmp;
	for(int i=0;i<Num;i++)
	{
		cout<<"学号：";
		cin>>tmp.ID;
		cout<<"姓名：";
		cin>>tmp.name;
		cout<<"三门课程成绩：";
		cin>>tmp.score[0]>>tmp.score[1]>>tmp.score[2];
		A.push_back(tmp);
	}
	return A;								//返回值为创建好的向量A
}

void Sort_ID(vector<Student> &A,const int &Num)		//定义向量排序函数Sort_ID，按ID排序
{
	int i,j,min_inx;

	for(i=0;i<Num-1;i++)					//选择法排序
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
			swap(A[i],A[min_inx]);			//使用swap函数实现数据交换
		}
	}
}

void Display(vector<Student> &A,const int &Num)		//定义向量信息显示函数
{
	int i;

	for(i=0;i<Num;i++)						//循环显示全部信息
	{
		cout<<setw(10)<<A[i].ID;
		cout<<setw(10)<<A[i].name;
		cout<<showpoint<<"	"<<setprecision(3)<<A[i].score[0]<<"	"<<setprecision(3)<<A[i].score[1]<<"	"<<setprecision(3)<<A[i].score[2]<<endl;
	}
}

int Delete(vector<Student> &A,string S,int &Num)		//定义向量元素删除函数Delete
{
	int i,j,flag;

	flag=0;
	for(i=0;i<Num;i++)
	{
		if(A[i].name == S)						//找到对应的元素
		{
			for(j=i;(j+1)<Num;j++)
			{
				swap(A[j],A[j+1]);				//将其放到最后一个
			}
			A.pop_back();						//删除最后一个向量，即找出的对应向量
			flag++;
			Num--;
		}
	}
	return flag;								//返回值为找到的对应向量元素的个数
}

int Write(vector<Student> &A,const int &Num,string FileName)	//定义文件输出函数Write_dat
{
	int i;

	ofstream out(FileName);					//创建输出流
	if(out != NULL)							//判断输出流创建正常
	{
		for(i=0;i<Num;i++)					//循环输出
		{
			out<<setw(10)<<A[i].ID;
			out<<setw(10)<<A[i].name;
			out<<showpoint<<"	"<<setprecision(3)<<A[i].score[0]<<"	"<<setprecision(3)<<A[i].score[1]<<"	"<<setprecision(3)<<A[i].score[2]<<endl;
		}
		out.close();						//及时关闭文件
		return 1;							//返回值1表示成功
	}
	else
	{
		return 0;							//一旦失败，返回值0
	}
}