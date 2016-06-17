#define _CRT_SECURE_NO_WARININGS 1
#include <iostream>
#include <assert.h>
using namespace std;
size_t GetMaxDigit(int *a, size_t size)
{
	assert(a);
	int bucket = 10;
	int n = 1;
	for (int i = 0; i < size;i++)
	{
		while (a[i] > bucket)
		{
			bucket *= 10;
			n++;
		}
	}
	return n;
}
void LSDSort(int *a, size_t size)
{
	assert(a);
	//int bucket[10] = { 0 };
	int count[10] = { 0 };
	int start[10] = { 0 };
	size_t n = GetMaxDigit(a, size);
	int ret = 1;
	for (int j = 0; j < n;j++)
	{
		memset(count, 0, sizeof(int)* 10);
		memset(start, 0, sizeof(int)* 10);
		for (int i = 0; i < size; i++)
		{
			int index = (a[i]/ret) % 10;
			count[index]++;
		}
		for (int i = 1; i < 10; i++)
		{
			start[i] = start[i - 1] + count[i - 1];
		}
		int *bucket = new int[size];
		memset(bucket, 0, sizeof(int)*size);
		for (int i = 0; i < size; i++)
		{
			int index = start[(a[i] / ret) % 10]++;
			bucket[index] = a[i];
		}
		memcpy(a, bucket, sizeof(int)*size);
		ret *= 10;
	}
}

void Print(int *a, size_t size)
{
	assert(a);
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[] = { 3, 22, 93, 43, 55, 14, 28, 65, 39, 8100 };
	LSDSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
	return 0;
}