#include "circular_queue.h"
//#include "linked_queue.h"
#include <iostream>

using namespace std;

enum Compare_result{N, L, R, D, S, E};
/*********************************************************
	N : 行中没有冒号（no）
	L : 左边部分比右边部分长（left）
	R : 右边部分比左边部分长（right）
	D : 左边部分和右边部分不同但有相同的长度（different）
	S : 左边部分和右边部分完全相同（same）
	E : 错误（error）
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
		if( string_in(in) == true)		//顺利读入，则比较
		{
			result = compare(in);			//进行比较，并返回结果代码
			show_result(result);			//显示结果
		}
		else							//读入失败，则报错
			cout<<"错误：未检测到有效输入！"<<endl;
	}
}

void introduction()
{
	cout<<"输入一行字符，输入由两部分组成，之间用冒号分开。"<<endl
		<<"程序会输出两部分的比较结果"<<endl<<endl;
}

bool string_in(Queue &item)
{
	char t;
	bool End_at_FirstTime=true;		//默认第一次读到'\n'而读不到有效数据

	while(1)
	{
		cin.get(t);
		if(t == '\n')		//读到回车符就结束读取
			break;
		if(item.append(t) == overflow)		//未结束，则将读取的字符加入队列
		{
			cout<<"失败：队列内存不足！"<<endl;		//队列溢出，则报错并返回false
			return false;
		}
		End_at_FirstTime = false;	//第一次成功读取，未停下
	}
	if(End_at_FirstTime == true)	//若第一次读不到有效数据，则返回false
		return false;
	return true;			//读取成功，返回true
}

Compare_result compare(Queue &item)
{
	bool flag=false;
	char t;
	int l_count,r_count;
	Queue right,left;

	l_count = 0;
	while(item.retrieve(t) == success)		//第一个循环，读取冒号左边数据
	{
		if(t == ':')
		{
			item.serve();		//队头冒号出队
			flag = true;
			break;
		}
		else
		{
			if( left.append(t) == success)	//顺利读入左临时队列，则原始队列队头出队
			{
				item.serve();
				l_count++;
			}
			else
			{
				cout<<"失败：队列内存不足！"<<endl;
				return E;
			}
		}
	}
	r_count = 0;
	while(item.retrieve(t) == success)		//第二个循环，读取冒号右边数据
	{
		if( right.append(t) == success)	//顺利读入右临时队列，则原始队列队头出队
		{
			item.serve();
			r_count++;
		}
		else
		{
			cout<<"失败：队列内存不足！"<<endl;
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
	case N : cout<<"N : 行中没有冒号（no）"<<endl;break;
	case L : cout<<"L : 左边部分比右边部分长（left）"<<endl;break;
	case R : cout<<"R : 右边部分比左边部分长（right）"<<endl;break;
	case D : cout<<"D : 左边部分和右边部分不同但有相同的长度（different）"<<endl;break;
	case S : cout<<"S : 左边部分和右边部分完全相同（same）"<<endl;break;
	case E : cout<<"E : 错误（error）"<<endl;break;
	}
}