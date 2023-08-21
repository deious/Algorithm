#include <iostream>

using namespace std;

long long Calculate(long long num)
{
	long long a = num;
	for (long i = 2; i <= num; i *= 2)
	{
		a += (num / i) * (i / 2);
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long a, b;
	cin >> a >> b;
	cout << Calculate(b) - Calculate(a - 1) << "\n";

	return 0;
}