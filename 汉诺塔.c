#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

/*
如果是1个盘子
	直接将A柱子上的盘子从A移到C
否则
	先将A柱子上的n-1个盘子借助C移到B
	直接将A柱子上的盘子从A移到C
	最后将B柱子上的n-1个盘子借助A移到C
*/
void hanuota(int n, char x, char y, char z)
{
	if (n == 1)
	{
		printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n", n, x, z);
	}
	else
	{
		hanuota(n - 1, x, z, y);
		printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n", n, x, z);
		hanuota(n - 1, y, x, z);
	}
}

int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("请输入要移动盘子的个数: ");
	scanf("%d", &n);

	hanuota(n, ch1, ch2, ch3);
	return 0;
}