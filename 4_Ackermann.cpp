#include <iostream>

using namespace std;

int b = 1000000007;
int i = 0;

int Ackermann(int m, int n)
{
	i++;
	if (m == 0) return (++n % b);
	if (m > 0 && n == 0) return (Ackermann(m - 1, 1) % b);
	if (m > 0 && n > 0) return Ackermann(m - 1, Ackermann(m, n - 1)) % b;
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << "Ackermann(" << x << "," << y << ") = " << Ackermann(x, y) << " " << i; 
	system("pause");
	return 0;
}