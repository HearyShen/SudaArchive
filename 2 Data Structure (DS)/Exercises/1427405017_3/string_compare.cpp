#include "circular_queue.h"
//#include "linked_queue.h"
#include <iostream>

using namespace std;

enum Compare_result{N, L, R, D, S, E};
/*********************************************************
	N : ����û��ð�ţ�no��
	L : ��߲��ֱ��ұ߲��ֳ���left��
	R : �ұ߲��ֱ���߲��ֳ���right��
	D : ��߲��ֺ��ұ߲��ֲ�ͬ������ͬ�ĳ��ȣ�different��
	S : ��߲��ֺ��ұ߲�����ȫ��ͬ��same��
	E : ����error��
***********************************************************/

void introduction();
bool string_in(Queue &item);
Compare_result compare(Queue &item);
void show_result(const Compare_result result);

void main()
{
	Queue in;
	Compare_result result;

	introduction();

	while(1)
	{
		if( string_in(in) == true)		//˳�����룬��Ƚ�
		{
			result = compare(in);			//���бȽϣ������ؽ������
			show_result(result);			//��ʾ���
		}
		else							//����ʧ�ܣ��򱨴�
			cout<<"����δ��⵽��Ч���룡"<<endl;
	}
}

void introduction()
{
	cout<<"����һ���ַ�����������������ɣ�֮����ð�ŷֿ���"<<endl
		<<"�������������ֵıȽϽ��"<<endl<<endl;
}

bool string_in(Queue &item)
{
	char t;
	bool End_at_FirstTime=true;		//Ĭ�ϵ�һ�ζ���'\n'����������Ч����

	while(1)
	{
		cin.get(t);
		if(t == '\n')		//�����س����ͽ�����ȡ
			break;
		if(item.append(t) == overflow)		//δ�������򽫶�ȡ���ַ��������
		{
			cout<<"ʧ�ܣ������ڴ治�㣡"<<endl;		//����������򱨴�����false
			return false;
		}
		End_at_FirstTime = false;	//��һ�γɹ���ȡ��δͣ��
	}
	if(End_at_FirstTime == true)	//����һ�ζ�������Ч���ݣ��򷵻�false
		return false;
	return true;			//��ȡ�ɹ�������true
}

Compare_result compare(Queue &item)
{
	bool flag=false;
	char t;
	int l_count,r_count;
	Queue right,left;

	l_count = 0;
	while(item.retrieve(t) == success)		//��һ��ѭ������ȡð���������
	{
		if(t == ':')
		{
			item.serve();		//��ͷð�ų���
			flag = true;
			break;
		}
		else
		{
			if( left.append(t) == success)	//˳����������ʱ���У���ԭʼ���ж�ͷ����
			{
				item.serve();
				l_count++;
			}
			else
			{
				cout<<"ʧ�ܣ������ڴ治�㣡"<<endl;
				return E;
			}
		}
	}
	r_count = 0;
	while(item.retrieve(t) == success)		//�ڶ���ѭ������ȡð���ұ�����
	{
		if( right.append(t) == success)	//˳����������ʱ���У���ԭʼ���ж�ͷ����
		{
			item.serve();
			r_count++;
		}
		else
		{
			cout<<"ʧ�ܣ������ڴ治�㣡"<<endl;
			return E;
		}
	}

	if(flag == false)
		return N;
	if(l_count > r_count)
		return L;
	if(l_count < r_count)
		return R;
	if(l_count == r_count)
	{
		char t_l,t_r;

		for(int i=0;i<l_count;i++)
		{
			left.retrieve(t_l);
			left.serve();
			right.retrieve(t_r);
			right.serve();

			if(t_l != t_r)
				return D;
		}
		return S;
	}
}

void show_result(const Compare_result result)
{
	switch(result)
	{
	case N : cout<<"N : ����û��ð�ţ�no��"<<endl;break;
	case L : cout<<"L : ��߲��ֱ��ұ߲��ֳ���left��"<<endl;break;
	case R : cout<<"R : �ұ߲��ֱ���߲��ֳ���right��"<<endl;break;
	case D : cout<<"D : ��߲��ֺ��ұ߲��ֲ�ͬ������ͬ�ĳ��ȣ�different��"<<endl;break;
	case S : cout<<"S : ��߲��ֺ��ұ߲�����ȫ��ͬ��same��"<<endl;break;
	case E : cout<<"E : ����error��"<<endl;break;
	}
}