#pragma warning(disable:4996)		//关闭vs2017的检查scanf不安全警告
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
	int front;		//front始终指向队头第一个有效元素
	int rear;		//rear始终指向对尾有效元素的下一个空元素
	int length;
}CircularQueue;

/*
采用牺牲一个空间方案；也就是说eg：申请6个空间只能存储5个元素；
0.rear和front在变化时，只会加，不会减；
1.当rear的下一个位置是front时，表示队列已满；
2.当front = rear = 0 时表示队列初始化
3.当front = rear 时表示队列为空
4.入队元素 rear = (rear + 1) % length
5.出队元素 front = (front + 1) % length
*/
void initCircularQueue(CircularQueue * pCirQueue, int length);		//length是申请的数组长度
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
	printf("出队元素是:%d\n", deCircularQueue(&queue1));
	traverseCircularQueue(&queue1);
	return 0;
}

void initCircularQueue(CircularQueue * pCirQueue, int length)
{
	pCirQueue->first = (int *)malloc(sizeof(int)*length);
	if (NULL == pCirQueue->first)
	{
		printf("分配内存空间失败\n");
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
		printf("该队已满，无法入队!\n");
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
		printf("该队已空，无法出队！\n");
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