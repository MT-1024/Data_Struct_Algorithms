#pragma warning(disable:4996)		//关闭vs2017的检查scanf不安全警告
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}LinkNode, *LinkList;		//LinkNode相当于sturct Node
							//LinkList相当于struct Node *, LinkList是指向strut Node类型的指针变量

LinkNode * initLinkListRear(void);		//尾插法建立链表
LinkNode * initLinkListFront(void);		//头插法建立链表
void traverseLinkList(LinkNode * pHead);		//从首结点开始遍历链表
bool isEmpty(LinkNode * pHead);
int getLengthLinkList(LinkNode * pHead);		//获取链表的长度（不含Head结点）
bool insertLinkNode(LinkNode * pHead, int position, int value);		//在第pos个位置插入data为value的的结点
bool deleteLinkNode(LinkNode * pHead, int position, int * pDelete);		//删除第pos个位置的结点，并记录被删结点的地址
LinkNode * locateLinkNode(LinkNode * pHead, int position);		//返回第position结点的地址
int searchLinkNode(LinkNode * pHead, int value);		//查找结点第一个data=value的位置，并返回该节点在链表中的位置




int main()
{
	LinkNode  * pHead;
	pHead = initLinkListRear();
	traverseLinkList(pHead);
	printf("该链表是否为空？%d\n", isEmpty(pHead));
	printf("该链表的长度是：%d \n", getLengthLinkList(pHead));
	insertLinkNode(pHead, 1, 1);
	insertLinkNode(pHead, 4, 4);
	traverseLinkList(pHead);
	int value;		//用于返回需要删除的值
	deleteLinkNode(pHead, 4, &value);
	printf("被删除结点的值是：%d\n", value);
	traverseLinkList(pHead);
	printf("查找结点data域为2的位置是：%d \n", searchLinkNode(pHead, 2));
	return 0;
}




LinkNode * initLinkListRear(void)
{
	LinkNode * pHead = (LinkNode *)malloc(sizeof(LinkNode));		//创建头结点的指针
	if (NULL == pHead)		//如果首地址为空，显示内存分配失败并且退出程序
	{
		printf("内存分配失败！\n");
		exit(-1);
	}
	pHead->pNext = NULL;		//头结点pNext域初始化
	LinkNode * pTemp = pHead;
	int tempValue;		//临时存放要输入的data值
	int length;			//想要创建链表中元素的个数（不含头结点）

	printf("请输入需要生成的链表的长度:length= ");
	scanf("%d", &length);

	for (int i = 0; i < length; i++)
	{
		LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
		if (NULL == newNode)		//如果首地址为空，显示内存分配失败并且退出程序
		{
			printf("内存分配失败！\n");
			exit(-1);
		}
		newNode->pNext = NULL;
		printf("请输入第%d个结点的值： ", i + 1);
		scanf("%d", &tempValue);
		newNode->data = tempValue;		//尾插法建立链表
		pTemp->pNext = newNode;
		pTemp = newNode;
	}

	return pHead;
}

LinkNode * initLinkListFront(void)
{
	LinkNode * pHead = (LinkNode *)malloc(sizeof(LinkNode));		//创建头结点的指针
	if (NULL == pHead)		//如果首地址为空，显示内存分配失败并且退出程序
	{
		printf("内存分配失败！\n");
		exit(-1);
	}
	pHead->pNext = NULL;		//头结点pNext域初始化
	LinkNode * pTemp = pHead;
	int tempValue;		//临时存放要输入的data值
	int length;			//想要创建链表中元素的个数（不含头结点）

	printf("请输入需要生成的链表的长度:length= ");
	scanf("%d", &length);

	for (int i = 0; i < length; i++)
	{
		LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
		if (NULL == newNode)		//如果首地址为空，显示内存分配失败并且退出程序
		{
			printf("内存分配失败！\n");
			exit(-1);
		}
		newNode->pNext = NULL;
		printf("请输入第%d个结点的值： ", i + 1);
		scanf("%d", &tempValue);
		newNode->data = tempValue;
		newNode->pNext = pTemp->pNext;		//头插法建立链表
		pTemp->pNext = newNode;
	}

	return pHead;
}



void traverseLinkList(LinkNode * pHead)
{
	LinkNode * pTemp = pHead->pNext;
	printf("链表的遍历结果是：");
	while (NULL != pTemp)
	{
		printf(" %d ", pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

bool isEmpty(LinkNode * pHead)
{
	if (pHead->pNext == NULL)
		return true;
	else
		return false;
}

int getLengthLinkList(LinkNode * pHead)
{
	int length = 0;
	LinkNode * pTemp = pHead->pNext;
	while (pTemp != NULL)
	{
		length++;
		pTemp = pTemp->pNext;
	}
	return length;
}

bool insertLinkNode(LinkNode * pHead, int position, int value)
{
	if (position <1 || position > getLengthLinkList(pHead) + 1)
	{
		printf("插入位置不合法!\n");
		return false;
	}
	LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
	newNode->pNext = NULL;		//新申请的结点初始化指针域为空

	LinkNode * pTemp = pHead;

	pTemp = locateLinkNode(pHead, position - 1);		//定位被插入位置的前面一个结点的地址
	newNode->data = value;
	newNode->pNext = pTemp->pNext;
	pTemp->pNext = newNode;
	return true;
}

bool deleteLinkNode(LinkNode * pHead, int position, int * pDelete)
{
	if (position < 1 || position > getLengthLinkList(pHead))
	{
		printf("删除位置不合法!\n");
		return false;
	}	LinkNode * pTemp;
	if (position == 1)
	{
		pTemp = pHead->pNext;
		pHead->pNext = pTemp->pNext;
		*pDelete = pTemp->data;		//记录被删结点的data值
		free(pTemp);		//释放pTemp->data的值
		return true;
	}
	//if (position == getLengthLinkList(pHead))
	//{
	//	pTemp = locateLinkNode(pHead, position - 1);
	//	LinkNode * pTemp2 = locateLinkNode(pHead, position);
	//	*pDelete = pTemp2->data;
	//	pTemp->pNext = NULL;
	//	free(pTemp2);
	//	return true;
	//}
	pTemp = locateLinkNode(pHead, position - 1);
	LinkNode * pTemp2 = locateLinkNode(pHead, position);
	*pDelete = pTemp2->data;
	pTemp->pNext = pTemp2->pNext;
	free(pTemp2);
	return true;
}



LinkNode * locateLinkNode(LinkNode * pHead, int position)
{
	if (position > getLengthLinkList(pHead) + 1)
	{
		printf("定位位置不合法!\n");
		return NULL;
	}
	LinkNode * pTemp = pHead;

	if (position == 0)
		return pTemp;

	for (int i = 1; i <= position; i++)
	{
		pTemp = pTemp->pNext;
	}
	return pTemp;
}

int searchLinkNode(LinkNode * pHead, int value)
{
	int position = 1;
	LinkNode * pTemp = pHead->pNext;
	while (pTemp != NULL && pTemp->data != value)
	{
		pTemp = pTemp->pNext;
		position++;
	}
	if (position > getLengthLinkList(pHead))
	{
		printf("没有data域为%d的结点！ ", value);
		return -1;
	}
	return position;
}