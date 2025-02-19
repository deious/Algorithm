#include <iostream>

using namespace std;

int num[1001];

int Calculate(int n)
{
	if (n <= 99)
	{
		return 1;
	}

	int a, b, c;
	a = n % 10;
	n /= 10;
	b = n % 10;
	n /= 10;
	c = n;

	if ((b - a) == (c - b))
	{
		return 1;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= 1000; i++)
	{
		num[i] = num[i - 1] + Calculate(i);
	}

	cout << num[N] << "\n";

	return 0;
}