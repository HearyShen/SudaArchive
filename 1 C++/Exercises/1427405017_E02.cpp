/*************************
	E02
	1427405017
	沈家赟
	2015-3-15 7:14
*************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void main()
{
	ifstream in_txt("Data.txt");			//a)读取Data.txt中的所有数据
	int num[9];
	if(in_txt != NULL)
	{
		for(int i=0;i<9;i++)					
		{
			in_txt>>num[i];
		}
		in_txt.close();								//及时关闭文件
		cout<<"文件Data.txt已读取"<<endl;
	}
	else
	{
		cout<<"无法读取Data.txt"<<endl;
		return;
	}

	ofstream out_dat("Res.dat",ios::binary);			//b)将读取数据以二进制形式写入Res.dat
	if(out_dat != NULL)
	{
		out_dat.write((char *)num,sizeof(num));
		out_dat.close();							//及时关闭文件
		cout<<"二进制数据已写入Res.dat"<<endl;
	}
	else
	{
		cout<<"无法写入Res.dat"<<endl;
		return;
	}

	ifstream in_dat("Res.dat",ios::binary);				//c)再次读取Res.dat中的所有数据
	int num2[9];
	if(in_dat != NULL)
	{
		in_dat.read((char*)num2,sizeof(num2));
		in_dat.close();								//及时关闭文件
		cout<<"二进制文件Res.dat已读取"<<endl;
	}
	else
	{
		cout<<"无法读取Res.dat"<<endl;
		return;
	}

	ofstream out_txt("Res.txt");			//d)以文本文件形式输出到Res.txt中
	if(out_txt != NULL)
	{
		for(int i=0;i<9;i++)
		{
			out_txt.width(10);						//每个数据占10列
			out_txt.fill('C');						//左边补'C'字符
			out_txt<<num2[i];

			if((i+1)%2==0)							//两个数据即换行
			{
				out_txt<<endl;
			}
		}
		out_txt.close();							//及时关闭文件
		cout<<"文本文件Res.txt已输出"<<endl;
	}
	else
	{
		cout<<"无法读取Res.txt"<<endl;
		return;
	}
}