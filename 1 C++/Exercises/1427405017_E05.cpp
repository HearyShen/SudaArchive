/******************************
	E05
	1427405017
	����S
	2015-3-20 19:32
*******************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Create(vector<int> &Nums);	//����������������Create
void Delete_Repeat(vector<int> &Nums);	//�����ظ�Ԫ��ɾ������Delete_Repeat
void Display(const vector<int> &Nums);	//��������Ԫ����ʾ����Display

void main()
{
	vector<int> nums;					//����int������nums

	Create(nums);						//������������
	cout<<"��ʼ����Ԫ������Ϊ��"<<endl;
	Display(nums);

	Delete_Repeat(nums);				//ɾ���ظ�Ԫ��
	cout<<"��ɾ���ظ�Ԫ��..."<<endl;

	sort(nums.begin(),nums.end());		//����
	cout<<"�������������..."<<endl;

	cout<<"����������Ԫ������Ϊ��"<<endl;
	Display(nums);
}

vector<int> Create(vector<int> &Nums)	//����������������Create������ֵΪ����
{
	Nums.push_back(35);					//һ��һ�����ӣ����Խ�����
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

void Delete_Repeat(vector<int> &Nums)	//�����ظ�Ԫ��ɾ������Delete_Repeat
{
	int i,j,k;

	for(i=0;i<Nums.size()-1;i++)		//���ѭ������Ԫ��
	{
		for(j=i+1;j<Nums.size();j++)	//���ѭ�����ҶԱ�Ԫ��
		{
			if(Nums[i] == Nums[j])		//һ������ظ�
			{
				for(k=j;(k+1)<Nums.size();k++)
				{
					swap(Nums[k],Nums[k+1]);	//ѭ�����ظ�Ԫ�طŵ����һ��
				}
				Nums.pop_back();		//ɾ�����һ��
			}
		}
	}
}

void Display(const vector<int> &Nums)	//��������Ԫ����ʾ����Display
{
	int i;

	for(i=0;i<Nums.size();i++)
	{
		cout<<" "<<Nums[i];
	}
	cout<<endl;
}