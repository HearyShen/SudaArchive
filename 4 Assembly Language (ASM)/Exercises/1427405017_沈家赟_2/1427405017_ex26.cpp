/*********************
	ex26
	1427405017
	����S
	2016/3/17 20:46
*********************/
/********************************************************
2.9   ���д����EX26ʵ�����¹��ܣ�
	������һ�����ͣ�˫�֣�32λ�����飬
	�����13���޷���������
	���㡰����֮�͡��롰ż��֮�͡�֮��ľ���ֵ��
	����ʾ�����

	˵���������ڶ�������ʱ��ʼ������13��������
		Ҳ����ͨ�������������������������
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	unsigned int arr[13];
	unsigned int odd_sum = 0;	//����odd
	unsigned int even_sum = 0;	//ż��even
	int delta_abs = 0;

	for(int i=0;i<13;i++)
	{
		arr[i] = (unsigned)rand()%1024;
		printf("%d 0x%02x \n",arr[i],arr[i]);
	}
	printf("\n");

	_asm
	{
		LEA ESI, arr;
		MOV ECX, 13;	//��ѭ��������
		MOV EAX, 0;		//index
		LEA EDI, odd_sum;
		LEA EDX, even_sum;
MAIN_LOOP:
		MOV EBX, [ESI+EAX*4];
		AND EBX, 1;		//ȡ������ֵ��1�� ������
		JNZ ODD_SUM;	//����������Ϊ0����Ϊ����
		JZ EVEN_SUM;	//��������Ϊ0����Ϊż��
ODD_SUM:
		MOV EBX, [ESI+EAX*4];
		ADD [EDI], EBX;
		INC EAX;		//index++
		DEC ECX;		//��ѭ��������--
		JNZ MAIN_LOOP;
		JZ OVER;
EVEN_SUM:
		MOV EBX, [ESI+EAX*4];
		ADD [EDX], EBX;
		INC EAX;		//index++
		DEC ECX;		//��ѭ��������--
		JNZ MAIN_LOOP;
		JZ OVER;
OVER:					//����֮�ͣ�ż��֮�ͼ������
		MOV EAX, [EDI];
		MOV EBX, [EDX];
		SUB EAX, EBX;
		JS ABS;			//����ֵΪ��������ת��ABS���ת��
		JNS END;		//����ֵ��Ϊ��������ת��END
ABS:
		IMUL EAX,  -1;
END:					//����֮����ż��֮��֮��ľ���ֵ�������
		MOV delta_abs, EAX;
	}
	printf("����֮��Ϊ��%d 0x%02x\n",odd_sum,odd_sum);
	printf("ż��֮��Ϊ��%d 0x%02x\n",even_sum,even_sum);
	printf("����֮����ż��֮�͵ľ���ֵΪ��%d 0x%02x\n",delta_abs,delta_abs);
}