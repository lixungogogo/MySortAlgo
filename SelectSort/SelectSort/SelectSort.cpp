#include <iostream>
#include <assert.h>
using namespace std;

void SelectSort(int *a, int size)
{
	assert(a);
	int end = size - 1;
	int MaxIndex = 0;
	for (int end = size - 1; end > 0; end--)
	{
		int begin = 0;
		while (begin < end)
		{
			if (a[begin] > a[MaxIndex])
				MaxIndex = begin;
			begin++;
		}
		if (a[MaxIndex] > a[end])
			swap(a[MaxIndex], a[end]);
	}
}

void SelectSort_OP(int *a, int size)
{
	assert(a);
	int begin = 0;
	int end = size - 1;
	int maxIndex = 0;
	int minIndex = 0;
	while (begin < end)
	{
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxIndex])
				maxIndex = i;
			if (a[i] < a[minIndex])
				minIndex = i;
		}
		swap(a[begin], a[minIndex]);
		if (maxIndex == begin)
			swap(a[end], a[minIndex]);
		else
			swap(a[end], a[maxIndex]);
		begin++;
		end--;
	}
}


void Print(int *a,int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int a[] = { 9, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	SelectSort_OP(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
	return 0;
}