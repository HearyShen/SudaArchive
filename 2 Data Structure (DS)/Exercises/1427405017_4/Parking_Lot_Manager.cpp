#include <iostream>
#include <sstream>
#include "utility.h"
#include "contiguous_stack.h"
#include "linked_queue.h"
#include "Record.h"

using namespace std;

enum Signal{in,out,display,error};

void introduction();
void instruction();
Signal input(Stack<Record> &parking_lot, Queue<Record> &temp);
double getParkingFee(Record &in_record, Record &out_record, double fee_per_hour);
void show_all(Stack<Record> &parking_lot);

void main()
{
	Stack<Record> parking_lot;
	Queue<Record> temp;
	Signal signal;

	introduction();
	instruction();

	while(1)
	{
		signal = input(parking_lot, temp);
		/*switch(signal)
		{
		case in : break;
		case out : cout<<"停车费为："<<parking_fee();break;
		case display : show_all(parking_lot);break;
		}*/
	}
}

void introduction()
{
	cout<<"停车场管理"<<endl
		<<"该停车场有10个车位，为栈结构；停车场外便道亦可停车，供停车场满时使用，为队列结构"<<endl<<endl;
}

void instruction()
{
	cout<<"依次输入：进出信息in/out 车牌号码 时间"<<endl
		<<"如：in 苏E12345 2015 1 1 9 10 00  表示 到达一辆牌照为“苏E12345”的车 时间为2015年1月1日9时10分0秒"<<endl
		<<"输入display可显示停车场停车信息"<<endl<<endl;
}

Signal input(Stack<Record> &parking_lot, Queue<Record> &temp)
{
	string status;
	bool t_status;
	string t_license;
	int t_time[6];

	cin>>status;				//一、读取状态

	if(status == "in")					//到达（in）
	{
		t_status = true;
	}
	else if(status == "out")			//离去（out）
	{
		t_status = false;
	}
	else if(status == "display")		//显示（display）：调用停车场（栈）遍历显示函数show_all
	{
		show_all(parking_lot);
		return display;
	}
	else								//错误输入：提示
	{
		cout<<"输入错误！"<<endl;
		return error;
	}
	cin>>t_license;				//二、读取车牌

	for(int i=0;i<6;i++)		//三、读取时间
	{
		cin>>t_time[i];
	}
	Record record(t_status,t_license,t_time);

	if(t_status == true)				//in
	{
		if(parking_lot.push(record) == overflow)
			temp.append(record);
		return in;
	}

	if(t_status == false)				//out
	{
		Stack<Record> t_recordStack;
		Record old_record;
		bool flag_find = false;
		
		while( parking_lot.empty() != true)				//遍历查找停车场（栈）中元素
		{
			parking_lot.top(old_record);
			parking_lot.pop();
			
			if(old_record.getLicense() == t_license)		//找到离开车辆，移出栈，并按时计费
			{
				double parking_fee;
				parking_fee = getParkingFee(old_record, record, 5.0);

				cout<<"停车费："<<parking_fee<<"元"<<endl;
				flag_find = true;
				break;
			}
			else		//其余记录正常进入临时栈
			{
				t_recordStack.push(old_record);
			}
		}
		while( t_recordStack.empty() != true)		//查找完成后，把停车场栈还原
		{
			t_recordStack.top(old_record);
			t_recordStack.pop();
			parking_lot.push(old_record);
		}
		if(flag_find == false)					//找不到车辆时给以友好提示
			cout<<"未找到此车辆，请检查车牌信息是否正确！"<<endl;
		return out;
	}
}

double getParkingFee(Record &in_record, Record &out_record, double fee_per_hour)
{
	int stay_time[6];
	double time_length_h = 0;
	double parking_fee;

	for(int i=0;i<6;i++)
	{
		stay_time[i] = out_record.getTime()[i] - in_record.getTime()[i];
	}
	time_length_h = (double)stay_time[5]/3600		//秒->时
		+ (double)stay_time[4]/60					//分->时
		+ stay_time[3]						//时
		+ stay_time[2]*24					//日->时
		+ stay_time[1]*30*24				//月->时
		+ stay_time[0]*12*30*24;			//年->时
	parking_fee = time_length_h * fee_per_hour;		//得出总费用

	return parking_fee;
}

void show_all(Stack<Record> &parking_lot)
{
	parking_lot.traverse(show);
}