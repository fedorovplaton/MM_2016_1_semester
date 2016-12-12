#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int* p;
int* w;
int** A;
vector <int> answer;

void Find_Answer(int k, int s)
{
	if (A[k][s] == 0)
		return;
	if (A[k - 1][s] == A[k][s])
		Find_Answer(k - 1, s);
	else{
		Find_Answer(k - 1, s - w[k]);
		answer.push_back(k);
    }
}

int main()
{
	int N, W;
	cin >> W >> N;
	p = new int[N + 1];
	w = new int[N + 1];
	A = new int*[N + 1];
	for (int i = 0; i <= N; i++)
		A[i] = new int[W + 1];

	for (int i = 1; i <= N; i++)
	{
		cin >> w[i] >> p[i];
	}

	for (int i = 0; i <= N; i++)
		A[i][0] = 0;
	for (int i = 0; i <= W; i++)
		A[0][i] = 0;

	for (int k = 1; k <= N; k++)
	{
		for (int s = 1; s <= 13; s++)
		{
			if (s >= w[k])
			{
				A[k][s] = max(A[k - 1][s], A[k - 1][s - w[k]] + p[k]);
			}
			else
				A[k][s] = A[k - 1][s];
		}
	}
	for (int i = 0; i <= N; i++){
		for (int j =  0; j <= W; j++)
			cout << A[i][j] << " ";
		cout << '\n';
	}

	cout << "Max - " << A[N][W] << '\n';
	Find_Answer(N, W);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	system("pause>>void");
	return EXIT_SUCCESS;
}
