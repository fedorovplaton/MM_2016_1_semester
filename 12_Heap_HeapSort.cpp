#include <iostream>

using namespace std;

enum {MAX_SIZE = 100};

struct Heap
{
private:
	int CurrentSize = 0;
	int* a = new int[MAX_SIZE];
	void heapify(int i)
	{
		int LeftChild;
		int RightChild;
		int LargestChild;
		while (true)
		{
			LeftChild = i * 2 + 1;
			RightChild = i * 2 + 2;
			LargestChild = i;
			if (LeftChild < CurrentSize && a[LeftChild] > a[i])
			{
				LargestChild = LeftChild;
			}
			if (RightChild < CurrentSize && a[RightChild] > a[LargestChild])
			{
				LargestChild = RightChild;
			}
			if (i == LargestChild)
				break;
			int c = a[i];
			a[i] = a[LargestChild];
			a[LargestChild] = c;
			i = LargestChild;
		}
	}
public:
	void push(int key)
	{
		a[CurrentSize] = key;
		CurrentSize++;
		int i = CurrentSize - 1;
		int parent = (i - 1) / 2;
		while (i > 0 && a[parent] < a[i])
		{
			int c = a[parent];
			a[parent] = a[i];
			a[i] = c;
			i = parent;
			parent = (i - 1) / 2;
		}
		heapify(i);
	}
	int take_max()
	{
		int c = a[0];
		a[0] = a[CurrentSize - 1];
		CurrentSize--;
		heapify(0);
		return c;
	}
	void out()
	{
		for (int i = 0; i < CurrentSize; i++)
			cout << a[i] << " ";
	}
	int* sort()
	{
		int* b = new int[CurrentSize];
		for (int i = 0; i < CurrentSize; i++)
		{
			b[i] = a[0];
			a[0] = a[CurrentSize - 1];
			CurrentSize--;
			heapify(0);
		}
		return b;
	}
};

int main()
{
	Heap my;

	/*
	n = 10
	for (int i = 0; i < 10; i++)
	my.push((i * 1003) % 13);
	*/
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		my.push(x);
	}
	for (int i = 0; i < n; i++)
		cout << my.take_max() << " ";

	system("pause");
	EXIT_SUCCESS;
}