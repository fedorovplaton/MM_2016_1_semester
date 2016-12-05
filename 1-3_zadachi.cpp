using namespace std;
#include <iostream>

void B()
{
	double answer = 0;
	double number = 0;
	for (;;){
		double x;
		cin >> x;
		if (x != 0){
			answer *= (number / (number + 1));
			answer += (x / (number + 1));
			number += 1;
		}
		else{
			break;
		}
	}
	cout << answer * (number / (number + 1));
	return;
}
 

double bin(double a, int n)
{
	if (n == 0) return 1;
    if (n == 1) return a;
	if (n % 2 == 0) return bin(a * a, n / 2);
	else return bin(a, n -1) * a;
}

void A()
{
	double index;
    int pow;
	cin >> index >> pow;
	cout << bin(index, pow);
	return;
}


void C(){
	int const N = 16;
	int a[N];
	int n;
	int ans = 0;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	cin >> n;
	for (int i = 0; i < N; i++)
		if (a[i] == n)
			ans += 1;
	cout << ans << '\n';
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
		{
			if (a[j] < a[i]){
				int c = a[j];
				a[j] = a[i];
				a[i] = c;
			}

		}
	}
	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
	return;
}

int main()
{
	//Вписать "A();", "B();", "C();".
	return 0;
}

