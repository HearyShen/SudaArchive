/******************
	ex31
	1427405017
	����S
	2015/3/29 8:51
******************/
/*************************************************
3.7   ���д����ex31ʵ�����¹��ܣ�
	���û��Ӽ�������һ���ַ�����
	Ȼ�󣬰��ַ����е����д�д��ĸת��ΪСд��ĸ��
	�������ַ�����
	������ӳ���ʵ�ְ�һ�����ܵĴ�д��ĸת��Ϊ��Ӧ��Сд��ĸ��
**************************************************/
#include <stdio.h>
#include <string>

char str[100];

int main()
{
	printf("Ƕ�������ex31\n");
	printf("������һ���ַ�����\n");
	gets(str);
	//scanf("%s",&str);

	_asm{
		LEA ESI, str;
		MOV ECX, 0;
MAIN_LOOP:
		MOV AL, [ESI+ECX*1];
		CMP AL, 0;			//�������� ��\0��
		JE END_LOOP;		// ��'\0'�������ѭ��
		CALL TO_LOWER;	//����תСд����TO_LOWER(��ڱ���AL, ���ڱ���AL)
		MOV [ESI+ECX*1], AL;
		INC ECX;
		JMP MAIN_LOOP;

END_LOOP:

	}

	printf("%s\n",str);
	return 0;

	_asm{
TO_LOWER:
		CMP AL, 'A';
		JB EXCLUSION;
		CMP AL, 'Z';
		JA EXCLUSION;
		ADD AL, 32;		//'A'<=AL<='Z',��+32תСд
		RET;
EXCLUSION:
		RET;
	}
}