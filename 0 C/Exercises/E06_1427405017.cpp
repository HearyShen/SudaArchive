#include <stdio.h>

void main()
{
	char a,A;//a用于输入小写字母，A用于输出大写字母
	
	printf("请输入一个小写字母\n");
	scanf("%c",&a);

	A=a-32;//字母是字符也代表数字
	
	printf("该小写字母的相应大写字母为%c\n",A);
}