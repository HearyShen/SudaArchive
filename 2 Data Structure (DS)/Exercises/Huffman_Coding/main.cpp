#include <iostream>
#include <fstream>
#include <windows.h>
#include "Huffman_Tree.h"
#include "Pixel.h"

using namespace std;
const int W = 4;
const int H = 4;

//typedef struct tagBITMAPFILEHEADER
//{
//    WORD bfType;			//位图文件的类型，必须为BM(1-2字节）
//    DWORD bfSize;			//位图文件的大小，以字节为单位（3-6字节，低位在前）
//    WORD bfReserved1;		//位图文件保留字，必须为0(7-8字节）
//    WORD bfReserved2;		//位图文件保留字，必须为0(9-10字节）
//    DWORD bfOffBits;		//位图数据的起始位置，以相对于位图（11-14字节，低位在前）
//							//文件头的偏移量表示，以字节为单位
//}BITMAPFILEHEADER;
//
//typedef struct tagBITMAPINFOHEADER{
//	DWORD biSize;//本结构所占用字节数（15-18字节）
//	LONG biWidth;//位图的宽度，以像素为单位（19-22字节）
//	LONG biHeight;//位图的高度，以像素为单位（23-26字节）
//	WORD biPlanes;//目标设备的级别，必须为1(27-28字节）
//	WORD biBitCount;//每个像素所需的位数，必须是1（双色），（29-30字节）
//	//4(16色），8(256色）16(高彩色)或24（真彩色）之一
//	DWORD biCompression;//位图压缩类型，必须是0（不压缩），（31-34字节）
//	//1(BI_RLE8压缩类型）或2(BI_RLE4压缩类型）之一
//	DWORD biSizeImage;//位图的大小(其中包含了为了补齐行数是4的倍数而添加的空字节)，以字节为单位（35-38字节）
//	LONG biXPelsPerMeter;//位图水平分辨率，每米像素数（39-42字节）
//	LONG biYPelsPerMeter;//位图垂直分辨率，每米像素数（43-46字节)
//	DWORD biClrUsed;//位图实际使用的颜色表中的颜色数（47-50字节）
//	DWORD biClrImportant;//位图显示过程中重要的颜色数（51-54字节）
//}BITMAPINFOHEADER;
//
//typedef struct tagRGBQUAD{
//	BYTE rgbBlue;//蓝色的亮度（值范围为0-255)
//	BYTE rgbGreen;//绿色的亮度（值范围为0-255)
//	BYTE rgbRed;//红色的亮度（值范围为0-255)
//	BYTE rgbReserved;//保留，必须为0
//}RGBQUAD;
//
//
//typedef struct tagBITMAPINFO{
//	BITMAPINFOHEADER bmiHeader;//位图信息头
//	RGBQUAD bmiColors[1];//颜色表
//}BITMAPINFO;

struct HuffmanHead
{
	int CodeTypes;
};


void main()
{
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	RGBQUAD rgbQuad[256];
	//BITMAPINFO bitmapInfo;

	FILE* pfin = fopen("4X4.bmp","rb");
	if(pfin == NULL)
		cerr<<"error"<<endl;

	

	//ifstream fin("in.bmp");
	//ofstream fout("out.bmp");

	/*读 in.bmp*/
	fread(&fileHeader,sizeof(BITMAPFILEHEADER),1,pfin);		//in: BitmapFileHeader
	cout<<fileHeader.bfType<<endl
		<<fileHeader.bfSize<<endl
		<<fileHeader.bfReserved1<<endl
		<<fileHeader.bfReserved2<<endl
		<<fileHeader.bfOffBits<<endl;
	fread(&infoHeader,sizeof(BITMAPINFOHEADER),1,pfin);		//in: BitmapInfoHeader
	cout<<"宽度（像素）："<<infoHeader.biWidth<<endl
		<<"高度（像素）："<<infoHeader.biHeight<<endl
		<<"每像素占用位："<<infoHeader.biBitCount<<endl;			//256色度 对应 8位每像素
	fread(rgbQuad,sizeof(RGBQUAD),256,pfin);					//in: RGBQUAD

	fseek(pfin,fileHeader.bfOffBits,SEEK_SET);

	char pixels[W*H];
	int size = 0;
	cout<<"位图数据预览（转int）："<<endl;
	while(size < (infoHeader.biWidth * infoHeader.biHeight))			//读取像素并显示
	{
		fread(&pixels[size],sizeof(char),1,pfin);
		cout<<(int)pixels[size]<<" ";
		//cout<<pixels[size];
		size++;
	}
	fclose(pfin);//及时关闭文件
	cout<<endl;


	/*遍历读取的像素点char[]，去重并得出权重weight，实际像素种类数目sorted_size，得出sorted_pixels[]*/
	Pixel sorted_pixels[W*H];
	for(int i=0;i<size;i++)
	{
		sorted_pixels[i].pixel = pixels[i];
		sorted_pixels[i].weight = 0;
	}
	int size_sorted = size;
	//int weight[W*H];
	for(int i=0;i<size_sorted;i++)
	{
		sorted_pixels[i].weight = 1;
		for(int j=i+1;j<size_sorted;j++)
		{
			if(sorted_pixels[i].pixel == sorted_pixels[j].pixel)
			{
				for(int k=j;k<size_sorted;k++)
				{
					sorted_pixels[k] = sorted_pixels[k+1];
				}
				size_sorted--;
				sorted_pixels[i].weight++;
				j--;
			}
		}
	}
	/*根据权值weight，升序排序sorted_pixels[]*/
	for(int i=0;i<size_sorted;i++)
	{
		int min_index = i;
		for(int j=i+1;j<size_sorted;j++)
		{
			if(sorted_pixels[j].weight < sorted_pixels[min_index].weight)
			{
				min_index = j;
			}
		}
		if(min_index != i)
			swap(sorted_pixels[min_index],sorted_pixels[i]);
	}

	/*准备Huffman编码*/
	HuffNode *myHuffTree = new HuffNode[2 * size_sorted - 1];
	Code *myHuffCode = new Code[size_sorted];
	if (size_sorted>MaxN)
    {
        cout << "定义的n越界，修改MaxN!" << endl;
        exit(0);
	}

	/*构建赫夫曼树，形成编码，写入sorted_pixels[].HuffmanCode中，并显示*/
	Huffman(sorted_pixels, size_sorted, myHuffTree);
	HuffmanCode(myHuffTree, size_sorted, myHuffCode);
	for(int i=0;i<size_sorted;i++)
	{
		char hfcode = 0;
		cout<<"Code:";
		for (int j = 0; j<myHuffCode[i].start; j++)
		{
			//sorted_pixels[i].HuffmanCode[j] = myHuffCode[i].bit[j];
			hfcode = hfcode + myHuffCode[i].bit[j]*pow(2.0,myHuffCode[i].start-j-1);
			sorted_pixels[i].hfcode = hfcode;
            cout << myHuffCode[i].bit[j];
		}
		cout<<" Start:"<<myHuffCode[i].start<<" Weight:"<<myHuffCode[i].weight<<endl;
	}


	/*将对应的sorted_pixels(即像素和赫夫曼编码的 对应表) 写入新文件 *.huf */
	FILE* pfhuf = fopen("out.huf","wb");
	if(pfhuf == NULL)
		cerr<<"error"<<endl;

	fwrite(&fileHeader,sizeof(BITMAPFILEHEADER),1,pfhuf);
	fwrite(&infoHeader,sizeof(BITMAPINFOHEADER),1,pfhuf);
	fwrite(rgbQuad,sizeof(RGBQUAD),256,pfhuf);
	fseek(pfhuf,fileHeader.bfOffBits,SEEK_SET);

	HuffmanHead hfhead;
	hfhead.CodeTypes = size_sorted;
	fwrite(&hfhead,sizeof(HuffmanHead),1,pfhuf);//写入赫夫曼编码个数

	size = 0;
	while(size < size_sorted)
	{
		fwrite(&sorted_pixels[size],sizeof(Pixel),1,pfhuf);
		size++;
	}


	/*将各个元素对应的赫夫曼编码（压缩后的数据）写入 *.huf */
	char hfcode;
	for(int i=0;i<(infoHeader.biWidth * infoHeader.biHeight);i++)
	{
		hfcode = getHuffmanCode(pixels[i],sorted_pixels,size_sorted); 
		fwrite(&hfcode,sizeof(char),1,pfhuf);
	}

	fclose(pfhuf);//及时关闭文件


	/*读取 *.huf 文件*/
	FILE* fin = fopen("out.huf","rb");
	if(pfin == NULL)
		cerr<<"error"<<endl;

	fread(&fileHeader,sizeof(BITMAPFILEHEADER),1,fin);
	fread(&infoHeader,sizeof(BITMAPINFOHEADER),1,fin);
	fread(rgbQuad,sizeof(RGBQUAD),256,fin);

	fseek(pfin,fileHeader.bfOffBits,SEEK_SET);

	fread(&hfhead,sizeof(HuffmanHead),1,fin);		//读取赫夫曼编码个数
	size = 0;
	while(size < hfhead.CodeTypes)					//读取赫夫曼编码表
	{
		fread(&sorted_pixels[size],sizeof(Pixel),1,fin);
		cout<<"读取的编码表(char->int)"<<(int)sorted_pixels[size].hfcode<<endl;
		size++;
	}

	char hfcodes[W*H];
	cout<<"赫夫曼码(char->int)|像素码(char->int)"<<endl;
	for(int i=0;i<(infoHeader.biWidth * infoHeader.biHeight);i++)
	{
		fread(&hfcodes[i],sizeof(char),1,fin);			//读取所有像素（赫夫曼编码）
		pixels[i] = getBMPpixel(hfcodes[i],sorted_pixels,hfhead.CodeTypes);
		cout<<(int)hfcodes[i]<<"|"<<(int)pixels[i];
	}
	cout<<endl;
	fclose(fin);

	/*还原 out.bmp*/
	FILE* pfout = fopen("out.bmp","wb");
	if(pfout == NULL)
		cerr<<"error"<<endl;

	fwrite(&fileHeader,sizeof(BITMAPFILEHEADER),1,pfout);
	fwrite(&infoHeader,sizeof(BITMAPINFOHEADER),1,pfout);
	fwrite(rgbQuad,sizeof(RGBQUAD),256,pfout);
	fseek(pfout,fileHeader.bfOffBits,SEEK_SET);

	size = 0;
	while(size < (infoHeader.biWidth * infoHeader.biHeight))
	{
		//pixel[size] = getBMPpixel(
		fwrite(&pixels[size],sizeof(char),1,pfout);
		cout<<(int)pixels[size];
		size++;
	}
	fclose(pfout);
}