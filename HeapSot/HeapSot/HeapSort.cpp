#define _CRT_SECURE_NO_WAININGS 1
#include <iostream>
#include <assert.h>
using namespace std;
//向下调整
void AdjustDown(int *a, size_t size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&a[child + 1]<a[child])
		{
			child++;
		}
		if (a[child]<a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}
//升序排序
void HeapSort(int *data,int size)
{
	//建堆
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustDown(data, size, i); 
	}
	int index = size;
	while (index)
	{
		AdjustDown(data, index, 0);
		swap(data[0], data[index - 1]);
		index--;
	}
}

int main()
{
	int data[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(data) / sizeof(data[0]);
	HeapSort(data,size );
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << "　";
	}
	return 0;
}