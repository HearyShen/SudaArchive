/************************
	E03
	1427405017
	����S
	2015-3-15  7:56
************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main()
{
	vector<string> mth;								//����string����
	int i,j;

	mth.push_back("January");						//��ʼ���·ݵ���
	mth.push_back("February");						//�������ӷ�Խ��
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

	cout<<"1-12��Ӣ�ĵ��ʳ�ʼ����Ϊ��"<<endl;		//��ʾ��ʼ����
	for(i=0;i<mth.size();i++)
	{
		cout<<mth[i]<<endl;
	}

	int min_inx;									//ѡ������
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
			mth[i].swap(mth[min_inx]);				//����swapʵ�ֽ���
		}
	}
	
	cout<<"1-12��Ӣ�ĵ��ʸ����ֵ�������Ϊ��"<<endl;	//��ʾ������
	for(i=0;i<mth.size();i++)
	{
		cout<<mth[i]<<endl;
	}
}