/*************************
	E02
	1427405017
	����S
	2015-3-15 7:14
*************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void main()
{
	ifstream in_txt("Data.txt");			//a)��ȡData.txt�е���������
	int num[9];
	if(in_txt != NULL)
	{
		for(int i=0;i<9;i++)					
		{
			in_txt>>num[i];
		}
		in_txt.close();								//��ʱ�ر��ļ�
		cout<<"�ļ�Data.txt�Ѷ�ȡ"<<endl;
	}
	else
	{
		cout<<"�޷���ȡData.txt"<<endl;
		return;
	}

	ofstream out_dat("Res.dat",ios::binary);			//b)����ȡ�����Զ�������ʽд��Res.dat
	if(out_dat != NULL)
	{
		out_dat.write((char *)num,sizeof(num));
		out_dat.close();							//��ʱ�ر��ļ�
		cout<<"������������д��Res.dat"<<endl;
	}
	else
	{
		cout<<"�޷�д��Res.dat"<<endl;
		return;
	}

	ifstream in_dat("Res.dat",ios::binary);				//c)�ٴζ�ȡRes.dat�е���������
	int num2[9];
	if(in_dat != NULL)
	{
		in_dat.read((char*)num2,sizeof(num2));
		in_dat.close();								//��ʱ�ر��ļ�
		cout<<"�������ļ�Res.dat�Ѷ�ȡ"<<endl;
	}
	else
	{
		cout<<"�޷���ȡRes.dat"<<endl;
		return;
	}

	ofstream out_txt("Res.txt");			//d)���ı��ļ���ʽ�����Res.txt��
	if(out_txt != NULL)
	{
		for(int i=0;i<9;i++)
		{
			out_txt.width(10);						//ÿ������ռ10��
			out_txt.fill('C');						//��߲�'C'�ַ�
			out_txt<<num2[i];

			if((i+1)%2==0)							//�������ݼ�����
			{
				out_txt<<endl;
			}
		}
		out_txt.close();							//��ʱ�ر��ļ�
		cout<<"�ı��ļ�Res.txt�����"<<endl;
	}
	else
	{
		cout<<"�޷���ȡRes.txt"<<endl;
		return;
	}
}