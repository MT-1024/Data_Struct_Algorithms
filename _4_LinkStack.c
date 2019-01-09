#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node		//ջ�����������
{
	int data;
	struct Node * pNext;
}LinkNode;

typedef struct Stack		//ջ���汣��2����Ϣ��ջͷ���ĵ�ַ��ջβ�ڵ�ĵ�ַ
{
	LinkNode * top;
	LinkNode * buttom;
}LinkStack;

void initLinkStack(LinkStack * pStack);		//��ʼ��ʱ������һ���սڵ㣬��������ָ����Ϊ�գ�data��stack1�е�2���򶼱���ÿսڵ�ĵ�ַ
void pushLinkStack(LinkStack * pStack, int value);
int	 popLinkStack(LinkStack * pStack);
void traverseLinkStack(LinkStack * pStack);
bool isLinkStackEmpty(LinkStack * pStack);		//��ջ��������ֻҪ���пղ�������
int getLengthLinkStack(LinkStack * pStack);
void clearLinkStack(LinkStack * pStack);		//���ջ�е�Ԫ�أ����Ǳ���ջ�Ľṹ

int main()
{
	LinkStack stack1;
	initLinkStack(&stack1);
	printf("��ջ�Ƿ�Ϊ�գ� %d \n", isLinkStackEmpty(&stack1));
	pushLinkStack(&stack1, 60);
	pushLinkStack(&stack1, 50);
	pushLinkStack(&stack1, 40);
	pushLinkStack(&stack1, 30);
	pushLinkStack(&stack1, 20);
	pushLinkStack(&stack1, 10);
	popLinkStack(&stack1);
	popLinkStack(&stack1);
	popLinkStack(&stack1);
	printf("ĩβ����ֵ�ǣ�%d \n", stack1.buttom->data);
	clearLinkStack(&stack1);
	traverseLinkStack(&stack1);
	printf("��ջ�ĳ����ǣ�%d \n", getLengthLinkStack(&stack1));
	printf("��ջ�Ƿ�Ϊ�գ� %d \n", isLinkStackEmpty(&stack1));
	return 0;
}

void initLinkStack(LinkStack * pStack)
{
	pStack->top = (LinkNode *)malloc(sizeof(LinkNode));
	if (NULL == pStack->top)
	{
		printf("�ڴ����ʧ��\n");
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
		printf("�ڴ����ʧ��\n");
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
		printf("����ջΪ�գ���Ԫ�س�ջ��\n");
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
		printf("����ջΪ�գ��޷�������\n");
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