#include <iostream>

using namespace std;

long long check[10];

void Calculate(long long n, long long ten)
{
	while (n > 0) 
	{
		check[n % 10] += ten;
		n /= 10;
	}

	return;
}

void Solve(long long a, long long b, long long ten) 
{
	while (a % 10 != 0 && a <= b)
	{
		Calculate(a, ten);
		a++;
	}

	if (a > b) 
		return;

	while (b % 10 != 9 && b >= a)
	{
		Calculate(b, ten);
		b--;
	}

	long long cnt = (b / 10 - a / 10 + 1);

	for (int i = 0; i < 10; i++)
		check[i] += (cnt * ten);

	Solve(a / 10, b / 10, ten * 10);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;

	Solve(1, n, 1);

	for (int i = 0; i < 10; i++)
		cout << check[i] << " ";

	return 0;
}