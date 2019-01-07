#pragma warning(disable:4996)		//�ر�vs2017�ļ��scanf����ȫ����
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}LinkNode, *LinkList;		//LinkNode�൱��sturct Node
							//LinkList�൱��struct Node *, LinkList��ָ��strut Node���͵�ָ�����

LinkNode * initLinkListRear(void);		//β�巨��������
LinkNode * initLinkListFront(void);		//ͷ�巨��������
void traverseLinkList(LinkNode * pHead);		//���׽�㿪ʼ��������
bool isEmpty(LinkNode * pHead);
int getLengthLinkList(LinkNode * pHead);		//��ȡ����ĳ��ȣ�����Head��㣩
bool insertLinkNode(LinkNode * pHead, int position, int value);		//�ڵ�pos��λ�ò���dataΪvalue�ĵĽ��
bool deleteLinkNode(LinkNode * pHead, int position, int * pDelete);		//ɾ����pos��λ�õĽ�㣬����¼��ɾ���ĵ�ַ
LinkNode * locateLinkNode(LinkNode * pHead, int position);		//���ص�position���ĵ�ַ
int searchLinkNode(LinkNode * pHead, int value);		//���ҽ���һ��data=value��λ�ã������ظýڵ��������е�λ��




int main()
{
	LinkNode  * pHead;
	pHead = initLinkListRear();
	traverseLinkList(pHead);
	printf("�������Ƿ�Ϊ�գ�%d\n", isEmpty(pHead));
	printf("������ĳ����ǣ�%d \n", getLengthLinkList(pHead));
	insertLinkNode(pHead, 1, 1);
	insertLinkNode(pHead, 4, 4);
	traverseLinkList(pHead);
	int value;		//���ڷ�����Ҫɾ����ֵ
	deleteLinkNode(pHead, 4, &value);
	printf("��ɾ������ֵ�ǣ�%d\n", value);
	traverseLinkList(pHead);
	printf("���ҽ��data��Ϊ2��λ���ǣ�%d \n", searchLinkNode(pHead, 2));
	return 0;
}




LinkNode * initLinkListRear(void)
{
	LinkNode * pHead = (LinkNode *)malloc(sizeof(LinkNode));		//����ͷ����ָ��
	if (NULL == pHead)		//����׵�ַΪ�գ���ʾ�ڴ����ʧ�ܲ����˳�����
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	pHead->pNext = NULL;		//ͷ���pNext���ʼ��
	LinkNode * pTemp = pHead;
	int tempValue;		//��ʱ���Ҫ�����dataֵ
	int length;			//��Ҫ����������Ԫ�صĸ���������ͷ��㣩

	printf("��������Ҫ���ɵ�����ĳ���:length= ");
	scanf("%d", &length);

	for (int i = 0; i < length; i++)
	{
		LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
		if (NULL == newNode)		//����׵�ַΪ�գ���ʾ�ڴ����ʧ�ܲ����˳�����
		{
			printf("�ڴ����ʧ�ܣ�\n");
			exit(-1);
		}
		newNode->pNext = NULL;
		printf("�������%d������ֵ�� ", i + 1);
		scanf("%d", &tempValue);
		newNode->data = tempValue;		//β�巨��������
		pTemp->pNext = newNode;
		pTemp = newNode;
	}

	return pHead;
}

LinkNode * initLinkListFront(void)
{
	LinkNode * pHead = (LinkNode *)malloc(sizeof(LinkNode));		//����ͷ����ָ��
	if (NULL == pHead)		//����׵�ַΪ�գ���ʾ�ڴ����ʧ�ܲ����˳�����
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	pHead->pNext = NULL;		//ͷ���pNext���ʼ��
	LinkNode * pTemp = pHead;
	int tempValue;		//��ʱ���Ҫ�����dataֵ
	int length;			//��Ҫ����������Ԫ�صĸ���������ͷ��㣩

	printf("��������Ҫ���ɵ�����ĳ���:length= ");
	scanf("%d", &length);

	for (int i = 0; i < length; i++)
	{
		LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
		if (NULL == newNode)		//����׵�ַΪ�գ���ʾ�ڴ����ʧ�ܲ����˳�����
		{
			printf("�ڴ����ʧ�ܣ�\n");
			exit(-1);
		}
		newNode->pNext = NULL;
		printf("�������%d������ֵ�� ", i + 1);
		scanf("%d", &tempValue);
		newNode->data = tempValue;
		newNode->pNext = pTemp->pNext;		//ͷ�巨��������
		pTemp->pNext = newNode;
	}

	return pHead;
}



void traverseLinkList(LinkNode * pHead)
{
	LinkNode * pTemp = pHead->pNext;
	printf("����ı�������ǣ�");
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
		printf("����λ�ò��Ϸ�!\n");
		return false;
	}
	LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
	newNode->pNext = NULL;		//������Ľ���ʼ��ָ����Ϊ��

	LinkNode * pTemp = pHead;

	pTemp = locateLinkNode(pHead, position - 1);		//��λ������λ�õ�ǰ��һ�����ĵ�ַ
	newNode->data = value;
	newNode->pNext = pTemp->pNext;
	pTemp->pNext = newNode;
	return true;
}

bool deleteLinkNode(LinkNode * pHead, int position, int * pDelete)
{
	if (position < 1 || position > getLengthLinkList(pHead))
	{
		printf("ɾ��λ�ò��Ϸ�!\n");
		return false;
	}	LinkNode * pTemp;
	if (position == 1)
	{
		pTemp = pHead->pNext;
		pHead->pNext = pTemp->pNext;
		*pDelete = pTemp->data;		//��¼��ɾ����dataֵ
		free(pTemp);		//�ͷ�pTemp->data��ֵ
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
		printf("��λλ�ò��Ϸ�!\n");
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
		printf("û��data��Ϊ%d�Ľ�㣡 ", value);
		return -1;
	}
	return position;
}