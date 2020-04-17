#ifndef RECORD_H
#define RECORD_H

class Record
{
private:
	bool status;		// trueΪ�������falseΪ����ȥ��
	string license;		// ���ƺ��ַ���
	int time[6];		// ������ʱ����
public:
	Record();
	Record(bool Status, string License, int Time[]);
	string getLicense() const;
	int* getTime();
	friend void show(Record &record);
};

Record::Record()
{
	status = true;
	license = "empty";
	for(int i = 0; i<6; i++)
	{
		time[i] = 0;
	}
}

Record::Record(bool Status, string License, int Time[])
{
	status = Status;
	license = License;
	for(int i = 0; i<6; i++)
	{
		time[i] = Time[i];
	}
}

string Record::getLicense() const
{
	return license;
}
int* Record::getTime()
{
	return time;
}

void show(Record &record)
{
	if(record.status == true)
		cout<<"����";
	else
		cout<<"��ȥ";

	cout<<'\t'<<record.license;
	cout<<'\t'<<record.time[0]<<'/'<<record.time[1]<<'/'<<record.time[2]<<' '<<record.time[3]<<':'<<record.time[4]<<':'<<record.time[5]<<endl;
}
#endif