#include <iostream>

using namespace std;

long long dp[1000001];

long long Calculate(int num)
{
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= num; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
	}

	return dp[num] % 1000000000;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	if (n < 0)
	{
		n *= -1;
		if (n % 2 == 0)
		{
			cout << "-1\n";
		}
		else
		{
			cout << "1\n";
		}
	}
	else if (n == 0)
	{
		cout << "0\n";
	}
	else
	{
		cout << "1\n";
	}

	cout << Calculate(n) << "\n";

	return 0;
}