/*********************
	ex25
	1427405017
	����S
	2016/3/17 19:52
*********************/
/********************************************************
2.8   ���д����ex25ʵ�����¹��ܣ�
	ͳ��ĳ���ַ��ͣ��ֽڡ�8λ��������10������֮�ۼӺ͡�
	������Ϊ����Ԫ���е��������޷�������Ҳ�������з�������
	��ֱ��޷��������з��������Σ�
	�������ǵ��ۼӺͣ�������16λ��ʾ��������ʾ�����

	˵���������ڶ�������ʱ��ʼ������10�����ݣ�
		Ҳ����ͨ�������������������������

*********************************************************/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char arr[10];
	unsigned int unsigned_sum = 0;
	signed int signed_sum = 0;

	for(int i=0;i<10;i++)
	{
		arr[i] = rand()%256;
		printf("%d 0x%02x \n",arr[i],arr[i]);
	}
	printf("\n");

	_asm
	{
		LEA ESI, arr;
		MOV ECX, 10;	//��ѭ��������
		MOV EAX, 0;		//index
		LEA EDI, unsigned_sum;
		MOV [EDI], 0;
MAIN_LOOP1:
		MOV EBX, 0;
		MOV BL, [ESI+EAX*1];
		ADD [EDI], EBX;
		INC EAX;		//index++
		DEC ECX;		//��ѭ��������--
		JNZ MAIN_LOOP1;
		JZ OVER1;
OVER1:

	}
	printf("���޷���������ʱ���ۼӺ�Ϊ��0x%X %d\n",unsigned_sum,unsigned_sum);

	_asm
	{
		LEA ESI, arr;
		MOV ECX, 10;	//��ѭ��������
		MOV EAX, 0;		//index
		LEA EDI, signed_sum;
		MOV [EDI], 0;
MAIN_LOOP2:
		SUB [ESI+EAX*1], 0;
		JS SIGNED;
		JNS ELSE;
SIGNED:
		MOV EBX, 0xFFFFFFFF;
		MOV BL, [ESI+EAX*1];
		ADD [EDI], EBX;
		INC EAX;		//index++
		DEC ECX;		//��ѭ��������--
		JNZ MAIN_LOOP2;
		JZ OVER2;
ELSE:
		MOV EBX, 0;
		MOV BL, [ESI+EAX*1];
		ADD [EDI], EBX;
		INC EAX;		//index++
		DEC ECX;		//��ѭ��������--
		JNZ MAIN_LOOP2;
		JZ OVER2;
OVER2:
	}
	printf("���з���������ʱ���ۼӺ�Ϊ��0x%X %d\n",signed_sum,signed_sum);
}