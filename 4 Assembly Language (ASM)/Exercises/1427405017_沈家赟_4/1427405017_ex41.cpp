/******************
	ex41
	1427405017
	����S
	2015/5/8
******************/
/*************************************************
4.6   ���д����ex41ʵ�����¹��ܣ�
	���û��Ӽ�������һ���ַ�����
	Ȼ��ͳ�Ƹ��ַ����и���Ӣ����ĸ���ֵĸ�����
	��������Щͳ�ƽ����

	��������ַ���ָ��
**************************************************/
#include <stdio.h>

#define MAX_LEN 50

int main()
{
	char str_in[MAX_LEN];
	char en[52];
	int count_en = 0;
	for(int i=0;i<26;i++)
	{
		en[i] = 'a'+i;
	}
	for(int i=26;i<52;i++)
	{
		en[i] = 'A'+i-26;
	}
	printf("Ƕ�������ex41\n");
	printf("������һ���Ϊ%d���ַ�����\n",MAX_LEN);
	gets(str_in);

	_asm{
		LEA ESI, str_in;
		LEA EDI, en;
		MOV count_en, 0;
		CLD;
PRE_SCAN:
		MOV ECX, 52;	// 26*2
		LODSB;			// BYTE PTR[ESI] -> AL
		CMP AL, 0;
		JE OVER;
		PUSH EDI;		//SCASB��ı�EDI����ǰ�����Ա���һѭ���ָ�
SCAN_EN:
		SCASB;
		LOOPNE SCAN_EN;
		JNZ NEXT;
FOUND:
		INC count_en; 
NEXT:
		POP EDI;		//�ָ�EDI
		JMP PRE_SCAN;
OVER:
	}
		
	printf("Ӣ����ĸ����%d��\n",count_en);

	return 0;
}