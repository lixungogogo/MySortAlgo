#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//·Âº¯Êý
struct Greater
{
	bool operator()(const int& l, const int& r)
	{
		return l > r;
	}
};
//·Âº¯Êý
struct Less
{
	bool operator()(const int& l, const int& r)
	{
		return l < r;
	}
};
//Ä¬ÈÏÉýÐò
template <class Compare = Greater>
void InsertSort(int *data, size_t size)
{
	Compare com;
	for (int i = 0; i < size - 1; i++)
	{
		int end = i;
		int temp = data[end + 1];
		while (com(data[end],temp) && end > -1)
		{
			data[end + 1] = data[end];
			end--;
		}
		data[end + 1] = temp;
	}
}

void Print(int *a, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void TestInsertSort()
{
	int a[] = { 5, 4, 8, 9, 7, 6, 2, 1, 3, 0 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));//ÉýÐò
	Print(a, sizeof(a) / sizeof(a[0]));
	InsertSort<Less>(a, sizeof(a) / sizeof(a[0]));//½µÐò
	Print(a, sizeof(a) / sizeof(a[0]));
}

int main()
{
	TestInsertSort();
	return 0;
}