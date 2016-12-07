#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define N 10

bool if_left_bigger(string a, string b)
{
	for (int i = 0; i < min(a.length(), b.length()); i++){
		if ((int)a[i] > (int)b[i])
			return true;
		if ((int)a[i] < (int)b[i])
			return false;
	}
	if (a.length() > b.length())
		return true;
	else
		return false;
}

void Merge(string *Arr, int first, int last)
{
	int middle, j;
	string *mas = new string[last + 1];
	middle = (first + last) / 2; 
	int next_one_1 = first; 
	int next_one_2 = middle + 1; 
	for (j = first; j <= last; j++) 
		if ((next_one_1 <= middle) && ((next_one_2>last) || (if_left_bigger(Arr[next_one_2],Arr[next_one_1]))))
		{
			mas[j] = Arr[next_one_1];
			next_one_1++;
		}
		else
		{
			mas[j] = Arr[next_one_2];
			next_one_2++;
		}
	for (j = first; j <= last; j++) 
	{
		Arr[j] = mas[j];
	}
	delete[]mas;
};

void MergeSort(string *Arr, int first, int last)
{
	{
		if (first<last)
		{
			MergeSort(Arr, first, (first + last) / 2); 
			MergeSort(Arr, (first + last) / 2 + 1, last); 
			Merge(Arr, first, last); 
		}
	}
};

//97-122

void main()
{
	string* Str = new string[N];
	for (int i = 0; i < N; i++){
		int g = rand() % 10 + 1;
		for (int j = 0; j < g; j++)
		{
			Str[i] += (char)(65 + rand() % 26);
		}
	}
	for(int i = 0; i < N; i++)
		cout << Str[i] << endl;

	MergeSort(Str, 0, N - 1);

	cout << '\n';
	for (int i = 0; i < N; i++) 
		cout << Str[i] << endl;
	delete[]Str;
	system("pause>>void");
}