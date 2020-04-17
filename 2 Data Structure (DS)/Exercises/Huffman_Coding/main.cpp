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
//    WORD bfType;			//λͼ�ļ������ͣ�����ΪBM(1-2�ֽڣ�
//    DWORD bfSize;			//λͼ�ļ��Ĵ�С�����ֽ�Ϊ��λ��3-6�ֽڣ���λ��ǰ��
//    WORD bfReserved1;		//λͼ�ļ������֣�����Ϊ0(7-8�ֽڣ�
//    WORD bfReserved2;		//λͼ�ļ������֣�����Ϊ0(9-10�ֽڣ�
//    DWORD bfOffBits;		//λͼ���ݵ���ʼλ�ã��������λͼ��11-14�ֽڣ���λ��ǰ��
//							//�ļ�ͷ��ƫ������ʾ�����ֽ�Ϊ��λ
//}BITMAPFILEHEADER;
//
//typedef struct tagBITMAPINFOHEADER{
//	DWORD biSize;//���ṹ��ռ���ֽ�����15-18�ֽڣ�
//	LONG biWidth;//λͼ�Ŀ�ȣ�������Ϊ��λ��19-22�ֽڣ�
//	LONG biHeight;//λͼ�ĸ߶ȣ�������Ϊ��λ��23-26�ֽڣ�
//	WORD biPlanes;//Ŀ���豸�ļ��𣬱���Ϊ1(27-28�ֽڣ�
//	WORD biBitCount;//ÿ�����������λ����������1��˫ɫ������29-30�ֽڣ�
//	//4(16ɫ����8(256ɫ��16(�߲�ɫ)��24�����ɫ��֮һ
//	DWORD biCompression;//λͼѹ�����ͣ�������0����ѹ��������31-34�ֽڣ�
//	//1(BI_RLE8ѹ�����ͣ���2(BI_RLE4ѹ�����ͣ�֮һ
//	DWORD biSizeImage;//λͼ�Ĵ�С(���а�����Ϊ�˲���������4�ı�������ӵĿ��ֽ�)�����ֽ�Ϊ��λ��35-38�ֽڣ�
//	LONG biXPelsPerMeter;//λͼˮƽ�ֱ��ʣ�ÿ����������39-42�ֽڣ�
//	LONG biYPelsPerMeter;//λͼ��ֱ�ֱ��ʣ�ÿ����������43-46�ֽ�)
//	DWORD biClrUsed;//λͼʵ��ʹ�õ���ɫ���е���ɫ����47-50�ֽڣ�
//	DWORD biClrImportant;//λͼ��ʾ��������Ҫ����ɫ����51-54�ֽڣ�
//}BITMAPINFOHEADER;
//
//typedef struct tagRGBQUAD{
//	BYTE rgbBlue;//��ɫ�����ȣ�ֵ��ΧΪ0-255)
//	BYTE rgbGreen;//��ɫ�����ȣ�ֵ��ΧΪ0-255)
//	BYTE rgbRed;//��ɫ�����ȣ�ֵ��ΧΪ0-255)
//	BYTE rgbReserved;//����������Ϊ0
//}RGBQUAD;
//
//
//typedef struct tagBITMAPINFO{
//	BITMAPINFOHEADER bmiHeader;//λͼ��Ϣͷ
//	RGBQUAD bmiColors[1];//��ɫ��
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

	/*�� in.bmp*/
	fread(&fileHeader,sizeof(BITMAPFILEHEADER),1,pfin);		//in: BitmapFileHeader
	cout<<fileHeader.bfType<<endl
		<<fileHeader.bfSize<<endl
		<<fileHeader.bfReserved1<<endl
		<<fileHeader.bfReserved2<<endl
		<<fileHeader.bfOffBits<<endl;
	fread(&infoHeader,sizeof(BITMAPINFOHEADER),1,pfin);		//in: BitmapInfoHeader
	cout<<"��ȣ����أ���"<<infoHeader.biWidth<<endl
		<<"�߶ȣ����أ���"<<infoHeader.biHeight<<endl
		<<"ÿ����ռ��λ��"<<infoHeader.biBitCount<<endl;			//256ɫ�� ��Ӧ 8λÿ����
	fread(rgbQuad,sizeof(RGBQUAD),256,pfin);					//in: RGBQUAD

	fseek(pfin,fileHeader.bfOffBits,SEEK_SET);

	char pixels[W*H];
	int size = 0;
	cout<<"λͼ����Ԥ����תint����"<<endl;
	while(size < (infoHeader.biWidth * infoHeader.biHeight))			//��ȡ���ز���ʾ
	{
		fread(&pixels[size],sizeof(char),1,pfin);
		cout<<(int)pixels[size]<<" ";
		//cout<<pixels[size];
		size++;
	}
	fclose(pfin);//��ʱ�ر��ļ�
	cout<<endl;


	/*������ȡ�����ص�char[]��ȥ�ز��ó�Ȩ��weight��ʵ������������Ŀsorted_size���ó�sorted_pixels[]*/
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
	/*����Ȩֵweight����������sorted_pixels[]*/
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

	/*׼��Huffman����*/
	HuffNode *myHuffTree = new HuffNode[2 * size_sorted - 1];
	Code *myHuffCode = new Code[size_sorted];
	if (size_sorted>MaxN)
    {
        cout << "�����nԽ�磬�޸�MaxN!" << endl;
        exit(0);
	}

	/*�����շ��������γɱ��룬д��sorted_pixels[].HuffmanCode�У�����ʾ*/
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


	/*����Ӧ��sorted_pixels(�����غͺշ�������� ��Ӧ��) д�����ļ� *.huf */
	FILE* pfhuf = fopen("out.huf","wb");
	if(pfhuf == NULL)
		cerr<<"error"<<endl;

	fwrite(&fileHeader,sizeof(BITMAPFILEHEADER),1,pfhuf);
	fwrite(&infoHeader,sizeof(BITMAPINFOHEADER),1,pfhuf);
	fwrite(rgbQuad,sizeof(RGBQUAD),256,pfhuf);
	fseek(pfhuf,fileHeader.bfOffBits,SEEK_SET);

	HuffmanHead hfhead;
	hfhead.CodeTypes = size_sorted;
	fwrite(&hfhead,sizeof(HuffmanHead),1,pfhuf);//д��շ����������

	size = 0;
	while(size < size_sorted)
	{
		fwrite(&sorted_pixels[size],sizeof(Pixel),1,pfhuf);
		size++;
	}


	/*������Ԫ�ض�Ӧ�ĺշ������루ѹ��������ݣ�д�� *.huf */
	char hfcode;
	for(int i=0;i<(infoHeader.biWidth * infoHeader.biHeight);i++)
	{
		hfcode = getHuffmanCode(pixels[i],sorted_pixels,size_sorted); 
		fwrite(&hfcode,sizeof(char),1,pfhuf);
	}

	fclose(pfhuf);//��ʱ�ر��ļ�


	/*��ȡ *.huf �ļ�*/
	FILE* fin = fopen("out.huf","rb");
	if(pfin == NULL)
		cerr<<"error"<<endl;

	fread(&fileHeader,sizeof(BITMAPFILEHEADER),1,fin);
	fread(&infoHeader,sizeof(BITMAPINFOHEADER),1,fin);
	fread(rgbQuad,sizeof(RGBQUAD),256,fin);

	fseek(pfin,fileHeader.bfOffBits,SEEK_SET);

	fread(&hfhead,sizeof(HuffmanHead),1,fin);		//��ȡ�շ����������
	size = 0;
	while(size < hfhead.CodeTypes)					//��ȡ�շ��������
	{
		fread(&sorted_pixels[size],sizeof(Pixel),1,fin);
		cout<<"��ȡ�ı����(char->int)"<<(int)sorted_pixels[size].hfcode<<endl;
		size++;
	}

	char hfcodes[W*H];
	cout<<"�շ�����(char->int)|������(char->int)"<<endl;
	for(int i=0;i<(infoHeader.biWidth * infoHeader.biHeight);i++)
	{
		fread(&hfcodes[i],sizeof(char),1,fin);			//��ȡ�������أ��շ������룩
		pixels[i] = getBMPpixel(hfcodes[i],sorted_pixels,hfhead.CodeTypes);
		cout<<(int)hfcodes[i]<<"|"<<(int)pixels[i];
	}
	cout<<endl;
	fclose(fin);

	/*��ԭ out.bmp*/
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