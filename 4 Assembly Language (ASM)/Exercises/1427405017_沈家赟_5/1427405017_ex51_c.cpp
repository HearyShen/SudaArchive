/******************
	ex51_c
	1427405017
	����S
	2015/6/9
******************/
/*************************************************
5.4  ����VC2010���ɿ�����������дһ��ʵ�����¹��ܵĳ���
���û��Ӽ�������һ��ʮ������������Ȼ�������������ӡ�
����Ҫ����������ֻ�ܲ����ַ�����ʽ��ֻ��ʹ�ø�ʽ����%s������
Ӧ����ƺ��ʵĺ�����

���ڱ���ѡ���С��С�����͡��ٶ���󻯡�������£�
���ɻ���ʽ��Ŀ����룬������Դ�������Ŀ����롣
**************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20

int main()
{
	char str_in[MAX_LENGTH], str_out[MAX_LENGTH][10];
	unsigned int num = 0, factors_count = 0;
	puts("ex51_c\n������һ��ʮ��������");
	gets_s(str_in);

	num = atoi(str_in);
	for (int i=num; i > 0; i--)
	{
		if (num%i == 0)
		{
			itoa(i, str_out[factors_count++], 10);
		}
	}

	puts("��ʮ������ֵ������Ϊ��");
	for (unsigned int i = 0; i < factors_count; i++)
	{
		printf("%s ", str_out[i]);
	}
	printf("\n");

	return 0;
}