#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}Node;

typedef struct LinkQueue		//仅front处删除，仅rear处插入
{
	Node * front;		//front指向头结点，头结点的下一个结点才是队列的第一个结点
	Node * rear;		//rear指向尾结点
}LinkQueue;

void initLinkQueue(LinkQueue * pLinkQueue);		//初始化申请一个空节点，front和rear均指向该空节点，该空节点不保存数据
bool isLinkQueueEmpty(LinkQueue * pLinkQueue);
void enLinkQueue(LinkQueue * pLinkQueue, int value);
int deLinkQueue(LinkQueue * pLinkQueue);		//pHead不是要删除的队首元素，pHead->pNext所指向的元素才是要删除的元素
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
		printf("该队列为空！无法出队！\n");
		return -1;
	}
	else
	{
		Node * pTemp = pLinkQueue->front->pNext;		//链表头结点的下一个结点出队
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