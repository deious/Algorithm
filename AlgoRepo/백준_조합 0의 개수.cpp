#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Calculate(int n, int x)
{
	int num = 0;

	for (long long i = x; n / i >= 1; i *= x)
	{
		num += n / i;
	}

	return num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	long long five = 0;
	long long two = 0;

	five = Calculate(n, 5) - Calculate(n - m, 5) - Calculate(m, 5);
	two = Calculate(n, 2) - Calculate(n - m, 2) - Calculate(m, 2);

	cout << min(five, two) << "\n";

	return 0;
}