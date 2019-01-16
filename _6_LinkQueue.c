#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}Node;

typedef struct LinkQueue		//��front��ɾ������rear������
{
	Node * front;		//frontָ��ͷ��㣬ͷ������һ�������Ƕ��еĵ�һ�����
	Node * rear;		//rearָ��β���
}LinkQueue;

void initLinkQueue(LinkQueue * pLinkQueue);		//��ʼ������һ���սڵ㣬front��rear��ָ��ÿսڵ㣬�ÿսڵ㲻��������
bool isLinkQueueEmpty(LinkQueue * pLinkQueue);
void enLinkQueue(LinkQueue * pLinkQueue, int value);
int deLinkQueue(LinkQueue * pLinkQueue);		//pHead����Ҫɾ���Ķ���Ԫ�أ�pHead->pNext��ָ���Ԫ�ز���Ҫɾ����Ԫ��
void traverseQueue(LinkQueue * pLinkQueue);

int main()
{
	LinkQueue queue1;
	initLinkQueue(&queue1);
	enLinkQueue(&queue1,1);
	enLinkQueue(&queue1,2);
	enLinkQueue(&queue1,3);
	enLinkQueue(&queue1,4);
	deLinkQueue(&queue1);
	traverseQueue(&queue1);
	return 0;
}

void initLinkQueue(LinkQueue * pLinkQueue)
{
	pLinkQueue->front = pLinkQueue->rear = (Node *)malloc(sizeof(Node));
	pLinkQueue->front->pNext = NULL;
}

bool isLinkQueueEmpty(LinkQueue * pLinkQueue)
{
	if (pLinkQueue->front == pLinkQueue->rear)
		return true;
	else
		return false;
}

void enLinkQueue(LinkQueue * pLinkQueue, int value)
{
	Node * pNewNode = (Node *)malloc(sizeof(Node));
	pNewNode->pNext = NULL;
	pNewNode->data = value;

	pLinkQueue->rear->pNext = pNewNode;
	pLinkQueue->rear = pNewNode;
}

int deLinkQueue(LinkQueue * pLinkQueue)
{
	if (true == isLinkQueueEmpty(pLinkQueue))
	{
		printf("�ö���Ϊ�գ��޷����ӣ�\n");
		return -1;
	}
	else
	{
		Node * pTemp = pLinkQueue->front->pNext;		//����ͷ������һ��������
		int value = pTemp->data;
		pLinkQueue->front->pNext = pTemp->pNext;
		free(pTemp);
		if (NULL == pLinkQueue->front)
			pLinkQueue->front = pLinkQueue->rear;
		return value;
	}
}

void traverseQueue(LinkQueue * pLinkQueue)
{
	Node * pTemp = pLinkQueue->front->pNext;
	while (pTemp != NULL)
	{
		printf("%d ", pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}