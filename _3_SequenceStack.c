#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct SequenceStack
{
	int * first;		//存放数组基地址
	int top;		//first[]的末尾元素,top初始值为-1
	int stacklength;		//申请的栈的容量
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
		printf("分配内存失败\n");
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
		printf("该栈满了！无法压栈！\n");
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
		printf("该栈为空！无法出栈！\n");
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
		printf("该栈为空！无法遍历！\n");
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
		printf("该栈为空！无需清空！\n");
	}
	else
	{
		pStack->top = -1;
	}

}