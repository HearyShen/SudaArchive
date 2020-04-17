#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

typedef struct
{
	int ID;					//工号
	string Name;			//姓名
	int WorkYears;			//工龄
	float Salary;			//工资
}WORKER;

void txt_to_vector(const string &FileName,vector<WORKER>& A);
void Sort(vector<WORKER> &Arr);
void Display(const vector<WORKER> &Arr);
void liter(const vector<WORKER> &Arr,vector<WORKER> &B,int X=10);
void Fliter(const vector<WORKER> &Arr,vector<WORKER> &C,double Y=1500.0);

void main()
{
	vector<WORKER> A,B,C;

	txt_to_vector("D:\\input.txt",A);
	Sort(A);
	cout<<"排序后："<<endl;
	Display(A);

	Fliter(A,B,5);
	cout<<"筛选后："<<endl;
	Display(B);

	Fliter(A,C,2000.0);
	cout<<"筛选后："<<endl;
	Display(C);
}

void txt_to_vector(const string &FileName,vector<WORKER>& A)
{
	ifstream in(FileName);
	if(in != NULL)
	{
		WORKER temp;

		while(in.eof() == 0)
		{
			in>>temp.ID>>temp.Name>>temp.WorkYears>>temp.Salary;
			if(in != NULL)
			{
				A.push_back(temp);
			}
		}
		in.close();
	}
	else
	{
		cout<<"无法打开该文件！"<<endl;
		exit(0);
	}
}

void Sort(vector<WORKER> &Arr)
{
	int min_inx,n;

	n = Arr.size();
	for(int i=0;i<n-1;i++)
	{
		min_inx = i;
		for(int j=i+1;j<n;j++)
		{
			if(Arr[j].Name < Arr[min_inx].Name)
			{
				min_inx = j;
			}
		}
		if(min_inx != i)
		{
			swap(Arr[i],Arr[min_inx]);
		}
	}
}

void Display(const vector<WORKER> &Arr)
{
	int n,i;

	n = Arr.size();
	for(i=0;i<n;i++)
	{
		cout<<setw(10)<<left<<Arr[i].ID;
		cout<<setw(10)<<Arr[i].Name;
		cout<<setw(5)<<Arr[i].WorkYears;
		cout<<setprecision(1)<<fixed<<Arr[i].Salary<<endl;
	}
}

void Fliter(const vector<WORKER> &Arr,vector<WORKER> &B,int X)
{
	int i;
	
	B.clear();
	for(i=0;i<Arr.size();i++)
	{
		if(Arr[i].WorkYears >= X)
		{
			B.push_back(Arr[i]);
		}
	}
}

void Fliter(const vector<WORKER> &Arr,vector<WORKER> &C,double Y)
{
	int i;

	C.clear();
	for(i=0;i<Arr.size();i++)
	{
		if(Arr[i].Salary >= Y)
		{
			C.push_back(Arr[i]);
		}
	}
}