#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, sqrtn;
	long long sum = 0;
	cin >> n;
	sqrtn = (int)(sqrt(n) + 0.0000001);

	for (int i = 2; i <= sqrtn; i++)
	{
		int k = n / i;
		sum += i * (k - i + 1) + (long long)(k - i) * (k + i + 1) / 2;
		sum %= 1000000;
	}
	
	cout << sum << "\n";

	return 0;
}