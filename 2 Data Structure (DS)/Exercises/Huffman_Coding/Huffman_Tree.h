#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include <iostream>
#include <stdlib.h>
#include "Pixel.h"
using namespace std;

#include <iostream>
#include <stdlib.h>
using namespace std;
const int MaxValue = 10000;//��ʼ�趨��Ȩֵ���ֵ
const int MaxBit = 8;//��ʼ�趨��������λ��
const int MaxN = 20;//��ʼ�趨����������
struct HuffNode//���������Ľ��ṹ
{
    int weight;//Ȩֵ
    int flag;//���
    int parent;//˫�׽���±�
    int leftChild;//�����±�
    int rightChild;//�Һ����±�
};
struct Code//��Ź��������������Ԫ�ؽṹ
{
    int bit[MaxBit];//����
    int start;//�������ʼ�±�
    int weight;//�ַ���Ȩֵ
};

void Huffman(Pixel pixels[], int n, HuffNode huffTree[]) 
//void Huffman(int weight[], int n, HuffNode huffTree[])
//����Ҷ������ΪnȨֵΪweight�Ĺ�������huffTree
{
    int j, m1, m2, x1, x2;
    //��������huffTree��ʼ����n��Ҷ���Ĺ�����������2n-1�����
    for (int i = 0; i<2 * n - 1; i++)
    {
        if (i<n)
			huffTree[i].weight = pixels[i].weight;
            //huffTree[i].weight = weight[i];
        else
            huffTree[i].weight = 0;
        //ע������û��else��{}����������n��Ҷ�ӽڵ㻹��n-1����Ҷ�ӽڵ㶼���������4���ĳ�ʼ��
        huffTree[i].parent = 0;
        huffTree[i].flag = 0;
        huffTree[i].leftChild = -1;
        huffTree[i].rightChild = -1;
    }
    //�����������huffTree��n-1����Ҷ���
    for (int i = 0; i<n - 1; i++)
    {
        m1 = m2 = MaxValue;//Maxvalue=10000;(����һ���൱�����)
        x1 = x2 = 0;//x1��x2������������С������ֵ�������Ӧ���±�
 
        for (j = i; j<n + i; j++)//ѭ���ҳ�����Ȩ���У���С�Ķ���ֵ--morgan
        {
            if (huffTree[j].weight<m1&&huffTree[j].flag == 0)
            {
                m2 = m1;
                x2 = x1;
                m1 = huffTree[j].weight;
                x1 = j;
            }
            else if(huffTree[j].weight<m2&&huffTree[j].flag == 0)
            {
                m2 = huffTree[j].weight;
                x2 = j;
            }
        }
        //���ҳ�������Ȩֵ��С�������ϲ�Ϊһ������
        huffTree[x1].parent = n + i;
        huffTree[x2].parent = n + i;
        huffTree[x1].flag = 1;
        huffTree[x2].flag = 1;
        huffTree[n + i].weight = huffTree[x1].weight + huffTree[x2].weight;
        huffTree[n + i].leftChild = x1;
        huffTree[n + i].rightChild = x2;
    }
}
void HuffmanCode(HuffNode huffTree[], int n, Code huffCode[])
//��n�����Ĺ�������huffTree�������������huffCode
{
    Code *cd = new Code;
    int child, parent;
    //��n��Ҷ���Ĺ���������
    for (int i = 0; i<n; i++)
    {
        //cd->start=n-1;//���ȳ���������һλΪn-1,
        cd->start = 0;//,----�޸Ĵ�0��ʼ����--morgan
        cd->weight = huffTree[i].weight;//ȡ�ñ����ӦȨֵ���ַ�
        child = i;
        parent = huffTree[child].parent;
        //��Ҷ�������ֱ�������
        while (parent != 0)
        {
            if (huffTree[parent].leftChild == child)
                cd->bit[cd->start] = 0;//���ӽ�����0
            else
                cd->bit[cd->start] = 1;//�Һ��ӽ�����1
                                      //cd->start--;
            cd->start++;//�ĳɱ�������--morgan
            child = parent;
            parent = huffTree[child].parent;
        }
        //����Ҷ���ı���Ͳ��ȳ��������ʼλ
        //for(intj=cd->start+1;j<n;j++)
        for (int j = cd->start - 1; j >= 0; j--)//�����޸ı��룬�Ӹ��ڵ㿪ʼ����--morgan
            huffCode[i].bit[cd->start - j - 1] = cd->bit[j];
 
        huffCode[i].start = cd->start;
        huffCode[i].weight = cd->weight;//��������Ӧ��Ȩֵ
    }
}










//typedef struct{
//	unsigned int weight;
//	unsigned int parent,lchild,rchild;
//}HTNode, *HuffmanTree;
//typedef char **HuffmanCode;
//
//void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
//{
//	if(n<=1)
//		return;
//	m = 2*n - 1;
//	HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));
//	for(p = HT,i=1;i<=n;++i,++p,++w)
//		*p = {*w,0,0,0};
//	for( ; i<=m; ++i, ++p)
//		*p = {0,0,0,0};
//	for(i = n+1;i<=m;++i)
//	{
//		Select(HT,i-1,s1,s2);
//		HT[s1].
//	}
//}




////#include "heap.h"
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int DefaultSize=20;//ȱʡȨֵ���ϴ�С
//
//struct HuffmanNode//�������ඨ��
//{
//	float data;//�������
//	HuffmanNode *leftChild, *rightChild, *parent;
//	//������Ů�͸����ָ��
//	HuffmanNode():leftChild(NULL),rightChild(NULL),parent(NULL){ } //���캯��
//	HuffmanNode(float elem, HuffmanNode *left=NULL,HuffmanNode *right=NULL, HuffmanNode *pr=NULL):data(elem), leftChild(left), rightChild(right), parent(pr){}
//	bool operator <=(HuffmanNode &R){return data<=R.data;}
//	bool operator>(HuffmanNode &R){return data>R.data;}
//};
//
//class HuffmanTree//Huffman���ඨ��
//{
//public:
//	HuffmanTree(float w[], int n);//���캯��
//	~HuffmanTree(){deleteTree(root);}//��������
//protected:
//	HuffmanNode *root;//Huffman���ĸ�
//	void deleteTree(HuffmanNode *t);//ɾ����tΪ��������
//	void mergeTree(HuffmanNode &ht1, HuffmanTree &ht2,HuffmanNode *&parent);//�ϲ�������
//};
//
//HuffmanTree::HuffmanTree(float w[], int n)
//{
////����n��Ȩֵw[1]~w[n]������Huffman����
//	minHeap hp;//ʹ����С�Ѵ��ɭ��
//	HuffmanNode * parent, first, second, work;
//	for(int i=0; i<n; i++)//ɭ�ָ�������ʼ��
//	{
//		work.data=w[i]; work.leftChild=NULL;
//		work.rightChild=NULL; work.parent=NULL;
//		hp.Insert(work);//������С����
//	}
//	for(int i=0; i<n-1; i++)
//	{
//		//��n-1�ˣ��γ�Hufman��
//		hp.RemoveMin(first);
//		//ѡ�����Ȩֵ��С����
//		hp.RemoveMin(second);
//		//ѡ�����Ȩֵ��С����
//		merge(first, second, parent);//�ϲ�
//		hp.Insert(* parent);//���²��뵽��С����
//	}
//	root=parent;//���������
//};
//
//void HuffmanTree::mergeTree(HuffmanNode &bt1,HuffmanNode &bt2, HuffmanNode *&parent)
//{
//	parent=new Huffman Node;
//	parent->leftChild=&bt1;
//	parent->rightChild=&bt2;
//	parent->data=bt1.root->data+bt2.root->data;
//	bt1.root->parent=parent;
//	bt2.root->parent=parent;
//};

#endif