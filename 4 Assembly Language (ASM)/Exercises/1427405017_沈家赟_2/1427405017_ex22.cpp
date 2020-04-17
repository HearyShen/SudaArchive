/*********************
	ex22
	1427405017
	����S
	2016/3/15 9:19
*********************/
/********************************************************
2.5   ���д����ex22ʵ�����¹��ܣ�
	���û��Ӽ�������2����������32λ��ʾ����
	����2��������Ϊ�з��������Ƚϴ�С����ʾ�ϴ�ֵ��
	����2��������Ϊ�޷��������Ƚϴ�С����ʾ�ϴ�ֵ��
*********************************************************/
#include <stdio.h>

void main()
{
	int a,b;
	int signed_bigger;
	unsigned int unsigned_bigger;

	scanf("%d %d",&a,&b);

	_asm
	{
		MOV EAX, a;
		MOV EBX, b;
		CMP EAX, EBX;
		JGE SIGNED_OVER;	//(signed) EAX >= EBX, then jump to SIGNED_OVER, else exchange
		XCHG EAX, EBX;
SIGNED_OVER:
		MOV signed_bigger, EAX;

		CMP EAX, EBX;
		JA UNSIGNED_OVER;	//(unsigned) EAX > EBX, then jump to UNSIGNED_OVER, else exchange
		XCHG EAX, EBX;
UNSIGNED_OVER:
		MOV unsigned_bigger, EAX;
	}
	printf("signed_bigger: %d\n",signed_bigger);
	printf("unsigned_bigger: %d\n",unsigned_bigger);
}