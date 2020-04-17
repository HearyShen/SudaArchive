/********************************
	E01
	1427405017
	沈家赟
	2015-3-11  11:19
*********************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Charactor			//定义结构体类型Charactor用于26个英文字母及其频数
{
	char ch;
	int num;
};

void main()
{
	string s;							//定义待输入字符串s
	struct Charactor charactor[26];		//定义结构体数组charactor
	int i,j;

	cout<<"请输入一个不包含空格的仅由英文字母组成的字符串，长度不超过200个字符。"<<endl;
	getline(cin,s);						//输入字符串s

	transform(s.begin(),s.end(),s.begin(),tolower);	//字符串元素中大写字母转小写

	for(i=0,j='a';i<26;i++,j++)			//结构体数组初始化
	{
		charactor[i].ch=j;
		charactor[i].num=0;
	}
	
	for(i=0;i<s.size();i++)				//统计各字母频数
	{
		for(j=0;j<26;j++)
		{
			if(s[i] == charactor[j].ch)
			{
				charactor[j].num++;
				break;
			}
		}
	}

	int max_inx;
	struct Charactor temp;
	for(i=0;i<s.size()-1;i++)			//选择法排序
	{
		max_inx=i;
		for(j=i+1;j<s.size();j++)
		{
			if(charactor[j].num>charactor[max_inx].num)
			{
				max_inx=j;
			}
		}
		if(max_inx != i)
		{
			swap(charactor[max_inx],charactor[i]);
		}
	}

	for(i=0;i<26;i++)					//输出排序后的英文字母
	{
		if(charactor[i].num > 0)
		{
			cout<<charactor[i].ch<<"	个数："<<charactor[i].num<<endl;
		}
	}
	cout<<endl;							//结尾换行
}