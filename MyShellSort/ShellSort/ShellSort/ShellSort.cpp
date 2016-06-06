#include <iostream>
#include <assert.h>
using namespace std;

struct Greater
{
	bool operator()(const int& l,const int& r)
	{
		return l > r;
	}
};

struct Less
{
	bool operator()(const int& l, const int& r)
	{
		return l < r;
	}
};
template <class Compare = Greater>
void ShellSort(int *data,size_t size)
{
	Compare com;
	int gap = size / 3 + 1;
	while (gap >= 1)
	{
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;
			int temp = data[end + gap];
			while (end > -1 && com(data[end],temp))
			{
				data[end + gap] = data[end];
				end -= gap;
			}
			data[end + gap] = temp;
		}
		gap--;
	}
}

void Print(int *a, size_t size)
{
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int a[] = { 5, 4, 2, 3, 1, 8, 6, 7, 9, 0 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
	ShellSort<Less>(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
	return 0;
}