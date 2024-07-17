#include <iostream>

using namespace std;

long long dp[68];

long long Koong(int n)
{
	if (n <= 3)
	{
		return dp[n];
	}
	
	if (dp[n])
	{
		return dp[n];
	}

	return dp[n] = Koong(n - 1) + Koong(n - 2) + Koong(n - 3) + Koong(n - 4);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;

	dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;

	while (t--)
	{
		cin >> n;
		cout << Koong(n) << "\n";
	}

	return 0;
}