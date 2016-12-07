/*#include <iostream>
using namespace std;

enum {MAX = 100};


void run(int i, int j, int** b)
{
	if (i >= 2){
		b[i - 2][j] += 1;
		run(i - 2, j, b);
	}
	if (j >= 2){
		b[i][j - 2] += 1;
		run(i, j - 2, b);
	}
	if (i >= 1 && j >= 1)
	{
		b[i - 1][j - 1] += 1;
		run(i - 1, j - 1, b);
	}
}

int problem()
{
	//int a[MAX][MAX];
	int n, m, answer = 0;
	cin >> n >> m;
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
		for (int j = 0; j < m; j++)
			a[i][j] = 0;
	}
	run(n - 1, m - 1, a);
	answer = a[0][0];
	return answer;
}


int main()
{
	cout << problem();
	system("pause>>void");
	EXIT_SUCCESS;
}*/