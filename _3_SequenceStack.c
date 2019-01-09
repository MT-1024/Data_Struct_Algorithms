#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct SequenceStack
{
	int * first;		//����������ַ
	int top;		//first[]��ĩβԪ��,top��ʼֵΪ-1
	int stacklength;		//�����ջ������
}SequenceStack;

void initSequenceStack(SequenceStack * pStack, int length);
bool isSequenceStackEmpty(SequenceStack * pStack);
bool isSequenceStackFull(SequenceStack * pStack);
void pushSequenceStack(SequenceStack * pStack, int value);
int popSequenceStack(SequenceStack * pStack);
void traverseStack(SequenceStack * pStack);
void clearSequenceStack(SequenceStack * pStack);


int main()

{
	SequenceStack stack1;
	initSequenceStack(&stack1,2);
	isSequenceStackEmpty(&stack1);
	pushSequenceStack(&stack1, 30);
	pushSequenceStack(&stack1, 20);
	pushSequenceStack(&stack1, 10);
	popSequenceStack(&stack1);
	traverseStack(&stack1);

	return 0;
}


void initSequenceStack(SequenceStack * pStack, int length)
{
	pStack->first = (int *)malloc(sizeof(int)*length);
	if (NULL == pStack)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	else
	{
		pStack->top = -1;
		pStack->stacklength = length;
	}
}

bool isSequenceStackEmpty(SequenceStack * pStack)
{
	if (-1 == pStack->top)
	{
		return true;
	}
	else
		return false;
}

bool isSequenceStackFull(SequenceStack * pStack)
{
	if (pStack->top == pStack->stacklength -1)
	{
		return true;
	}
	else
		return false;
}



void pushSequenceStack(SequenceStack * pStack, int value)
{
	if (true == isSequenceStackFull(pStack))
	{
		printf("��ջ���ˣ��޷�ѹջ��\n");
	}
	else
	{
		pStack->top++;
		pStack->first[pStack->top] = value;
	}
}

int popSequenceStack(SequenceStack * pStack)
{
	if (true == isSequenceStackEmpty(pStack))
	{
		printf("��ջΪ�գ��޷���ջ��\n");
		return -1;
	}
	else
	{
		return pStack->first[pStack->top--];
	}

}

void traverseStack(SequenceStack * pStack)
{
	if (true == isSequenceStackEmpty(pStack))
	{
		printf("��ջΪ�գ��޷�������\n");
	}
	else
	{
		for (int i = pStack->top; i >= 0; i--)
		{
			printf("%d ", pStack->first[i]);
		}
		printf("\n");
	}
}

void clearSequenceStack(SequenceStack * pStack)
{
	if (true == isSequenceStackEmpty(pStack))
	{
		printf("��ջΪ�գ�������գ�\n");
	}
	else
	{
		pStack->top = -1;
	}

}