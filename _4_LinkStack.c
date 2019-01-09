#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node		//栈里面结点的类型
{
	int data;
	struct Node * pNext;
}LinkNode;

typedef struct Stack		//栈里面保存2个信息：栈头结点的地址；栈尾节点的地址
{
	LinkNode * top;
	LinkNode * buttom;
}LinkStack;

void initLinkStack(LinkStack * pStack);		//初始化时，申请一个空节点，并且置其指针域为空，data域；stack1中的2个域都保存该空节点的地址
void pushLinkStack(LinkStack * pStack, int value);
int	 popLinkStack(LinkStack * pStack);
void traverseLinkStack(LinkStack * pStack);
bool isLinkStackEmpty(LinkStack * pStack);		//链栈不会满，只要有判空操作就行
int getLengthLinkStack(LinkStack * pStack);
void clearLinkStack(LinkStack * pStack);		//清空栈中的元素，但是保存栈的结构

int main()
{
	LinkStack stack1;
	initLinkStack(&stack1);
	printf("该栈是否为空？ %d \n", isLinkStackEmpty(&stack1));
	pushLinkStack(&stack1, 60);
	pushLinkStack(&stack1, 50);
	pushLinkStack(&stack1, 40);
	pushLinkStack(&stack1, 30);
	pushLinkStack(&stack1, 20);
	pushLinkStack(&stack1, 10);
	popLinkStack(&stack1);
	popLinkStack(&stack1);
	popLinkStack(&stack1);
	printf("末尾结点的值是：%d \n", stack1.buttom->data);
	clearLinkStack(&stack1);
	traverseLinkStack(&stack1);
	printf("该栈的长度是：%d \n", getLengthLinkStack(&stack1));
	printf("该栈是否为空？ %d \n", isLinkStackEmpty(&stack1));
	return 0;
}

void initLinkStack(LinkStack * pStack)
{
	pStack->top = (LinkNode *)malloc(sizeof(LinkNode));
	if (NULL == pStack->top)
	{
		printf("内存分配失败\n");
		exit(-1);
	}
	else
	{
		pStack->buttom = pStack->top;
		pStack->buttom->pNext = NULL;
	}
}

void pushLinkStack(LinkStack * pStack, int value)
{
	LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
	if (NULL == newNode)
	{
		printf("内存分配失败\n");
		exit(-1);
	}
	newNode->data = value;
	newNode->pNext = pStack->top;
	pStack->top = newNode;
}

int popLinkStack(LinkStack * pStack)
{
	if (true == isLinkStackEmpty(pStack))
	{
		printf("该链栈为空，无元素出栈！\n");
		return -1;
	}
	LinkNode *pTemp = pStack->top;
	int value = pStack->top->data;

	pStack->top = pStack->top->pNext;
	free(pTemp);
	return value;
}


void traverseLinkStack(LinkStack * pStack)
{
	if (true == isLinkStackEmpty(pStack))
		printf("该链栈为空，无法遍历！\n");
	else
	{
		LinkNode * pTemp = pStack->top;
		while (pTemp != pStack->buttom)
		{
			printf("%d ", pTemp->data);
			pTemp = pTemp->pNext;
		}
		printf("\n");
	}
}

bool isLinkStackEmpty(LinkStack * pStack)
{
	if (pStack->buttom == pStack->top)
		return true;
	else
		return false;
}

int getLengthLinkStack(LinkStack * pStack)
{
	int i = 0;
	LinkNode * pTemp = pStack->top;
	while (pTemp != pStack->buttom)
	{
		pTemp = pTemp->pNext;
		i++;
	}
	return i;
}

void clearLinkStack(LinkStack * pStack)
{
	LinkNode * pTemp = pStack->top;
	while (pStack->top != pStack->buttom)
	{
		pStack->top = pStack->top->pNext;
		free(pTemp);
		pTemp = pStack->top;
	}
}