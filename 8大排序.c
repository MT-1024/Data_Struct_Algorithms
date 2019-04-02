#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void swap(int *a, int *b);
void bubbleSort(int a[], int size);
void selectSort(int a[], int size);
void inserionSort(int a[], int size);
void quickSort(int a[], int left, int right);
void mergeSort(int a[], int size);
void shellSort(int a[], int size);
void heapSort(int a[], int size);
void adjustHeap(int a[], int k, int size);

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int a[], int size)
{
	for (int i = size - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
	}
}

void selectSort(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (a[i] > a[j])
				swap(&a[i], &a[j]);
		}
	}
}

void inserionSort(int a[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int temp = a[i];	//拷贝待插入的a[i]；因为后面寻找插入位置时会移动元素，导致覆盖a[i]
		while (i >= 0 && a[i - 1] > temp)
		{
			a[i] = a[i - 1];
			i--;
		}
		a[i] = temp;
	}

}

void quickSort(int a[], int left, int right)
{
	if (left >= right)
		return;
	int j = right;	//右侧的哨兵j先检测比pivot小的值，这样才可以把i当成最后与left交换的最终位置
	int i = left;	//左边的哨兵i后检测比pivot大的值
	int pivot = a[left];
	while (i != j)
	{
		while (i < j && a[j] >= pivot)	//右侧哨兵先向左移动
			j--;
		while (i < j&&a[i] <= pivot)	//左侧哨兵后向右移动
			i++;
		if (i < j)
			swap(&a[i], &a[j]);
	}
	swap(&a[left], &a[i]);
	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);
}

void mergeSort(int a[], int size)
{


}

void shellSort(int a[], int size)
{
	int increasement, i, j, temp;	//increasement是步长，数组a[]被分为size/increasement个组
	for (increasement = size / 2; increasement >= 1; increasement /= 2)
	{
		for (i = increasement; i < size; ++i)
		{
			temp = a[i];		// a[increasement/2]是数组a[]的中间元素
			j = i - increasement;	//j指向已排序数组，j此时一定为0，即a[j]是数组首元素
			while (j >= 0 && a[j] > temp)	//a[j] >  a[temp]=a[increment] 时，将a[j]后移
			{
				a[j + increasement] = a[j]; //将a[j]后移
				j -= increasement;		//j向前移动incre个位置
			}
			a[j + increasement] = temp;
		}
	}
}

void heapSort(int a[], int size)
{
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		adjustHeap(a, i, size);
	}
	for (int j = size - 1; j > 0; j--)
	{
		swap(&a[j], &a[0]);
		adjustHeap(a, 0, j);
	}
}

void adjustHeap(int a[], int i, int size)
{
	int temp = a[i];
	for (int k = i * 2 + 1; k < size; k = k * 2 + 1)
	{
		if (k + 1 < size && a[k] < a[k + 1])
			++k;
		if (a[k] > temp)
		{
			a[i] = a[k];
			i = k;
		}
		else
			break;
	}
	a[i] = temp;

}

int main()
{
	int array[5] = { 5,4,3,2,1 };
	heapSort(array, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", array[i]);
	}
}
