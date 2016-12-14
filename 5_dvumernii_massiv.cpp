#include <iostream>

using namespace std;

/*
0 1 2 3
4 5 6 7
8 9 10 11
3 4*/

struct array{
private:
	int* a = new int[];
	int height = 0;
	int width = 0;
	
public:
	array(int k, int l)
	{
		height = k;
		width = l;
		a = new int[k * l];
	}
	int* e(int n, int m)
	{
		return &a[(height - 1) * n + m]; // 2 * 2 + 3 * 2 = 10
	}
	~array()
	{
		cout << "destr" << '\n';
		delete[]a;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	array my(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> *(my.e(i, j));
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << *my.e(i, j);
		}
		cout << '\n';
	}

	//find max
	if (n != 0 && m != 0){
		int max_i = 0, max_j = 0;
		int c = *(my.e(0, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (*(my.e(i, j)) > c)
				{
					c = *(my.e(i, j));
					max_i = i;
					max_j = j;
				}
			}
		}
	}
	system("pause>>void");
	EXIT_SUCCESS;
}