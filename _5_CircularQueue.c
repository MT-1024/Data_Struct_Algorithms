#pragma warning(disable:4996)		//�ر�vs2017�ļ��scanf����ȫ����
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}Node;

typedef struct CircularQueue
{
	int * first;
	int front;		//frontʼ��ָ���ͷ��һ����ЧԪ��
	int rear;		//rearʼ��ָ���β��ЧԪ�ص���һ����Ԫ��
	int length;
}CircularQueue;

/*
��������һ���ռ䷽����Ҳ����˵eg������6���ռ�ֻ�ܴ洢5��Ԫ�أ�
0.rear��front�ڱ仯ʱ��ֻ��ӣ��������
1.��rear����һ��λ����frontʱ����ʾ����������
2.��front = rear = 0 ʱ��ʾ���г�ʼ��
3.��front = rear ʱ��ʾ����Ϊ��
4.���Ԫ�� rear = (rear + 1) % length
5.����Ԫ�� front = (front + 1) % length
*/
void initCircularQueue(CircularQueue * pCirQueue, int length);		//length����������鳤��
void enCircularQueue(CircularQueue * pCirQueue, int value);
int deCircularQueue(CircularQueue * pCirQueue);
bool isCircularQueueEmpty(CircularQueue * pCirQueue);
bool isCirCularQUeueFull(CircularQueue * pCirQueue);
void traverseCircularQueue(CircularQueue * pCirQueue);

int main()
{
	CircularQueue queue1;
	initCircularQueue(&queue1, 6);
	enCircularQueue(&queue1, 1);
	enCircularQueue(&queue1, 2);
	enCircularQueue(&queue1, 3);
	enCircularQueue(&queue1, 4);
	enCircularQueue(&queue1, 5);
	enCircularQueue(&queue1, 6);
	printf("����Ԫ����:%d\n", deCircularQueue(&queue1));
	traverseCircularQueue(&queue1);
	return 0;
}

void initCircularQueue(CircularQueue * pCirQueue, int length)
{
	pCirQueue->first = (int *)malloc(sizeof(int)*length);
	if (NULL == pCirQueue->first)
	{
		printf("�����ڴ�ռ�ʧ��\n");
		exit(-1);
	}
	else
	{
		pCirQueue->front = pCirQueue->rear = 0;
		pCirQueue->length = length;
	}
}
void enCircularQueue(CircularQueue * pCirQueue, int value)
{
	if (true == isCirCularQUeueFull(pCirQueue))
	{
		printf("�ö��������޷����!\n");
	}
	else
	{
		pCirQueue->first[pCirQueue->rear] = value;
		pCirQueue->rear++;
	}
}
int deCircularQueue(CircularQueue * pCirQueue)
{
	if (true == isCircularQueueEmpty(pCirQueue))
	{
		printf("�ö��ѿգ��޷����ӣ�\n");
		return -999;
	}
	else
	{
		return pCirQueue->first[pCirQueue->front++];
	}
}

bool isCircularQueueEmpty(CircularQueue * pCirQueue)
{
	if (pCirQueue->front == pCirQueue->rear)
		return true;
	else
		return false;
}
bool isCirCularQUeueFull(CircularQueue * pCirQueue)
{
	if ((pCirQueue->rear + 1) % pCirQueue->length == pCirQueue->front)
		return true;
	else
		return false;
}
void traverseCircularQueue(CircularQueue * pCirQueue)
{
	int i = pCirQueue->front;
	while (i != pCirQueue->rear)
	{
		printf("%d ", pCirQueue->first[i]);
		i = (i + 1) % pCirQueue->length;
	}
	printf("\n");
}