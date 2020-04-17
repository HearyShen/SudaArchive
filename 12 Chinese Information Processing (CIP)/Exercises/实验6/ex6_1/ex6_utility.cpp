#include "ex6_utility.h"

/*
IMPLEMENTATIONS
*/

unsigned int gb2312ToAddr(const unsigned char gbEncode[],
	const unsigned int rowCount,
	const unsigned int colCount)
{
	unsigned int index, addr;

	//index = gbEncode[1] - 0xA1 + 94 * (gbEncode[0] - 0xB0) + 15 * 94;
	//addr = index * 32;

	addr = ((gbEncode[0] - 0xA1) * 94 + gbEncode[1] - 0xA1) * rowCount * colCount / BYTE_BITS;

	return addr;
}

void printChinese(FILE *fp,
	const unsigned int startAddr,
	const char fillCh,
	const unsigned int fillCount,
	const unsigned int rowCount,
	const unsigned int colCount)
{
	unsigned char buffer[BUFFER_SIZE], mask, ch;

	fseek(fp, startAddr, SEEK_SET);
	int flag = fread(buffer, sizeof(unsigned char), rowCount * colCount / BYTE_BITS, fp);
	if (flag <= 0)
	{
		printf("ERROR: can't read file.\n");
		return;
	}

	for (unsigned int row = 0; row < rowCount; row++)
	{
		for (unsigned int col = 0; col < colCount / BYTE_BITS; col++)
		{
			mask = 0x80;
			for (int count = 0; count < BYTE_BITS; count++)
			{
				ch = mask >> count & buffer[row * 2 + col] ? fillCh : ' ';
				for (int fill = 0; fill < fillCount; fill++)
				{
					printf("%c", ch);
				}
			}
		}
		printf("\n");
	}
}