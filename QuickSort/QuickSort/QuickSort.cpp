#include <iostream>
#include <assert.h>
using namespace std;

int _PartSort(int *a, int left, int right)
{
	assert(a);
	int begin = left;
	int end = right - 1; 
	int key = a[right];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
 			++begin;
		while (begin < end && a[end] >= key)
			--end;
		if (begin < end)
			swap(a[begin], a[end]);
	}
	if (a[begin] > a[right])
	{
		swap(a[begin], a[right]);
		return begin;
	}
	else
		return begin;
}
//[]
void QuickSort(int *a, int left,int right)
{
	assert(a);
	if (left >= right)
		return;
	int div = _PartSort(a, left, right);
	QuickSort(a, left, div);
	QuickSort(a, div + 1, right);
}

void Print(int *a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[] = {5,5,1,4,9,8,5,3,6,5,7};
	//int a[] = { 4, 3 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0])-1);
	Print(a, sizeof(a) / sizeof(a[0]));
	return 0;
}

