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
		case out : cout<<"ͣ����Ϊ��"<<parking_fee();break;
		case display : show_all(parking_lot);break;
		}*/
	}
}

void introduction()
{
	cout<<"ͣ��������"<<endl
		<<"��ͣ������10����λ��Ϊջ�ṹ��ͣ�����������ͣ������ͣ������ʱʹ�ã�Ϊ���нṹ"<<endl<<endl;
}

void instruction()
{
	cout<<"�������룺������Ϣin/out ���ƺ��� ʱ��"<<endl
		<<"�磺in ��E12345 2015 1 1 9 10 00  ��ʾ ����һ������Ϊ����E12345���ĳ� ʱ��Ϊ2015��1��1��9ʱ10��0��"<<endl
		<<"����display����ʾͣ����ͣ����Ϣ"<<endl<<endl;
}

Signal input(Stack<Record> &parking_lot, Queue<Record> &temp)
{
	string status;
	bool t_status;
	string t_license;
	int t_time[6];

	cin>>status;				//һ����ȡ״̬

	if(status == "in")					//���in��
	{
		t_status = true;
	}
	else if(status == "out")			//��ȥ��out��
	{
		t_status = false;
	}
	else if(status == "display")		//��ʾ��display��������ͣ������ջ��������ʾ����show_all
	{
		show_all(parking_lot);
		return display;
	}
	else								//�������룺��ʾ
	{
		cout<<"�������"<<endl;
		return error;
	}
	cin>>t_license;				//������ȡ����

	for(int i=0;i<6;i++)		//������ȡʱ��
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
		
		while( parking_lot.empty() != true)				//��������ͣ������ջ����Ԫ��
		{
			parking_lot.top(old_record);
			parking_lot.pop();
			
			if(old_record.getLicense() == t_license)		//�ҵ��뿪�������Ƴ�ջ������ʱ�Ʒ�
			{
				double parking_fee;
				parking_fee = getParkingFee(old_record, record, 5.0);

				cout<<"ͣ���ѣ�"<<parking_fee<<"Ԫ"<<endl;
				flag_find = true;
				break;
			}
			else		//�����¼����������ʱջ
			{
				t_recordStack.push(old_record);
			}
		}
		while( t_recordStack.empty() != true)		//������ɺ󣬰�ͣ����ջ��ԭ
		{
			t_recordStack.top(old_record);
			t_recordStack.pop();
			parking_lot.push(old_record);
		}
		if(flag_find == false)					//�Ҳ�������ʱ�����Ѻ���ʾ
			cout<<"δ�ҵ��˳��������鳵����Ϣ�Ƿ���ȷ��"<<endl;
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
	time_length_h = (double)stay_time[5]/3600		//��->ʱ
		+ (double)stay_time[4]/60					//��->ʱ
		+ stay_time[3]						//ʱ
		+ stay_time[2]*24					//��->ʱ
		+ stay_time[1]*30*24				//��->ʱ
		+ stay_time[0]*12*30*24;			//��->ʱ
	parking_fee = time_length_h * fee_per_hour;		//�ó��ܷ���

	return parking_fee;
}

void show_all(Stack<Record> &parking_lot)
{
	parking_lot.traverse(show);
}