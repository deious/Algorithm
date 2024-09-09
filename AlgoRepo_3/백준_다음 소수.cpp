#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(long long num)
{
	if (num < 2)
	{
		return false;
	}

	int n = sqrt(num);

	for (int i = 2; i <= n; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	long long n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		while (true)
		{
			if (IsPrime(n))
			{
				cout << n << "\n";
				break;
			}

			n++;
		}
	}

	return 0;
}