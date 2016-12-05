/*#include <iostream>

using namespace std;

/*
0 1 2 3
4 5 6 7
8 9 10 11
4 3


int main()
{
	int n; // stroki
	int m; // stolbci
	cin >> n >> m;
	int* a = new int[n * m];
	// a[i][j] = a[(n - 1) * i + (j)];
	// zapolnenie
	for (int i = 0; i < n * m; i++)
		cin >> *(a + i);
	//poisk max
	int max = *a;
	for (int i = 0; i < (n * m); i++)
		if (*(a + i) > max)
			max = *(a + i);
	// max - otvet
	cout << max;
	system("pause>>void");
	EXIT_SUCCESS;
}*/