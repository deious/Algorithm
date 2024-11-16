#include <iostream>

using namespace std;

int dp[21];

int Fibo(int n)
{
	if (n <= 1)
	{
		dp[n] = n;
		return dp[n];
	}

	if (dp[n] != 0)
	{
		return dp[n];
	}

	return dp[n] = Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	Fibo(n);
	cout << dp[n] << "\n";

	return 0;
}