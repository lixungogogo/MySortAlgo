#include <iostream>
#include <assert.h>
using namespace std;

struct Greater
{
	bool operator()(const int& l, const int& r)
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
void BubbleSort(int *a, int size)
{
	Compare com;
	assert(a);
	int end = size - 1;
	while (end > 0)
	{
		bool ret = false;
		for (int i = 0; i < end; i++)
		{
			if (com(a[i],a[i + 1]))
			{
				swap(a[i], a[i + 1]);
				ret = true;
			}
		}
		if (!ret)
			break;
		end--;
	}
}

void Print(int *a, int size)
{
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
	BubbleSort<Less>(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
	return 0;
}