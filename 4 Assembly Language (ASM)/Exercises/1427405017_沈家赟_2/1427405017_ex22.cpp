/*********************
	ex22
	1427405017
	沈家赟
	2016/3/15 9:19
*********************/
/********************************************************
2.5   请编写程序ex22实现如下功能：
	由用户从键盘输入2个整数（用32位表示）；
	把这2个整数作为有符号数，比较大小，显示较大值；
	把这2个整数作为无符号数，比较大小，显示较大值。
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