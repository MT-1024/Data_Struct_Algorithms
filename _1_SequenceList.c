#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>		//包含了exit()函数

struct SeqList		//定义了一个数据类型，该数据类型有三个成员
{
	int * first;	//数组第一个元素的地址,并且该数组是int型
	int length;		//数组所能容纳的最大元素的个数
	int nums;		//当前数组有效元素的个数
};

void initSeqList(struct SeqList *pSeqList, int len);		//初始化SeqList
void showSeqList(struct SeqList *pSeqList);
bool appendSeqList(struct SeqList *pSeqList, int value);	//数组空位置追加元素
bool insertSeqList(struct SeqList *pSeqList, int position, int value);		//在pos位置前插入元素，pos从1开始；eg 如果pos=4，表示在a[3]插入元素
bool deleteElem(struct SeqList *pSeqList, int position, int *pValue);	//删除指定位置的元素，并返回删除掉元素的地址
int getElemIndex(struct SeqList *pSeqList, int value);		//获取为value的第一个元素的下标
bool destorySeqList(struct SeqList *pSeqList);
bool isEmpty(struct SeqList *pSeqList);		//数组中元素个数是否为空
bool isFull(struct SeqList *pSeqList);		//数组中元素是否满了
void sortSeqList(struct SeqList * pSeqList);//选择排序
void inverseSeqList(struct SeqList * pSeqList);
void swap(int *a, int *b);

int main()
{
	int value1;					//value1中保存的是删除的元素的值
	struct SeqList seq1;		//seq1对象里的三个成员还没有初始化
	initSeqList(&seq1, 4);
	appendSeqList(&seq1, 2);
	appendSeqList(&seq1, 3);
	appendSeqList(&seq1, 4);
	insertSeqList(&seq1, 1, 1);
	deleteElem(&seq1, 1, &value1);
	insertSeqList(&seq1, 1, 1);
	showSeqList(&seq1);

	inverseSeqList(&seq1);
	showSeqList(&seq1);

	//printf("%d\n", value1);
	sortSeqList(&seq1);
	//destorySeqList(&seq1);
	showSeqList(&seq1);
	printf("查找元素为%d的下标是:%d\n", 4, getElemIndex(&seq1, 4));
	return 0;
}


void initSeqList(struct SeqList *pSeqList, int len)
{
	pSeqList->first = (int *)malloc(sizeof(int)*len);
	if (NULL == pSeqList->first)		//如果首地址为空，显示内存分配失败并且退出程序
	{
		printf("内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pSeqList->length = len;
		pSeqList->nums = 0;
	}
}

void showSeqList(struct SeqList * pSeqList)
{
	if (isEmpty(pSeqList))
	{
		printf("数组为空！\n");
	}
	else
	{
		for (int i = 0; i < pSeqList->nums; i++)
		{
			printf("%d ", pSeqList->first[i]);
		}
		printf("\n");
	}
}

bool appendSeqList(struct SeqList * pSeqList, int value)
{
	if (isFull(pSeqList))
	{
		return false;
	}
	else
	{
		pSeqList->first[pSeqList->nums] = value;
		pSeqList->nums++;
		//pSeqList->nums = pSeqList->nums + 1;
		return true;
	}
}

bool insertSeqList(struct SeqList * pSeqList, int position, int value)		//position从1开始；eg:如果pos=4，在数组第四个元素前插入元素
{
	if (isFull(pSeqList))
	{
		printf("插入失败！\n");
		return false;
	}
	if (position <1 || position > pSeqList->nums + 1)
	{
		printf("插入位置不合法！\n");
		return false;
	}
	else
	{
		for (int i = pSeqList->nums - 1; i >= position - 1; i--)
		{
			pSeqList->first[i + 1] = pSeqList->first[i];
		}
		pSeqList->first[position - 1] = value;
		pSeqList->nums++;
		return true;
	}
}

bool deleteElem(struct SeqList * pSeqList, int position, int *pValue)
{
	if (isEmpty(pSeqList))
	{
		printf("数组为空，无法删除！\n");
		return false;
	}
	if (position<1 || position > pSeqList->nums)
	{
		printf("删除位置不合法！\n");
		return false;
	}
	else
	{
		*pValue = pSeqList->first[position - 1];
		for (int i = position; i <= pSeqList->nums; i++)
		{
			pSeqList->first[i - 1] = pSeqList->first[i];
		}
		pSeqList->nums--;
		return true;
	}
}

int getElemIndex(struct SeqList *pSeqList, int value)
{
	if (isEmpty(pSeqList))
		return -1;
	else
	{
		for (int i = 0; i < pSeqList->nums; i++)
		{
			if (value == pSeqList->first[i])
			{
				return i;
			}
		}
		return -1;
	}
}

bool destorySeqList(struct SeqList *pSeqList)
{
	free(pSeqList->first);
	return true;
}

bool isEmpty(struct SeqList * pSeqList)
{
	if (0 == pSeqList->nums)
		return true;
	else
		return false;
}

bool isFull(struct SeqList * pSeqList)
{
	if (pSeqList->length == pSeqList->nums)
	{
		printf("分配空间已满！\n");
		return true;
	}
	else
		return false;
}

void sortSeqList(struct SeqList * pSeqList)
{
	for (int i = 0; i < pSeqList->nums; i++)
	{
		for (int j = i + 1; j < pSeqList->nums; j++)
		{
			if (pSeqList->first[i] > pSeqList->first[j])
				swap(&pSeqList->first[i], &pSeqList->first[j]);
		}
	}
}

void inverseSeqList(struct SeqList * pSeqList)
{
	for (int i = 0; i < pSeqList->nums / 2; i++)
	{
		swap(&pSeqList->first[i], &pSeqList->first[pSeqList->nums - i - 1]);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
