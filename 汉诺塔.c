#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

/*
�����1������
	ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
����
	�Ƚ�A�����ϵ�n-1�����ӽ���C�Ƶ�B
	ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
	���B�����ϵ�n-1�����ӽ���A�Ƶ�C
*/
void hanuota(int n, char x, char y, char z)
{
	if (n == 1)
	{
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c����\n", n, x, z);
	}
	else
	{
		hanuota(n - 1, x, z, y);
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c����\n", n, x, z);
		hanuota(n - 1, y, x, z);
	}
}

int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("������Ҫ�ƶ����ӵĸ���: ");
	scanf("%d", &n);

	hanuota(n, ch1, ch2, ch3);
	return 0;
}