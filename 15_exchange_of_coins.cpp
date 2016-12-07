#include <iostream>
#include <vector>

using namespace std;



int main()
{
	vector <int> used;
	int n;
	int x1, x2;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> x1;
	x2 = x1;
_	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		while (x1 >= a[i]){
			x1 -= a[i];
			used.push_back(a[i]);
		}
	}
	if (x1 == 0){
		for (int i = 0; i < used.size(); i++)
			cout << used[i] << " ";
	}
	else
		cout << "0";

	system("pause>>void");
	EXIT_SUCCESS;
}