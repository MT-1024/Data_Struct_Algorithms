#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>		//������exit()����

struct SeqList		//������һ���������ͣ�������������������Ա
{
	int * first;	//�����һ��Ԫ�صĵ�ַ,���Ҹ�������int��
	int length;		//�����������ɵ����Ԫ�صĸ���
	int nums;		//��ǰ������ЧԪ�صĸ���
};

void initSeqList(struct SeqList *pSeqList, int len);		//��ʼ��SeqList
void showSeqList(struct SeqList *pSeqList);
bool appendSeqList(struct SeqList *pSeqList, int value);	//�����λ��׷��Ԫ��
bool insertSeqList(struct SeqList *pSeqList, int position, int value);		//��posλ��ǰ����Ԫ�أ�pos��1��ʼ��eg ���pos=4����ʾ��a[3]����Ԫ��
bool deleteElem(struct SeqList *pSeqList, int position, int *pValue);	//ɾ��ָ��λ�õ�Ԫ�أ�������ɾ����Ԫ�صĵ�ַ
int getElemIndex(struct SeqList *pSeqList, int value);		//��ȡΪvalue�ĵ�һ��Ԫ�ص��±�
bool destorySeqList(struct SeqList *pSeqList);
bool isEmpty(struct SeqList *pSeqList);		//������Ԫ�ظ����Ƿ�Ϊ��
bool isFull(struct SeqList *pSeqList);		//������Ԫ���Ƿ�����
void sortSeqList(struct SeqList * pSeqList);//ѡ������
void inverseSeqList(struct SeqList * pSeqList);
void swap(int *a, int *b);

int main()
{
	int value1;					//value1�б������ɾ����Ԫ�ص�ֵ
	struct SeqList seq1;		//seq1�������������Ա��û�г�ʼ��
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
	printf("����Ԫ��Ϊ%d���±���:%d\n", 4, getElemIndex(&seq1, 4));
	return 0;
}


void initSeqList(struct SeqList *pSeqList, int len)
{
	pSeqList->first = (int *)malloc(sizeof(int)*len);
	if (NULL == pSeqList->first)		//����׵�ַΪ�գ���ʾ�ڴ����ʧ�ܲ����˳�����
	{
		printf("�ڴ����ʧ�ܣ�\n");
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
		printf("����Ϊ�գ�\n");
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

bool insertSeqList(struct SeqList * pSeqList, int position, int value)		//position��1��ʼ��eg:���pos=4����������ĸ�Ԫ��ǰ����Ԫ��
{
	if (isFull(pSeqList))
	{
		printf("����ʧ�ܣ�\n");
		return false;
	}
	if (position <1 || position > pSeqList->nums + 1)
	{
		printf("����λ�ò��Ϸ���\n");
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
		printf("����Ϊ�գ��޷�ɾ����\n");
		return false;
	}
	if (position<1 || position > pSeqList->nums)
	{
		printf("ɾ��λ�ò��Ϸ���\n");
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
		printf("����ռ�������\n");
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
