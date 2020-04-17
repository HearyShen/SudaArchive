/******************************
	E05
	1427405017
	沈家赟
	2015-3-20 19:32
*******************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Create(vector<int> &Nums);	//声明向量创建函数Create
void Delete_Repeat(vector<int> &Nums);	//声明重复元素删除函数Delete_Repeat
void Display(const vector<int> &Nums);	//声明向量元素显示函数Display

void main()
{
	vector<int> nums;					//定义int型向量nums

	Create(nums);						//创建所需向量
	cout<<"初始向量元素依次为："<<endl;
	Display(nums);

	Delete_Repeat(nums);				//删除重复元素
	cout<<"已删除重复元素..."<<endl;

	sort(nums.begin(),nums.end());		//排序
	cout<<"已完成升序排序..."<<endl;

	cout<<"处理后的向量元素依次为："<<endl;
	Display(nums);
}

vector<int> Create(vector<int> &Nums)	//定义向量创建函数Create，返回值为向量
{
	Nums.push_back(35);					//一项一项增加，规避越界风险
	Nums.push_back(46);
	Nums.push_back(57);
	Nums.push_back(13);
	Nums.push_back(24);
	Nums.push_back(35);
	Nums.push_back(68);
	Nums.push_back(13);
	Nums.push_back(79);
	Nums.push_back(88);
	Nums.push_back(46);

	return Nums;
}

void Delete_Repeat(vector<int> &Nums)	//定义重复元素删除函数Delete_Repeat
{
	int i,j,k;

	for(i=0;i<Nums.size()-1;i++)		//外层循环对照元素
	{
		for(j=i+1;j<Nums.size();j++)	//内岑循环查找对比元素
		{
			if(Nums[i] == Nums[j])		//一旦相等重复
			{
				for(k=j;(k+1)<Nums.size();k++)
				{
					swap(Nums[k],Nums[k+1]);	//循环将重复元素放到最后一项
				}
				Nums.pop_back();		//删除最后一项
			}
		}
	}
}

void Display(const vector<int> &Nums)	//定义向量元素显示函数Display
{
	int i;

	for(i=0;i<Nums.size();i++)
	{
		cout<<" "<<Nums[i];
	}
	cout<<endl;
}