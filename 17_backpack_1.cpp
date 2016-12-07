#include <iostream>

using namespace std;

int main()
{
	int n;
	double w;
	cin >> w >> n;
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[3];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1]; // weight, price
	}
	double** b = new double*[n];
	for (int i = 0; i < n; i++)
		b[i] = new double[2];
	for (int i = 0; i < n; i++)
	{
		b[i][1] = (double)i;
		b[i][0] = (double)a[i][1] / (double)a[i][0];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][0] > b[j][0])
			{
				int c1 = b[j][0];
				int c2 = b[j][1];
				b[j][0] = b[i][0];
				b[j][1] = b[i][1];
				b[i][0] = c1;
				b[i][1] = c2;
			}
		}
	}

	int m = 0;
	double w1 = w;
	while (m != n + 1)
	{
		if (a[(int)b[m][1]][0] < w)
		{
			cout << b[m][1] << " - " << a[(int)b[m][1]][0] / w1 << endl;
			w -= a[(int)b[m][1]][0];
			m++;
		}
		else
		{
			cout << b[m][1] << " - " << a[(int)b[m][1]][0] / w1
				<< endl;
			m++;
			break;
		}
	} 
	for (int i = m; i < n; i++)
		cout << b[m][1] << " - " << "0" << endl;

	system("pause>>void");
	EXIT_SUCCESS;                         
}