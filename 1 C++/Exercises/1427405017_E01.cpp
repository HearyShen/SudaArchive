/********************************
	E01
	1427405017
	����S
	2015-3-11  11:19
*********************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Charactor			//����ṹ������Charactor����26��Ӣ����ĸ����Ƶ��
{
	char ch;
	int num;
};

void main()
{
	string s;							//����������ַ���s
	struct Charactor charactor[26];		//����ṹ������charactor
	int i,j;

	cout<<"������һ���������ո�Ľ���Ӣ����ĸ��ɵ��ַ��������Ȳ�����200���ַ���"<<endl;
	getline(cin,s);						//�����ַ���s

	transform(s.begin(),s.end(),s.begin(),tolower);	//�ַ���Ԫ���д�д��ĸתСд

	for(i=0,j='a';i<26;i++,j++)			//�ṹ�������ʼ��
	{
		charactor[i].ch=j;
		charactor[i].num=0;
	}
	
	for(i=0;i<s.size();i++)				//ͳ�Ƹ���ĸƵ��
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
	for(i=0;i<s.size()-1;i++)			//ѡ������
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

	for(i=0;i<26;i++)					//���������Ӣ����ĸ
	{
		if(charactor[i].num > 0)
		{
			cout<<charactor[i].ch<<"	������"<<charactor[i].num<<endl;
		}
	}
	cout<<endl;							//��β����
}