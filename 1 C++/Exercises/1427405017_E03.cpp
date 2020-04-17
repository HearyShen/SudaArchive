/************************
	E03
	1427405017
	沈家赟
	2015-3-15  7:56
************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main()
{
	vector<string> mth;								//定义string向量
	int i,j;

	mth.push_back("January");						//初始化月份单词
	mth.push_back("February");						//逐项增加防越界
	mth.push_back("March");
	mth.push_back("April");
	mth.push_back("May");
	mth.push_back("June");
	mth.push_back("July");
	mth.push_back("August");
	mth.push_back("September");
	mth.push_back("October");
	mth.push_back("November");
	mth.push_back("December");

	cout<<"1-12月英文单词初始排序为："<<endl;		//显示初始排序
	for(i=0;i<mth.size();i++)
	{
		cout<<mth[i]<<endl;
	}

	int min_inx;									//选择法排序
	string tmp;
	for(i=0;i<mth.size()-1;i++)
	{
		min_inx=i;
		for(j=i+1;j<mth.size();j++)
		{
			if(mth[j]<mth[min_inx])
			{
				min_inx=j;
			}
		}
		if(i != min_inx)
		{
			mth[i].swap(mth[min_inx]);				//利用swap实现交换
		}
	}
	
	cout<<"1-12月英文单词根据字典序排序为："<<endl;	//显示排序结果
	for(i=0;i<mth.size();i++)
	{
		cout<<mth[i]<<endl;
	}
}