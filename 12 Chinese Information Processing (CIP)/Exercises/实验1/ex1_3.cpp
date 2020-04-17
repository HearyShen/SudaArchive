/**
	CIP - ex1_3
	Created:	2017.9.19 Tue
	Modified:	2017.9.25 Mon

	1427405017
	沈家赟
*/

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void numToFile(const char txtfname[], const char binfname[]);

/*
	main
	描述：主函数，
		将10个1~100之间的随机正整数写入文本文件和二进制文件

	输入：无
	输出：写入数据的文本文件和二进制文件
*/
void main()
{
	char txtf[] = "text.txt", binf[] = "bin.dat";

	printf("写入开始！\n文本文件：%s\n二进制文件%s\n", txtf, binf);
	numToFile(txtf, binf);
	printf("写入完成！\n");

	puts("\n按任意键退出\n");
	getchar();
}


/*
	numToFile
	描述：创建文本文件和二进制文件，将10个1~100之间的随机正整数写入这两个文件

	输入：创建文本文件及二进制文件的文件名（含路径）
	输出：写入数据的文本文件和二进制文件
*/
void numToFile(const char txtfname[], const char binfname[])
{
	FILE *fptxt, *fpbin;
	int randNum, count;

	fptxt = fopen(txtfname, "w");
	if(fptxt == NULL)
	{
		printf("文件%s打开失败！\n", txtfname);
		exit(0);
	}

	fpbin = fopen(binfname, "wb");
	if(fpbin == NULL)
	{
		printf("文件%s打开失败！\n", binfname);
		exit(0);
	}

	for(count=0; count<10; count++)
	{
		randNum = rand()%100+1;	// 产生1~100之间的整数

		fprintf(fptxt, "%d\n", randNum);
		fwrite(&randNum, sizeof(int), 1, fpbin);
	}

	fclose(fptxt);
	fclose(fpbin);
}

#endif // !_CRT_SECURE_NO_WARNINGS