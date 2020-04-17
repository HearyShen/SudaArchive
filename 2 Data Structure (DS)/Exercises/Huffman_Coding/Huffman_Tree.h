#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include <iostream>
#include <stdlib.h>
#include "Pixel.h"
using namespace std;

#include <iostream>
#include <stdlib.h>
using namespace std;
const int MaxValue = 10000;//初始设定的权值最大值
const int MaxBit = 8;//初始设定的最大编码位数
const int MaxN = 20;//初始设定的最大结点个数
struct HuffNode//哈夫曼树的结点结构
{
    int weight;//权值
    int flag;//标记
    int parent;//双亲结点下标
    int leftChild;//左孩子下标
    int rightChild;//右孩子下标
};
struct Code//存放哈夫曼编码的数据元素结构
{
    int bit[MaxBit];//数组
    int start;//编码的起始下标
    int weight;//字符的权值
};

void Huffman(Pixel pixels[], int n, HuffNode huffTree[]) 
//void Huffman(int weight[], int n, HuffNode huffTree[])
//建立叶结点个数为n权值为weight的哈夫曼树huffTree
{
    int j, m1, m2, x1, x2;
    //哈夫曼树huffTree初始化。n个叶结点的哈夫曼树共有2n-1个结点
    for (int i = 0; i<2 * n - 1; i++)
    {
        if (i<n)
			huffTree[i].weight = pixels[i].weight;
            //huffTree[i].weight = weight[i];
        else
            huffTree[i].weight = 0;
        //注意这里没打else那{}，故无论是n个叶子节点还是n-1个非叶子节点都会进行下面4步的初始化
        huffTree[i].parent = 0;
        huffTree[i].flag = 0;
        huffTree[i].leftChild = -1;
        huffTree[i].rightChild = -1;
    }
    //构造哈夫曼树huffTree的n-1个非叶结点
    for (int i = 0; i<n - 1; i++)
    {
        m1 = m2 = MaxValue;//Maxvalue=10000;(就是一个相当大的数)
        x1 = x2 = 0;//x1、x2是用来保存最小的两个值在数组对应的下标
 
        for (j = i; j<n + i; j++)//循环找出所有权重中，最小的二个值--morgan
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
        //将找出的两棵权值最小的子树合并为一棵子树
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
//由n个结点的哈夫曼树huffTree构造哈夫曼编码huffCode
{
    Code *cd = new Code;
    int child, parent;
    //求n个叶结点的哈夫曼编码
    for (int i = 0; i<n; i++)
    {
        //cd->start=n-1;//不等长编码的最后一位为n-1,
        cd->start = 0;//,----修改从0开始计数--morgan
        cd->weight = huffTree[i].weight;//取得编码对应权值的字符
        child = i;
        parent = huffTree[child].parent;
        //由叶结点向上直到根结点
        while (parent != 0)
        {
            if (huffTree[parent].leftChild == child)
                cd->bit[cd->start] = 0;//左孩子结点编码0
            else
                cd->bit[cd->start] = 1;//右孩子结点编码1
                                      //cd->start--;
            cd->start++;//改成编码自增--morgan
            child = parent;
            parent = huffTree[child].parent;
        }
        //保存叶结点的编码和不等长编码的起始位
        //for(intj=cd->start+1;j<n;j++)
        for (int j = cd->start - 1; j >= 0; j--)//重新修改编码，从根节点开始计数--morgan
            huffCode[i].bit[cd->start - j - 1] = cd->bit[j];
 
        huffCode[i].start = cd->start;
        huffCode[i].weight = cd->weight;//保存编码对应的权值
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
//const int DefaultSize=20;//缺省权值集合大小
//
//struct HuffmanNode//树结点的类定义
//{
//	float data;//结点数据
//	HuffmanNode *leftChild, *rightChild, *parent;
//	//左、右子女和父结点指针
//	HuffmanNode():leftChild(NULL),rightChild(NULL),parent(NULL){ } //构造函数
//	HuffmanNode(float elem, HuffmanNode *left=NULL,HuffmanNode *right=NULL, HuffmanNode *pr=NULL):data(elem), leftChild(left), rightChild(right), parent(pr){}
//	bool operator <=(HuffmanNode &R){return data<=R.data;}
//	bool operator>(HuffmanNode &R){return data>R.data;}
//};
//
//class HuffmanTree//Huffman树类定义
//{
//public:
//	HuffmanTree(float w[], int n);//构造函数
//	~HuffmanTree(){deleteTree(root);}//析构函数
//protected:
//	HuffmanNode *root;//Huffman树的根
//	void deleteTree(HuffmanNode *t);//删除以t为根的子树
//	void mergeTree(HuffmanNode &ht1, HuffmanTree &ht2,HuffmanNode *&parent);//合并二叉树
//};
//
//HuffmanTree::HuffmanTree(float w[], int n)
//{
////给出n个权值w[1]~w[n]，构造Huffman树。
//	minHeap hp;//使用最小堆存放森林
//	HuffmanNode * parent, first, second, work;
//	for(int i=0; i<n; i++)//森林各棵树初始化
//	{
//		work.data=w[i]; work.leftChild=NULL;
//		work.rightChild=NULL; work.parent=NULL;
//		hp.Insert(work);//插入最小堆中
//	}
//	for(int i=0; i<n-1; i++)
//	{
//		//做n-1趟，形成Hufman树
//		hp.RemoveMin(first);
//		//选择根的权值最小的树
//		hp.RemoveMin(second);
//		//选择根的权值次小的树
//		merge(first, second, parent);//合并
//		hp.Insert(* parent);//重新插入到最小堆中
//	}
//	root=parent;//建立根结点
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