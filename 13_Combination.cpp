#include <iostream>

using namespace std;

void pers(int* array, int* changing_array, int n, int current_number, int length, bool* Used)
{
	if (length - 1 == current_number)
	{
		for (int i = 0; i < n; i++)
		{
			if (!Used[i])
			{
				changing_array[current_number] = array[i];
				for (int j = 0; j < length; j++)
					cout << changing_array[j] << " ";
				cout << '\n';
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (!Used[i])
			{
				Used[i] = true;
				changing_array[current_number] = array[i];
				pers(array, changing_array, n, current_number + 1, length, Used);
				Used[i] = false;
			}
		}
	}
	return;
}

void PersArrray()
{
	cout << "Dlinamassiva probel dlina miniperestonovki" << endl;
	int n, m;
	cin >> n >> m;
	int* main = new int[n];
	bool* used = new bool[n];
	for (int i = 0; i < n; i++){
		cin >> main[i];
		used[i] = false;
	}
	int* changing = new int[m];
	pers(main, changing, n, 0, m, used);
	delete(main);
	delete(used);
	delete(changing);
	return;
}

int main()
{
	PersArrray();
	system("pause");
	EXIT_SUCCESS;
}